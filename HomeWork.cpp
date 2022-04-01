#include <iostream>

using std::cout; using std::cin; using std::endl;

class Person
{
private:
	std::string name;
	std::string sex;
	int age;
	double weight;
public:
	Person(std::string name, int age, std::string sex, double weight) {
		this->name = name;
		this->sex = sex;
		this->age = age;
		this->weight = weight;
	}
	~Person() {}
	void setName(std::string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setWeight(double weight) { this->weight = weight; }
	std::string getName() const { return name; }
	std::string getSex() const { return sex; }
	int getAge() const { return age; }
	double getWeight() const { return weight; }
};
class Student : public Person
{
private:
	static int counter;
	int edcYears;
public:
	Student(std::string name, int age, std::string sex, double weight, int edcYears) : Person(name, age, sex, weight), edcYears(edcYears) { ++counter; }
	~Student() { --counter; }
	int setYears(int year) { edcYears = year; }
	int getYears() { return edcYears; }
	void incYears(int year) { edcYears += year; }
	void info() {
		printf("%s | %d years old | Sex is %s | %d year of education | Weight is: %.2f\n", getName().c_str(), getAge(), getSex().c_str(), getYears(), getWeight());
	}
	static int objectCount() { return counter; }
};

int Student::counter = 0;
void countInfo() {
	cout << "We made " << Student::objectCount() << " objects!!!\n";
}

class Fruit
{
private:
	std::string name;
	std::string color;
public:
	Fruit(std::string name, std::string color) : name(name), color(color) {}
	~Fruit() {}
	void setName(std::string name) { this->name = name; }
	void setColor(std::string color) { this->color = color; }
	std::string getName() const { return name; }
	std::string getColor() const { return color; }
};
class Apple : public Fruit {
public:
	Apple(std::string color, std::string name = "apple") : Fruit(name, color) {}
	~Apple() {}
};
class Banana : public Fruit {
public:
	Banana(std::string name = "banana", std::string color = "yellow") : Fruit(name, color) {}
	~Banana() {}
};
class GrannySmith : public Apple {
public:
	GrannySmith(std::string name = "Granny Smith apple", std::string color = "green") : Apple(color, name) {}
	~GrannySmith() {}
};

int main()
{
	//TASK 1
	countInfo();
	Student s1("Anton", 23, "male", 80.1, 2020);
	Student s2("Elena", 26, "female", 65.31, 2019);
	countInfo();
	s1.info();
	s2.info();
	s2.incYears(3); s2.setWeight(72.1); s2.setAge(29);
	s2.info();

	Student* ptrS1;
	ptrS1 = new Student("Evgenij", 33, "male", 79.3, 2021);
	ptrS1->info();
	countInfo();
	delete ptrS1;
	countInfo();
	cout << endl;

	//TASK 2
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	//TASK 3
	/* Для игры в blackjack нам необходимо три вида объекта.
		1. Карты
		2. Игрок
		3. Дилер
		(дополнительно можно добавить какие либо ОЧКИ/ФИШКИ)
	Соответсвенно нужны такие классы:
		1. Класс Person (родительский класс,)
		Классы Dealer и Player дочерние от Person
		2. Класс Card (номинал карты, масть)
		3. Класс Deck (колода: массив из карт)
		4. Игровой класс (текущее состояние игры и правила)
		5?(доп. Класс для очков/фишек)
			*/

	return 0;
}