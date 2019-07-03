#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int WordCount(char *buffer, int WC) {

	//initialize pointer IN=1, OUT =0
	int IN = 1;
	int OUT = 0;

	int i = 0;
	int state = OUT;

	int wc = 0;

	while (buffer[i] != '\0') {
		if (isalpha(buffer[i])) {
			if (state == OUT) {
				++wc;
				state = IN;
			}
		}
		else if (buffer[i] == ' ')
			state = OUT;
		i++;
	}
	return wc;
}

int main() {

	int toWC = 0;

	ifstream infile;
	char buffer[80];
	infile.open("lab0-1.txt", ios::in);
	if (infile.fail()) {
		cout << "can't open the input file" << endl;
		exit(1);
	}

	while (infile.getline(buffer, 80)) {

		int WC = 0;

		cout << buffer << endl;
		WC = WordCount(buffer, WC);
		cout << "The number of words:"<< WC <<endl;

		toWC = toWC + WC;
	}
	cout <<"Total Number of Words:"<< toWC<<endl;

	return 0;
}