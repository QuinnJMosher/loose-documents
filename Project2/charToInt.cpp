#include <iostream>

using namespace std;

int char_to_int(char* input);

void main() {
	char* string = "123";
	cout << char_to_int(string) << endl;
	system("pause");

}

int char_to_int(char* input) {
	int out = 0;
	int power = 0;
	for (int i = strlen(input) - 1; i > -1; i--) {
		out += (input[i] - ('1' - 1)) * pow(10, power);
		power++;
	}
	return out;
}