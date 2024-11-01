#include "Data.h"
using namespace std;
// Конструктор за замовчуванням
Data::Data()
	: passportNumber(0), roomNumber(0) {}

// Конструктор з параметрами
Data::Data(const string& _passportSeries, int _passportNumber,
	Initial&& _surname, Date&& _birthDate,
	Address&& _address, Date&& _checkInDate,
	Date&& _checkOutDate, int _roomNumber,
	const string& _guestName)
	: passportSeries(_passportSeries),
	passportNumber(_passportNumber),
	initial(make_unique<Initial>(std::move(_surname))),  // Переміщення об'єкта
	birthDate(make_unique<Date>(std::move(_birthDate))),  // Переміщення об'єкта
	address(make_unique<Address>(std::move(_address))),    // Переміщення об'єкта
	checkInDate(make_unique<Date>(std::move(_checkInDate))), // Переміщення об'єкта
	checkOutDate(make_unique<Date>(std::move(_checkOutDate))), // Переміщення об'єкта
	roomNumber(_roomNumber){}

// Конструктор копіювання
Data::Data(const Data& other)
	: passportSeries(other.passportSeries),
	passportNumber(other.passportNumber),
	initial(make_unique<Initial>(*other.initial)),
	birthDate(make_unique<Date>(*other.birthDate)),
	address(make_unique<Address>(*other.address)),
	checkInDate(make_unique<Date>(*other.checkInDate)),
	checkOutDate(make_unique<Date>(*other.checkOutDate)),
	roomNumber(other.roomNumber),
	guestName(other.guestName) {}

// Оператор присвоєння копіювання
Data& Data::operator=(const Data& other) {
	if (this == &other) return *this; // Захист від самоприсвоєння

	passportSeries = other.passportSeries;
	passportNumber = other.passportNumber;
	initial = make_unique<Initial>(*other.initial);
	birthDate = make_unique<Date>(*other.birthDate);
	address = make_unique<Address>(*other.address);
	checkInDate = make_unique<Date>(*other.checkInDate);
	checkOutDate = make_unique<Date>(*other.checkOutDate);
	roomNumber = other.roomNumber;
	guestName = other.guestName;

	return *this;
}

// Конструктор переміщення
Data::Data(Data&& other) noexcept
	: passportSeries(std::move(other.passportSeries)),
	passportNumber(other.passportNumber),
	initial(std::move(other.initial)),
	birthDate(std::move(other.birthDate)),
	address(std::move(other.address)),
	checkInDate(std::move(other.checkInDate)),
	checkOutDate(std::move(other.checkOutDate)),
	roomNumber(other.roomNumber),
	guestName(std::move(other.guestName)) {}

// Оператор присвоєння переміщення
Data& Data::operator=(Data&& other) noexcept {
	if (this == &other) return *this; // Захист від самоприсвоєння

	passportSeries = std::move(other.passportSeries);
	passportNumber = other.passportNumber;
	initial = std::move(other.initial);
	birthDate = std::move(other.birthDate);
	address = std::move(other.address);
	checkInDate = std::move(other.checkInDate);
	checkOutDate = std::move(other.checkOutDate);
	roomNumber = other.roomNumber;
	guestName = std::move(other.guestName);

	return *this;
}

// Геттери
Initial* Data::getInitial() const { return initial.get(); }
Date* Data::getBirthDate() const { return birthDate.get(); }
Address* Data::getAddress() const { return address.get(); }
Date* Data::getCheckInDate() const { return checkInDate.get(); }
Date* Data::getCheckOutDate() const { return checkOutDate.get(); }
string Data::getPassportSeries() const { return passportSeries; }
int Data::getPassportNumber() const { return passportNumber; }
int Data::getRoomNumber() const { return roomNumber; }
string Data::getGuestName() const { return guestName; }

// Сеттери
void Data::setInitial(const Initial& _initial) { initial = make_unique<Initial>(_initial); }
void Data::setBirthDate(const Date& _birthDate) { birthDate = make_unique<Date>(_birthDate); }
void Data::setAddress(const Address& _address) { address = make_unique<Address>(_address); }
void Data::setCheckInDate(const Date& _checkInDate) { checkInDate = make_unique<Date>(_checkInDate); }
void Data::setCheckOutDate(const Date& _checkOutDate) { checkOutDate = make_unique<Date>(_checkOutDate); }
void Data::setPassportSeries(const string& _passportSeries) { passportSeries = _passportSeries; }
void Data::setPassportNumber(int _passportNumber) { passportNumber = _passportNumber; }
void Data::setRoomNumber(int _roomNumber) { roomNumber = _roomNumber; }
void Data::setGuestName(const string& _guestName) { guestName = _guestName; }

