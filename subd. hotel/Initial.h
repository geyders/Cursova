#pragma once
#include <string>
#ifndef INITIAL_H
#define INITIAL_H
using namespace std;

class Initial {
private:
    string surname;
    string patronymic;
    string name;

public:
    // Конструктор за замовчуванням
    Initial();

    // Конструктор з параметрами
    Initial(const string& _surname, const string& _patronymic, const string& _name);

    // Конструктор копіювання
    Initial(const Initial& other);

    // Конструктор переміщення
    Initial(Initial&& other) noexcept;

    // Геттери
    string getSurname() const;
    string getPatronymic() const;
    string getName() const;

    // Сеттери
    void setSurname(const string& _surname);
    void setPatronymic(const string& _patronymic);
    void setName(const string& _name);

    // Оператор присвоєння
    Initial& operator=(const Initial& other);
};
#endif // INITIAL_H