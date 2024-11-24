#include <iostream>

bool isLeapYear(unsigned year);
unsigned getDaysInMonth(unsigned month, unsigned year);
bool isDateValid(unsigned day, unsigned month, unsigned year);
void goToNextDay(unsigned int& day, unsigned int& month, unsigned int& year);
void printDateAfterNDays(unsigned day, unsigned month, unsigned year, unsigned daysToAdd);

int main() {
	std::cout << "Enter date in format dd//mm//yyyy and then days, which will be added to it: ";

	unsigned day, month, year, n;
	std::cin >> day >> month >> year >> n;

	std::cout << std::endl;

	printDateAfterNDays(day, month, year, n);

	return 0;
}

bool isLeapYear(unsigned year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned getDaysInMonth(unsigned month, unsigned year) {
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}

	return 31;
}

bool isDateValid(unsigned day, unsigned month, unsigned year) {
	if (month < 1 || month > 12 || year == 0) return false;
	return day >= 1 && day <= getDaysInMonth(month, year);
}

void goToNextDay(unsigned int& day, unsigned int& month, unsigned int& year)
{
	if (!isDateValid(day, month, year)) return;

	day++;

	if (day > getDaysInMonth(month, year))
	{
		day = 1;

		(month == 12) ? month = 1 : month++;

		if (month == 1) year++;
	}
}

void printDateAfterNDays(unsigned day, unsigned month, unsigned year, unsigned daysToAdd) {
	if (!isDateValid(day, month, year)) {
		std::cout << "This date is invalid!";
		return;
	}

	int copyNDays = daysToAdd;

	while (copyNDays != 0)
	{
		goToNextDay(day, month, year);
		copyNDays--;
	}

	std::cout << "Date after " << daysToAdd << " days: "
		<< day << "/" << month << "/" << year << std::endl;
}
