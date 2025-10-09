#include "Date.h"

Date::Date() : year(1601), month(1), day(1) {}

Date::Date(int year, int month, int day)
	: year(year), month(month), day(day) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

int Date::compare(const Date& other) const {
	if (year < other.getYear()) return -1;
	else if (year > other.getYear()) return 1;

	if (month < other.getMonth()) return -1;
	else if (month > other.getMonth()) return 1;

	if (day < other.getDay()) return -1;
	else if (day > other.getDay()) return 1;

	return 0;
}

