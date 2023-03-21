#ifndef _DUELO_H
#define _DUELO_H

#include "../SerVivo/SerVivo.h"
#include "../Treinador/Treinador.h"
#include "../Pokemon/Pokemon.h"

class Duelo
{
private:
    void grava();
    void recupera();
    std::string fileName;
    vector<Treinador*> treinadores;
    vector<Pokemon*> pokemons;
public:
    Duelo(std::string& fileName);
    bool adciona(std::string);
    void imprimeTreinadores();
    void imprimePokemons();
    void imprimeTime(Treinador treinador);
    void Batalha(Treinador t1, Treinador t2);
    static char opcao();
};

endif /* _DUELO_H */
