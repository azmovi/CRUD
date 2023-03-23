#ifndef _DUELO_H
#define _DUELO_H

#include <cstdlib>
#include "../SerVivo/SerVivo.h"
#include "../Treinador/Treinador.h"
#include "../Pokemon/Pokemon.h"

class Duelo
{
private:
    void grava();
    void recupera();
    std::string fileName;
    std::vector<SerVivo*> seresVivos;
    std::vector<Treinador*> treinadores;
    std::vector<Pokemon*> pokemons;

public:
    Duelo(std::string& fileName);
    bool adciona(std::string);
    bool atualiza(int, std::string);
    void Batalha(Treinador t1, Treinador t2);
    static int opcaoPrincipal();
    static int atualizaAtributosTreinador();
    static int atualizaAtributosPokemon();
    static int opcaoImprime();
};

endif /* _DUELO_H */
