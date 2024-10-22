//#include <iostream>
//
//int main()
//{
//	int n;
//	std::cin >> n;
//
//	int sidespace = (n - 1) / 2;
//	int rowNum = 2 * n - 1;
//	int columnHeight = n - 2;
//	int rocketStartWidth = n / 2 + 1;
//	//first-row
//	for (int i = 1;i <= rowNum; i++) {
//		if (i <= sidespace || i> rowNum-sidespace) {
//			std::cout << ".";
//		}
//		else {
//			std::cout << "#";
//		}
//	}
//	std::cout << std::endl;
//	//columns
//	for (int a = 0; a < columnHeight; a++) {
//		for (int i = 1;i <= rowNum; i++) {
//			if (i == sidespace + 1 || i == rowNum - sidespace) {
//				std::cout << "#";
//			}
//			else {
//				std::cout << ".";
//			}
//		}
//		std::cout << std::endl;
//	}
//	//rocket-start
//	for (int i = 1;i <= rowNum; i++) {
//		if (i <= rocketStartWidth || i > rowNum - rocketStartWidth) {
//			std::cout << "#";
//		}
//		else {
//			std::cout << ".";
//		}
//	}
//	std::cout << std::endl;
//	//rocket-end
//	for (int a = 1;a < n;a++) {
//		for (int i = 1;i <= rowNum; i++) {
//			if (i == a+1 || i == rowNum - a) {
//				std::cout << "#";
//			}
//			else {
//				std::cout << ".";
//			}
//		}
//		std::cout << std::endl;
//	}
//	
//
//}
//
//
//
