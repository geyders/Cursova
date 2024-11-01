#pragma once
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // ������������
    Date();
    Date(int _day, int _month, int _year);
    Date(const Date& other);
    Date(Date&& other) noexcept;

    // �������
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // �������
    void setDay(int _day);
    void setMonth(int _month);
    void setYear(int _year);

    // �������� ���������
    Date& operator=(const Date& other);

    // ����� ��� ������������ ���� � �����
    std::string toString() const;
};
