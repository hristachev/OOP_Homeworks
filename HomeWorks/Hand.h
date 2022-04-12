#pragma once
#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>
#include <iostream>

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
            if ((*iter)->GetValue() == CardValue::ACE)
            {
                isAceOnHand = true;
            }
        }
        if (isAceOnHand && value <= 11) {
            value += 10;
        } // проверяет наличие туза в руке и при общем счете меньше или равному 11, учитывает туз за 11 баллов вместо 1
        return value;
    } 
    ~Hand() {}
};

#endif