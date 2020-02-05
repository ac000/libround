#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "libround.h"

int main(int argc, char *argv[])
{
	double rf;

	if (argc < 3)
		return -1;

	rf = lr_get_rounding_factor(atoi(argv[2]));

	printf("Rounding factor  : %f\n", rf);
	printf("ceil             : %f --> %f\n",
	       atof(argv[1]), ceil(atof(argv[1]) * rf) / rf);
	printf("ceil0            : %f --> %f\n",
	       atof(argv[1]), lr_ceil0(atof(argv[1]), rf));
	printf("floor            : %f --> %f\n",
	       atof(argv[1]), floor(atof(argv[1]) * rf) / rf);
	printf("floor0           : %f --> %f\n",
	       atof(argv[1]), lr_floor0(atof(argv[1]), rf));
	printf("round            : %f --> %f\n",
	       atof(argv[1]), round(atof(argv[1]) * rf) / rf);
	printf("round_half_up    : %f --> %f\n",
	       atof(argv[1]), lr_round_half_up(atof(argv[1]), rf));
	printf("round_half_up0   : %f --> %f\n",
	       atof(argv[1]), lr_round_half_up0(atof(argv[1]), rf));
	printf("round_half_down  : %f --> %f\n",
	       atof(argv[1]), lr_round_half_down(atof(argv[1]), rf));
	printf("round_half_down0 : %f --> %f\n",
	       atof(argv[1]), lr_round_half_down0(atof(argv[1]), rf));
	printf("round_half_even  : %f --> %f\n",
	       atof(argv[1]), lr_round_half_even(atof(argv[1]), rf));

	exit(EXIT_SUCCESS);
}
