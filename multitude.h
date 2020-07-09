#pragma once
#include "pch.h"
#include <iostream>	
#include <set>
#include <iterator>
#include <Windows.h>

using namespace std;

class multitude {
private:
	//int size;
	//char* array;
public:
	set <char> data;
	multitude();
	multitude(char a);
	multitude(set <char> def); //constructor
	void show();
	void insert(char letter);
	void erase(char letter);
	multitude operator +(multitude a);
	multitude operator -(multitude a);
	multitude intersection(multitude a);
	bool isSame(multitude a);
	void erase();
	
};

multitude::multitude() {
	data.clear();
}

multitude::multitude(char a) {
	data.insert(a);
}

multitude::multitude(set <char> def) {
	copy(def.begin(), def.end(), inserter(data, data.begin()));

}

void multitude::show() {
	copy(data.begin(), data.end(), ostream_iterator<char>(cout, ","));
	cout << endl;
}

void multitude::insert(char letter) {
	data.insert(letter);
}

void multitude::erase(char letter) {
	if (data.find(letter) == data.end()) {
		cout << "в множестве нет такой буквы" << "\n";
	}
	else
		data.erase(letter);
}

multitude multitude:: operator +(multitude a) {
	multitude res(data);
	copy(a.data.begin(), a.data.end(), inserter(res.data, res.data.begin()));
	return res;
}

multitude multitude:: operator -(multitude a) {
	multitude res(data);
	//data.erase(a.data.begin(), a.data.end());
	multiset <char> ::iterator it = a.data.begin();
	for (int i = 1; it != a.data.end(); i++, it++) {
		if (res.data.find(*it) != res.data.end()) {
			res.data.erase(*it);
			//cout << *it << " ";
		}
	}
	//cout << endl;
	return res;
}

multitude multitude::intersection(multitude a) {
	multitude res;
	multiset <char> ::iterator it = a.data.begin();
	for (int i = 1; it != a.data.end(); i++, it++) {
		if (data.find(*it) != data.end()) {
			res.insert(*it);
			//cout << *it << " ";
		}
	}
	//cout << "flag";
	return res;
}

bool multitude::isSame(multitude a) {
	multiset <char> ::iterator it = a.data.begin();
	for (int i = 1; it != a.data.end(); i++, it++) {
		if (data.find(*it) == data.end()) {
			return false;
		}
	}
	
	multiset <char> ::iterator it1 = data.begin();
	for (int i = 1; it1 != data.end(); i++, it1++) {
		if (a.data.find(*it1) == a.data.end()) {
			return false;
		}
	}
	
	return true;
}

void multitude::erase() {
	data.clear();
}


/*
Определить класс «Множество», реализующий функционирование множества символов русского языка.
В классе реализовать возможности : добавление и удаления символа в / из множества, объединение множеств,
сравнения с другим множеством, пересечения множеств, вычитания множеств.
Функции объединения и вычитания множеств реализовать как перегрузки операций сложения и вычитания.

С использованием класса «Множество» найти в файле пару предложений, которые содержат один и тот же набор символов,
а также пару предложений, в которых не совпадают ни один символ.Найденные предложения запишите в отдельный файл.
*/