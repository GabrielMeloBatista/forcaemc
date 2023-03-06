#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

map<char, bool> chutou;
vector<char> ChutesErrados;
string PalavraSecreta;

bool LetraExiste(char chute, string PalavraSecreta)
{
    for (char letra : PalavraSecreta)
    {
        if (chute == letra)
        {
            return true;
        }
    }

    return false;
}

bool Acertou(string PalavraSecreta)
{
    for (char letra : PalavraSecreta)
    {
        if (!chutou[letra])
        {
            return false;
        }
    }
    return true;
}

bool enforcou()
{
    return ChutesErrados.size() > 5;
}

void MostraCabecalho()
{
    cout << "*********************" << endl;
    cout << "*** Jogo da forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void MostraChutesErrados()
{
    if (ChutesErrados.size() > 0)
    {
        cout << "Chutes errados: ";
        for (char letra : ChutesErrados)
        {
            cout << letra << " ";
        }
        cout << endl;
    }
}

void MostraPalavra(string PalavraSecreta)
{
    for (char letra : PalavraSecreta)
    {
        if (chutou[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

void GerenciarChutes(string PalavraSecreta)
{
    char chute;
    cout << "Seu chute: ";
    cin >> chute;
    chute = toupper(chute);
    chutou[chute] = true;

    if (LetraExiste(chute, PalavraSecreta))
    {
        cout << "Seu chute está na palavra." << endl;
    }
    else
    {
        cout << "Seu chute não esta na palavra." << endl;
        ChutesErrados.push_back(chute);
    }
    cout << endl;
}

vector<string> LerArquivo()
{
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {

        vector<string> PalavrasArquivos;
        string palavraLida;
        int qtdPalavras;

        arquivo >> qtdPalavras;

        for (int i = 0; i < qtdPalavras; i++)
        {
            arquivo >> palavraLida;
            PalavrasArquivos.push_back(palavraLida);
        }

        arquivo.close();
        return PalavrasArquivos;
    }
    else
    {
        cout << "Não foi possivel encontrar arquivo de palavras" << endl;
        exit(0);
    }
}

void sorteiaPalavra()
{
    vector<string> palavras = LerArquivo();
    srand(time(NULL));
    int indiceSorteado = rand() % palavras.size();
    PalavraSecreta = palavras[indiceSorteado];
}

void salvaArquivo(vector<string> novaLista)
{
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        arquivo << novaLista.size() << endl;

        for (string palavra : novaLista)
        {
            arquivo << palavra << endl;
        }

        arquivo.close();
    }
    else
    {
        cout << "Não foi possivel adicionar a palavra no banco de dados" << endl;
        exit(0);
    }
}

void adicionaPalavra()
{
    vector<string> listaPalavra = LerArquivo();
    string novaPalavra;

    cout << "Digite uma palavra" << endl;
    cin >> novaPalavra;

    transform(novaPalavra.begin(), novaPalavra.end(), novaPalavra.begin(), ::toupper);

    listaPalavra.push_back(novaPalavra);

    salvaArquivo(listaPalavra);
}

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
        cout << "Você deseja adicionar uma nova palavra ao banco?(S/N)";

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
