#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void LinesCounter(string stroka);
void WordsCounter(string slovo);
void BytesCounter(string byte);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	string* files = new string[argc];
	int key = 0;
	bool if_lines = false, if_words = false, if_bytes = false;
	for (int i = 1; i < argc; i++) {
		string argument = argv[i];
		if (argument == "-l" or argument == "--lines") {
			if_lines = true;
		}
		else if (argument == "-w" or argument == "--words") {
			if_words = true;
		}
		else if (argument == "-c" or argument == "--bytes") {
			if_bytes = true;
		}
		else {
			//files.push_back(argument);
			files[key] = argument + ".txt";
			key++;
		}
	}
	if (!if_lines && !if_words && !if_bytes) {
		if_lines = true;
		if_words = true;
		if_bytes = true;
	}
	for (int i = 0; i < key; i++) {
		string s = files[i];
		ifstream file(s);
		file.open(s);
		if (file.is_open()) {
			if (if_lines)
				LinesCounter(s);
			if (if_words)
				WordsCounter(s);
			if (if_bytes)
				BytesCounter(s);
			cout << " file: " << s << '\n';
			file.close();
		}
		else
			cout << "file not found: " << s << '\n';
	}
}
void LinesCounter(string f) {
	ifstream file;
	file.open(f);
	if (file.is_open()) {
		string str;
		int l_count = 0;
		while (!file.eof()) {
			getline(file, str);
			l_count++;
		}
		file.close();
		cout << " lines: " << l_count;
	}
}
void WordsCounter(string f) {
	ifstream file;
	file.open(f);
	if (file.is_open()) {
		string str;
		int w_count = 0;
		while (!file.eof()) {
			file >> str;
			w_count++;
		}
		file.close();
		cout << " words: " << w_count;
	}
}
void BytesCounter(string f) {
	ifstream file;
	file.open(f);
	if (file.is_open()) {
		int b_count = 0;
		file.seekg(0, ios_base::end);
		b_count = file.tellg();
		file.close();
		cout << " bytes: " << b_count;
	}
}