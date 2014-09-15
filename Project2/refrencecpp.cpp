#include <iostream>

using namespace std;

void changeCase(char &input);

void main() {
	char character = 'X';
	cout << character << endl;
	changeCase(character);
	cout << character << endl;
	system("pause");
}

void changeCase(char &input) {
	if (input >= 'a') {
		input -= ('a' - 'A');
	} else {
		input += ('a' - 'A');
	}

}