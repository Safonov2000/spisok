

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

struct Student { // Структура студент

	string name; // Имя студента

	double score; // Результат студента
};

int main() {

	system("chcp 1251"); // Русский язык

	Student students[100]; // Массив на 100 элементов

	int number = 0; // Счетчик


	ifstream ctenie("students.txt"); // Чтение из файла

	if (!ctenie) { // Если не удается прочитать файл

		cout << "Ошибка открытия: " << "\n"; // Выводим ошибку об открытии

		return 1; // Завершаем программу с кодом ошибки
	}

	while (ctenie >> students[number].name >> students[number].score) { // Цикл для чтение из данных файла

		number++; // Увеличиваем счетчик
	}

	ctenie.close(); // Закрываем файл

	for (int i = 0; i < number - 1; i++) { // Сортировка студентов

		for (int j = 0; j < number - i - 1; j++) {

			if (students[j].score < students[j + 1].score) {

				Student temp = students[j];

				students[j] = students[j + 1];

				students[j + 1] = temp;
			}
		}
	}

	ofstream file("sorted_students.txt"); // Запись в файл

	for (int i = 0; i < number; i++) { // Цикл для записи всех студентов

		file << students[i].name << " " << students[i].score << "\n"; // Запись в файл

		cout << students[i].name << " " << students[i].score << "\n"; // Вывоод на экран 
	}

	file.close(); // Закрываем в файл

	cout << "Обработано " << number << " Студентов: " << "\n"; // Выводим сообщение о том, что студенты обработаны

	return 0; // Завершаем программу
}
