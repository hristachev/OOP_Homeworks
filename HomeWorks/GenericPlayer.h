#pragma once
#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <iostream>
#include <string>
#include "Hand.h"


using std::string; using std::cout;

class GenericPlayer : public Hand {
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& GPlayer);
protected:
	string name;
public:
	GenericPlayer(const string& name = "");
	virtual bool IsHitting() const = 0;
	bool IsBoosted() {
		// Проверяет есть ли у игрока перебор, в случае перебора возвращает true, иначе false
		return (GetValue() > 21);
	}
	void Bust() const {
		cout << name << " too much...!\n";
	}
	virtual ~GenericPlayer() {}
};
GenericPlayer::GenericPlayer(const string& PName) : name(PName){}
std::ostream& operator<<(std::ostream& os, const GenericPlayer& GPlayer) {
	os << GPlayer.name << ":\t";
	std::vector<Card*>::const_iterator pCard;
	if (!GPlayer.cards.empty())
	{
		for (pCard = GPlayer.cards.begin(); pCard != GPlayer.cards.end(); ++pCard) {
			os << *(*pCard) << "\t";
		}
		if (GPlayer.GetValue() != 0)
		{
			cout << "[" << GPlayer.GetValue() << "]";
		}
	}
	else
	{
		os << " ";
	}
	return os;
}
#endif 