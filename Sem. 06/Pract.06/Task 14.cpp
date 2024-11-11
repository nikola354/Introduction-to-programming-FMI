// Task 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void uniteArrays(const int arr1[], int arr1Length, const int arr2[], int arr2Length, int result[]) {

	int i = 0, j = 0, r = 0;;

	while (i < arr1Length && j < arr2Length) {
		if (arr1[i] < arr2[j]) {
			result[r] = arr1[i];
			i++;
		}
		else if (arr1[i] > arr2[j]) {
			result[r] = arr2[j];
			j++;
		}
		else {
			result[r] = arr1[i];
			i++;
			j++;
		}

		r++;
	}

	while (i < arr1Length) {
		result[r] = arr1[i];
		i++;
		r++;
	}

	while (j < arr2Length) {
		result[r] = arr2[j];
		j++;
		r++;
	}


}

void print(const int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr1[] = { 1,5,7,8 };
	int arr2[] = { 2,3,9 };
	int result[7];
	uniteArrays(arr1, 4, arr2, 3, result);

	print(result, 7);
}

