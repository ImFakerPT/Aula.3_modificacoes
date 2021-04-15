#include "Jogo.h"
#include "PontoNaval.h"
#include <iostream>
using namespace std;

Jogo::Jogo()
{

}

Jogo::~Jogo()
{

}

void Jogo::NewGame()
{
	PontoNaval P1(1, 1, 'O'), P2(5, 'B', 'T'), P3(5, 'C', 'O'), P4(10, 'J', 'O');
	cout << "Jogo Batalha Naval 2020/2021\n\n\n";
	Player1.GetTab()->SetCell(P1);
	Player1.GetTab()->SetCell(P2);
	Player1.GetTab()->SetCell(P3);

	Player2.GetTab()->SetCell(P1);
	Player2.GetTab()->SetCell(P2);
	Player2.GetTab()->SetCell(P4);

	Player1.GetTab()->Draw2(5, 4, *(Player2.GetTab()));

	Save("player.txt");
}

#pragma region  Read/Save
void Jogo::Save(string file)
{
	// Exemplo para escrever nm ficheiro os pontos de um tabuleiro com tiros e Barcos/Navios
	// Quando criarem a classe Jogador, deve ter um array do tipo "PontoNaval" com os seus "Tiros" dados e outro com os seus "Barcos/Navios", devem usar estes arrays para escrever no ficheiro e não o tabuleiro
	PontoNaval P;
	ofstream os;

	os.open(file);

	Player1.GetTab()->Save(os);

	os.close();
}

void Jogo::Read(string file)
{

}
#pragma region