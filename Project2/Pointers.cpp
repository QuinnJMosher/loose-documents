#include <iostream>

using namespace std;

void main() {
	int arr = 0;
	int *arrPos = &arr;

	int arr_length = -1;
	int *arr_end = arrPos;

	/*for (int *p = arrPos; p < arr_end; p++) {
		*p = 0;
	}*/

	cout << "Enter numbers (enter \"-1\" to end) \n";

	for (int *p = arrPos; *(p - 1) != -1; p++) {
		cin >> *p;
		arr_length++;
	}

	arr_end += arr_length;

	/*const int array1_length = arr_length;
	int array1[array1_length];
	int i = array1_length - 1;

	for (int *p = arr_end - 1; p > arrPos - 1; p--) {
		array1[i] = *p;
		i--;
	}*/

	for (int *p = arr_end - 1; p > arrPos - 1; p--) {
		cout << *p << " ";
	}
	cout << endl;

	system("pause");
}