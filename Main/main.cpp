#include "../Duelo/Duelo.h"

int main()
{
    int op = 1;
    int id;
    Duelo duelo("info.dat");
    std::vector<int> opcoes = {
        duelo.adciona("TREINADOR"),
        duelo.adciona("POKEMON"),
        duelo.atualizaAtributos(),
        
    }
    std::vector<int> atualiza = {
        duelo.atualizaAtributosTreinador();
        duelo.atualizaAtributosPokemon();
        duelo.
    }
    while(op != -1)
    {
        op = Cadastro::opcao() - 1;
        if(op > -1)
        {
            opcoes[op];
        }
    }
