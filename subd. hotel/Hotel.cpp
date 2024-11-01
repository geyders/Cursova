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

    // �������� �����
    std::cout << "������ ���� ��������: ";
    std::cin >> passportSeries;

    std::cout << "������ ����� ��������: ";
    std::cin >> passportNumber;

    std::cout << "������ ������� �����: ";
    std::cin >> surname;
    std::cout << "������ ��'� �����: ";
    std::cin >> name;
    std::cout << "������ �� ������� �����: ";
    std::cin >> patronymic;

    // ��'������� � ����� ��'�
    std::ostringstream fullName;
    fullName << surname << " " << name << " " << patronymic;
    std::string guestName = fullName.str();

    std::cout << "������ ����� ������: ";
    std::cin >> roomNumber;

    std::cout << "������ ��� ������: ";
    std::cin >> roomType;

    std::cout << "������ ���� ���������� (����, �����, ��): ";
    std::cin >> birthDay >> birthMonth >> birthYear;

    std::cout << "������ ���� ����� (����, �����, ��): ";
    std::cin >> checkInDay >> checkInMonth >> checkInYear;

    std::cout << "������ ���� ����� (����, �����, ��): ";
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

    // ���������� ����� � ���� Input.txt
    std::ofstream outFile("Input.txt", std::ios::app); 
    if (outFile.is_open()) {
        outFile << "���� ��������: " << passportSeries << "\n"
            << "����� ��������: " << passportNumber << "\n"
            << "�������: " << surname << "\n"
            << "��'�: " << name << "\n"
            << "�� �������: " << patronymic << "\n"
            << "����� ������: " << roomNumber << "\n"
            << "��� ������: " << roomType << "\n"
            << "���� ����������: " << birthDay << "/" << birthMonth << "/" << birthYear << "\n"
            << "���� �����: " << checkInDay << "/" << checkInMonth << "/" << checkInYear << "\n"
            << "���� �����: " << checkOutDay << "/" << checkOutMonth << "/" << checkOutYear << "\n"
            << "----------------------------\n"; 
        outFile.close(); 
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }

    std::cout << "��� ������ ������." << std::endl;
}


// ������� ����� � �����
void Hotel::readDataFromFile(vector<Data>& data, const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        throw runtime_error("��������� ������� ����: " + fileName);
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
    cout << "��� ������� � ����� " << fileName << "." << endl;
}


// ��������� �����
void Hotel::printData(const vector<Data>& data) const {
    for (const auto& guest : data) {
        cout << "���� ��������: " << guest.getPassportSeries() << endl;
        cout << "����� ��������: " << guest.getPassportNumber() << endl;
        cout << "ϲ� �����: " << guest.getInitial()->getSurname() << " "
            << guest.getInitial()->getName() << " "
            << guest.getInitial()->getPatronymic() << endl;
        cout << "����� ������: " << guest.getRoomNumber() << endl;
        cout << "���� ����������: " << guest.getBirthDate()->getDay() << "/"
            << guest.getBirthDate()->getMonth() << "/"
            << guest.getBirthDate()->getYear() << endl;
        cout << "���� �'����: " << guest.getCheckInDate()->getDay() << "/"
            << guest.getCheckInDate()->getMonth() << "/"
            << guest.getCheckInDate()->getYear() << endl;
        cout << "���� �����: " << guest.getCheckOutDate()->getDay() << "/"
            << guest.getCheckOutDate()->getMonth() << "/"
            << guest.getCheckOutDate()->getYear() << endl;
        cout << "������: " << guest.getAddress()->getRoomType() << " "
            << guest.getRoomNumber() << endl;
    }
}



// ������ ���
void Hotel::modifyData(vector<Data>& data) {
    int roomNumber;
    cout << "������ ����� ������ ��� ���� �����: ";
    cin >> roomNumber;

    for (auto& guest : data) {
        if (guest.getRoomNumber() == roomNumber) {
            string newGuestName;
            cout << "������ ���� ��'� �����: ";
            cin >> newGuestName;
            guest.setGuestName(newGuestName);
            cout << "��� ��������." << endl;
            return;
        }
    }

    cout << "ó��� � ����� ������� ������ �� ���������." << endl;
}

// ��������� �����
void Hotel::deleteData(vector<Data>& data) {
    int roomNumber;
    cout << "������ ����� ������ ��� ���������: ";
    cin >> roomNumber;

    auto it = remove_if(data.begin(), data.end(), [roomNumber](const Data& guest) {
        return guest.getRoomNumber() == roomNumber;
        });

    if (it != data.end()) {
        data.erase(it, data.end());
        cout << "����� ��������." << endl;
    }
    else {
        cout << "ó��� � ����� ������� ������ �� ���������." << endl;
    }
}


// ���������� ����� �� ������� ������
void Hotel::sortData(vector<Data>& data) {
    sort(data.begin(), data.end(), [](const Data& a, const Data& b) {
        return a.getRoomNumber() < b.getRoomNumber();
        });
    cout << "��� ����������� �� ������� ������." << endl;
}

// ���������� ����� � ����
void Hotel::saveDataToFile(const vector<Data>& data, const string& fileName) const {
    ofstream file(fileName);
    if (!file) {
        throw runtime_error("��������� ������� ���� ��� ������: " + fileName);
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
    cout << "��� ��������� � ���� " << fileName << "." << endl;
}


// ����� ��� ������ �� ������� ������
void Hotel::searchRoom(int roomNumber, const std::vector<Data>& data) const
{
    bool found = false;
    for (const auto& record : data) {
        if (record.getRoomNumber() == roomNumber) {
            found = true;
            std::cout << "��� ��� ������ ������ " << roomNumber << ":\n";
            std::cout << "��������� ����: " << record.getPassportSeries() << "\n";
            std::cout << "����� ��������: " << record.getPassportNumber() << "\n";
            std::cout << "��'� �����: " << record.getFullName() << "\n";
            std::cout << "���� ����������: " << record.getBirthDate()->toString() << "\n"; // ����� toString ��� ������ ����
            std::cout << "������: " << record.getAddress()->toString() << "\n"; // ����� toString ��� ������ ������
            std::cout << "���� �����: " << record.getCheckInDate()->toString() << "\n";
            std::cout << "���� �����: " << record.getCheckOutDate()->toString() << "\n";
            break;
        }
    }
    if (!found) {
        std::cout << "����� ������ " << roomNumber << " �� ��������.\n";
    }
}



// ��������� ������ ����� �� �� �������
void Hotel::displayRooms() const {
    cout << "������ ����� �� �� �������:" << endl;
    cout << "��������, 101: 1000 ���/����" << endl;
    cout << "��������, 102: 1000 ���/����" << endl;
    cout << "��������, 103: 1000 ���/����" << endl;
    cout << "��������, 104: 1000 ���/����" << endl;
    cout << "����, 201: 2000 ���/����" << endl;
    cout << "����, 202: 2200 ���/����" << endl;
    cout << "����, 203: 2200 ���/����" << endl;
    cout << "��������������, 204: 2900 ���/����" << endl;
}
