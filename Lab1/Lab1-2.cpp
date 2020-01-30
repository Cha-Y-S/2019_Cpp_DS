#include <iostream>

using namespace std;

int recursiveAdd(int x, int y);
int recursiveDif(int x, int y);
int sumOfANum(int x);

int main()
{
	int x, y, z;
	
	cout << "Enter number 1 : ";
	cin >> x;

	cout << "Enter number 2 : ";
	cin >> y;

	cout << "\tAddition Result is : " << recursiveAdd(x, y) << endl;
	cout << "\tDifference Result is : " << recursiveDif(x, y) << endl;

	cout << "Enter number 3 : ";
	cin >> z;
	
	cout << "\tResult is : ";
	int sum = sumOfANum(z);
	cout << sum << endl;

	return 0;
}

int recursiveAdd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return recursiveAdd(x + 1, y - 1);
}

int recursiveDif(int x, int y)
{
	if (x > y)
	{
		int temp = x;
		x = y;
		y = temp;
	}

	if (x == 0)
		return y;
	else
		return recursiveDif(x - 1, y - 1);
}

int sumOfANum(int x)
{
	int sum = 0;
	if (x == 1)
	{
		cout << x << " = ";
		return 1;
	}
	else
	{
		cout << x << " + ";
		sum += x + sumOfANum(x - 1);
	}
	return sum;
}