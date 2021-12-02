// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: MultiStepper.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>
#include <math.h>
// #include <Utility.h>


// Define some steppers and the pins the will use
#define EN          8  

//Direction pin
#define X_DIR       5 
#define Y_DIR       6
#define Z_DIR       7

// Step pin
#define X_STP       2
#define Y_STP       3 
#define Z_STP       4

// End stops (https://forum.arduino.cc/t/using-end-stops-on-cnc-shield-design-for-gbrl/510231/2)
#define X_LIM       9
#define Y_LIM       10
#define Z_LIM       11

#define MICROSTEPS_FULL  6400  // Number of microsteps in a full rotation
#define ANGLE_MIN   -15.
#define ANGLE_MAX   90.


void step (boolean dir, byte dirPin, byte stepperPin, int steps, int delayTime) {

  // Set rotation direction
  digitalWrite(dirPin, dir);

  for (int i = 0; i < steps; i++) {

    // Run one 1/32 microstep unit
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(delayTime);

    digitalWrite(stepperPin, LOW);
    delayMicroseconds(delayTime);

  }
}


void loop () {
  step (true, Y_DIR, Y_STP, 20, 100);
}
