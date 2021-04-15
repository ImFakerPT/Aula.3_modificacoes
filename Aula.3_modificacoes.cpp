#include <iostream>
#include "Jogo.h"

using namespace std;

int main()
{
    Jogo* G;

    G = new Jogo();

    G->NewGame();

    system("pause");
}