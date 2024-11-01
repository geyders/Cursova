#pragma once
#include <string>

class Address {
private:
    std::string roomType;
    int roomNumber;

public:
    // Конструктори
    Address();
    Address(const std::string& _roomType, int _roomNumber);
    Address(const Address& other);
    Address(Address&& other) noexcept;

    // Деструктор
    ~Address();

    // Геттери
    std::string getRoomType() const;
    int getRoomNumber() const;

    // Сеттери
    void setRoomType(const std::string& _roomType);
    void setRoomNumber(int _roomNumber);

    // Оператор присвоєння
    Address& operator=(const Address& other);

    // Метод для перетворення адреси в рядок
    std::string toString() const;
};

