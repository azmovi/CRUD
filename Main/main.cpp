#include "../Cadastro/Cadastro.h"

int main()
{
    int op = 1;
    int id;
    Cadastro cadastro("info.dat");
    while(op != 0)
    {
        op = cadastro.opcao();
        switch(op)
        {
            case 1:
            {
                std::cout << "Id: ";
                std::cin >> id;
                cadastro.imprime(id);
                break;
            }
            case 2:
            {
                std::cout << "Id: ";
                std::cin >> id;
                cadastro.imprimeTime(id);
                break;
            }
            
            case 3:
            {
                cadastro.adiciona(TREINADOR);
                break;
            }
            case 4:
            {
                cadastro.adiciona(POKEMON);
                break;
            }
            case 5:
            {
                std::cout << "Id: ";
                std::cin >> id; 
                cadastro.atualiza(id);
                break;
            }
            case 6:
            {
                std::cout << "Id: ";
                std::cin >> id;
                cadastro.remove(id);
                break;
            }
            case 7:
            {
                int id_treinador, id_pokemon;
                std::cout << "ID do Treinador ";
                std::cin >> id_treinador;
                std::cout << "Id do Pokemon ";
                std::cin >> id_pokemon;
                cadastro.treinadorCaptura(id_treinador, id_pokemon);
                break;
            }
            case 8:
            {
                cadastro.imprimeTodos();
                break;
            }
        }
    }
}
