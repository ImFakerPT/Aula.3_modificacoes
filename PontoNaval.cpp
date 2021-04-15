//#include "stdafx.h"
#include "PontoNaval.h"
#include <iostream>

using namespace std;

PontoNaval::PontoNaval()
{
	SetX(1);
	SetY('A');
	SetC('.');
}

PontoNaval::PontoNaval(int m_x, char m_y, char m_c)
{
	SetX(m_x);
	SetY(m_y);
	SetC(m_c);
}

PontoNaval::PontoNaval(int m_x, int m_y, char m_c)
{
	SetX(m_x);
	SetY(m_y);
	SetC(m_c);
}

PontoNaval::~PontoNaval()
{

}

bool PontoNaval::SetX(int m_x)
{
	if (m_x >= 1 && m_x <= 10) {
		x = m_x;
		return true;
	}

	cout << "Valor de X invalido" << endl;
	return false;
}

bool PontoNaval::SetY(char m_y)
{
	if (m_y >= 'A' && m_y <= 'J') {
		y = m_y;
		return true;
	}

	cout << "Valor de Y invalido" << endl;
	return false;
}

bool PontoNaval::SetY(int m_y)
{
	if (m_y >= 1 && m_y <= 10) {
		y = char(m_y + 64);
		return true;
	}

	cout << "Valor de Y invalido" << endl;
	return false;
}

bool PontoNaval::SetC(char m_c)
{
	if (m_c == 'A' || m_c == 'T' || m_c == 'O' || m_c == '.') {
		c = m_c;
		return true;
	}

	cout << "Valor de C invalido" << endl;
	return false;
}

int PontoNaval::GetIntY()
{
	int aux;
	aux = int(y) - 64;
	return aux;
}

void PontoNaval::Ask2Set(void)
{
	int aux_x = 0;
	char aux_y = ' ';
	char aux_c = '.';

	cout << "Insira um valor para X:";
	do { cin >> aux_x; } while (!SetX(aux_x));

	cout << "Insira um valor para Y:";
	do { cin >> aux_y; } while (!SetY(aux_y));

	cout << "Insira um valor para C:";
	do { cin >> aux_c; } while (!SetC(aux_c));
}

void PontoNaval::Show(void)
{
	cout << '(' << GetX() << ',' << GetY() << ')' << endl;
}

bool PontoNaval::operator == (const PontoNaval ponto) const
{
	if (GetX() == ponto.GetX() && GetY() == ponto.GetY())
		return true;

	return false;
}

bool PontoNaval::operator != (const PontoNaval ponto) const
{
	if (GetX() != ponto.GetX() || GetY() != ponto.GetY())
		return true;

	return false;
}

#pragma region  Read/Save
void PontoNaval::Save(ofstream& os)
{
	os << "(" << GetX() << "," << GetY() << "," << GetC() << ")";
}

void PontoNaval::Read(ifstream& is)
{
	char aux[3];

	is.getline(aux, 3, '(');
	is.getline(aux, 3, ',');
	SetX(atoi(aux));
	is.getline(aux, 3, ',');
	SetC(aux[0]);
	is.getline(aux, 3, ')');
	SetY(aux[0]);
}
#pragma endregion