#include <iostream>
#include <string>
//TASK1
class DivisionByZero {
public:
	DivisionByZero (std::string m_message = "") : message(m_message) {}
	const std::string& getMsg() const { return message; }
	~DivisionByZero (){}
private:
	std::string message;
};

template<typename T>
T div1(T a, T b) {
	if (b == 0)
		throw DivisionByZero("Division by ZERO!");
	return a / b;
}

//TASK 2
class Ex
{
public:
	double x;
	Ex(const double& _x) : x(_x) {}
};
class Bar
{
public:
	Bar(const double& _y = 0.0) : y(_y) {}
	void setBar(double a) {
		if ((y + a) > 100) 
			y = a; 
		else throw Ex(a * y);
			
	}
private:
	double y;
};

//TASK 3
class OffTheField
{
public:
	OffTheField(int c_x, int c_y, int n_x, int n_y) : currentX(c_x), currentY(c_y), newX(n_x), newY(n_y), msg("") {
		if (newX > 10 || newX <1 )
		{
			msg += "Coordinate X FAIL! Robot is out of field now!\n";
			msg += '[' + std::to_string(currentX) + ']' + '[' + std::to_string(currentY)
				+ "] to [" + std::to_string(newX) + ']' + '[' + std::to_string(newY) + "]\n";
		}
		if (newY > 10 || newY < 1)
		{
			msg += "Coordinate Y FAIL! Robot is out of field now!\n";
			msg += '[' + std::to_string(currentX) + ']' + '[' + std::to_string(currentY)
				+ "] to [" + std::to_string(newX) + ']' + '[' + std::to_string(newY) + "]\n";
		}
	}
	const std::string& getMsg() const { return msg; }
private:
	std::string msg;
	int currentX;
	int currentY;
	int newX;
	int newY;
};
class IllegalCommand
{
public:
	IllegalCommand(int c_x, int c_y, int n_x, int n_y) : currentX(c_x), currentY(c_y), newX(n_x), newY(n_y), msg("") {
		if (abs(currentX - newX) > 1)
		{
			msg += "Coordinate X FAIL! Step is too big!\n";
			msg += '[' + std::to_string(currentX) + ']' + '[' + std::to_string(currentY)
				+ "] to [" + std::to_string(newX) + ']' + '[' + std::to_string(newY) + "]\n";
		}
		if (abs(currentY - newY) > 1)
		{
			msg += "Coordinate Y FAIL! Step is too big!\n";
			msg += '[' + std::to_string(currentX) + ']' + '[' + std::to_string(currentY)
				+ "] to [" + std::to_string(newX) + ']' + '[' + std::to_string(newY) + "]\n";
		}
		if (currentX == newX && currentY == newY)
		{
			msg += "Coordinate X and Y FAIL! You can't step into the current location!\n";
			msg += '[' + std::to_string(currentX) + ']' + '[' + std::to_string(currentY)
				+ "] to [" + std::to_string(newX) + ']' + '[' + std::to_string(newY) + "]\n";
			
		}
	}
	const std::string& getMsg() const { return msg; }
	~IllegalCommand(){}
private:
	std::string msg;
	int currentX;
	int currentY;
	int newX;
	int newY;
};
class Robot
{
public:
	Robot(int x = 0, int y = 0) : posX(x), posY(y) {
		std::cout << "Starter position is: [" << posX << "]|[" << posY << "]\n";
	}
	void move(int x, int y) {
		if (abs(posX - x) > 1 || abs(posY - y) > 1 || (posX == x && posY == y))
			throw IllegalCommand(posX, posY, x, y);
		if (x > 10 || x < 1 || y > 10 || y < 1)
			throw OffTheField(posX, posY, x, y);
		std::cout << "Robot is step from [" << posX << '|' << posY << "] to ["
				  << x << '|' << y << "]\n";
		posX = x;
		posY = y;
	}
	~Robot() {}
private:
	int posX;
	int posY;
};

int main() {
	//TASK1
	int x1, y1;
	std::cout << "Enter 2 numbers: ";
	std::cin >> x1 >> y1;
	try
	{
		std::cout << div1(x1, y1) << "\n";
	}
	catch (const DivisionByZero& a)
	{
		std::cerr << a.getMsg() << "\n";
	}

	//TASK2 
	Bar b;
	int n;
	while (true){
		std::cout << "\n[Task 2]\nEnter a number: ";
		try
		{
			if (std::cin >> n && n != 0)
				b.setBar(n);
			break;
		}
		catch (const Ex& ex)
		{
			std::cout << "Exception: " << ex.x << "\n";
		}

	}
	//TASK 3
	int numX, numY;
	Robot r;
	while (true)
	{
		std::cout << "Enter coordinate X and Y: ";
		std::cin >> numX >> numY;

		if (numX == 0 && numY == 0)
			break;
		try
		{
			r.move(numX, numY);
		}
		catch (const IllegalCommand& exept)
		{
			std::cout << exept.getMsg() << '\n';
		}
		catch (const OffTheField& exept) 
		{
			std::cout << exept.getMsg() << '\n';
		}

	}
	
	return 0;
}