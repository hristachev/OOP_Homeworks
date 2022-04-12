#pragma once
#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <iostream>
#include <string>
#include "Hand.h"

 
using std::string; using std::cout;

class GenericPlayer : public Hand {
	string name;
public:
	GenericPlayer(const string& name) : name(name) { this->name = name; }
	
	virtual void IsHitting() const = 0;
	bool IsBoosted() {
	 // ���� ����� ����� ���� � ������ ������ 21 = �������, ���������� true. � ��������� ������� false.
		return (GetValue() > 21);
	}
	void Bust() const {
		cout << name << " too much...!\n";
	}
	virtual ~GenericPlayer(){}
};
#endif