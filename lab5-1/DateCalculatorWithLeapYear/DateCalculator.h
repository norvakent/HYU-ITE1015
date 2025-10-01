#ifndef DATE_CALCULATOR_H
#define DATE_CALCULATOR_H

#include "Date.h"

class DateCalculator {
	public:
		static const int MIN_YEAR = 1601;
		static const int MAX_YEAR = 9999;

		bool isLeap(int y) const;
		int daysInMonth(int y, int m) const;
		bool isValid(const Date& d) const;

		Date fromSerial(int days) const;
		int toSerial(const Date& date) const;

		Date addDays(const Date& date, int k) const;
		int diffDays(const Date& date1, const Date& date2) const;
		int dayOfWeek(const Date& date) const;
		bool nthWeekdayInMonth(int y, int m, int weekday, int n, Date& out) const;
};

#endif
