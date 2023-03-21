#ifndef _TREINADOR_H
#define _TREINADOR_H

#include <vector>
#include "../SerVivo/SerVivo.h"
#include "../Pokemon/Pokemon.h"

class Treinador: public SerVivo
{
private:
    int idade;
    int totalPokemons = 0;
    std::vector<Pokemon*> time(3);
public:
    Treinador(std::string& nome, std::string& regiao, int& idade);

    std::string getTipo() const override;
    void imprime() const override;

    void listaTime();
    bool removePokemon(std::string);
    bool adcionaPokemon();
    bool temPokemon();

    int getIdade() const;
    void setIdade(int);




};

#endif /* _TREINADOR_H */
