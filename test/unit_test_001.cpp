//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-03
// PURPOSE: unit tests for the AverageAngle class
//          https://github.com/RobTillaart/AverageAngle
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)

#include <ArduinoUnitTests.h>

#include "AverageAngle.h"


unittest_setup()
{
}

unittest_teardown()
{
}

unittest(test_constructor)
{
  AverageAngle dd(AverageAngle::DEGREES);
  AverageAngle rr(AverageAngle::RADIANS);
  
  assertEqual(0, dd.type());
  assertEqual(1, rr.type());
}

unittest(test_degrees)
{
  AverageAngle aa(AverageAngle::DEGREES);

  for (int i = 0; i < 10; i++)
  {
    int n = aa.add(i);
    assertEqual(i + 1, n);
  }
  assertEqual(10,  aa.count());
  assertEqual(10,  aa.getTotalLength());
  assertEqual(1,   aa.getAverageLength());
  assertEqual(4.5, aa.getAverage());
}

unittest_main()

// --------
