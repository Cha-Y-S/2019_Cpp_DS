/******************************************************************************************************************
* Name : 차윤성
* Student Id : 20163162
* Program ID : Hw#1-2
* Description : 도형의 이름과 변의 길이 또는 반지름을 데이터로 가지는 파일을 입력받아 각 도형의 넓이를 구하는 프로그램
* Algorithm : srcName 함수를 통해 circle일 경우 1, triangle일 경우 0, rectangle일 경우 -1을 반환하게 하고
*			  각각의 경우에 대해 변의 길이 또는 반지름을 구조체 내 변수에 대입한 후에
*			  이를 토대로 area를 구함
* Variables :
* srcName - 데이터 name 검사하는 함수
* name - 도형의 이름	aSide - 변의 길이
* bSide - 변의 길이	area - 면적
* radius - 원의 반지름	figure - 구조체 이름
* MAX_FIG - 구조체 배열의 크기(여기선 hw1-2.txt 파일 내 데이터 개수만큼 지정함)
* figure - 구조체 이름
******************************************************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#define MAX_FIG 7

using namespace std;

typedef struct {		// 구조체 내 변수들 초기화
	char name[10] = {};
	double aSide = 0;
	double bSide = 0;
	double area = 0;
	double radius = 0;
}figure;

int srcName(char *name);

int main() {

	figure fig[MAX_FIG];	// 구조체 배열 선언

	ifstream infile;
	infile.open("hw1-2.txt", ios::in);

	if (infile.fail()) {	// 파일을 불러올 수 없을 때 아래 메세지 출력
		cout << "can't open the input file" << endl;
		exit(1);
	}

	cout << fixed;
	cout.precision(2);					// 결과 출력 시 소수점 둘째자리까지 출력하도록 설정.

	while (!infile.eof()) {				// while문은 데이터가 끝날때까지 반복
		for (int i = 0; i < MAX_FIG; i++) {
			infile >> fig[i].name;
			switch (srcName(fig[i].name)) {
			case 1:			// name == circle 일 때
				infile >> fig[i].radius;
				fig[i].area = (fig[i].radius*fig[i].radius)*3.14;	// 원의 넓이 = 반지름*반지름*3.14
				break;
			case 0:			// name == triangle 일 때
				infile >> fig[i].aSide >> fig[i].bSide;
				fig[i].area = (fig[i].aSide*fig[i].bSide) / 2;		// 삼각형의 넓이 = 밑변*높이/2
				break;
			case -1:		// name == rectangle 일 때
				infile >> fig[i].aSide >> fig[i].bSide;
				fig[i].area = fig[i].aSide*fig[i].bSide;			// 사각형의 넓이 = 변1*변2
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
* description : srcName의 사용목적은 매개변수로 들어온 char형 배열의 이름을 검사하는 것
				name = circle -> 1 return
				name = triangle -> 0 return
				name = rectangle -> -1 return
				main 함수 내에서 각 반환된 값 별로 area 산출
***********************************************************************************/
int srcName(char *name) {
	if (!strcmp(name,"circle")) return 1;
	else if (!strcmp(name, "triangle")) return 0;
	else return -1;
}