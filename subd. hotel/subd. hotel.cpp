#include "Functions.h" 

int _stateMenu;
Hotel hotel; // ��������� ��'���� ����� Hotel


void Menu() {
	cout << "������� ��: " << endl
		<< "(0)����� � ��������" << endl
		<< "(1) �������� �����" << endl
		<< "(2) ���� �����" << endl
		<< "(3) ������ ���" << endl
		<< "(4) �������� ���" << endl
		<< "(5) ������ ���" << endl
		<< "(6) ���������� �����" << endl
		<< "(7) ���������� �����" << endl
		<< "(8) ����� �� ������� ������" << endl
		<< "(9) ��������� ������ ������ �� �� �������" << endl
		<< "��� ����: ";
	cin >> _stateMenu;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();

	//������������� ������
	int _actions,
		amountOfData = 0;
	string fileName;

	//������ ������
	Data* d = new Data[amountOfData];

	while (_stateMenu != 0) 
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");//������� �������

			cout << "�������� ������ �� � �����?(1 - ������, 0 - � �����): ";
			cin >> _actions;
			
			system("cls");//������� �������

			if (_actions == 1) 
			{
				//���� �������
				DataEntry(d, amountOfData);
			}
			else {
				//���� �� �����
				/*
				//� ������ ����� �������� ����� � ������� 
				cout << "������� �������� �����: ";
				cin >> fileName;//Input.txt
				*/

				ReadingData(d, amountOfData, "Input.txt");
			}

			system("pause");//�������� �������
			system("cls");//������� �������
			Menu();
			break;
		////////////////////////////////////////////////////////
		case 2:
			system("cls");//������� �������

			if (amountOfData != 0) {
				Print(d, amountOfData);
			}
			else
				cout << "��� ����!" << endl;

			system("pause");//�������� �������
			system("cls");//������� �������
			Menu();
			break;
		/////////////////////////////////////////////////////////
		case 3:
			system("cls");//������� �������

			if (amountOfData != 0) {
				DataChange(d, amountOfData);
			}
			else
				cout << "��� ����!" << endl;

			system("pause");//�������� �������
			system("cls");//������� �������
			Menu();
			break;
		/////////////////////////////////////////////////////////
		case 4:
			system("cls");

			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
			}
			else
				cout << "��� ����!" << endl;

			system("pause");//�������� �������
			system("cls");//������� �������
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 5: 
			system("cls");//������� �������

			if (amountOfData != 0) {
				AddDate(d, amountOfData);
				amountOfData++;
			}
			else 
				cout << "��� ����!" << endl;

			system("pause");//�������� �������
			system("cls");//������� �������
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 6:
			system("cls");//������� �������

			if (amountOfData != 0) {
				DataSorting(d, amountOfData);
			}
			else
				cout << "��� ����!" << endl;

			system("pause");//�������� �������
			system("cls");//������� �������
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 7:
			system("cls");//������� �������

			cout << "������ ����� �����: ";
			cin >> fileName;

			if (amountOfData != 0) {
				SavingData(d, amountOfData, fileName);
			}
			else
				cout << "��� ����!" << endl;

			system("pause");//�������� �������
			system("cls");//������� �������
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 8:
			system("cls"); // ������� �������

			if (amountOfData != 0) {
				int roomNumber;
				cout << "������� ����� ������� ��� ������: ";
				cin >> roomNumber;
				searchByRoomNumber(d, amountOfData, roomNumber);
			}
			else {
				cout << "��� ����!" << endl;
			}

			system("pause"); // �������� �������
			system("cls"); // ������� �������
			Menu();
			break;
		//////////////////////////////////////////////////////////
		case 9:
			system("cls"); // ������� ������
			hotel.displayRooms(); // ������ ������ ��� ��������� ������ ������ �� �� �������
			system("pause"); // �������� ������
			system("cls"); // ������� ������
			Menu();
			break;
		//////////////////////////////////////////////////////////
	
		//////////////////////////////////////////////////////////
		default:
			cout << "������ �������� ����� 䳿!" << endl;
			system("pause");//�������� �������
			system("cls");//������� �������
			Menu();
			break;
		}
	}
}