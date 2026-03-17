#include "Header.h"

void task_1() {
	using namespace std;

	int output, count = 0;

	vector<int> V;
	list<int> L;
	deque<int> D;	
	
	InputContainersForTask_1(V, D, L);

	cout << "\n======= Вывод =======\n 1 - в консоль\n 2 - в файл\n";
	output = getNumber();
	while (output < 1 || output>2) {
		cout << "Ошибка!\nНужна цифра от 1 до 2!\n ";
		output = getNumber();
	}
	switch (output) {
	case 1:
		cout << "\n\n==========Контейнеры до изменений ==========\n";
		cout << "Вектор: ";
		for (auto it = V.begin(); it != V.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		cout << "Дек: ";
		for (auto it = D.begin(); it != D.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		cout << "Список: ";
		for (auto it = L.begin(); it != L.end(); ++it) {
			cout << *it << " ";
		}

		V.front() = V.front() * 2;
		V.back() = V.back() * 2;
		for (auto& i : V) {
			if (count == V.size() / 2) {
				i = i * 2;
			}
			count++;
		}
		count = 0;

		D.front() = D.front() * 2;
		D.back() = D.back() * 2;
		for (auto& i : D) {
			if (count == D.size() / 2) {
				i = i * 2;
			}
			count++;
		}
		count = 0;

		L.front() = L.front() * 2;
		L.back() = L.back() * 2;
		for (auto& i : L) {
			if (count == L.size() / 2) {
				i = i * 2;
			}
			count++;
		}

		cout << "\n\n==========Контейнеры после изменений ==========\n";
		cout << "Вектор: ";
		for (auto it = V.begin(); it != V.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		cout << "Дек: ";
		for (auto it = D.begin(); it != D.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		cout << "Список: ";
		for (auto it = L.begin(); it != L.end(); ++it) {
			cout << *it << " ";
		}
		break;
	case 2:
	{
		string filename;
		filename = getText();

		ofstream file(filename);

		if (file.is_open()) {
			file << "==========Контейнеры до изменений ==========\n";
			file << "Вектор: ";
			for (auto it = V.begin(); it != V.end(); ++it) {
				file << *it << " ";
			}
			file << endl;
			file << "Дек: ";
			for (auto it = D.begin(); it != D.end(); ++it) {
				file << *it << " ";
			}
			file << endl;
			file << "Список: ";
			for (auto it = L.begin(); it != L.end(); ++it) {
				file << *it << " ";
			}

			V.front() = V.front() * 2;
			V.back() = V.back() * 2;
			for (auto& i : V) {
				if (count == V.size() / 2) {
					i = i * 2;
				}
				count++;
			}
			count = 0;

			D.front() = D.front() * 2;
			D.back() = D.back() * 2;
			for (auto& i : D) {
				if (count == D.size() / 2) {
					i = i * 2;
				}
				count++;
			}
			count = 0;

			L.front() = L.front() * 2;
			L.back() = L.back() * 2;
			for (auto& i : L) {
				if (count == L.size() / 2) {
					i = i * 2;
				}
				count++;
			}

			file << "\n\n==========Контейнеры после изменений ==========\n";
			file << "Вектор: ";
			for (auto it = V.begin(); it != V.end(); ++it) {
				file << *it << " ";
			}
			file << endl;
			file << "Дек: ";
			for (auto it = D.begin(); it != D.end(); ++it) {
				file << *it << " ";
			}
			file << endl;
			file << "Список: ";
			for (auto it = L.begin(); it != L.end(); ++it) {
				file << *it << " ";
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		file.close();
		break;
	}
	}
	
}

void task_2() {
	using namespace std;

	vector<int> V;

	inputVector(V);

	for (auto i = V.begin(); i != V.end(); ++i) {
		++i;
		i = V.insert(i, -1);
	}

	outputVector(V);
}

void task_3() {
	using namespace std;

	int middleElement = 0, cnt = 0;
	vector<int> V;
	list<int> L;

	inputVector(V);
	inputList(L);

	for (auto i = L.begin(); i != L.end(); ++i) {
		if (cnt == L.size() / 2) {
			middleElement = *i;
			break;
		}
		cnt++;
	}

	auto iterator = std::find(L.begin(), L.end(), middleElement);
	L.erase(iterator);
	V.push_back(middleElement);

	outputVector(V);
	outputList(L);
}

// ===== заполнение строки "name" с консоли =====
std::string getFilenameFromConsole() {
	using namespace std;

	string filename;
	bool valid;

	do {
		valid = true;
		cout << "Введите имя файла (только английские буквы): ";
		getline(cin, filename);

		if (filename.empty()) {
			cout << "Ошибка! Имя файла не может быть пустым.\n";
			valid = false;
			continue;
		}

		for (char c : filename) {
			if (!isalpha(c)) {
				valid = false;
				break;
			}
		}

		if (!valid) {
			cout << "Ошибка! Используйте только английские буквы.\n";
		}

	} while (!valid);

	return filename;
}

// ===== рандомное заполнение строки "name" =====
std::string getFilenameRandom() {
	using namespace std;

	int length;
	string filename;

	cout << "Введите длину имени файла: ";
	cin >> length;
	cin.ignore();

	srand(time(nullptr));

	for (int i = 0; i < length; i++) {
		char c = rand() % 52;
		if (c < 26) {
			filename += 'a' + c;
		}
		else {
			filename += 'A' + (c - 26);
		}
	}

	cout << "Сгенерировано имя: " << filename << endl;
	return filename;
}

// ===== заполнение строки "name" из файла =====
std::string getFilenameFromFile() {
	using namespace std;

	string inputFile;
	string filename;

	cout << "Введите имя файла, из которого прочитать имя: ";
	getline(cin, inputFile);

	ifstream file(inputFile);

	if (!file.is_open()) {
		cout << "Ошибка открытия файла!\n";
		return "";
	}

	getline(file, filename);
	file.close();

	bool valid = true;
	if (filename.empty()) {
		valid = false;
	}
	else {
		for (char c : filename) {
			if (!isalpha(c)) {
				valid = false;
				break;
			}
		}
	}

	if (!valid) {
		cout << "Ошибка! В файле должно быть имя только из английских букв.\n";
		return "";
	}

	cout << "Прочитано имя: " << filename << endl;
	return filename;
}

// ===== меню ввода строки "name" =====
std::string getFilename() {
	using namespace std;

	int choice;
	string filename;

	cout << "Выберите способ ввода имени файла:\n1 - с консоли\n2 - рандомно\n3 - из файла\nВаш выбор: ";
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 1:
		filename = getFilenameFromConsole();
		break;
	case 2:
		filename = getFilenameRandom();
		break;
	case 3:
		filename = getFilenameFromFile();
		break;
	default:
		cout << "Неверный выбор!\n";
		filename = "";
	}

	return filename;
}

void task_4() {
	using namespace std;

	string name;
	int K;

	K = getNumber();

	while (K < 0) {
		cout << "Ошибка!\n";
		K = getNumber();
	}
	name = getFilename();
	name += ".txt";
	fstream file(name);

	if (file.is_open()) {
		ostream_iterator<char> out(file);
		fill_n(out, K, '*');
		file.close();
		cout << "Записано " << K << " символов * в файл " << name << endl;
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
}
