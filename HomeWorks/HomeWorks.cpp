#include <iostream>
#include <limits>
#include <ostream>

using std::cout; using std::cin; using std::endl;
void TASKONE();
template<typename Ch, typename Tr>
inline std::basic_ostream<Ch, Tr>& endll(std::basic_ostream<Ch, Tr>& endll);

int main() {
	//TASK 1
	TASKONE();
	//TASK 2
	cout << endll << "Hi!" << endll << "BYE!";

	return 0;
}
template<typename Ch, typename Tr>
inline std::basic_ostream<Ch, Tr>& endll(std::basic_ostream<Ch, Tr>& endll) {
	return flush((endll.put(endll.widen('\n'))).put(endll.widen('\n')));
}
void TASKONE() {
	cout << "Enter your number: ";
	int num;
	while (cin.good())
	{
		cin >> num;
		if (cin.good() && cin.peek() == '\n')
		{
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cout << "OOOPS, SOMETHING WENT WRONG! Enter your integer number again: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "Your integer number is: " << num;
}