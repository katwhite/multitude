// multitude.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "multitude.h"
#include <locale.h>
#include <iostream>
#include <fstream>
#include <Windows.h>


int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	/*
	set <char> example;
	multitude ex;
	for (int i = 0; i < 5; i++) {
		cout << "введите букву которую хотите добавить" << "\n";
		char letter;
		cin >> letter;
		ex.insert(letter);
	}
	ex.show();

	cout << "\n" << "введите букву которую хотите удалить" << "\n";
	char letter;
	cin >> letter;
	ex.erase(letter);
	ex.show();

	cout << "\n" << "введите букву которую хотите удалить" << "\n";
	
	cin >> letter;
	ex.erase(letter);
	ex.show();
	

	set <char> st{'в', 'г', 'х', 'ъ'};
	multitude setcopy(st);
	cout << "setcopy = ";
	setcopy.show();

	multitude letr('п');
	cout << "letr = ";
	letr.show();

	cout << "letr + setcopy = ";

	multitude res = setcopy + letr;
	cout << "res = ";
	res.show();

	cout << endl << "res - setcopy = ";

	multitude res1 = res - setcopy;
	res1.show();

	res1.erase();
	cout << "res1 удалён";
	res1.show();
	cout << " полностью.";

	set <char> examp{ 'ы', 'ц', 'й' };
	set <char> examp1{ 'ч', 'ц', 'й', 'з' };

	
	multitude ex1(examp);
	multitude ex2(examp1);
	cout << endl << "set1 = ";
	ex1.show();
	//copy(examp.begin(), examp.end(), ostream_iterator<char>(cout, " "));
	cout << endl << "set2 = ";
	ex2.show();
	//copy(examp1.begin(), examp1.end(), ostream_iterator<char>(cout, " "));

	multitude result = ex1.intersection(ex2);
	cout << "их пересечение = ";
	result.show();

	if (ex1.isSame(ex2))
		cout << "ex1 = ex2";
	else
		cout << "ex1 != ex2";
	cout << endl;
*/


	ifstream file("in.txt");
	if (!file.is_open())
	{
		cout << "Файл in.txt не существует" << endl;
		return -1;
	}
	ofstream out("out.txt");
	if (!out.is_open())
	{
		cout << "Невозможно создать выходной файл out.txt" << endl;
		return -2;
	}
