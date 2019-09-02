/******************************************************************************************************************
* Name : ������
* Student Id : 20163162
* Program ID : Hw#1-1
* Description : ���Ϸκ��� �������� �Է¹޾� ��ġ����� ����� ����ϴ� ���α׷�
* Algorithm :	���� ���Ϸκ��� �Է¹��� �����͸� ����ü �迭 �� �ε������� row,col,value�� ������ �Ŀ�
*				�Է¹��� �������� fast_transpose algorithm�� �̿��Ͽ� ��ġ��ķ� ��ȯ��Ų��.
* Variables :	row - �� ����ü�� ��				col - �� ����ü�� ��
*				value - �� ����ü�� ���� ����		row_term - �� ���� ������ ���� ������ �����ϴ� �迭 ex) 0�� 2��, 1�� 2��...
*				num_col - ���� �� ����			starting_pos - �� ���� ������ ���� ���� ��ġ�� �������ִ� �迭 ex) 0�� index 1����, 1�� index 3����...		
*				num_terms - 0�� �ƴ� ������ ����	inArr - ���Ϸκ��� �Է¹��� �������� �����ϴ� ����ü �迭 ����
*				outArr - �������� ��ġ��Ų ����� �����ϴ� ����ü �迭 ����
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
		exit(1);		// ������ ���� ������ �޼��� ���
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
* description : fast_transpose�� �������� �Ű����� a[]�� ��� ����
				�Ű����� b[]�� ���� ������ ��ġ��Ű�� ���̴�.
				row_term - �� �ε������� �Ű����� a ���� ������ ���� ex) Index 0 : 0�� 1��,Index 1 : 1�� 2��...
				starting_pos - �� �ε������� a ���� ���۵Ǵ� ��ġ�� �����ϴ� �迭 ex) Index 0 = 1 : �Ű��������� 0���� ������ġ�� Index 1����
				ù��° for�� - row_term�� 0���� �ʱ�ȭ ��Ŵ
				�ι�° for�� - a ���� ������ row_term �� �ε����� ����� ����
					a[].col = 0 : Index 0�� +1		a[].col = 1 : Index 1�� +1		a[].col = 2 : Index 2�� +1
					a[].col = 3 : Index 3�� +1		a[].col = 5 : Index 5�� +1
				����° for�� - startin_pos�� �� a[].col ���� ������ġ�� ����
					starting_pos[0] = row_term[0](a[].col = 0 �� ����)		
					starting_pos[1] = row_term[1](a[].col = 1 �� ����) + starting_pos[0](�������� ������ Index)
					starting_pos[2] = row_term[2](a[].col = 2 �� ����) + starting_pos[1](�������� ������ Index)
					...
				�׹�° for�� - �Ű����� b�� ���� ��ġ�� b[starting_pos[]]�� ���ϰ� a[].col,a[].row,a[].value ���� ���� ����
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