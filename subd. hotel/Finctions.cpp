#include "Functions.h"
#include <regex>

void DataEntry(Data* (&d), int& n)//���� ������ �������
{
	cout << "������ ������� �����: ";
	cin >> n;

	//������� ������ 
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "������ ϲ�: ";
		cin >> d[i]._initial.sutname;
		cin >> d[i]._initial.patronymic;
		cin >> d[i]._initial.name;

		cout << "������ ���� ��������: ";
		cin >> d[i].passportSeries;

		cout << "������ ����� ��������: ";
		cin >> d[i].passportNumber;


		cout << "������ ���� ����������: ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "������ ��� �� ����� ������ � �����: ";
		cin >> d[i]._address.typeroom;
		cin >> d[i]._address.numroom;

		cout << "������ ���� �'���� (����, �����, ��): ";
		cin >> d[i].checkInDate.day >> d[i].checkInDate.month >> d[i].checkInDate.year;

		cout << "������ ���� ����� (����, �����, ��): ";
		cin >> d[i].checkOutDate.day >> d[i].checkOutDate.month >> d[i].checkOutDate.year;

		
		cout << "                             " << endl;
	}
}
void ReadingData(Data* (&d), int& n, string fileName)//������ ������ �� �����
{
	//������� ����� ��� ������
	ifstream reading(fileName);

	if (reading) {

		reading >> n;

		//������� ������
		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i]._initial.sutname;
			reading >> d[i]._initial.patronymic;
			reading >> d[i]._initial.name;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;

			reading >> d[i]._address.typeroom;
			reading >> d[i]._address.numroom;

			reading >> d[i].passportSeries;
			reading >> d[i].passportNumber;

			reading >> d[i]._address.typeroom;
			reading >> d[i]._address.numroom;

			reading >> d[i].checkInDate.day >> d[i].checkInDate.month >> d[i].checkInDate.year;

			reading >> d[i].checkOutDate.day >> d[i].checkOutDate.month >> d[i].checkOutDate.year;
		}

		cout << "��� �������!" << endl;
	}
	else
		cout << "������� �������� �����!" << endl;

	reading.close();
}
void Print(Data* d, int n)//����� ������
{
	for (int i = 0; i < n; i++) {
		cout << "" << i + 1 << ":" << endl;

		cout << "ϲ�: " << d[i]._initial.sutname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "����: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
		cout << "�����: " << d[i]._address.typeroom << " " << d[i]._address.numroom << endl;
		cout << "�������: " << d[i].passportSeries << " " << d[i].passportNumber << endl;
		cout << "���� �'����: " << d[i].checkInDate.day << "/" << d[i].checkInDate.month << "/" << d[i].checkInDate.year << endl;
		cout << "���� �����: " << d[i].checkOutDate.day << "/" << d[i].checkOutDate.month << "/" << d[i].checkOutDate.year << endl;

		cout << "                          " << endl;
	}
}
void DataChange(Data* (&d), int n)//��������� ������
{
	int _n;
	cout << "������ ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	//��������, ��� ������� ���������� ��������
	if (_n >= 0 && _n < n) {
		cout << "������ ϲ�: ";
		cin >> d[_n]._initial.sutname;
		cin >> d[_n]._initial.patronymic;
		cin >> d[_n]._initial.name;

		cout << "������ ����: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		cout << "������ ������: ";
		cin >> d[_n]._address.typeroom;
		cin >> d[_n]._address.numroom;

		system("cls");

		cout << "��� ������!" << endl;
	}
	else
		cout << "����� ������� ������!" << endl;
}
void DeleteData(Data* (&d), int& n)//�������� ������
{
	int _n;
	cout << "������ ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--; 

	system("cls");

	//��������, ��� ������� ���������� ��������
	if (_n >= 0 && _n < n) {

		//��������� ������
		Data* buf = new Data[n];

		Copy(buf, d, n);

		//�������� ����� ������
		--n;
		d = new Data[n];

		int q = 0;

		//���������� ������ ����� �� ��������
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << "��� ����!" << endl;
	}
	else
		cout << "����� ������� ������!" << endl;
}
void Copy(Data* (&d_n), Data* (&d_o), int n)//����� ������
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}
void Copy(Data& d_n, Data& d_o)//����� ������ ��������
{
	d_n._initial.sutname = d_o._initial.sutname;
	d_n._initial.patronymic = d_o._initial.patronymic;
	d_n._initial.name = d_o._initial.name;

	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;

	d_n._address.typeroom = d_o._address.typeroom;
	d_n._address.numroom = d_o._address.numroom;
}
void AddDate(Data* (&d), int& n)//�������� ������
{
	//��������� ������
	Data* buf = new Data[n];

	//��������� ������ � ��������� ������
	Copy(buf, d, n);

	//�������� ����� ������
	n++;
	d = new Data[n];

	//���������� ������
	Copy(d, buf, --n);

	cout << "ϲ�: ";
	cin >> d[n]._initial.sutname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "������ ����: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	cout << "������ ������: ";
	cin >> d[n]._address.typeroom >> d[n]._address.numroom;

	system("cls");

	cout << "��� ��������!" << endl;

	delete[]buf;
}
void DataSorting(Data* d, int n)//���������� ������
{
	//��������� ����������
	Data buf;

	//���������� ������� ���������
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//����� ����������
			if (d[i]._initial.sutname > d[j]._initial.sutname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}
	cout << "��� �����������!" << endl;
}
void SavingData(Data* d, int n, string fileName)//���������� ������
{
	//��������� ����� ��� ������
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._initial.sutname << endl;
			record << d[i]._initial.name << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			record << d[i]._date.year << endl;

			record << d[i]._address.typeroom << " ";
			if (i < n - 1)
				record << d[i]._address.numroom << endl;
			else
				record << d[i]._address.numroom;
		}
	}
	else
		cout << "������� �������� �����!" << endl;

	record.close();
}
void searchByRoomNumber(Data* d, int n, int roomNumber) {
	bool found = false;
	for (int i = 0; i < n; ++i) {
		if (d[i]._address.numroom == roomNumber) {
			cout << "ϲ�: " << d[i]._initial.sutname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
			cout << "����: " << d[i]._date.day << "." << d[i]._date.month << "." << d[i]._date.year << endl;
			cout << "������� �: " << d[i]._address.typeroom << ", �����: " << d[i]._address.numroom << endl;
			cout << "----------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "����� ������ �� ��������!" << endl;
	}
}
