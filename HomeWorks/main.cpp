#include <iostream>

class Date {
	int day, month, year;
public:
	Date(int dDay=1, int mMonth=1, int yYear=2000) : day(dDay), month(mMonth), year(yYear) {}
	void setDay(int day) { this->day = day; }
	void setMonth(int month) { this->day = day; }
	void setYear(int year) { this->day = day; }
	const int& getDay() const { return day; }
	const int& getMonth() const { return month; }
	const int& getYear() const { return year; }
	friend std::ostream& operator<< (std::ostream& os, const Date& date) {
		os << "Date: " << date.day << " | " << date.month << " | " << date.year << "\n";
		return os;
	}
};
template <typename T>
class pointer {
	T* tPtr;
public:
	pointer(T* ptr = nullptr) : tPtr(ptr){}
	pointer(pointer& ptr) { 
		tPtr = ptr.tPtr;
		ptr.tPtr = nullptr;
	}
	~pointer() { delete tPtr; }
	bool isNull() const { return tPtr == nullptr; }
	pointer& operator= (pointer& tP) {
		if (&tP == this)
			return *this;

		delete tPtr;
		tPtr = tP.tPtr;
		tP.tPtr = nullptr;
		return *this;
	}
	T* operator->() const { return tPtr; }
	T& operator* () const { return *tPtr; }
};
const pointer<Date>& compare(const pointer<Date>& a, const pointer<Date>& b) {
	if (a->getYear() > b->getYear())
		return a;
	else if (a->getYear() < b->getYear())
		return b;
	else {
		if (a->getMonth() > b->getMonth())
			return a;
		else if (a->getMonth() < b->getMonth())
			return b;
		else
		{
			if (a->getDay() > b->getDay())
				return a;
			else if (a->getDay() < b->getDay())
				return b;
			else
				std::cout << "Same date!!!\n";
		}
	}
}

void swap(pointer<Date>& a, pointer<Date>& b) {
	pointer<Date> val;
	val = a;
	a = b;
	b = val;
}

int main() {
	//TASK 1
	pointer<Date> today(new Date(19, 04, 2022));
	pointer<Date> date;
	std::cout << "Date: " << today->getDay() << " | " << today->getMonth() << " | " << today->getYear() << "\n";
	std::cout << "[Today]\n" << *today;
	std::cout << "Today? " << (today.isNull() ? "is null!\n" : "isn't null!\n");
	std::cout << "Date? " << (date.isNull() ? "is null!\n" : "isn't null!\n");
	date = today;
	std::cout << "Today? " << (today.isNull() ? "is null!\n" : "isn't null!\n");
	std::cout << "Date? " << (date.isNull() ? "is null!\n" : "isn't null!\n");

	std::cout << *date << "\n";
	//TASK 2
	pointer<Date> date1(new Date(27, 11, 2019));
	pointer<Date> date2(new Date(29, 11, 2019));
	pointer<Date> date3(new Date(18, 03, 2010));
	std::cout << *compare(date1, date2);
	swap(date2, date3);
	std::cout << *compare(date1, date2);

	return 0;
}