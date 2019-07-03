#include<iostream>
using namespace std;

void Magic(const int n);

int main(void)
{
	int Mnum;

	cin >> Mnum;

	Magic(Mnum);

	return 0;
}

void Magic(const int n)
{
	const int MaxSize = 100;
	int square[MaxSize][MaxSize], k, l;

	if ((n > MaxSize) || (n < 1)) {// n이 예외의 값을 가질 경우
		cout << "Error! ... n out of range.\n";
		exit(1);
	}
	else if (n % 2 == 0) {// n이 짝수일 경우
		cout << "Error! ... n is even.\n";
		exit(1);
	}

	for (int x = 0; x < n; x++) {// n*n행렬의 값을 초기화
		for (int y = 0; y < n; y++) {
			square[x][y] = 0;
		}
	}

	int key = 2, i = 0, j = n / 2; // 초기값 지정

	square[i][j] = 1;

	while (key <= n * n) {
		if (i - 1 < 0)
			k = n - 1;
		else
			k = i - 1;
		if (j - 1 < 0)
			l = n - 1;
		else
			l = j - 1;
		if (square[k][l])
			i = (i + 1) % n;
		else {
			i = k;
			j = l;
		}

		square[i][j] = key; key++;
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cout << square[x][y];
			if (square[x][y] / 10 == 0)
				cout << "  ";
			else
				cout << " ";
		}
		cout << endl;
	}
}
