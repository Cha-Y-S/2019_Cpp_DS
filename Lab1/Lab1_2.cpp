#include <iostream>

using namespace std;

int RecursiveAddition(int x, int y) {

	if (x > 0) RecursiveAddition(x - 1, y + 1);
	else {
		return y;
	}
}

int RecursiveDifference(int x, int y) {

	if (x > 0) RecursiveDifference(x - 1, y - 1);
	else {
		return y;
	}
}

int SumOfANumber(int n) {
	if (n == 1) return 1;
	return n + SumOfANumber(n - 1);
}

int main() {
	int inputNum1, inputNum2,inputNum3;
	int addResult, difResult, sumResult;

	cout << "Enter number 1: ";
	cin >> inputNum1;

	cout << "Enter number 2: ";
	cin >> inputNum2;

	addResult = RecursiveAddition(inputNum1,inputNum2);
	difResult = RecursiveDifference(inputNum1, inputNum2);

	cout << "\tAddition Result is: " << addResult << endl;
	cout << "\tDifference Result: " << difResult << endl;

	cout << "Enter a number: ";
	cin >> inputNum3;
	sumResult = SumOfANumber(inputNum3);
	cout << "\t Result is: " << sumResult << endl;

}
