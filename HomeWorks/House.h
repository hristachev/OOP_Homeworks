#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const string& name = "Dealer") {}
	virtual bool IsHitting() const;
	void FlipFirstCard();
	virtual ~House(){}
};
bool House::IsHitting() const {
	return (GetValue() <= 16);
}
void House::FlipFirstCard() {
	if (!(cards.empty()))
	{
		cards[0]->flip();
	}
	else
	{
		cout << "No card!\n";
	}
}
#endif HOUSE_H