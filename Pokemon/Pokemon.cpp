#include "Pokemon.h"

Pokemon::Pokemon(std::string& nome, std::string& regiao, int& vida,
        int& dano, std::string& specialAtk,
        std::string elemento)
    :SerVivo(nome, regiao), vida(vida), dano(dano), elemento(elemento)
{
    int ElementoInvalido = true; 
    for(int i = 0; i < 4; ++i)
    {
        if(elmentos[i] == this->elemento)
        {
            ElementoInvalido = false;
        }
    }
    if(ElementoInvalido)
    {
        std::cout << "Não exist o elemento escrito." << std::endl;
        std::cout << "Seu pokemon é do tipo NORMAL." << std::endl;
    }
}

std::string getTipo() const override
{
    return "POKEMON";
}

void Pokemon::imprime() const override
{
    SerVivo::imprime();
    std::cout << "Vida-> " << this->vida << "Dano-> " << this->dano << std::endl;
    std::cout << "Elemento: " << this->elemento << std::endl;
}

std::string Pokemon::getNome() const
{
    return this->nome;
}
void Pokemon::setNome(std::string nome)
{
    this->nome = nome;
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
    this->elemento = elemento;
}

