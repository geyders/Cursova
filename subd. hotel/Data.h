#pragma once
#include <memory>
#include <string>
#include "Initial.h"
#include "Date.h"
#include "Address.h"

using namespace std;

class Data {
private:
    unique_ptr<Initial> initial;
    string passportSeries;
    int passportNumber;
    unique_ptr<Date> birthDate;
    unique_ptr<Address> address;
    unique_ptr<Date> checkInDate;
    unique_ptr<Date> checkOutDate;
    int roomNumber;
    string guestName;

public:
    // Конструктор за замовчуванням
    Data();

    // Конструктор з параметрами
    Data(const string& _passportSeries, int _passportNumber,
        Initial&& _initial, Date&& _birthDate,
        Address&& _address, Date&& _checkInDate,
        Date&& _checkOutDate, int _roomNumber,
        const string& _guestName);

    // Конструктор копіювання
    Data(const Data& other);

    // Оператор присвоєння копіювання
    Data& operator=(const Data& other);

    // Конструктор переміщення
    Data(Data&& other) noexcept;

    // Оператор присвоєння переміщення
    Data& operator=(Data&& other) noexcept;

    // Геттери
    Initial* getInitial() const;
    Date* getBirthDate() const;
    Address* getAddress() const;
    Date* getCheckInDate() const;
    Date* getCheckOutDate() const;
    string getPassportSeries() const;
    int getPassportNumber() const;
    int getRoomNumber() const;
    string getGuestName() const;

    string getSurname() const {
        return initial ? initial->getSurname() : ""; 
    }

    string getName() const {
        return initial ? initial->getName() : ""; 
    }

    string getPatronymic() const {
        return initial ? initial->getPatronymic() : ""; 
    }

    string getFullName() const {
        return getSurname() + " " + getName() + " " + getPatronymic();
    }

    // Сеттери
    void setInitial(const Initial& _initial);
    void setBirthDate(const Date& _birthDate);
    void setAddress(const Address& _address);
    void setCheckInDate(const Date& _checkInDate);
    void setCheckOutDate(const Date& _checkOutDate);
    void setPassportSeries(const string& _passportSeries);
    void setPassportNumber(int _passportNumber);
    void setRoomNumber(int _roomNumber);
    void setGuestName(const string& _guestName);
};

