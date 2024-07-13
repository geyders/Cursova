#include "Functions.h" 

int _stateMenu;
Hotel hotel; // Створення об'єкта класу Hotel


void Menu() {
	cout << "Виберіть дію: " << endl
		<< "(0)Вихід з програми" << endl
		<< "(1) Введення даних" << endl
		<< "(2) Вивід даних" << endl
		<< "(3) Змінити дані" << endl
		<< "(4) Видалити дані" << endl
		<< "(5) Додати дані" << endl
		<< "(6) Сортування даних" << endl
		<< "(7) Збереження даних" << endl
		<< "(8) Пошук за номером кімнати" << endl
		<< "(9) Виведення номерів готелю та їх вартості" << endl
		<< "Ваш вибір: ";
	cin >> _stateMenu;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();

	//инициализация данных
	int _actions,
		amountOfData = 0;
	string fileName;

	//массив данных
	Data* d = new Data[amountOfData];

	while (_stateMenu != 0) 
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");//очистка консоли

			cout << "Введення вручну чи з файла?(1 - вручну, 0 - з файла): ";
			cin >> _actions;
			
			system("cls");//очистка консоли

			if (_actions == 1) 
			{
				//ввод вручную
				DataEntry(d, amountOfData);
			}
			else {
				//ввод из файла
				/*
				//В случае ввода названия файла с данными 
				cout << "Введите название файла: ";
				cin >> fileName;//Input.txt
				*/

				ReadingData(d, amountOfData, "Input.txt");
			}

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		////////////////////////////////////////////////////////
		case 2:
			system("cls");//очистка консоли

			if (amountOfData != 0) {
				Print(d, amountOfData);
			}
			else
				cout << "Дані пусті!" << endl;

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		/////////////////////////////////////////////////////////
		case 3:
			system("cls");//очистка консоли

			if (amountOfData != 0) {
				DataChange(d, amountOfData);
			}
			else
				cout << "Дані пусті!" << endl;

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		/////////////////////////////////////////////////////////
		case 4:
			system("cls");

			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
			}
			else
				cout << "Дані пусті!" << endl;

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 5: 
			system("cls");//очистка консоли

			if (amountOfData != 0) {
				AddDate(d, amountOfData);
				amountOfData++;
			}
			else 
				cout << "Дані пусті!" << endl;

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 6:
			system("cls");//очистка консоли

			if (amountOfData != 0) {
				DataSorting(d, amountOfData);
			}
			else
				cout << "Дані пусті!" << endl;

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 7:
			system("cls");//очистка консоли

			cout << "Введіть назву файлу: ";
			cin >> fileName;

			if (amountOfData != 0) {
				SavingData(d, amountOfData, fileName);
			}
			else
				cout << "Дані пусті!" << endl;

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 8:
			system("cls"); // очистка консоли

			if (amountOfData != 0) {
				int roomNumber;
				cout << "Введите номер комнаты для поиска: ";
				cin >> roomNumber;
				searchByRoomNumber(d, amountOfData, roomNumber);
			}
			else {
				cout << "Дані пусті!" << endl;
			}

			system("pause"); // задержка консоли
			system("cls"); // очистка консоли
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 9:
			system("cls"); // очистка консолі
			hotel.displayRooms(); // Виклик методу для виведення номерів готелю та їх вартості
			system("pause"); // затримка консолі
			system("cls"); // очистка консолі
			Menu();
			break;
		//////////////////////////////////////////////////////////
	
		//////////////////////////////////////////////////////////
		default:
			cout << "Невірно введений номер дії!" << endl;
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		}
	}
}