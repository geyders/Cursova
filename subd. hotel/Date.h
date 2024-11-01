#pragma once
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Конструктори
    Date();
    Date(int _day, int _month, int _year);
    Date(const Date& other);
    Date(Date&& other) noexcept;

    // Геттери
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Сеттери
    void setDay(int _day);
    void setMonth(int _month);
    void setYear(int _year);

    // Оператор присвоєння
    Date& operator=(const Date& other);

    // Метод для перетворення дати в рядок
    std::string toString() const;
};
