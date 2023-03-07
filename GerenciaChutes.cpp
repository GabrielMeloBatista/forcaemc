#include <iostream>
#include <map>
#include <vector>
#include "GerenciaChutes.hpp"
#include "logica.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> ChutesErrados;

void GerenciarChutes(std::string PalavraSecreta)
{
    char chute;
    std::cout << "Seu chute: ";
    std::cin >> chute;
    chute = toupper(chute);
    chutou[chute] = true;

    if (LetraExiste(chute, PalavraSecreta))
    {
        std::cout << "Seu chute está na palavra." << std::endl;
    }
    else
    {
        std::cout << "Seu chute não esta na palavra." << std::endl;
        ChutesErrados.push_back(chute);
    }
    std::cout << std::endl;
}