#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <map>

using namespace std;

/*
Данных:
1. Инициалы(ФИО)
2. Дата
3. Адрес
*/

//структура фио
struct Initial {
	string sutname,
		patronymic,
		name;
};

//структура дата
struct Date {
	int day,
		month,
		year;
};

//структура адрес
struct Address {
	string typeroom;
	int numroom;
};

//структура данных
struct Data {
	Initial _initial;
	string passportSeries;
	string passportNumber;
	Date _date;
	Address _address;
	Date checkInDate;
	Date checkOutDate;
	int roomNumber;
};

class Hotel {
public:
	Hotel() {
		// Заповнюємо словник номерами та їх вартістю за добу
		rooms[101] = 1000;
		rooms[102] = 1200;
		rooms[103] = 900;
		rooms[104] = 1500;
		rooms[105] = 1100;
	}

	void displayRooms() {
		cout << "Номери готелю та їх вартість за добу:" << endl;
		for (const auto& room : rooms) {
			cout << "Номер " << room.first << ": " << room.second << " грн" << endl;
		}
	}

private:
	map<int, int> rooms;
};

//прототипы функций
void DataEntry(Data* (&d), int& n);//ввод данных вручную
void ReadingData(Data* (&d), int& n, string fileName);//чтение данных тз файлаа
void Print(Data* d, int n);//вывод данных
void DataChange(Data* (&d), int n);//изменение данных
void DeleteData(Data* (&d), int& n);//удаление данных
void Copy(Data* (&d_n), Data* (&d_o), int n);//копия данных
void Copy(Data& d_n, Data& d_o);//копия данных элемента
void AddDate(Data* (&d), int& n);//добавить данные
void DataSorting(Data *d, int n);//сортировка данных
void SavingData(Data* d, int n, string fileName);//сохранение данных
void searchByRoomNumber(Data* d, int n, int roomNumber);//функция поиска
void checkRoomAvailability(Data* d, int amountOfData); // функция проверки свободных номеров
