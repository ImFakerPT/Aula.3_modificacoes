#pragma once
#include "PontoNaval.h"

class Tabuleiro
{
private:
	int DimX;
	int DimY;
	PontoNaval M[10][10];

public:
	Tabuleiro();
	Tabuleiro(int mdx, int mdy);
	~Tabuleiro();

	void SetDimX(int mdx) { DimX = mdx; }
	void SetDimY(int mdy) { DimY = mdy; }
	int GetDimX() { return DimX; }
	int GetDimY() { return DimY; }

	void SetCell(int lin, int col, char m_c);
	PontoNaval GetCell(int lin, int col) { return M[lin - 1][col - 1]; }
	void SetCell(PontoNaval P) { M[P.GetX() - 1][P.GetIntY() - 1] = P; }
	PontoNaval GetCell(PontoNaval P) { return M[P.GetX() - 1][P.GetIntY() - 1]; }

	void SimbolBoxListDraw();
	void DrawFirstLine(int x0, int dxcel);
	void DrawMiddleLine(int x0, int dxcel);
	void DrawEndLine(int x0, int dxcel);
	void DrawDataLine(int line, int x0, int dxcel);
	void Draw(int x0, int y0);
	void Draw2(int x0, int y0, Tabuleiro T);
	void Save(std::ofstream& os);
	void Read(std::ifstream& is);
};

