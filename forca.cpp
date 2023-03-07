#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "logica.hpp"
#include "GerenciaArquivo.hpp"
#include "GerenciaChutes.hpp"
#include "mostrarInfo.hpp"

using namespace std;

map<char, bool> chutou;
vector<char> ChutesErrados;
string PalavraSecreta;

int main(int argc, char const *argv[])
{
    MostraCabecalho();

    sorteiaPalavra();

    while (!Acertou(PalavraSecreta) && !enforcou())
    {
        MostraChutesErrados();

        MostraPalavra(PalavraSecreta);

        GerenciarChutes(PalavraSecreta);
    }

    cout << "fim de jogo!!" << endl;
    cout << "A palavra secreta era " << PalavraSecreta << endl;
    if (Acertou(PalavraSecreta))
    {
        char resposta;

        cout << "Parabens!! Você acertou a palavra correta!!" << endl;
        cout << "Você deseja adicionar uma nova palavra ao banco?(S/N): ";

        cin >> resposta;

        if (toupper(resposta) == 'S')
        {
            adicionaPalavra();
        }
    }
    else
    {
        cout << "Você Perdeu, tente novamente." << endl;
    }

    return 0;
}
