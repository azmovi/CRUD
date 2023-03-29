#ifndef CADASTRO_H
#define CADASTRO_H

#include "../SerVivo/SerVivo.h"
#include <vector>

class Cadastro {
public:
    Cadastro(string fileName);
    bool adiciona(int tipo);
    void imprime(int id);
    bool remove(int id);
    bool atualiza(int id);
    static char opcao();
private:
    void grava();
    void recupera();
    int indice(int id);

    string fileName;
    std::vector<SerVivo*> seresVivos;
};

#endif /* CADASTRO_H */

