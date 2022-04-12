#include <iostream>
#include <string>


using std::cout; using std::cin; using std::endl;
//TASK 1
template<typename T>
class Pair1 {
	T vFirst;
	T vSecond;
public:
	Pair1(const T& first, const T& second) : vFirst(first), vSecond(second) {}
	const T& first() const { return vFirst; }
	const T& second() const { return vSecond; }
};
//TASK 2
template<typename T1, typename T2>
class Pair {
	T1 vFirst;
	T2 vSecond;
public:
	Pair(const T1& first, const T2& second) : vFirst(first), vSecond(second) {}
	const T1& first() const { return vFirst; }
	const T2& second() const { return vSecond; }
};
//TASK 3
template<typename T3>
class StringValuePair : public Pair<std::string, T3> {
public:
	StringValuePair(const std::string & first, const T3 & second) : Pair<std::string, T3>(first, second) {}
};

int main() {
	//TASK 1
	Pair1<int> pP1(6, 9);
	cout << "Pair: " << pP1.first() << ' ' << pP1.second() << '\n';

	const Pair1<double> pP2(3.4, 7.8);
	cout << "Pair: " << pP2.first() << ' ' << pP2.second() << '\n';
	cout << endl;
	//TASK 2
	Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	cout << endl;
	//TASK 3
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	cout << endl;

	return 0;
}