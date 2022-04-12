#pragma once
#ifndef CARD_H
#define CARD_H

#include <iostream>

using std::cout;

enum Suit : char { HEARTS = 3, DIAMONDS = 4, CLUBS = 5, SPADES = 6 };// HEARTS = �����, DIAMONDS = ����, CLUBS = �����, SPADES = ����, ������ ����� ������������� ��� ����, ���������� � ������� � �������
enum CardValue { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
class Card {
private:
	Suit suit;
	CardValue cardValue;
	bool faceDown; // faceDown - ������� �����
public:
	Card(Suit suit, CardValue value, bool faceDown = true) : suit(suit), cardValue(value), faceDown(faceDown) {
		this->suit = suit;
		this->faceDown = faceDown;
		if (faceDown)
			cout << "Card value is " << cardValue << ", suit is " << suit << " and face down!\n";
		else
			cout << "Card value is " << cardValue << ", suit is " << suit << " and face up!\n";
	}
	bool GetFaceDown() { return faceDown; }
	CardValue GetValue() { return cardValue; }
	Suit GetSuit() { return suit; }
	void flip() {
		faceDown = !faceDown;
		if (faceDown)
			cout << "Card is flipped and face down now!\n";
		else
			cout << "Card is flipped and face up now!\n";
	}
	~Card() {}
};
#endif