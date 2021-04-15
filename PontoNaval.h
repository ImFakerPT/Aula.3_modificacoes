#pragma once

#include <fstream>

class PontoNaval
{
private:
	int x; // 1...10
	char y; // A...J
	char c; // carteres possíveis '.' 'O' 'T' 'A'

public:
	PontoNaval();
	PontoNaval(int m_x, char m_y, char m_c);
	PontoNaval(int m_x, int m_y, char m_c);
	~PontoNaval();

	bool SetX(int m_x);
	bool SetY(char m_y);
	bool SetY(int m_y);
	bool SetC(char m_c);

	int GetX() const { return x; }
	char GetY() const { return y; }
	int GetIntY();
	char GetC() const { return c; }

	void Ask2Set(void);
	void Show();

	bool operator == (const PontoNaval ponto) const;
	bool operator != (const PontoNaval ponto) const;


	void Save(std::ofstream& os);
	void Read(std::ifstream& is);
};

