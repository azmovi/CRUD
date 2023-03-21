#ifndef _POKEMON_H
#define _POKEMON_H

#include "../SerVivo/SerVivo.h"

class Pokemon: public SerVivo
{
private:
    int vida;
    int dano;
    std::string elemento;
    std::string elementos[4] = {"fogo", "agua", "grama", "normal"};
public:
    Pokemon(std::string& nome, std::string& regiao, int& vida,
            int& dano,std::string& elemento="normal");
    
    std::string getTipo() const override;
    void imprime() const override;

    int getVida() const;
    void setVida(int);
    int getDano() const;
    void setDano(int);
    std::string getElemento() const;
    void setElemento(std::string);

}
#endif /* _POKEMON_H */
