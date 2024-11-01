#include "Initial.h"
#include <utility>

// Конструктор за замовчуванням
Initial::Initial() : surname(""), patronymic(""), name("") {}

// Конструктор з параметрами
Initial::Initial(const string& _surname, const string& _patronymic, const string& _name)
    : surname(_surname), patronymic(_patronymic), name(_name) {}

// Конструктор копіювання
Initial::Initial(const Initial& other)
    : surname(other.surname), patronymic(other.patronymic), name(other.name) {}

// Конструктор переміщення
Initial::Initial(Initial&& other) noexcept
    : surname(move(other.surname)), patronymic(move(other.patronymic)), name(move(other.name)) {}

// Геттери
string Initial::getSurname() const { return surname; }
string Initial::getPatronymic() const { return patronymic; }
string Initial::getName() const { return name; }

// Сеттери
void Initial::setSurname(const string& _surname) { surname = _surname; }
void Initial::setPatronymic(const string& _patronymic) { patronymic = _patronymic; }
void Initial::setName(const string& _name) { name = _name; }

// Оператор присвоєння
Initial& Initial::operator=(const Initial& other) {
    if (this == &other) return *this; // перевірка на самоприсвоєння
    surname = other.surname;
    patronymic = other.patronymic;
    name = other.name;
    return *this;
}
