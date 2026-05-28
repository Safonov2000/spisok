
#include<iostream>


using namespace std;

struct spisok { // Структура список 

	int uzel; // Поле для хранения узла

	spisok* next; // Структура списка обращаемся к next

};

spisok* spisok1(int value) { // Функция создания нового угла

	spisok* newspisok = new spisok; // Выделяем память в куче для одного угла

	newspisok->uzel = value; // Записываем переднее число в поле uzel нового числа

	newspisok->next = 0; // Пока новый узел не соединен с новыми узлами

	return newspisok; // Возвращаем адрес нового узла

}

spisok* perevorot(spisok* head) { // Функция переворота списка

	spisok* newukaz = 0; // Проходим по исходному списку и каждый узел цепляем в начало списка

	while (head != 0) { // Цикл продолжается, пока в исходном списке есть узлы

		spisok* nod = head; // Текущий первый узел

		head = head->next; // Сдвигаем head на следующий узел

		nod->next = newukaz; // Перенаправляем указатель 

		newukaz = nod; // Обновляем начало нового списка

		
	}

	return newukaz; // Возвращаем указатель на начало перевернутого списка

}

void printspisok(spisok* head) { // Функция вывода списка на экран

	while (head != 0) { // Проходим по всем узлам списка

		cout << head->uzel << " "; // Выводим значение текущего узла на экран

		head = head->next; // Переходим к следующему узлу
	}

	cout << "\n"; // Переходим на новую строку
}

int main() {

	system("chcp 1251"); // Русский язык

	spisok* head = spisok1(1); // Создаем первый узел со значением 1

	head->next = spisok1(2); // Создаем второй узел со значением 2

	head->next->next = spisok1(3); // Создаем третий узел со значением 3

	head->next->next->next = spisok1(4); // Создаем четвертый узел со значением 4

	head->next->next->next->next = spisok1(5); // Создаем 5 узел со значением 5

	head->next->next->next->next->next = spisok1(6); // Создаем 6 узел со значением 6

	head->next->next->next->next->next->next = spisok1(7); // Создаем 7 узел со значением 7

	head->next->next->next->next->next->next->next = spisok1(8); // Создаем 8 узел со значением 8

	head->next->next->next->next->next->next->next->next = spisok1(9); // Создаем 9 узел со значением 9

	head->next->next->next->next->next->next->next->next->next = spisok1(10); // Создаем 10 узел со значением 10


	cout << "Был список: "; // Выводим сообщение был список 

	printspisok(head); // Вызываем функцию printspisok, передаем ей начало списка

	head = perevorot(head); // Вызываем функцию переворот, которая переворачивает список

	
	cout << "Стал список: "; // Выводим сообщение стал список

	printspisok(head); // Вызываем printspisok для перевернутого списка

	while (head != 0) { // Проходим по всем узлам спискам и удаляем их

		spisok* temp = head; // Сохраняем указатель на текущий узел во временную переменную

		head = head->next; // Переходим к следующему узлу до того, как удалим переменную

		delete temp; // Удаляем узел
	}

	return 0; // Завершаем программу
}

