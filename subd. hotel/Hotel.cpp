#include "Hotel.h"
#include <memory>
#include <string>
#include <cstdio>
#include <io.h> 
#include <fcntl.h> 
#include <sstream> 
#include <fstream> 

void Hotel::DataEntry(vector<Data>& data) {
    std::string passportSeries, surname, name, patronymic;
    int passportNumber, roomNumber;
    int birthDay, birthMonth, birthYear;
    int checkInDay, checkInMonth, checkInYear;
    int checkOutDay, checkOutMonth, checkOutYear;
    std::string roomType;

    // Введення даних
    std::cout << "Введіть серію паспорта: ";
    std::cin >> passportSeries;

    std::cout << "Введіть номер паспорта: ";
    std::cin >> passportNumber;

    std::cout << "Введіть прізвище гостя: ";
    std::cin >> surname;
    std::cout << "Введіть ім'я гостя: ";
    std::cin >> name;
    std::cout << "Введіть по батькові гостя: ";
    std::cin >> patronymic;

    // Об'єднання в повне ім'я
    std::ostringstream fullName;
    fullName << surname << " " << name << " " << patronymic;
    std::string guestName = fullName.str();

    std::cout << "Введіть номер кімнати: ";
    std::cin >> roomNumber;

    std::cout << "Введіть тип кімнати: ";
    std::cin >> roomType;

    std::cout << "Введіть дату народження (день, місяць, рік): ";
    std::cin >> birthDay >> birthMonth >> birthYear;

    std::cout << "Введіть дату заїзду (день, місяць, рік): ";
    std::cin >> checkInDay >> checkInMonth >> checkInYear;

    std::cout << "Введіть дату виїзду (день, місяць, рік): ";
    std::cin >> checkOutDay >> checkOutMonth >> checkOutYear;

    Initial initial(surname, name, patronymic);
    Date birthDate(birthDay, birthMonth, birthYear);
    Address address(roomType, roomNumber);
    Date checkInDate(checkInDay, checkInMonth, checkInYear);
    Date checkOutDate(checkOutDay, checkOutMonth, checkOutYear);

    Data guest(passportSeries, passportNumber, std::move(initial),
        std::move(birthDate), std::move(address),
        std::move(checkInDate), std::move(checkOutDate),
        roomNumber, guestName);

    data.push_back(guest);

    // Збереження даних у файл Input.txt
    std::ofstream outFile("Input.txt", std::ios::app); 
    if (outFile.is_open()) {
        outFile << "Серія паспорта: " << passportSeries << "\n"
            << "Номер паспорта: " << passportNumber << "\n"
            << "Прізвище: " << surname << "\n"
            << "Ім'я: " << name << "\n"
            << "По батькові: " << patronymic << "\n"
            << "Номер кімнати: " << roomNumber << "\n"
            << "Тип кімнати: " << roomType << "\n"
            << "Дата народження: " << birthDay << "/" << birthMonth << "/" << birthYear << "\n"
            << "Дата заїзду: " << checkInDay << "/" << checkInMonth << "/" << checkInYear << "\n"
            << "Дата виїзду: " << checkOutDay << "/" << checkOutMonth << "/" << checkOutYear << "\n"
            << "----------------------------\n"; 
        outFile.close(); 
    }
    else {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
    }

    std::cout << "Дані додано успішно." << std::endl;
}


// Читання даних з файлу
void Hotel::readDataFromFile(vector<Data>& data, const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        throw runtime_error("Неможливо відкрити файл: " + fileName);
    }

    string passportSeries, name, surname, patronymic, typeroom, guestName;
    int passportNumber, roomNumber;
    int birthDay, birthMonth, birthYear;
    int checkInDay, checkInMonth, checkInYear;
    int checkOutDay, checkOutMonth, checkOutYear;

    while (file >> passportSeries >> passportNumber >> surname >> name >> patronymic
        >> birthDay >> birthMonth >> birthYear
        >> typeroom >> roomNumber
        >> checkInDay >> checkInMonth >> checkInYear
        >> checkOutDay >> checkOutMonth >> checkOutYear) {

        Initial guestInitial(surname, name, patronymic);
        Date birthDate(birthDay, birthMonth, birthYear);
        Address address(typeroom, roomNumber);
        Date checkInDate(checkInDay, checkInMonth, checkInYear);
        Date checkOutDate(checkOutDay, checkOutMonth, checkOutYear);


        Data newGuest(
            passportSeries,
            passportNumber,
            std::move(guestInitial),
            std::move(birthDate),
            std::move(address),
            std::move(checkInDate),
            std::move(checkOutDate),
            roomNumber,
            guestName  
        );

        data.push_back(std::move(newGuest));
    }

    file.close();
    cout << "Дані зчитано з файлу " << fileName << "." << endl;
}


