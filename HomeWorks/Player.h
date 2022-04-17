#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "GenericPlayer.h"
using std::cin;

class Player : public GenericPlayer
{
public:
	Player(const string& name = "") {}
	virtual bool IsHitting() const;
	void Win() const {
		cout << name << " win!\n";
	}
	void Lose() const {
		cout << name << " lose!\n";
	}
	void Push() const {
		cout << name << " push.\n";
	}
	virtual ~Player(){}
};
bool Player::IsHitting() const {
	cout << name << ", do you want a hit? (Y/N): ";
	char ask;
	cin >> ask;
	return (ask == 'y' || ask == 'Y');
}
#endif PLAYER_H