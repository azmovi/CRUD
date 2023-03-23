#ifndef _TREINADOR_H
#define _TREINADOR_H

#include <vector>
#include "../SerVivo/SerVivo.h"
#include "../Pokemon/Pokemon.h"

class Treinador: public SerVivo
{
private:
    int idade;
    std::string genero;
    int totalPokemons = 0;
    std::vector<Pokemon*> time(3);
public:
    Treinador(int& id, std::string& nome, std::string& regiao,
            std::string& genero, int& idade);

    std::string getTipo() const override;
    void imprime() const override;

    void listaTime();
    bool removePokemon(std::string);
    bool adcionaPokemon();
    bool temPokemon();

    int getIdade() const;
    void setIdade(int);
    std::string getGenero() const;
    void setGenero(std::string);




};

#endif /* _TREINADOR_H */