// Виведення даних
void Hotel::printData(const vector<Data>& data) const {
    for (const auto& guest : data) {
        cout << "Серія паспорту: " << guest.getPassportSeries() << endl;
        cout << "Номер паспорта: " << guest.getPassportNumber() << endl;
        cout << "ПІБ гостя: " << guest.getInitial()->getSurname() << " "
            << guest.getInitial()->getName() << " "
            << guest.getInitial()->getPatronymic() << endl;
        cout << "Номер кімнати: " << guest.getRoomNumber() << endl;
        cout << "Дата народження: " << guest.getBirthDate()->getDay() << "/"
            << guest.getBirthDate()->getMonth() << "/"
            << guest.getBirthDate()->getYear() << endl;
        cout << "Дата в'їзду: " << guest.getCheckInDate()->getDay() << "/"
            << guest.getCheckInDate()->getMonth() << "/"
            << guest.getCheckInDate()->getYear() << endl;
        cout << "Дата виїзду: " << guest.getCheckOutDate()->getDay() << "/"
            << guest.getCheckOutDate()->getMonth() << "/"
            << guest.getCheckOutDate()->getYear() << endl;
        cout << "Адреса: " << guest.getAddress()->getRoomType() << " "
            << guest.getRoomNumber() << endl;
    }
}



// Змінити дані
void Hotel::modifyData(vector<Data>& data) {
    int roomNumber;
    cout << "Введіть номер кімнати для зміни даних: ";
    cin >> roomNumber;

    for (auto& guest : data) {
        if (guest.getRoomNumber() == roomNumber) {
            string newGuestName;
            cout << "Введіть нове ім'я гостя: ";
            cin >> newGuestName;
            guest.setGuestName(newGuestName);
            cout << "Дані оновлено." << endl;
            return;
        }
    }

    cout << "Гість з таким номером кімнати не знайдений." << endl;
}

// Видалення даних
void Hotel::deleteData(vector<Data>& data) {
    int roomNumber;
    cout << "Введіть номер кімнати для видалення: ";
    cin >> roomNumber;

    auto it = remove_if(data.begin(), data.end(), [roomNumber](const Data& guest) {
        return guest.getRoomNumber() == roomNumber;
        });

    if (it != data.end()) {
        data.erase(it, data.end());
        cout << "Гостя видалено." << endl;
    }
    else {
        cout << "Гість з таким номером кімнати не знайдений." << endl;
    }
}


// Сортування даних за номером кімнати
void Hotel::sortData(vector<Data>& data) {
    sort(data.begin(), data.end(), [](const Data& a, const Data& b) {
        return a.getRoomNumber() < b.getRoomNumber();
        });
    cout << "Дані відсортовано за номером кімнати." << endl;
}

// Збереження даних у файл
void Hotel::saveDataToFile(const vector<Data>& data, const string& fileName) const {
    ofstream file(fileName);
    if (!file) {
        throw runtime_error("Неможливо відкрити файл для запису: " + fileName);
    }

    for (const auto& guest : data) {
        file << guest.getPassportSeries() << " " << guest.getPassportNumber() << endl;
        file << guest.getInitial()->getSurname() << " "
            << guest.getInitial()->getName() << " "
            << guest.getInitial()->getPatronymic() << endl;
        file << guest.getBirthDate()->getDay() << " "
            << guest.getBirthDate()->getMonth() << " "
            << guest.getBirthDate()->getYear() << endl;
        file << guest.getAddress()->getRoomType() << " "
            << guest.getRoomNumber() << endl;
        file << guest.getCheckInDate()->getDay() << " "
            << guest.getCheckInDate()->getMonth() << " "
            << guest.getCheckInDate()->getYear() << endl;
        file << guest.getCheckOutDate()->getDay() << " "
            << guest.getCheckOutDate()->getMonth() << " "
            << guest.getCheckOutDate()->getYear() << endl;
        file << guest.getGuestName() << endl;
        file << "-------------------------" << endl;
    }

    file.close();
    cout << "Дані збережено у файл " << fileName << "." << endl;
}


// Метод для пошуку за номером кімнати
void Hotel::searchRoom(int roomNumber, const std::vector<Data>& data) const
{
    bool found = false;
    for (const auto& record : data) {
        if (record.getRoomNumber() == roomNumber) {
            found = true;
            std::cout << "Дані для номера кімнати " << roomNumber << ":\n";
            std::cout << "Паспортна серія: " << record.getPassportSeries() << "\n";
            std::cout << "Номер паспорта: " << record.getPassportNumber() << "\n";
            std::cout << "Ім'я гостя: " << record.getFullName() << "\n";
            std::cout << "Дата народження: " << record.getBirthDate()->toString() << "\n"; // метод toString для виводу дати
            std::cout << "Адреса: " << record.getAddress()->toString() << "\n"; // метод toString для виводу адреси
            std::cout << "Дата заїзду: " << record.getCheckInDate()->toString() << "\n";
            std::cout << "Дата виїзду: " << record.getCheckOutDate()->toString() << "\n";
            break;
        }
    }
    if (!found) {
        std::cout << "Номер кімнати " << roomNumber << " не знайдено.\n";
    }
}



// Виведення номерів кімнат та їх вартості
void Hotel::displayRooms() const {
    cout << "Номери кімнат та їх вартість:" << endl;
    cout << "Стандарт, 101: 1000 грн/доба" << endl;
    cout << "Стандарт, 102: 1000 грн/доба" << endl;
    cout << "Стандарт, 103: 1000 грн/доба" << endl;
    cout << "Стандарт, 104: 1000 грн/доба" << endl;
    cout << "Люкс, 201: 2000 грн/доба" << endl;
    cout << "Люкс, 202: 2200 грн/доба" << endl;
    cout << "Люкс, 203: 2200 грн/доба" << endl;
    cout << "Президентський, 204: 2900 грн/доба" << endl;
}
