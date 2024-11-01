#include "Address.h"
#include <utility>
#include <sstream>

// Конструктор за замовчуванням
Address::Address() : roomType("Unknown"), roomNumber(0) {}

// Конструктор з параметрами
Address::Address(const std::string& _roomType, int _roomNumber)
    : roomType(_roomType), roomNumber(_roomNumber) {}

// Конструктор копіювання
Address::Address(const Address& other)
    : roomType(other.roomType), roomNumber(other.roomNumber) {}

// Конструктор переміщення
Address::Address(Address&& other) noexcept
    : roomType(std::move(other.roomType)), roomNumber(other.roomNumber) {
    other.roomNumber = 0;
}

// Деструктор
Address::~Address() = default;

// Геттери
std::string Address::getRoomType() const { return roomType; }
int Address::getRoomNumber() const { return roomNumber; }

// Сеттери
void Address::setRoomType(const std::string& _roomType) { roomType = _roomType; }
void Address::setRoomNumber(int _roomNumber) { roomNumber = _roomNumber; }

// Оператор присвоєння
Address& Address::operator=(const Address& other) {
    if (this != &other) {
        roomType = other.roomType;
        roomNumber = other.roomNumber;
    }
    return *this;
}

// Метод для перетворення адреси в рядок
std::string Address::toString() const {
    std::ostringstream oss;
    oss << "Тип кімнати: " << roomType << ", Номер кімнати: " << roomNumber;
    return oss.str();
}
