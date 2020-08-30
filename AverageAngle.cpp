//
//    FILE: AverageAngle.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.4
// PURPOSE: class for averaging angles
//     URL: https://github.com/RobTillaart/AverageAngle
//
// HISTORY:
//
// 0.1.0 2017-11-21 initial version
// 0.1.1 2017-12-09 fixed negative values of average
// 0.1.2 2018-03-30 added getAverageLength, getTotalLength + zero-test
// 0.1.3 2020-03-26 #pragma once; removed pre 1.00 support; readme.md
// 0.1.4 2020-05-27 update library.json

#include "AverageAngle.h"


AverageAngle::AverageAngle(const enum AngleType type)
{
  _type = type;
  _half_turn = _type==RADIANS ? M_PI : 180;
  _full_turn = 2 * _half_turn;
  reset();
}

void AverageAngle::add(float alpha)
{
  // Unwrap.
  while (alpha < _last - _half_turn)
    alpha += _full_turn;
  while (alpha > _last + _half_turn)
    alpha -= _full_turn;
  _last = alpha;

  _sum += alpha;
  _count++;
}

void AverageAngle::reset()
{
  _last = 0;
  _sum = 0;
  _count = 0;
}

float AverageAngle::getAverage()
{
  float avg = _sum/_count;
  while (avg < 0) avg += _full_turn;
  while (avg >= _full_turn) avg -= _full_turn;
  return avg;
}

// -- END OF FILE --
