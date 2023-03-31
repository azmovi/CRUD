#include "Pokemon.h"

Pokemon::Pokemon(int& id, std::string& nome, std::string& regiao, int& vida,
        int& dano, std::string& specialAtk, std::string& elemento)
    :SerVivo(id,nome, regiao), vida(vida), dano(dano), specialAtk(specialAtk), elemento(elemento)
{
    if(!elementoValido(elemento))
    {
        std::cout << "Elemento escrito não existe." << std::endl;
        std::cout << "Seu pokemon é do tipo NORMAL." << std::endl;
        elemento = elementos[3]; //normal
    }
}

bool Pokemon::elementoValido(std::string elemento)
{
    int ElementoInvalido = true; 
    for(int i = 0; i < 4; ++i)
    {
        if(elementos[i] == elemento)
        {
            return true;
        }
    }
    return false;
}

int Pokemon::getTipo() const 
{
    return POKEMON; 
}

void Pokemon::imprime() const 
{
    SerVivo::imprime();
    std::cout << "Vida-> " << this->vida << " Dano-> " << this->dano << std::endl;
    std::cout << "Elemento-> " << this->elemento << std::endl;
}

int Pokemon::getVida() const
{
    return this->vida;
}
void Pokemon::setVida(int vida)
{
    this->vida = vida;
}
int Pokemon::getDano() const
{
    return this->dano;
}
void Pokemon::setDano(int dano)
{
    this->dano = dano;
}
std::string Pokemon::getElemento() const
{
    return this->elemento;
}
void Pokemon::setElemento(std::string elemento)
{
    if(!elementoValido(elemento))
    {
        std::cout << "Elemento escrito não existe." << std::endl;
        std::cout << "Seu pokemon é do tipo " << this->elemento << std::endl;
    }
    else
    {
        this->elemento = elemento;
    }
}
std::string Pokemon::getSpecialAtk() const
{
    return this->specialAtk;
}
void Pokemon::setSpecialAtk(std::string specialAtk)
{
    this->specialAtk = specialAtk;
}

