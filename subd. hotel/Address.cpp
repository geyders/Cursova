#include "Address.h"
#include <utility>
#include <sstream>

// ����������� �� �������������
Address::Address() : roomType("Unknown"), roomNumber(0) {}

// ����������� � �����������
Address::Address(const std::string& _roomType, int _roomNumber)
    : roomType(_roomType), roomNumber(_roomNumber) {}

// ����������� ���������
Address::Address(const Address& other)
    : roomType(other.roomType), roomNumber(other.roomNumber) {}

// ����������� ����������
Address::Address(Address&& other) noexcept
    : roomType(std::move(other.roomType)), roomNumber(other.roomNumber) {
    other.roomNumber = 0;
}

// ����������
Address::~Address() = default;

// �������
std::string Address::getRoomType() const { return roomType; }
int Address::getRoomNumber() const { return roomNumber; }

// �������
void Address::setRoomType(const std::string& _roomType) { roomType = _roomType; }
void Address::setRoomNumber(int _roomNumber) { roomNumber = _roomNumber; }

// �������� ���������
Address& Address::operator=(const Address& other) {
    if (this != &other) {
        roomType = other.roomType;
        roomNumber = other.roomNumber;
    }
    return *this;
}

// ����� ��� ������������ ������ � �����
std::string Address::toString() const {
    std::ostringstream oss;
    oss << "��� ������: " << roomType << ", ����� ������: " << roomNumber;
    return oss.str();
}
