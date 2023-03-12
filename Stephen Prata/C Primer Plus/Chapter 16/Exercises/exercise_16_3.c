#include "exercise_16_3.h"

int main(void)
{
	rect_v vect_out;
	polar_v vect_in;
	
	printf("Enter the magnitude and angle in degrees of a vector:\n");
	
	while(scanf("%lf %lf", &vect_in.mag, &vect_in.angle) == 2)
	{
		if (vect_in.mag < 0)
		{
			printf("Try again!\n");
			continue;
		}
		
		vect_out = polar_to_rect(vect_in);
		
		printf("x: %.3f, y: %.3f\n", vect_out.x, vect_out.y);
		printf("Enter the magnitude and angle of a vector:\n");
	}
	
	return 0;
}

rect_v polar_to_rect(polar_v vect_p)
{
	rect_v vect_r;
	
	vect_r.x = vect_p.mag*cos(DEG_TO_RAD(vect_p.angle));
	vect_r.y = vect_p.mag*sin(DEG_TO_RAD(vect_p.angle));
	
	return vect_r;
}