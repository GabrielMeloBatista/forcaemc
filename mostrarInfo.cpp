#include <iostream>
#include <map>
#include <vector>
#include "mostrarInfo.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> ChutesErrados;

void MostraCabecalho()
{
    std::cout << "*********************" << std::endl;
    std::cout << "*** Jogo da forca ***" << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << std::endl;
}

void MostraChutesErrados()
{
    if (ChutesErrados.size() > 0)
    {
        std::cout << "Chutes errados: ";
        for (char letra : ChutesErrados)
        {
            std::cout << letra << " ";
        }
        std::cout << std::endl;
    }
}

void MostraPalavra(std::string PalavraSecreta)
{
    for (char letra : PalavraSecreta)
    {
        if (chutou[letra])
        {
            std::cout << letra << " ";
        }
        else
        {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}