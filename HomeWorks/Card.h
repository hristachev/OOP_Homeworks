#pragma once
#ifndef CARD_H
#define CARD_H

#include <iostream>

using std::cout;

enum Suit : char { HEARTS = 3, DIAMONDS = 4, CLUBS = 5, SPADES = 6 };// HEARTS = черви, DIAMONDS = буби, CLUBS = трефы, SPADES = пики, сделал такую инициализацию для себя, поиграться с выводом в консоль
enum CardValue { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
class Card {
private:
	Suit suit;
	CardValue cardValue;
	bool faceDown; // faceDown - рубашка вверх
public:
	Card(Suit suit, CardValue value, bool faceDown = true) : suit(suit), cardValue(value) {	this->suit = suit;}
	bool GetFaceDown() { return faceDown; }
	CardValue GetValue() { return cardValue; }
	Suit GetSuit() { return suit; }
	void flip() {
		faceDown = !faceDown;
	}
	friend std::ostream& operator<<(std::ostream& os, const Card& Card);
	~Card() {}
};
std::ostream& operator<<(std::ostream& os, const Card& Card) {
	const string suits[]{"H", "D", "C", "S"};
	const string CValues[]{ "0","A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	if (!Card.faceDown)
		os << CValues[Card.cardValue] << suits[Card.suit];
	else
		os << "XX";
}
#endif 