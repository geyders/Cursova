#include "Date.h"
#include <iomanip>
#include <sstream>

// Конструктор за замовчуванням
Date::Date() : day(1), month(1), year(2000) {}

// Конструктор з параметрами
Date::Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

// Конструктор копіювання
Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

// Конструктор переміщення
Date::Date(Date&& other) noexcept : day(other.day), month(other.month), year(other.year) {
    other.day = 0;
    other.month = 0;
    other.year = 0;
}

// Геттери
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

// Сеттери
void Date::setDay(int _day) { day = _day; }
void Date::setMonth(int _month) { month = _month; }
void Date::setYear(int _year) { year = _year; }

// Оператор присвоєння
Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

// Метод для перетворення дати в рядок
std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << "/"
        << std::setw(2) << std::setfill('0') << month << "/"
        << year;
    return oss.str();
}