/*
	multitude *sentences = new multitude[10];
	int count = 0;
	char a;
	while (!file.eof()) {
		for (int i = 0; i < 10; i++) {
			multitude s;
			s.erase();
			file >> a;
			//CharToOem(a);
			if (a != '.')
				s.insert(a);

			while (a != '.') {
				file >> a;
				s.insert(a);
			}
			//s.show();
			
			sentences[i] = s;
			
			count++;
			if (file.eof())
				break;
		}
	}
	bool notsame = true;

	for (int i = 0; i < count - 1; i++) {
		sentences[i].erase('.');
		sentences[i].show();
	}
	
	for (int i = 0; i < count - 1; i++) {
		//sentences[i].show();
	
		for (int j = i + 1; j < count - 1; j++) {
			if (sentences[i].isSame(sentences[j])) {
				notsame = false;
				cout << "одинаковые: ";
				sentences[i].show();
				sentences[j].show();

				out << endl << "исходное предложение:";
				multiset <char> ::iterator it = sentences[i].data.begin();
				for (int k = 1; it != sentences[i].data.end(); k++, it++) {
					out << *it << " ";
				}
				out << endl << "такое же предложение:";
				multiset <char> ::iterator it2 = sentences[j].data.begin();
				for (int k = 1; it2 != sentences[j].data.end(); k++, it2++) {
					out << *it2 << " ";
				}
				break;
			}
		}
	}
	if (notsame) {
		cout << "одинаковых предложений не найдено" << endl;
	}
	
	multitude empty;
	empty.erase();
	bool different = false;
	for (int i = 0; i < count - 1; i++) {
		//sentences[i].show();

		for (int j = i + 1; j < count - 1; j++) {
			
			//sentences[i].intersection(sentences[j]).show();
			//cout << "lulz!\n";

			if (sentences[i].intersection(sentences[j]).isSame(empty)) {
				different = true;
				cout << "разные: 1) ";
				sentences[i].show();
				cout << "2) ";
				sentences[j].show();

				out << endl << "исходное предложение:";
				multiset <char> ::iterator it = sentences[i].data.begin();
				for (int k = 1; it != sentences[i].data.end(); k++, it++) {
					out << *it << " ";
				}
				out << endl << "предложение не совпадающее с ним:";
				multiset <char> ::iterator it2 = sentences[j].data.begin();
				for (int k = 1; it2 != sentences[j].data.end(); k++, it2++) {
					out << *it2 << ", ";
				}
				
			}
		}
	}

	if (!different)
		cout << "разных предложений не найдено\n";


	/*
	multitude sample;
	sample.erase();
	char a;
	file >> a;
	if (a != '.')
		sample.insert(a);
	//sample.show();
	while (a != '.') {
		file >> a;
		sample.insert(a);
	}
	cout << "sample = ";
	sample.show();

	multitude compare;
	compare.erase();
	file >> a;
	if (a != '.')
		compare.insert(a);

	while (a != '.') {
		file >> a;
		compare.insert(a);
	}
	cout << "compare = ";
	compare.show();
	bool notsame;
	if (!sample.isSame(compare))
		notsame = true;
	else {
		cout << "same: ";
		sample.show();
		compare.show();
		notsame = false;
		out << "sample sentence:";
		multiset <char> ::iterator it = sample.data.begin();
		for (int i = 1; it != sample.data.end(); i++, it++) {
			out << *it << " ";
		}
		out << endl << "sentence to compare with:";
		multiset <char> ::iterator it2 = compare.data.begin();
		for (int i = 1; it2 != compare.data.end(); i++, it2++) {
			out << *it2 << " ";
		}
	}


	while (notsame) {
		cout << "fail" << endl;
		compare.erase();
		file >> a;
		if (a != '.')
			compare.insert(a);
		while (a != '.') {
			file >> a;
			compare.insert(a);
		}
		cout << "compare = ";
		compare.show();
		if (sample.isSame(compare)) {
			cout << "same: ";
			sample.show();
			compare.show();
			notsame = false;
			out << "sample sentence:";
			multiset <char> ::iterator it = sample.data.begin();
			for (int i = 1; it != sample.data.end(); i++, it++) {
				out << *it << " ";
			}
			out << endl << "sentence to compare with:";
			multiset <char> ::iterator it2 = compare.data.begin();
			for (int i = 1; it2 != compare.data.end(); i++, it2++) {
				out << *it2 << " ";
			}
		}
		if (file.eof()) {
			cout << "nothing has been found" << endl;
			break;
		}

	}
	*/


multitude *syllables = new multitude[10];
int count = 0;
string a;

while (!file.eof()) {
	for (int i = 0; i < 10; i++) {
		multitude s;
		s.erase();
		do {
			getline(file, a, ' ');
			s.insert(a);
			//cout << i << " ";
			//s.show();
		} while (a.find('.') > 100);
		syllables[i] = s;
		
		//syllables[i].show();
		count++;
		if (file.eof())
			break;
	}
}
bool notsame = true;

for (int i = 0; i < count; i++) {
	syllables[i].erase(".");
	syllables[i].show();
}

for (int i = 0; i < count; i++) {

	for (int j = i + 1; j < count; j++) {
		if (syllables[i].isSame(syllables[j])) {
			notsame = false;
			cout << "одинаковые: ";
			syllables[i].show();
			syllables[j].show();
		}
		
	}
}
if (notsame) {
	cout << "nothing has been found" << endl;
}

/*
for (int i = 0; i < 5; i++) {
	cout << "введите слог который хотите добавить" << "\n";
	string letter;
	cin >> letter;
	syllables.insert(letter);
}
syllables.show();
set <string> sylls{"ши", "щи", "ща", "ша", "ху"};
multitude syll2(sylls);
syll2.show();
if (syllables.isSame(syll2))
cout << "ex1 = ex2";
else
cout << "ex1 != ex2";
cout << endl;
*/
	
	system("pause");
	return 0;
}


