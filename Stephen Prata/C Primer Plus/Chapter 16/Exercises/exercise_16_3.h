#ifndef EXERCISE_16_3_H_
#define EXERCISE_16_3_H_

#include "math.h"
#include "stdio.h"

#define PI (4.0*atan(1))
#define DEG_TO_RAD(X) ((X)*PI/180.0)

typedef struct
{
	double x, y;
} rect_v;

typedef struct
{
	double mag, angle;
} polar_v;

rect_v polar_to_rect(polar_v);

#endif
