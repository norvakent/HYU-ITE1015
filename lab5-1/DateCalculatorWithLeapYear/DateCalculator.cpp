#include "DateCalculator.h"

static const int cumMonth[13] = {
	0,
	0,
	31,
	59,
	90,
	120,
	151,
	181,
	212,
	243,
	273,
	304,
	334
};

bool DateCalculator::isLeap(int y) const {
	if (y % 400 == 0) {
		if (y % 100 == 0) return false;
		return true;
	}
	if (y % 4 == 0) return true;
	return false;
}

int DateCalculator::daysInMonth(int y, int m) const {
	static const int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (m < 1 || m > 12) return 0;

	if (isLeap(y) && m == 2) return 29;

	return md[m];
}

bool DateCalculator::isValid(const Date& d) const {
	int year = d.getYear();
	int month = d.getMonth();
	int day = d.getDay();

	if (year < DateCalculator::MIN_YEAR || year > DateCalculator::MAX_YEAR) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	if (day < 1 || day > daysInMonth(year, month)) {
		return false;
	}
	return true;
}

int DateCalculator::toSerial(const Date& date) const {
	int y = date.getYear();
	int m = date.getMonth();
	int d = date.getDay();

	int y1 = (y - 1) - 1600;

	int daysYears = y1 * 365;
	for (int i = 1601; i < y; i++) {
		if (isLeap(i)) daysYears++;
	}
	
	int daysMonths = cumMonth[m] + ((isLeap(y) && m > 2) ? 1 : 0);
	
	return daysYears + daysMonths + d;
}

Date DateCalculator::fromSerial(int days) const {
	if (days < 0) return Date(0, 0, 0);

	const int D400 = 146097;
	const int D100 = 36524;
	const int D4 = 1461;
	const int D1 = 365;

	int cycles400 = days / D400;
	int remaining = days % D400;

	int cycles100 = remaining / D100;
	if (cycles100 == 4) cycles100 = 3;
	remaining -= cycles100 * D100;
	
	int cycles4 = remaining / D4;
	remaining -= cycles4 * D4;

	int singleYears = remaining / D1;
	if (singleYears == 4) singleYears = 3;
	remaining -= singleYears * D1;

	int year = 400 * cycles400 + 100 * cycles100 + 4 * cycles4 + singleYears;

	int month = 1;
	while (true) {
		int daysInThisMonth = daysInMonth(year, month);

		if (remaining < daysInThisMonth) break;
		remaining -= daysInThisMonth;
		month++;
	}

	int day = remaining + 1;

	return Date(year, month, day);
}

Date DateCalculator::addDays(const Date& date, int k) const {
	int days = toSerial(date);
	return fromSerial(days + k);
}

int DateCalculator::dayOfWeek(const Date& date) const {
	int days = toSerial(date);

	int iso = days % 7 + 1;

	return iso;
}

int DateCalculator::diffDays(const Date& date1, const Date& date2) const {
	return toSerial(date2) - toSerial(date1);
}

bool DateCalculator::nthWeekdayInMonth(int y, int m, int weekday, int n, Date& out) const {
	if (y < DateCalculator::MIN_YEAR || y > DateCalculator::MAX_YEAR) {
		return false;
	}
	if (m < 1 || m > 12) {
		return false;
	}
	if (weekday < 1 || weekday > 7) {
		return false;
	}
	if (n < 1 || n > 5) {
		return false;
	}

	int dim = daysInMonth(y, m);
	Date first(y, m, 1);
	if (isValid(first)) return false;

	int firstDow = dayOfWeek(first);

	int delta = weekday - firstDow;

	int firstOccur = 1 + delta + (delta < 0) ? 7 : 0;

	int target = firstOccur + 7 * (n - 1);

	if (target > daysInMonth(y, m)) return false;

	out = Date(y, m, target);
	return true;
}
