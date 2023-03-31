#ifndef _POKEMON_H
#define _POKEMON_H

#include "../SerVivo/SerVivo.h"

class Pokemon: public SerVivo
{
private:
    int vida;
    int dano;
    std::string specialAtk; 
    std::string elemento;
    std::string elementos[4] = {"fogo", "agua", "grama", "normal"};
public:
    Pokemon(
            int& id, std::string& nome, std::string& regiao,
            int& vida,int& dano, std::string& specialAtk, std::string& elemento);
    
    int getTipo() const override;
    void imprime() const override;

    bool elementoValido(std::string);

    int getVida() const;
    void setVida(int);

    int getDano() const;
    void setDano(int);

    std::string getElemento() const;
    void setElemento(std::string);

    std::string getSpecialAtk() const;
    void setSpecialAtk(std::string);
    

};
#endif /* _POKEMON_H */
