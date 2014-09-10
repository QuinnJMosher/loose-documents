#include <iostream>

using namespace std;

bool CheckPass(char input[]);

void main() {

	cout << "enter your name: \n";
	char name[] = "";
	cin >> name;

	bool acceptablePassword = false;
	cout << "enter a password: \n";

	while (!acceptablePassword) {
		char password[] = "";

		cin >> password;

		acceptablePassword = CheckPass(password);

		if (!acceptablePassword) {
			cout << "try another password \n";
		}
	}

	cout << "password accepted! \n";

	system("pause");

}

bool CheckPass(char input[]) {
	if (strlen(input) >= 8) {
		bool capital = false;
		bool number = false;
		bool symbol = false;

		int i = 0;
		bool notNull = true;
		while (notNull) {

			if (input[i] == '\0') {
				notNull = false;
				break;
			}
			else if (isupper(input[i])) {
				capital = true;
			}
			else if (isdigit(input[i])) {
				number = true;
			}
			else if (!isalpha(input[i]) && !isdigit(input[i])) {
				symbol = true;
			}

			i++;
		}

		if (capital && number && symbol) {
			return true;
		}
	}
	return false;
}