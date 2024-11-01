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
    // ����������� �� �������������
    Initial();

    // ����������� � �����������
    Initial(const string& _surname, const string& _patronymic, const string& _name);

    // ����������� ���������
    Initial(const Initial& other);

    // ����������� ����������
    Initial(Initial&& other) noexcept;

    // �������
    string getSurname() const;
    string getPatronymic() const;
    string getName() const;

    // �������
    void setSurname(const string& _surname);
    void setPatronymic(const string& _patronymic);
    void setName(const string& _name);

    // �������� ���������
    Initial& operator=(const Initial& other);
};
#endif // INITIAL_H