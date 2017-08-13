/*
 * libround.c - Rounding algorithms
 *
 * Copyright (C) 2010, 2012, 2017	Andrew Clayton
 * 					<andrew@digital-domain.net>
 *
 * Inspired by rounding-algorithms.hpp in the Boost C++ library.
 *
 * Released under the GNU Lesser General Public License (LGPL) version 2.1
 * See COPYING
 */

#include <math.h>
#include <stdbool.h>

#include "libround.h"

/* 
 * Check if a fraction is a half, even though if sometimes it
 * should be, it isn't stored as that, e.g it may actually be 
 * 0.5000001. Multiplying then dividing by 10 seems to clear 
 * that up.
 * Return 0 if not 0.5
 * Return 1 if 0.5
 */
static bool is_fraction_a_half(double value)
{
	double frac;
	double integral;

	frac = modf(value, &integral);
	/*
	 * We do round(frac * 10) / 10 to get around fp inaccuracies.
	 * This should ensure that frac ends up exactly as 0.[0-9]
	 */
	if (round(frac * 10) / 10 != 0.5 && round(frac * 10) / 10 != -0.5)
		return false;
	else
		return true;
}

/*
 * Given a number of decimal places (dp), return 10.0 to the power dp
 * This is used to easily get at the remaining fraction part of the
 * number beyond the decimal places we actually want.
 *
 * e.g given we want 9.4650 to 2 decimal places, this function will return
 * 100.00 which when multipied with 9.4650 gives 946.50, letting us easily
 * apply one of the rounding algorithms on it. We then divide that number by
 * the rounding factor again to get our final answer.
 */
double lr_get_rounding_factor(int dp)
{
	double rounding_factor = 10.0;

	return rounding_factor = pow(rounding_factor, (double)dp);
}

/* Round up, away from 0 */
double lr_ceil0(double value, double rf)
{
	double result;

	result = ceil(fabs(value * rf)) / rf;
	if (value < 0.0)
		return -result;
	else
		return result;
}

/* Round down, towards 0 */
double lr_floor0(double value, double rf)
{
	double result;

	result = floor(fabs(value * rf)) / rf;
	if (value < 0.0)
		return -result;
	else
		return result;
}

double lr_round_half_up(double value, double rf)
{
	value *= rf;
	/*
	 * Some extra work needed to check for a half fraction.  
	 * 9.495 to 2dp shows this problem.
	 */ 	
	if (!is_fraction_a_half(value))
		return round(value) / rf;
	
	value = ceil(value) / rf;

	return value;
}

/* Round away from 0 */
double lr_round_half_up0(double value, double rf)
{
	double result;

	result = lr_round_half_up(fabs(value), rf);
	if (value < 0.0)
		return -result;
	else
		return result;
}

double lr_round_half_down(double value, double rf)
{
	value *= rf;
	/*
	 * Some extra work needed to check for a half fraction. 
	 * 9.095 to 2dp shows this problem.
	 */
	if (!is_fraction_a_half(value))
		return round(value) / rf;

	value = floor(value) / rf;

	return value;
}

/* Round towards 0 */
double lr_round_half_down0(double value, double rf)
{
	double result;

	result = lr_round_half_down(fabs(value), rf);
	if (value < 0.0)
		return -result;
	else
		return result;
}

/*
 * Round half to even, aka, Bankers rounding
 */
double lr_round_half_even(double value, double rf)
{
	double tmp;

	value *= rf;
	if (!is_fraction_a_half(value))
		return round(value) / rf;

	tmp = floor(value);
	if ((int)tmp % 2 == 0)
		return tmp / rf;
	else		
		return (tmp + 1) / rf;
}
