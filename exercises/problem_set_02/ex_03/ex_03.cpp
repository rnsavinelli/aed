/* ex_02.cpp
 *
 * Copyright (c) 2020 Savinelli Roberto Nicolás <rsavinelli@est.frba.utn.edu.ar>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include "ex_03.hpp"

bool is_leap(int year)
{
	if (((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0) {
		return true;
	}

	else return false;
}

/* prompts user for the date field by field */
void date_get(date_t *date)
{
	int n_days {0};

	do {
		cout << "Enter the YEAR: ";
		cin  >> date->year;
	} while(date->year < 0);

	do {
		cout << "Enter the MONTH (1, 12): ";
		cin  >> date->month;
	} while(date->month > DECEMBER || date->month < JANUARY );

	switch (date->month) {
	case FEBRUARY:
		is_leap(date->year) ? n_days = 29 : n_days = 28;
		break;

	case APRIL:
	case JUNE:
	case SEPTEMBER:
	case NOVEMBER:
		n_days = 30;
		break;

	default:
		n_days = 31;
		break;
	}

	do {
		cout << "Enter the DAY (1, " << n_days << "): ";
		cin  >> date->day;
	} while((date->day > n_days) || (date->day < 1));
}

date_t date_copy(date_t date)
{
	date_t date_new {0, 0, 0};

	date_new.year = date.year;
	date_new.month = date.month;
	date_new.day = date.day;

	return date_new;
}

/* returns DD/MM/YYYY */
string date_format_alt(date_t date)
{
	string output_date;
	output_date.clear();

	if (date.day < 10) {
		output_date += "0";
	}
	output_date += to_string(date.day);

	output_date += "/";

	if(date.month < 10) {
		output_date += "0";
	}
	output_date += to_string(date.month);

	output_date += "/";

	if (abs(date.year) < 10) {
		output_date += "000";
	}

	else if (abs(date.year) < 100) {
		output_date += "00";
	}

	else if (abs(date.year) < 1000) {
		output_date += "0";
	}

	output_date += to_string(date.year);

	return output_date;
}

/* returns YYYYMMDD */
int date_format(date_t date)
{
	int yyyymmdd {0};

	if ((date.day % 10) != 0) {
		yyyymmdd += date.day;
	} else {
		yyyymmdd += date.day*10;
	}

	if ((date.month % 1000) != 0) {
		yyyymmdd += date.month*100;
	} else {
		yyyymmdd += date.month*1000;
	}

	yyyymmdd += date.year*10000;

	return yyyymmdd;
}
