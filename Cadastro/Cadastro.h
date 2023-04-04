#ifndef CADASTRO_H
#define CADASTRO_H

#include "../Pokemon/Pokemon.h"
#include "../Treinador/Treinador.h"
#include <vector>

class Cadastro {
public:
    Cadastro(std::string);
    bool adiciona(int);
    void imprime(int);
    void imprimeTime(int);
    bool remove(int);
    bool atualiza(int);
    void treinadorCaptura(int, int);
    void imprimeTodos();
    static int opcao();
private:
    void grava();
    void recupera();
    int indice(int);

    std::string fileName;
    std::vector<SerVivo*> seresVivos;
};

#endif /* CADASTRO_H */

