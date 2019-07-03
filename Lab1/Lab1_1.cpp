#include <iostream>

using namespace std;

int binarySearch1(int *arr, int num,int left, int right) {

	while (left <= right) {
		int mid = (left + right) / 2;

		if (num < arr[mid])
			right = mid - 1;
		else if (num > arr[mid])
			left = mid + 1;
		else if (num == arr[mid])
			return mid;
	}

	return -1;
}

int binarySearch2(int *arr, int num, int left, int right) {
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (num < arr[mid])
			return binarySearch2(arr, num, left, mid - 1);
		else if (num > arr[mid])
			return binarySearch2(arr, num, mid + 1, right);
		else if (num == arr[mid])
			return mid;
	}

	return -1;
}

int main() {

	int list[] = { 10,20,30,40,50,60,70,80,90,100 };
	int searchNum, methodNum, found;

	cout << "Enter an integer to search: ";
	cin >> searchNum;
	cout << "Enter method of search:(1.Binary Search	2.Recursive binary search):";
	cin >> methodNum;

	if (methodNum == 1) {
		found = binarySearch1(list, searchNum, 0, 9);
	}
	else {
		found = binarySearch2(list, searchNum, 0, 9);
	}

	if (found == -1) {
		cout << searchNum << " is NOT FOUND" << endl;
	}
	else
		cout << searchNum << " is at position " << found << "." << endl;
	return 0;

}
