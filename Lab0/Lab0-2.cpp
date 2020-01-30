// Find Min and Max numbers
#include <iostream>

using namespace std;

int findMin(int* list,int &pos,int count);
int findMax(int* list,int &pos,int count);

int main()
{
	int data[] = { 90,40,60,10,50,80,20,70 };
	int min, max, minPos, maxPos;
	min = findMin(data,minPos,sizeof(data)/sizeof(int));
	max = findMax(data,maxPos,sizeof(data)/sizeof(int));

	cout << "Minimum number is " << min << " at position " << minPos << "," << endl;
	cout << "Maximum number is " << max << " at position " << maxPos << endl;

	return 0;
}

int findMin(int* list,int &pos,int count)
{
	int min = list[0];

	for (int i = 0; i < count; i++)
	{
		if (list[i] < min)
		{
			min = list[i];
			pos = i + 1;
		}
	}
	return min;
}

int findMax(int* list,int &pos,int count)
{
	int max = 0;

	for (int i = 0; i < count; i++)
	{
		if (list[i] > max)
		{
			max = list[i];
			pos = i + 1;
		}
	}
	
	return max;
}