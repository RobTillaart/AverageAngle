#pragma once
//
//    FILE: AverageAngle.h
//  AUTHOR: Rob dot Tillaart at gmail dot com
// VERSION: 0.1.4
// PURPOSE: class for averaging angles
// HISTORY: See AverageAngle.cpp
//

#include "math.h"
#include "Arduino.h"

#define AVERAGE_ANGLE_LIB_VERSION "0.1.4"

class AverageAngle
{
public:
    enum AngleType { DEGREES, RADIANS };

    AverageAngle(const enum AngleType type = DEGREES);

    void 	 add(float alpha);
    void 	 reset();
    uint32_t count() { return _count; };
    float    getAverage();

    enum     AngleType type() { return _type; };

private:
    enum AngleType _type;
    float _half_turn;
    float _full_turn;
    float _last;
    float _sum;
    uint32_t _count;
};

// -- END OF FILE --
