// Задача 11: Дата представяме като три числа от тип unsigned. 
// Примерно (4 / 11 / 2022) е валидна дата. Напишете функция, 
// която приема дата, представена като три числа, и намира следващия ден. 
// От вас се очаква да проверите дали датата е валидна.
// Да се напише програма която намира коя ще е датата след n дена.

#include <iostream>

bool isLeapYear(unsigned year);
unsigned getDaysInMonth(unsigned month, unsigned year);
bool isDateValid(unsigned day, unsigned month, unsigned year);
void printDateAfterNDays(unsigned day, unsigned month, unsigned year, unsigned daysToAdd);

int main(){
    std::cout << "Enter date in format dd//mm//yyyy and then days, which will be added to it: ";
    unsigned day, month, year, n;
    std::cin >> day >> month >> year >> n;
    std::cout << "\n";
    printDateAfterNDays(day, month, year, n);
}

bool isLeapYear(unsigned year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned getDaysInMonth(unsigned month, unsigned year) {
	if (month == 2)
		return isLeapYear(year) ? 29 : 28;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;
}

bool isDateValid(unsigned day, unsigned month, unsigned year) {
	if (month < 1 || month > 12 || year == 0) return false;
	return day >= 1 && day <= getDaysInMonth(month, year);
}

void printDateAfterNDays(unsigned day, unsigned month, unsigned year, unsigned daysToAdd) {
	if (!isDateValid(day, month, year)) { 
		std::cout << "This date is invalid!";
		return;
	}

	day += daysToAdd;
	while (day > getDaysInMonth(month, year)) {
		day -= getDaysInMonth(month, year);
		month++;

		if (month > 12) {
			month = 1;
			year++;
		}
	}

	std::cout << "Date after " << daysToAdd << " days: "
		<< day << "/" << month << "/" << year << std::endl;
}