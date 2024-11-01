#include "Initial.h"
#include <utility>

// ����������� �� �������������
Initial::Initial() : surname(""), patronymic(""), name("") {}

// ����������� � �����������
Initial::Initial(const string& _surname, const string& _patronymic, const string& _name)
    : surname(_surname), patronymic(_patronymic), name(_name) {}

// ����������� ���������
Initial::Initial(const Initial& other)
    : surname(other.surname), patronymic(other.patronymic), name(other.name) {}

// ����������� ����������
Initial::Initial(Initial&& other) noexcept
    : surname(move(other.surname)), patronymic(move(other.patronymic)), name(move(other.name)) {}

// �������
string Initial::getSurname() const { return surname; }
string Initial::getPatronymic() const { return patronymic; }
string Initial::getName() const { return name; }

// �������
void Initial::setSurname(const string& _surname) { surname = _surname; }
void Initial::setPatronymic(const string& _patronymic) { patronymic = _patronymic; }
void Initial::setName(const string& _name) { name = _name; }

// �������� ���������
Initial& Initial::operator=(const Initial& other) {
    if (this == &other) return *this; // �������� �� �������������
    surname = other.surname;
    patronymic = other.patronymic;
    name = other.name;
    return *this;
}
