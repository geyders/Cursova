#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include "Hotel.h"
#include <Windows.h>
#include <direct.h> 
using namespace std;

int _stateMenu;
Hotel hotel; 

void Menu() {
    cout << "������� ��: " << endl
        << "(0) ����� � ��������" << endl
        << "(1) �������� �����" << endl
        << "(2) ���� �����" << endl
        << "(3) ������ ���" << endl
        << "(4) �������� ���" << endl
        << "(5) ���������� �����" << endl
        << "(6) ���������� �����" << endl
        << "(7) ����� �� ������� ������" << endl
        << "(8) ��������� ������ ������ �� �� �������" << endl
        << "(9) ������� �����������" << endl
        << "��� ����: ";
    cin >> _stateMenu;
}
int main() {
    try {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        Menu();

        int _actions;
        string fileName;

        vector<Data> data;

        while (_stateMenu != 0) {
            try {
                switch (_stateMenu) {
                case 1:
                    system("cls"); // ������� ������
                    std::cout << "�������� ������ �� � �����? (1 - ������, 0 - � �����): ";
                    std::cin >> _actions;
                    system("cls");

                    if (_actions == 1) {
                        hotel.DataEntry(data);
                    }
                    else {
                        hotel.readDataFromFile(data, "Input.txt");
                        if (data.empty()) {
                            std::cerr << "���� �� ������ ����� ��� ���� ������ ����������." << std::endl;
                        }
                    }

                    system("pause");
                    system("cls");
                    Menu();
                    break;


                case 2:
                    system("cls");
                    if (!data.empty()) {
                        hotel.printData(data);
                    }
                    else {
                        cout << "��� ����!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 3:
                    system("cls");
                    if (!data.empty()) {
                        hotel.modifyData(data);
                    }
                    else {
                        cout << "��� ����!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 4:
                    system("cls");
                    if (!data.empty()) {
                        hotel.deleteData(data);
                    }
                    else {
                        cout << "��� ����!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 5:
                    system("cls");
                    if (!data.empty()) {
                        hotel.sortData(data);
                    }
                    else {
                        cout << "��� ����!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 6:
                    system("cls");
                    cout << "������ ����� �����: ";
                    cin >> fileName;

                    if (!data.empty()) {
                        hotel.saveDataToFile(data, fileName);
                    }
                    else {
                        cout << "��� ����!" << endl;
                    }

                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 7:
                    system("cls");
                    int roomNumber;
                    cout << "������ ����� ������ ��� ������: ";
                    cin >> roomNumber;
                    hotel.searchRoom(roomNumber, data); 

                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 8:
                    system("cls");
                    hotel.displayRooms(); 
                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 9: 
                    system("cls");
                    cout << "��� ������� �������� ����������� ��������� ����, ��� ������ 10 ������.���������� �� 0 �������� ��������� ���� ������ �� ���������.��� �������� ����� �������� �� 1, ���� ���� 䳿 ����� ������ ������ �������� ����� � ������(1) ��� � �����(0).ϳ��� �������� ����� ����� ��������� ����.��� ��������� ����� �������� �� 2. ��� ����(����������� �����) �������� �� 3. ��� ������� ������ ����� ������ ��� ��� ������� ������ ���.ϳ��� ����� ������ ����� ������ ��'� �볺��� ���� ������� � �����. ��� ��������� ����� �������� ������� ������� 4 �����, �� ������� ����� ������ ��� ��� ������� ��������. ��� ���������� ����� ����� �������� ������ 5 �����. ��� ���� ����������� �� ������� �����.          ��� ���������� ����� � ���� ������ ����� 6. ��� ������ ������ ����� 7, ���� ������ ����� ������, ��� ��� ������ �������� ����� ����������.��� ��������� ������ � ����� �� �� ������� ������ �� ����� 8." << endl;
                    system("pause");
                    system("cls");
                    Menu();
                    break;

                default:
                    cout << "������ �������� ����� 䳿!" << endl;
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                }
            }
            catch (const exception& e) {
                cerr << "������� �������: " << e.what() << endl;
                system("pause");
                system("cls");
                Menu();
            }
        }
    }
    catch (const exception& e) {
        cerr << "��������� ������� ��������: " << e.what() << endl;
    }

    return 0;

}