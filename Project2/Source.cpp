#include <iostream>
#include <fstream>

using namespace std;

/*void main() {
	cout << "Enter file name: ";

	char input_fileName[20] = "";
	cin >> input_fileName;

	cout << endl;

	fstream f_output;
	f_output.open(input_fileName, ios_base::out);

	if (f_output.is_open()) {
		cout << "file open\n";
	} else {
		cout << "file could not be opened, closing program\n";
		system("pause");
		return;
	}

	cout << "Enter what you would like to put in the file, type -1 to end\n";

	char input_text[50] = "";
	do {
		cin >> input_text;

		if (strcmp(input_text, "-1") != 0) {
			f_output << input_text << " ";
		}
		
	} while (strcmp(input_text, "-1") != 0);

	cout << "file input ended, closing program.\n"; 
	system("pause");

	f_output.sync();
	f_output.close();
	f_output.clear();
}*/