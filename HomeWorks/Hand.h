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
        } //�������� �� ���������� ���� � ����
        if (cards[0]->GetFaceDown())
        {
            return 0;
        } //���������� 0 ���� ������ ����� ����� �������� �����.
        int value = 0;
        std::vector<Card*>::const_iterator iter;
        for (iter = cards.begin(); iter != cards.end(); ++iter)
        {
            value += (*iter)->GetValue();
        }
        bool isAceOnHand = false; //���������� ���� �� � ���� ���
        for (iter = cards.begin(); iter != cards.end(); ++iter) {
            if ((*iter)->GetValue() == CardValue::ACE)
            {
                isAceOnHand = true;
            }
        }
        if (isAceOnHand && value <= 11) {
            value += 10;
        } // ��������� ������� ���� � ���� � ��� ����� ����� ������ ��� ������� 11, ��������� ��� �� 11 ������ ������ 1
        return value;
    } 
    ~Hand() {}
};

#endif