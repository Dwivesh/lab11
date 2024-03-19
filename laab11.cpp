#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	//1.
	cout << "   1. Контейнерные алгоритмы.   " << endl;
	list<int> list_int;
	cout << "Введите количество элементов в списке" << endl;
	int c, a;
	cin >> c;

	for (int i = 0; i < c; i++) {
		cout << "Введите " << (i + 1) << "-е число." << endl;
		cin >> a;
		list_int.push_back(a);
	}
	cout << endl;

	/*
	list<int>::iterator it = list_int.begin();
	*/

	cout << "Список выглядит так:" << endl;
	for (auto i = list_int.begin(); i != list_int.end(); i++) {
		cout << *i << endl;
	}
	cout << endl;

	cout << "   1)   " << endl;
	int find_int;
	cout << "Введите элемент, который вы хотите найти." << endl;

	cin >> find_int;

	auto it = find(list_int.begin(), list_int.end(), find_int);

	if (it != list_int.end()) {
		cout << "Элемент найден: " << *it << endl;
	}
	else {
		cout << "Элемент не найден." << endl;
	}
	cout << endl;

	cout << "   2)   " << endl;
	cout << "Реверснутый список:" << endl;
	reverse(list_int.begin(), list_int.end());

	for (const auto& num : list_int) {
		cout << num << " ";
	}
	cout << endl << endl;

	cout << "   3)   " << endl;
	cout << "Отсортированный по возрастанию список:" << endl;
	list_int.sort();
	for (const auto& num : list_int) {
		cout << num << " ";
	}
	cout << endl << endl;

	cout << "   4)   " << endl;
	int sum = accumulate(list_int.begin(), list_int.end(), 0); // из numeric
	cout << "Сумма элементов списка:" << endl;
	cout << sum << endl;
	cout << endl << endl << endl;



	//5
	
	cout << "   5. Элементы в обратном порядке с помощью обратных итераторов:" << endl << endl;
	
	copy(list_int.rbegin(), list_int.rend(), ostream_iterator<int>(cout, " "));
	cout << endl << endl << endl << endl << endl;

	//2

	cout << "   2. Итераторы-адаптеры.  " << endl << endl;
	cout << "Вектор изначальный:" << endl;
		vector<int> vec = { 1, 2, 3, 4, 5 };
	for (const auto& num : vec) {
		cout << num << " ";
	}
	cout << endl << endl;;
	cout << "Вектор после удаления четных элементов:" << endl;
	vec.erase(remove_if(vec.begin(), vec.end(), [](int elem) { return elem % 2 == 0; }), vec.end());
		for (const auto& num : vec) {
			cout << num << " ";
		}
	cout << endl << endl;;
	cout << "Вектор после добавления в конец 6 и на вторую позицию 100:" << endl;
	*back_inserter(vec) = 6;
	
	vector<int>::iterator it2 = find(vec.begin(), vec.end(), 3);
	if (it2 != vec.end()) {
		*inserter(vec, it2) = 100;
	}
	
	for (const auto& num : vec) {
		cout << num << " ";
	}
	cout << endl << endl << endl << endl;

	//4
	cout << "4. Взаимодействие итераторов" << endl << endl;;
	cout << "Скопируем вектор из второго задания в очередь" << endl;
	cout << endl;

	
	queue<int> que_int;
	for (const auto& num : vec) {
		que_int.push(num);
	}

	cout << "Очередь:" << endl;
	while (!que_int.empty()) {
		cout << que_int.front() << " ";
		que_int.pop();
	}
	cout << endl << endl << endl << endl;

	//3

	cout << "3. Файловый ввод-вывод с итераторами" << endl << endl;

	ofstream outFile("output.txt");


	if (!outFile.is_open()) {
		cerr << "Не удалось открыть файл для записи." << endl;
		return 0;
	}
	
	
	string data = "някавай";
	copy(data.begin(), data.end(), ostream_iterator<char>(outFile));

	outFile.close();

	ifstream inFile("output.txt");

	if (!inFile.is_open()) {
		cerr << "Не удалось открыть файл для чтения." << endl;
		return 1;
	}

	istream_iterator<char> fileIterator(inFile);
	istream_iterator<char> endOfFileIterator;

	cout << "Содержимое файла:" << endl;
	while (fileIterator != endOfFileIterator) {
		cout << *fileIterator;
		++fileIterator;
	}

	inFile.close();


	return 0;
}