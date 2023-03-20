#ifndef _POKEMON_H
#define _POKEMON_H

#include <iostream>
#include <string>
#include <vector>

enum TIPO {AGUA, FOGO, GRAMA};
class Pokemon
{
private:
    std::string nome;
    int vida;
    int dano;
    std::vector<Pokemon*> pokemons;
public:
    Pokemon(std::string& nome, int& vida, int& dano);
    virtual int getTipo() = 0;
    virtual void imprime() const;
    static void luta(Pokemon* p1, Pokemon* p2);
    std::string getNome() const;
    void setNome(std::string nome);
    int getVida() const;
    void setVida(int vida);
    int getDano() const;
    void setDano(int dano);
    bool removePokemon(Pokemon pokemon);
}
#endif /* _POKEMON_H */
