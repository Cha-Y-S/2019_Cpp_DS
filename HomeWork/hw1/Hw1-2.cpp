/******************************************************************************************************************
* Name : ������
* Student Id : 20163162
* Program ID : Hw#1-2
* Description : ������ �̸��� ���� ���� �Ǵ� �������� �����ͷ� ������ ������ �Է¹޾� �� ������ ���̸� ���ϴ� ���α׷�
* Algorithm : srcName �Լ��� ���� circle�� ��� 1, triangle�� ��� 0, rectangle�� ��� -1�� ��ȯ�ϰ� �ϰ�
*			  ������ ��쿡 ���� ���� ���� �Ǵ� �������� ����ü �� ������ ������ �Ŀ�
*			  �̸� ���� area�� ����
* Variables :
* srcName - ������ name �˻��ϴ� �Լ�
* name - ������ �̸�	aSide - ���� ����
* bSide - ���� ����	area - ����
* radius - ���� ������	figure - ����ü �̸�
* MAX_FIG - ����ü �迭�� ũ��(���⼱ hw1-2.txt ���� �� ������ ������ŭ ������)
* figure - ����ü �̸�
******************************************************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#define MAX_FIG 7

using namespace std;

typedef struct {		// ����ü �� ������ �ʱ�ȭ
	char name[10] = {};
	double aSide = 0;
	double bSide = 0;
	double area = 0;
	double radius = 0;
}figure;

int srcName(char *name);

int main() {

	figure fig[MAX_FIG];	// ����ü �迭 ����

	ifstream infile;
	infile.open("hw1-2.txt", ios::in);

	if (infile.fail()) {	// ������ �ҷ��� �� ���� �� �Ʒ� �޼��� ���
		cout << "can't open the input file" << endl;
		exit(1);
	}

	cout << fixed;
	cout.precision(2);					// ��� ��� �� �Ҽ��� ��°�ڸ����� ����ϵ��� ����.

	while (!infile.eof()) {				// while���� �����Ͱ� ���������� �ݺ�
		for (int i = 0; i < MAX_FIG; i++) {
			infile >> fig[i].name;
			switch (srcName(fig[i].name)) {
			case 1:			// name == circle �� ��
				infile >> fig[i].radius;
				fig[i].area = (fig[i].radius*fig[i].radius)*3.14;	// ���� ���� = ������*������*3.14
				break;
			case 0:			// name == triangle �� ��
				infile >> fig[i].aSide >> fig[i].bSide;
				fig[i].area = (fig[i].aSide*fig[i].bSide) / 2;		// �ﰢ���� ���� = �غ�*����/2
				break;
			case -1:		// name == rectangle �� ��
				infile >> fig[i].aSide >> fig[i].bSide;
				fig[i].area = fig[i].aSide*fig[i].bSide;			// �簢���� ���� = ��1*��2
				break;
			}
		}
	}

	infile.close();

	for (int i = 0; i < MAX_FIG; i++) {
		if (!strcmp(fig[i].name, "circle")) {
			cout << fig[i].name << " " << fig[i].radius << "\t\t" << fig[i].area << endl;
		}
		else {
			cout << fig[i].name << " " << fig[i].aSide << " " << fig[i].bSide << "\t" << fig[i].area << endl;
		}
	}

}
/*********************************************************************************
* function : srcName
* description : srcName�� �������� �Ű������� ���� char�� �迭�� �̸��� �˻��ϴ� ��
				name = circle -> 1 return
				name = triangle -> 0 return
				name = rectangle -> -1 return
				main �Լ� ������ �� ��ȯ�� �� ���� area ����
***********************************************************************************/
int srcName(char *name) {
	if (!strcmp(name,"circle")) return 1;
	else if (!strcmp(name, "triangle")) return 0;
	else return -1;
}