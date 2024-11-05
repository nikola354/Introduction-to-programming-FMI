// TASK_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main() {

	int d, m, y;
	std::cin >> d >> m >> y;

	pak:
	if (d > 31) { std::cout << "Invalid day" << std::endl << "Try again" << std::endl; std::cin >> d >> m >> y; }
	
	switch (m) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		if (++d > 31) {
			d -= 31;
			++m;
		}
		if (m > 12) {
			m -= 12;
			++y;
		}

		std::cout << d << "\\" << m << "\\" << y;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (++d > 30) {
			d -= 30;
			++m;
		}
		
		std::cout << d << "\\" << m << "\\" << y;
		break;
	case 2:
		if ((y%4==0 && y%100 != 0) || y%400==0) {
			if (++d > 29) {
				d -= 29;
				++m;
			}
		}
		else if (++d > 28) {
			d -= 28;
			++m;
		}
		
		std::cout << d << "\\" << m << "\\" << y;
		break;

	default:  // 16
		std::cout << "Invalid month!  >:(" << std::endl << "Try again below:  :)" << std::endl << std::endl; std::cin >> d >> m >> y;
		goto pak;
	}
}
