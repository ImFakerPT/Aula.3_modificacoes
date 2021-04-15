#include "Tabuleiro.h"
#include <iostream>
#include <fstream>

using namespace std;

Tabuleiro::Tabuleiro()
{
	int i, j;
	PontoNaval P;
	SetDimX(10);
	SetDimY(10);

	for (i = 1; i <= GetDimY(); i++)
		for (j = 1; j <= GetDimX(); j++) {
			P.SetY(i);
			P.SetX(j);
			P.SetC('.');
			SetCell(P);
		}
}

Tabuleiro::Tabuleiro(int mdx, int mdy)
{
	int i, j;
	PontoNaval P;
	SetDimX(mdx);
	SetDimY(mdy);

	for (i = 1; i <= GetDimY(); i++)
		for (j = 1; j <= GetDimX(); j++) {
			P.SetY(i);
			P.SetX(j);
			P.SetC('.');
			SetCell(P);
		}
}

Tabuleiro::~Tabuleiro()
{
}

void Tabuleiro::SimbolBoxListDraw()
{
	cout << endl << endl;
	cout << "tabela ASCII e Extendida para as box";
	cout << endl << endl;

	int tabela[] =
	{ 185,186,187,188,200,201,202,203,204,206,
	191,192,217,218,179,196,193,194,195,197,221,180,
	45,47,60,62,88,91,92,93,94,95,238,240,
	30,31,176,177,178,219,220,223,254,
	59,123,124,125,143,205,189,190,207,241,242,245,249,46,58,61,127,174,175,145 };
	int j = 0;


	for (int i = 0; i < 62; i++)
	{
		cout << tabela[i] << '\t' << (char)tabela[i] << '\t';
		j++;
		if (j == 5) {
			cout << endl << endl;
			j = 0;
		}
	}
}

void Tabuleiro::DrawFirstLine(int x0, int dxcel)
{
	int i, j;

	for (i = 0; i < x0 + 2; i++)
		cout << " ";

	cout << char(218);
	for (j = 0; j < GetDimX(); j++) {
		for (i = 0; i < dxcel; i++)
			cout << char(196);
		if (j < GetDimX() - 1) {
			cout << char(194);
		}
	}
	cout << char(191);
}

void Tabuleiro::DrawMiddleLine(int x0, int dxcel)
{
	int i, j;

	for (i = 0; i < x0 + 2; i++)
		cout << " ";

	cout << char(195);
	for (j = 0; j < GetDimX(); j++) {
		for (i = 0; i < dxcel; i++)
			cout << char(196);
		if (j < GetDimX() - 1) {
			cout << char(197);
		}
	}
	cout << char(180);
}

void Tabuleiro::DrawEndLine(int x0, int dxcel)
{
	int i, j;

	for (i = 0; i < x0 + 2; i++)
		cout << " ";

	cout << char(192);
	for (j = 0; j < GetDimX(); j++) {
		for (i = 0; i < dxcel; i++)
			cout << char(196);
		if (j < GetDimX() - 1) {
			cout << char(193);
		}
	}
	cout << char(217);
}

void Tabuleiro::DrawDataLine(int line, int x0, int dxcel)
{
	int i;

	for (i = 0; i < x0; i++)
		cout << " ";

	if (line > 9) cout << line; //Escreve o número da linha
	else cout << line << " ";

	for (i = 1; i <= GetDimX(); i++) {
		cout << char(179);
		cout << " " << GetCell(line, i).GetC() << " ";
	}

	cout << char(179);
}

void Tabuleiro::Draw(int x0, int y0)
{
	int i, l, dxtab, dytab, dxcel; // , dycel;
//	dycel = 1;		
	dxcel = 3;
	dxtab = 4 * GetDimX();
	dytab = 1 * GetDimY();

	for (i = 0; i < y0; i++) // Linhas iniciais em branco
		cout << '\n';

	for (i = 0; i < x0 + 2; i++) // Colunas iniciais em branco
		cout << " ";

	for (i = 0; i < GetDimX(); i++) // Escreve as letras
		cout << "  " << char(65 + i) << " ";

	cout << '\n';

	// Draw first line
	DrawFirstLine(x0, dxcel);
	cout << '\n';
	DrawDataLine(1, x0, dxcel);
	cout << '\n';

	//Draw middle lines
	for (l = 2; l <= GetDimY(); l++) {
		DrawMiddleLine(x0, dxcel);
		cout << '\n';
		DrawDataLine(l, x0, dxcel);
		cout << '\n';
	}

	// Draw last line
	DrawEndLine(x0, dxcel);
	cout << '\n' << '\n';
}

void Tabuleiro::Draw2(int x0, int y0, Tabuleiro T)
{
	int i, l, dxtab, dytab, dxcel; // , dycel;
//	dycel = 1;		
	dxcel = 3;
	dxtab = 4 * GetDimX();
	dytab = 1 * GetDimY();

	for (i = 0; i < y0; i++) // Linhas iniciais em branco
		cout << '\n';

	for (l = 0; l < 2; l++) {
		for (i = 0; i < x0 + 2; i++) // Colunas iniciais em branco
			cout << " ";

		for (i = 0; i < GetDimX(); i++) // Escreve as letras
			cout << "  " << char(65 + i) << " ";
	}
	cout << '\n';

	// Draw first line
	DrawFirstLine(x0, dxcel);
	T.DrawFirstLine(x0, dxcel);
	cout << '\n';
	DrawDataLine(1, x0, dxcel);
	T.DrawDataLine(1, x0, dxcel);
	cout << '\n';

	//Draw middle lines
	for (l = 2; l <= GetDimY(); l++) {
		DrawMiddleLine(x0, dxcel);
		T.DrawMiddleLine(x0, dxcel);
		cout << '\n';
		DrawDataLine(l, x0, dxcel);
		T.DrawDataLine(l, x0, dxcel);
		cout << '\n';
	}

	// Draw last line
	DrawEndLine(x0, dxcel);
	T.DrawEndLine(x0, dxcel);
	cout << '\n' << '\n';
}

void Tabuleiro::SetCell(int m_y, int m_x, char m_c)
{
	M[m_y - 1][m_x - 1].SetY(m_y);
	M[m_y - 1][m_x - 1].SetX(m_x);
	M[m_y - 1][m_x - 1].SetC(m_c);
}


#pragma region  Read/Save
void Tabuleiro::Save(ofstream& os)
{
	// Exemplo para escrever nm ficheiro os pontos de um tabuleiro com tiros
	int i, j;

	for (i = 1; i <= GetDimY(); i++) {
		for (j = 1; j <= GetDimX(); j++) {
			if (GetCell(i, j).GetC() != '.') {
				GetCell(i, j).Save(os);
			}
		}
	}
}

void Tabuleiro::Read(ifstream& is)
{

}
#pragma endregion
