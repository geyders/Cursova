#pragma once
#include <string>

class Address {
private:
    std::string roomType;
    int roomNumber;

public:
    // ������������
    Address();
    Address(const std::string& _roomType, int _roomNumber);
    Address(const Address& other);
    Address(Address&& other) noexcept;

    // ����������
    ~Address();

    // �������
    std::string getRoomType() const;
    int getRoomNumber() const;

    // �������
    void setRoomType(const std::string& _roomType);
    void setRoomNumber(int _roomNumber);

    // �������� ���������
    Address& operator=(const Address& other);

    // ����� ��� ������������ ������ � �����
    std::string toString() const;
};

