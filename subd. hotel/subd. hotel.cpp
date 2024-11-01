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
    cout << "Виберіть дію: " << endl
        << "(0) Вихід з програми" << endl
        << "(1) Введення даних" << endl
        << "(2) Вивід даних" << endl
        << "(3) Змінити дані" << endl
        << "(4) Видалити дані" << endl
        << "(5) Сортування даних" << endl
        << "(6) Збереження даних" << endl
        << "(7) Пошук за номером кімнати" << endl
        << "(8) Виведення номерів готелю та їх вартості" << endl
        << "(9) Посібник користувача" << endl
        << "Ваш вибір: ";
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
                    system("cls"); // очистка консолі
                    std::cout << "Введення вручну чи з файла? (1 - вручну, 0 - з файла): ";
                    std::cin >> _actions;
                    system("cls");

                    if (_actions == 1) {
                        hotel.DataEntry(data);
                    }
                    else {
                        hotel.readDataFromFile(data, "Input.txt");
                        if (data.empty()) {
                            std::cerr << "Файл не містить даних або вони зчитані некоректно." << std::endl;
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
                        cout << "Дані пусті!" << endl;
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
                        cout << "Дані пусті!" << endl;
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
                        cout << "Дані пусті!" << endl;
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
                        cout << "Дані пусті!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 6:
                    system("cls");
                    cout << "Введіть назву файлу: ";
                    cin >> fileName;

                    if (!data.empty()) {
                        hotel.saveDataToFile(data, fileName);
                    }
                    else {
                        cout << "Дані пусті!" << endl;
                    }

                    system("pause");
                    system("cls");
                    Menu();
                    break;

                case 7:
                    system("cls");
                    int roomNumber;
                    cout << "Введіть номер кімнати для пошуку: ";
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
                    cout << "При запуску програми відкривається консольне меню, яке містить 10 пунктів.Натискаючи на 0 програма завершить свою роботу та закриється.Для введення даних натисніть на 1, після цієї дії можна обрати варіант введення даних — вручну(1) або з файлу(0).Після введення даних знову відкриється меню.Для перегляду даних натисніть на 2. Для зміни(редагування даних) натисніть на 3. Далі потрібно ввести номер кімнати для якої потрібно змінити дані.Після вводу кімнати можна змінити ім'я клієнта який проживає в номері. Для видалення даних спочатку потрібно вибрати 4 пункт, та вписати номер кімнати дані якої потрібно видалити. Для сортування даних треба спочатку обрати 5 пункт. Дані буде відсортовано за номером кімнат.          Для збереження даних у файл оберіть пункт 6. Для пошуку оберіть пункт 7, після введіть номер кімнати, про яку хочете дізнатись більше інформації.Для виведення номерів в готелі та їх вартості оберіть дію номер 8." << endl;
                    system("pause");
                    system("cls");
                    Menu();
                    break;

                default:
                    cout << "Невірно введений номер дії!" << endl;
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                }
            }
            catch (const exception& e) {
                cerr << "Виникла помилка: " << e.what() << endl;
                system("pause");
                system("cls");
                Menu();
            }
        }
    }
    catch (const exception& e) {
        cerr << "Глобальна помилка програми: " << e.what() << endl;
    }

    return 0;

}