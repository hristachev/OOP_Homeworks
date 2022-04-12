#include <iostream>
#include <cassert>
#include <vector>
#include "Container.h"
#include "ClassCard.h"

using std::cout; using std::cin; using std::endl;

class Hand
{
    std::vector<Card*> cards;
public:
    Hand(){}
    void Add(Card* ptrCard) {
        cards.push_back(ptrCard);
    }
    void Clear() {
        std::vector<Card*>::iterator iter = cards.begin();
        while (iter != cards.end())
        {
            delete* iter;
            *iter = nullptr;
            ++iter;
        }
        cards.clear();
    }
    int GetValue() const {
        if (cards.empty()) {
            return 0;
        } //Проверка на отсутствие карт в руке
        if (cards[0]->GetFaceDown())
        {
            return 0;
        } //Возвращает 0 если первая карта лежит рубашкой вверх.
        int value = 0;
        std::vector<Card*>::const_iterator iter;
        for (iter = cards.begin(); iter != cards.end(); ++iter)
        {
            value += (*iter)->GetValue();
        }
        bool isAceOnHand = false; //определяем есть ли в руке туз
        for (iter = cards.begin(); iter != cards.end(); ++iter) {
            if ((*iter)->GetValue()==CardValue::ACE)
            {
                isAceOnHand = true;
            }
        }
        if (isAceOnHand && value <= 11) {
            value += 10;
        } // проверяет наличие туза в руке и при общем счете меньше или равному 11, учитывает туз за 11 баллов вместо 1
        return value;
    }

    ~Hand(){}

};

void printVector(std::vector<int>& array, std::vector<int>::const_iterator& print);
int different(std::vector<int>& array);

int main() {
    //TASK 1
    Container arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(20);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(3);
    arr.push_back(12);
    cout << "Array is " << arr << endl;

    arr.sort();
    cout << "Sort array is " << arr << endl;

    arr.pop_front();
    arr.pop_front();
    arr.pop_front();
    cout << "Delete 3 front elements. Array is " << arr << endl;

    arr.pop_back();
    cout << "Delete 1 last element. Array is " << arr << endl;

    cout << endl;
    //TASK 2
    std::vector<int> array{ 1,2,3,4,5,6,6 };
    std::vector<int>::const_iterator print;
    different(array);
    printVector(array, print);

	return 0;
}
int different(std::vector<int>& array) {
    int count = 0;
    for (size_t i = 0; i < array.size(); i++)
    {
        size_t j = 0;
        while (j < i && array[j] != array[i])
            ++j;
        count += j == i;
    }
    return count;
}
void printVector(std::vector<int>& array, std::vector<int>::const_iterator& print) {
    cout << "Vector is ";
    print = array.begin();
    while (print != array.end()) {
        cout << *print << ' ';
        ++print;
    }
    cout << endl << "Different values in vector: " << different(array) << endl;
}