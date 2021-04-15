#pragma once
#include "Tabuleiro.h" 
class Player
{
private :
	char Nome[50];
	Tabuleiro T;
//	Barco MB[10];
	PontoNaval Tiros[100];
public:
	Player();
	~Player();

	Tabuleiro* GetTab(){ return &T; }
};

