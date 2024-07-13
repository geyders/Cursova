#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <map>

using namespace std;

/*
������:
1. ��������(���)
2. ����
3. �����
*/

//��������� ���
struct Initial {
	string sutname,
		patronymic,
		name;
};

//��������� ����
struct Date {
	int day,
		month,
		year;
};

//��������� �����
struct Address {
	string typeroom;
	int numroom;
};

//��������� ������
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
		// ���������� ������� �������� �� �� ������� �� ����
		rooms[101] = 1000;
		rooms[102] = 1200;
		rooms[103] = 900;
		rooms[104] = 1500;
		rooms[105] = 1100;
	}

	void displayRooms() {
		cout << "������ ������ �� �� ������� �� ����:" << endl;
		for (const auto& room : rooms) {
			cout << "����� " << room.first << ": " << room.second << " ���" << endl;
		}
	}

private:
	map<int, int> rooms;
};

//��������� �������
void DataEntry(Data* (&d), int& n);//���� ������ �������
void ReadingData(Data* (&d), int& n, string fileName);//������ ������ �� ������
void Print(Data* d, int n);//����� ������
void DataChange(Data* (&d), int n);//��������� ������
void DeleteData(Data* (&d), int& n);//�������� ������
void Copy(Data* (&d_n), Data* (&d_o), int n);//����� ������
void Copy(Data& d_n, Data& d_o);//����� ������ ��������
void AddDate(Data* (&d), int& n);//�������� ������
void DataSorting(Data *d, int n);//���������� ������
void SavingData(Data* d, int n, string fileName);//���������� ������
void searchByRoomNumber(Data* d, int n, int roomNumber);//������� ������
void checkRoomAvailability(Data* d, int amountOfData); // ������� �������� ��������� �������
