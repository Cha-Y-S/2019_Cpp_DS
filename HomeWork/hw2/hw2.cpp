#include <iostream>
#include <fstream>
#define MAX_SIZE 100 // 최대 크기를 100으로 설정

char bufEval[MAX_SIZE]; // 후위 연산으로 바꾼 수식을 저장하는 배열
// 따로 선정해 준 이유는 후위연산 알고리즘을 통해 결과를 뽑기 위해서
using namespace std;

class ArrStack {
public:
	int top;
	char *stack;
	int max_size;

	ArrStack(int size) {
		top = -1;
		stack = new char(size);
		max_size = size;
	}

	bool isFull();
	bool isEmpty();
	void push(char data);
	char pop();
};

bool ArrStack::isFull() {
	if (top + 1 == max_size) return true; // top+1이 max_size와 같으면 가득 찼다는 의미
	else return false;
}

bool ArrStack::isEmpty() {
	if (top == -1) return true;	// top이 -1이면 stack이 비어있다는 의미
	else return false;
}

void ArrStack::push(char data) {
	if (isFull()) cout << "Stack is Full" << endl;
	else {
		top++;	// top의 크기를 1 늘려준 후
		stack[top] = data;	// 그다음 인덱스에 data 삽입
	}
}

char ArrStack::pop() {
	if (isEmpty()) {	// stack이 비어있는지 검사
		cout << "Stack is empty" << endl;
		return 0;
	}
	else return stack[top--]; // stack[top]에 있는 걸 반환 후 top의 크기를 1 줄임
}

class IntStack {
public:
	int top;
	int* stack;
	int max_size;

	IntStack(int size) {
		top = -1;
		stack = new int[size];
		max_size = size;
	}

	bool isFull();
	bool isEmpty();
	void push(int data);
	int pop();
};
bool IntStack::isFull() {
	if (top + 1 == max_size) return true; // top+1이 max_size와 같으면 가득 찼다는 의미
	else return false;
}

bool IntStack::isEmpty() {
	if (top == -1) return true;	// top이 -1이면 stack이 비어있다는 의미
	else return false;
}

void IntStack::push(int data) {
	if (isFull()) cout << "Stack is Full" << endl;
	else {
		top++;	// top의 크기를 1 늘려준 후
		stack[top] = data;	// 그다음 인덱스에 data 삽입
	}
}

int IntStack::pop() {
	if (isEmpty()) {	// stack이 비어있는지 검사
		cout << "Stack is empty" << endl;
		return 0;
	}
	else return stack[top--]; // stack[top]에 있는 걸 반환 후 top의 크기를 1 줄임
}

int priority(char input);
void infixToPostfix(char *buffer);
int postfixEvaluation(char *buffer);

int main() {
	char buffer[MAX_SIZE];

	ifstream infile("hw2.txt");
	
	while (infile.getline(buffer, MAX_SIZE)) {	// 데이터 파일을 읽어옴
		cout << "1) Echo data\t(infix form)\t: " << buffer << endl;
		cout << "2) Conversion\t(postfix form)\t: ";
		infixToPostfix(buffer);
		cout << endl;
		cout << "3) Result\t\t\t: " << postfixEvaluation(bufEval) << endl;
	}
}

int priority(char input) {
	// 각각의 return값은 각 연산자 별 연산 우선순위를 의미
	if (input == ')') return 4;
	else if (input == '*' || input == '/') return 3;
	else if (input == '+' || input == '-') return 2;
	else if (input == '(') return 1;
	else if (input == ' ') return -1; // 데이터 파일에 공백이 있어서 -1을 반환하게 한 후 무시하도록 함
	else return 0;

}

void infixToPostfix(char *buffer) {
	ArrStack stkCon(MAX_SIZE);
	
	int i = 0, j = 0;
	while (buffer[i] != '\0') {
		switch (priority(buffer[i])) { // 연산 우선순위 별로 실행되도록 함
		case 0: // 숫자일 경우는 stack 에 push
			bufEval[j++] = buffer[i]; // 숫자를 bufEval에 저장
			cout << buffer[i] << " ";
			break;
		case 4: // ')'일 경우 stack의 top에 '('가 나올때까지 pop
			while (stkCon.stack[stkCon.top] != '(') {
				bufEval[j] = stkCon.pop();
				cout << bufEval[j++] << " ";
			}
			break;
		case 3: // 연산자가 *, /일 경우 + -와 처리 방법은 같으므로 case 2 와 똑같이 처리되도록 함
		case 2:
			if (priority(buffer[i]) >= priority(stkCon.stack[stkCon.top])) stkCon.push(buffer[i]);
			else{// 새로 들어온 연산자가 기존 스택에 있는 연산자보다 우선순위가 높으면 push.
				bufEval[j] = stkCon.pop();	// 우선순위가 낮으면 pop
				cout << bufEval[j++] << " ";
				stkCon.push(buffer[i]);
			}
			break;
		case 1: // '('경우 바로 stack에 push - 우선순위가 제일 낮으므로
			stkCon.push(buffer[i]);
			break;
			
		default: // buffer의 내용이 공백일경우 무시하도록 함
			break; 
		}
		i++;
	}

	while (stkCon.top != -1) { // 모든 연산자를 검사한 후에 스택에 남아있는 모든 걸 출력
		if (stkCon.stack[stkCon.top] == '(') { // '('은 출력이 안되도록 함
			stkCon.pop();
			continue;
		}
		else {
			bufEval[j] = stkCon.pop();
			cout << bufEval[j++] << " ";
		}
	}
	bufEval[j] = '\0'; // 마지막에 Null문자 적용
}

int postfixEvaluation(char *buffer) {
	IntStack stkEval(MAX_SIZE);

	int i = 0;
	int op1,op2;
	while (buffer[i] != '\0') { // 똑같이 연산자의 우선순위를 검사하지만 '(',')'가 없으므로 사칙연산만 검사
		switch (priority(buffer[i])) { // char형 정수를 int형 정수로 변환하는 방법 : char형 정수 -48(='0')
		case 0:	// 연산자가 아닌 숫자일 때 stack에 push
			stkEval.push(buffer[i]-'0');
			break;
		case 3:
		case 2:
			op2 = stkEval.pop();
			op1 = stkEval.pop();

			switch (buffer[i]) { // 각 연산자 별로 연산한 값을 다시 stack에 push
			case '+':
				stkEval.push(op1 + op2);
				break;
			case '-':
				stkEval.push(op1 - op2);
				break;
			case '*':
				stkEval.push(op1 * op2);
				break;
			case '/':
				stkEval.push(op1 / op2);
				break;
			}
			break;
		default: // '(',')' 또는 공백일 경우 무시
			break;
		}
		i++;
	} // 마지막까지 stack에 남아있는 값은 최종 연산 값
	return stkEval.pop();
}