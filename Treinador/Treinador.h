#ifndef _TREINADOR_H
#define _TREINADOR_H

#include <vector>
#include "../SerVivo/SerVivo.h"
#include "../Pokemon/Pokemon.h"

class Treinador: public SerVivo
{
private:
    std::string genero;
    int idade, totalPokemons = 0, vitorias = 0;
    std::vector<Pokemon*> time;
public:
    Treinador(int& id, std::string& nome, std::string& regiao,
            std::string& genero, int& idade);

    int getTipo() const override;
    void imprime() const override;

    void imprimeSeuTime();
    bool removePokemon(std::string);
    bool adcionaPokemon(Pokemon*);
    bool temPokemon();

    int getIdade() const;
    void setIdade(int);
    std::string getGenero() const;
    void setGenero(std::string);




};

#endif /* _TREINADOR_H */
