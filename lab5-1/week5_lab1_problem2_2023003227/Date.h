#ifndef DATE_H
#define DATE_H

class Date {
	private:
		int year;
		int month;
		int day;
	public:
		Date();
		Date(int year, int month, int day);

		int getYear() const;
		int getMonth() const;
		int getDay() const;

		int compare(const Date& other) const;
};

#endif
