#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int data[] = { 90,40,60,10,50,80,20,70 };

	int min = data[0];
	int max = 0;

	int posMin = 0;
	int posMax = 0;

	for (int i = 0; i < 8; i++) {
		if (data[i] < min) {
			min = data[i];
			posMin = i+1;
		}
	}

	cout << "Minimum number is " << min << " at position " << posMin << endl;

	for (int i = 0; i < 8; i++) {
		if (data[i] > max) {
			max = data[i];
			posMax = i+1;
		}
	}

	cout << "Maximum number is " << max << " at position " << posMax << endl;

	//printf("Minimum number is %d at position %d\n", min, posMin);
	
	//printf("Maximium number is %d at position %d\n", max, posMax);


	return 0;
}