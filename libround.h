/*
 * libround.h - Rounding algorithms API
 *
 * Copyright (C) 2010,2012	Andrew Clayton <andrew@digital-domain.net>
 * Inspired by rounding-algorithms.hpp in the Boost C++ library.
 * Released under the GNU Lesser General Public License (LGPL) version 2.1
 * See COPYING
 */

#ifndef _LIBROUND_H_
#define _LIBROUND_H_

double lr_get_rounding_factor(int dp);
double lr_ceil0(double value, double rf);
double lr_floor0(double value, double rf);
double lr_round_half_up(double value, double rf);
double lr_round_half_up0(double value, double rf);
double lr_round_half_down(double value, double rf);
double lr_round_half_down0(double value, double rf);
double lr_round_half_even(double value, double rf);

#endif /* _LIBROUND_H_ */
