// Polynomial Expression

#include <iostream>
#include <fstream>
#define MAX_TERMS 100

using namespace std;

void add(int sa, int fa, int sb, int fb, int &sd, int &fd);
int compare(int x, int y);
void attach(float coef, int expon);

struct poly
{
	float coef;
	int expon;
};

poly terms[MAX_TERMS];
int avail = 0;

int main()
{
	ifstream input;
	input.open("lab2-2.dat", ios::in);
	
	int i = 0;
	char j;
	int startA = 0;
	int finishA, startB, finishB;
	int startD, finishD;

	while (!input.eof())
	{
		input >> terms[i].coef >> terms[i].expon;
		avail++;
		i++;
		input.get(j);
		if (j == '\n')
		{
			finishA = i - 1;
			startB = i;
		}
	}
	finishB = i - 1;

	add(startA, finishA, startB, finishB, startD, finishD);

	for (; startD <= finishD; startD++)
	{
		cout << terms[startD].coef << " " << terms[startD].expon << " ";
	}
	cout << endl;
}

void add(int sa, int fa, int sb, int fb, int &sd, int &fd)
{
	float coefficient;
	sd = avail;

	while (sa <= fa && sb <= fb)
	{
		switch (compare(terms[sa].expon, terms[sb].expon))
		{
		case -1:
			attach(terms[sb].coef, terms[sb].expon);
			sb++;
			break;
		case 0:
			coefficient = terms[sa].coef + terms[sb].coef;
			if (coefficient)
			{
				attach(coefficient, terms[sa].expon);
				sa++; sb++;
				break;
			}
			sa++; sb++;
			break;
		case 1:
			attach(terms[sa].coef, terms[sa].expon);
			sa++;
		}
	}
	for (; sa <= fa; sa++)
		attach(terms[sa].coef, terms[sa].expon);
	for (; sb <= fb; sb++)
		attach(terms[sb].coef, terms[sb].expon);
	fd = avail - 1;
}

int compare(int x, int y)
{
	if (x > y)
		return 1;
	else if (x == y)
		return 0;
	else
		return -1;
}

void attach(float coef, int expon)
{
	if (avail >= MAX_TERMS)
	{
		cout << "too many elements" << endl;
		return;
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}