#ifndef CADASTRO_H
#define CADASTRO_H

#include "../Pokemon/Pokemon.h"
#include "../Treinador/Treinador.h"
#include <vector>

class Cadastro {
public:
    Cadastro(std::string fileName);
    bool adiciona(int tipo);
    void imprime(int id);
    void imprimeTime(int id);
    bool remove(int id);
    bool atualiza(int id);
    static int opcao();
private:
    void grava();
    void recupera();
    int indice(int id);

    std::string fileName;
    std::vector<SerVivo*> seresVivos;
};

#endif /* CADASTRO_H */

