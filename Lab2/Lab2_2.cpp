#include <iostream>

using namespace std;
#define MAX_TERMS 100
void add(int starta, int finisha, int stratb, int finishb, int startd, int finishd);
void sub(int starta, int finisha, int startb, int finishb, int startd, int finishd);
int compare(int a, int b);
void attach(int coefficient, int expon);
int startd, finishd;

typedef struct Polynomial {
	float coef;
	int expon;
};
Polynomial terms[MAX_TERMS];

int main() {
	int coef = 0, expon = 0;

	int starta = 0, finisha = 0;
	cout << "A(X) : ";
	do {
		cin >> coef >> expon;
		terms[finisha].coef = coef;
		terms[finisha++].expon = expon;
	} while (expon != 0);
	finisha--;
	int startb = finisha + 1;
	int finishb = startb;
	cout << "B(X) : ";
	do {
		cin >> coef >> expon;
		terms[finishb].coef = coef;
		terms[finishb++].expon = expon;
	} while (expon != 0);
	finishb--;
	startd = finishb + 1;
	finishd = startd;
	
	add(starta, finisha, startb, finishb, startd, finishd);
	cout << "C(X) :";
	for (; startd < finishd; startd++) {
		if (terms[startd].coef == 0) continue;
		cout << terms[startd].coef << " " << terms[startd].expon << " ";
	}

	return 0;
}
void add(int starta, int finisha, int startb, int finishb, int startd, int finishd)
{
	float coefficient;
	while (starta <= finisha && startb <= finishb) {
		switch (compare(terms[starta].expon, terms[startb].expon)) {
		case -1:
			attach(terms[startb].coef, terms[startb].expon);
			startb++; break;
		case 0:
			coefficient = terms[starta].coef + terms[startb].coef;
			attach(coefficient, terms[starta].expon);
			starta++; startb++; break;
		case 1:
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
		}
	}
}
void attach(int coefficient, int exponent)
{
	if (finishd >= MAX_TERMS) {
		cout << "다항식에 항이 너무 많습니다";
		exit(1);
	}
	terms[finishd].coef = coefficient;
	terms[finishd++].expon = exponent;
}
int compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}