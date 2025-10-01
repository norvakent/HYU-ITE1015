#include <iostream>
#include <cstdio>
#include "Date.h"
#include "DateCalculator.h"

using namespace std;

static void showMenu() {
	cout << "\n=== Date Calculation Toolkit ===" << endl;
	cout << "1. Get Days Between" << endl;
	cout << "2. Add Days" << endl;
	cout << "3. Day Of Week" << endl;
	cout << "4. Nth Weekday Of Month" << endl;
	cout << "5. Exit program" << endl;
	cout << "choose option: ";
}

static const char* dowName(int iso) {
	switch (iso) {
		case 1: return "MON";
		case 2: return "TUE";
		case 3: return "WED";
		case 4: return "THU";
		case 5: return "FRI";
		case 6: return "SAT";
		case 7: return "SUN";
		default: return "";
	}
}

int main() {
	DateCalculator calc;
	
	int choice;
	while (true) {
		showMenu();
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}

		switch (choice) {
			case 1: {
				int y1, m1, d1, y2, m2, d2;
				cout << "Enter first date (y m d): ";
				if (!(cin >> y1 >> m1 >> d1)) { cout << "Invalid input." << endl; break; }
				cout << "Enter second date (y m d): ";
				if (!(cin >> y2 >> m2 >> d2)) { cout << "Invalid input." << endl; break; }
				Date a(y1, m1, d1);
				Date b(y2, m2, d2);
				if (!calc.isValid(a) || !calc.isValid(b)) {
					cout << "INVALID" << endl;
					break;
				}
				int diff = calc.diffDays(a, b);
				cout << "DIFF" << diff << endl;
				break;
				}
			case 2: {
				int y, m, d, k;
				cout << "Enter date (y m d) and k: ";
				if (!(cin >> y >> m >> d >> k)) { cout << "Invalid input." << endl; break; }
				Date a(y, m, d);
				if (!calc.isValid(a)) {
					cout << "INVALID" << endl;
					break;
				}
				if (k <= 0) {
					cout << "INVALID" << endl;
					break;
				}
				Date b = calc.addDays(a, k);
				if (!calc.isValid(b)) {
					cout << "INVALID" << endl;
					break;
				}
				char buf[32];
				snprintf(buf, sizeof(buf), "%04d-%02d-%02d", b.getYear(), b.getMonth(), b.getDay());
				cout << "DATE " << buf << endl;
				break;
				}
			case 3: {
				int y, m, d;
				cout << "Enter date (y m d): ";
				if (!(cin >> y >> m >> d)) { cout << "Invalid input." << endl; break; }
				Date a(y, m, d);
				if (!calc.isValid(a)) {
					cout << "INVALID" << endl;
					break;
				}
				int iso = calc.dayOfWeek(a);
				cout << "Day Of Week: " << dowName(iso) << endl;
				break;
				}
			case 4: {
				int y, m, weekday, n;
				cout << "Enter (year month weekday(1=Mon..7=Sun) n): ";
				if (!(cin >> y >> m >> weekday >> n)) { cout << "Invalid input." << endl; break; }
				Date out;
				if (weekday < 1 || weekday > 7) {
					cout << "INVALID" << endl;
					break;
				}
				bool ok = calc.nthWeekdayInMonth(y, m, weekday, n, out);
				if (!ok) {
					if (y < DateCalculator::MIN_YEAR || y > DateCalculator:: MAX_YEAR || m < 1 || m > 12 || n < 1 || n > 5) {
						cout << "INVALID" << endl;
					} else {
						cout << "NONE" << endl;
					}
					break;
				}
				char buf[32];
				snprintf(buf, sizeof(buf), "%04d-%02d-%02d", out.getYear(), out.getMonth(), out.getDay());
				cout << "DATE " << buf << endl;
				break;
				}
			case 5:
				return 0;
			default:
				cout << "Invalid choice. Please select 1-5." << endl;
		}
	}

	return 0;
}
