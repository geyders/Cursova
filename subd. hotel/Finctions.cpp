#include "Functions.h"
#include <regex>

void DataEntry(Data* (&d), int& n)//ввод данных вручную
{
	cout << "Введіть кількість даних: ";
	cin >> n;

	//выделим память 
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введіть ПІБ: ";
		cin >> d[i]._initial.sutname;
		cin >> d[i]._initial.patronymic;
		cin >> d[i]._initial.name;

		cout << "Введіть серію паспорту: ";
		cin >> d[i].passportSeries;

		cout << "Введіть номер паспорту: ";
		cin >> d[i].passportNumber;


		cout << "Введіть дату народження: ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "Введіть тип та номер кімнати в готелі: ";
		cin >> d[i]._address.typeroom;
		cin >> d[i]._address.numroom;

		cout << "Введіть дату в'їзду (день, місяць, рік): ";
		cin >> d[i].checkInDate.day >> d[i].checkInDate.month >> d[i].checkInDate.year;

		cout << "Введіть дату виїзду (день, місяць, рік): ";
		cin >> d[i].checkOutDate.day >> d[i].checkOutDate.month >> d[i].checkOutDate.year;

		
		cout << "                             " << endl;
	}
}
void ReadingData(Data* (&d), int& n, string fileName)//чтение данных тз файла
{
	//создаем поток для чтения
	ifstream reading(fileName);

	if (reading) {

		reading >> n;

		//выделим память
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

		cout << "Дані зчитано!" << endl;
	}
	else
		cout << "Помилка відкриття файлу!" << endl;

	reading.close();
}
void Print(Data* d, int n)//вывод данных
{
	for (int i = 0; i < n; i++) {
		cout << "" << i + 1 << ":" << endl;

		cout << "ПІБ: " << d[i]._initial.sutname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "Дата: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
		cout << "Адрес: " << d[i]._address.typeroom << " " << d[i]._address.numroom << endl;
		cout << "Паспорт: " << d[i].passportSeries << " " << d[i].passportNumber << endl;
		cout << "Дата в'їзду: " << d[i].checkInDate.day << "/" << d[i].checkInDate.month << "/" << d[i].checkInDate.year << endl;
		cout << "Дата виїзду: " << d[i].checkOutDate.day << "/" << d[i].checkOutDate.month << "/" << d[i].checkOutDate.year << endl;

		cout << "                          " << endl;
	}
}
void DataChange(Data* (&d), int n)//изменение данных
{
	int _n;
	cout << "Введіть номер елементу (від 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	//проверка, что введено правильное значение
	if (_n >= 0 && _n < n) {
		cout << "Введіть ПІБ: ";
		cin >> d[_n]._initial.sutname;
		cin >> d[_n]._initial.patronymic;
		cin >> d[_n]._initial.name;

		cout << "Введіть дату: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		cout << "Введіть адресу: ";
		cin >> d[_n]._address.typeroom;
		cin >> d[_n]._address.numroom;

		system("cls");

		cout << "Дані змінено!" << endl;
	}
	else
		cout << "Номер введено невірно!" << endl;
}
void DeleteData(Data* (&d), int& n)//удаление данных
{
	int _n;
	cout << "Введіть номер елементу (від 1 до " << n << "): ";
	cin >> _n;
	_n--; 

	system("cls");

	//проверка, что введено правильное значение
	if (_n >= 0 && _n < n) {

		//временный массив
		Data* buf = new Data[n];

		Copy(buf, d, n);

		//выделяем новую память
		--n;
		d = new Data[n];

		int q = 0;

		//запоминаем данные кроме не нужноого
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << "Дані пусті!" << endl;
	}
	else
		cout << "Номер введено невірно!" << endl;
}
void Copy(Data* (&d_n), Data* (&d_o), int n)//копия данных
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}
void Copy(Data& d_n, Data& d_o)//копия данных элемента
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
void AddDate(Data* (&d), int& n)//добавить данные
{
	//временный массив
	Data* buf = new Data[n];

	//сохраняем данные в временный массив
	Copy(buf, d, n);

	//выделяем новую память
	n++;
	d = new Data[n];

	//возвращаем данные
	Copy(d, buf, --n);

	cout << "ПІБ: ";
	cin >> d[n]._initial.sutname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "Введіть дату: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	cout << "Введіть адресу: ";
	cin >> d[n]._address.typeroom >> d[n]._address.numroom;

	system("cls");

	cout << "Дані оновлено!" << endl;

	delete[]buf;
}
void DataSorting(Data* d, int n)//сортировка данных
{
	//временная переменная
	Data buf;

	//сортировка методом бульбашкм
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//умова сортировки
			if (d[i]._initial.sutname > d[j]._initial.sutname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}
	cout << "Дані посортовано!" << endl;
}
void SavingData(Data* d, int n, string fileName)//сохранение данных
{
	//создается поток для записи
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
		cout << "Помилка відкриття файлу!" << endl;

	record.close();
}
void searchByRoomNumber(Data* d, int n, int roomNumber) {
	bool found = false;
	for (int i = 0; i < n; ++i) {
		if (d[i]._address.numroom == roomNumber) {
			cout << "ПІБ: " << d[i]._initial.sutname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
			cout << "Дата: " << d[i]._date.day << "." << d[i]._date.month << "." << d[i]._date.year << endl;
			cout << "Проживає в: " << d[i]._address.typeroom << ", номер: " << d[i]._address.numroom << endl;
			cout << "----------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Номер кімнати не знайдено!" << endl;
	}
}
