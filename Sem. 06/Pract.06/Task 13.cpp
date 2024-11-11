// Task 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void uniteArrays(const int arr1[], int arr1Length,const int arr2[], int arr2Length, int result[]) {

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

int interactArrays(const int arr1[], int arr1Length, const int arr2[], int arr2Length, int result[]) {

	int r = 0;

	for (int i = 0; i < arr1Length; i++) {
		int currentItem = arr1[i];

		for (int j = 0; j < arr2Length; j++) {
			if (currentItem == arr2[j]) {
				result[r] = currentItem;
				r++;
			}
		}
	}

	return r;

}


void print(const int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main()
{
	const int ARR1_LENGTH = 5;
	const int ARR2_LENGTH = 4;
	int arr1[] = { 2,4,1,7,8 };
	int arr2[] = { 1,2,3,5 };
	const int RESULT_LENGHT = ARR1_LENGTH + ARR2_LENGTH;
	int result[RESULT_LENGHT];

	int length = interactArrays(arr1, ARR1_LENGTH, arr2, ARR2_LENGTH, result);

	print(result, length);

}

