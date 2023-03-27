#include "../Cadastro/Cadastro.h"

int main()
{
    int op = 1;
    int id;
    Duelo duelo("info.dat");
    while(op != 0)
    {
        op = Cadastro::opcao();
        switch(op)
        {
            case 1:
            {
                Cadastro::imprime();
            }
            case 2:
            {
                std::cout << "Id: ";
                std::cin >> id;
                Cadastro::imprimeTime(id);
                break;
            }
            
            case 3:
            {
                Cadastro::adiciona(TREINADOR);
                break;
            }
            case 4:
            {
                Cadastro::adiciona(POKEMON);
                break;
            }
            case 5:
            {
                std::cout << "ID: ";
                std::cin >> id; 
                Cadastro::atualiza(id);
                break
            }
            case 6:
            {
                std::cout << "ID: ";
                std::cin >> id;
                Cadastro::remove(id);
                break
            }
        }
    }
