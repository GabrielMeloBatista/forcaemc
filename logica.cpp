#include <map>
#include <vector>
#include "logica.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> ChutesErrados;

bool LetraExiste(char chute, std::string PalavraSecreta)
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

bool Acertou(std::string PalavraSecreta)
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

