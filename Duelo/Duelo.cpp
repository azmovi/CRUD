#include "Duelo.h"

Duelo(std::string& fileName)
    :fileName(fileName)
{
    recupera();
}
void Duelo::grava()
{
    //Ser Vivo
    std::string nome, regiao;
    //Pokemon
    int vida, dano;
    std::string specialAtk, elemento;
    Pokemon *pokemon;
    //Treinador
    int idade;
    Treinador *treinador;

    ofstream arquivo(fileName, ios::binary);

    for(size_t i = 0; i < seresVivos.size(); ++i)
    {
        tipo 
    }
}
void Duelo::recupera();
bool Duelo::adciona(std::string);
void Duelo::imprimeTreinadores();
void Duelo::imprimePokemons();
void Duelo::imprimeTime(Treinador treinador);
void Duelo::Batalha(Treinador t1, Treinador t2);
static char Duelo::opcao();

