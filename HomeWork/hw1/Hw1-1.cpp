/******************************************************************************************************************
* Name : 차윤성
* Student Id : 20163162
* Program ID : Hw#1-1
* Description : 파일로부터 희소행렬을 입력받아 전치행렬을 만들고 출력하는 프로그램
* Algorithm :	먼저 파일로부터 입력받은 데이터를 구조체 배열 각 인덱스별로 row,col,value에 저장한 후에
*				입력받은 희소행렬을 fast_transpose algorithm을 이용하여 전치행렬로 변환시킨다.
* Variables :	row - 각 구조체의 행				col - 각 구조체의 열
*				value - 각 구조체의 값의 개수		row_term - 각 행의 데이터 값별 개수를 저장하는 배열 ex) 0행 2개, 1행 2개...
*				num_col - 열의 총 개수			starting_pos - 각 행의 데이터 값별 시작 위치를 저장해주는 배열 ex) 0행 index 1부터, 1행 index 3부터...		
*				num_terms - 0이 아닌 데이터 개수	inArr - 파일로부터 입력받은 희소행렬을 저장하는 구조체 배열 변수
*				outArr - 희소행렬을 전치시킨 행렬을 저장하는 구조체 배열 변수
******************************************************************************************************************/
#include <iostream>
#include <fstream>
#define MAX_COL 10
using namespace std;

typedef struct {
	int row;
	int col;
	int value;
}term;

void fast_transpose(term a[], term b[]);

int main() {
	
	term inArr[MAX_COL];
	term outArr[MAX_COL];

	ifstream infile;
	infile.open("hw1-1.txt", ios::in);

	if (infile.fail()) {
		cout << "can't open the input file" << endl;
		exit(1);		// 파일을 열수 없을때 메세지 출력
	}

	for (int i = 0; i < 9; i++) {
		infile >> inArr[i].row >> inArr[i].col >> inArr[i].value;
	}

	infile.close();

	cout << "====== Sparse Matrix ======" << endl;
	cout << "row" << "\t" << "col" << "\t" << "value" << endl;
	
	for (int i = 0; i < 9; i++) {
		cout << inArr[i].row << "\t" << inArr[i].col << "\t" << inArr[i].value << endl;
	}

	fast_transpose(inArr, outArr);

	cout << endl;

	cout << "====== Transpose Matrix ======" << endl;
	cout << "col" << "\t" << "row" << "\t" << "value" << endl;
	
	for (int i = 0; i < 9; i++) {
		cout << outArr[i].row << "\t" << outArr[i].col << "\t" << outArr[i].value << endl;
	}
}

/*********************************************************************************
* function : fast_transpose
* description : fast_transpose의 사용목적은 매개변수 a[]의 행과 열을
				매개변수 b[]의 열과 행으로 전치시키는 것이다.
				row_term - 각 인덱스별로 매개변수 a 열의 갯수를 저장 ex) Index 0 : 0열 1개,Index 1 : 1열 2개...
				starting_pos - 각 인덱스별로 a 열이 시작되는 위치를 저장하는 배열 ex) Index 0 = 1 : 매개변수에서 0열의 시작위치는 Index 1부터
				첫번째 for문 - row_term을 0으로 초기화 시킴
				두번째 for문 - a 열의 갯수를 row_term 각 인덱스에 몇개인지 저장
					a[].col = 0 : Index 0값 +1		a[].col = 1 : Index 1값 +1		a[].col = 2 : Index 2값 +1
					a[].col = 3 : Index 3값 +1		a[].col = 5 : Index 5값 +1
				세번째 for문 - startin_pos에 각 a[].col 값의 시작위치를 저장
					starting_pos[0] = row_term[0](a[].col = 0 의 갯수)		
					starting_pos[1] = row_term[1](a[].col = 1 의 갯수) + starting_pos[0](이전까지 차지한 Index)
					starting_pos[2] = row_term[2](a[].col = 2 의 갯수) + starting_pos[1](이전까지 차지한 Index)
					...
				네번째 for문 - 매개변수 b에 시작 위치를 b[starting_pos[]]로 정하고 a[].col,a[].row,a[].value 값을 각각 저장
					b[starting_pos[0]( = 2 )].row = a[1].col	b[starting_pos[0]( = 2 )].col = a[1].row	b[starting_pos[0]( = 2 )].value = a[1].value
***********************************************************************************/
void fast_transpose(term a[], term b[]) {
	int row_term[MAX_COL], starting_pos[MAX_COL];
	int j, num_col = a[0].col, num_terms = a[0].value;

	b[0].row = num_col;
	b[0].col = a[0].row;
	b[0].value = num_terms;

	if (num_terms > 0) {
		for (int i = 0; i < num_col; i++) row_term[i] = 0;
		for (int i = 1; i <= num_terms; i++) row_term[a[i].col]++;

		starting_pos[0] = 1;
		for (int i = 1; i < num_col; i++) starting_pos[i] = starting_pos[i - 1] + row_term[i - 1];

		for (int i = 1; i <= num_terms; i++) {
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col; b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}