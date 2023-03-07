#include "GerenciaArquivo.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

extern std::string PalavraSecreta;

std::vector<std::string> LerArquivo()
{
    std::ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {

        std::vector<std::string> PalavrasArquivos;
        std::string palavraLida;
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
        std::cout << "Não foi possivel encontrar arquivo de palavras" << std::endl;
        exit(0);
    }
}

void sorteiaPalavra()
{
    std::vector<std::string> palavras = LerArquivo();
    srand(time(NULL));
    int indiceSorteado = rand() % palavras.size();
    PalavraSecreta = palavras[indiceSorteado];
}

void salvaArquivo(std::vector<std::string> novaLista)
{
    std::ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        arquivo << novaLista.size() << std::endl;

        for (std::string palavra : novaLista)
        {
            arquivo << palavra << std::endl;
        }

        arquivo.close();
    }
    else
    {
        std::cout << "Não foi possivel adicionar a palavra no banco de dados" << std::endl;
        exit(0);
    }
}

void adicionaPalavra()
{
    std::vector<std::string> listaPalavra = LerArquivo();
    std::string novaPalavra;

    std::cout << "Digite uma palavra" << std::endl;
    std::cin >> novaPalavra;

    transform(novaPalavra.begin(), novaPalavra.end(), novaPalavra.begin(), ::toupper);

    listaPalavra.push_back(novaPalavra);

    salvaArquivo(listaPalavra);
}