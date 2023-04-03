#include "Cadastro.h"
#include <algorithm>
#include <fstream>

Cadastro::Cadastro(std::string fileName) : fileName(fileName) {
    recupera();
}

void Cadastro::grava() {
    //Ser Vivo
    int id, tipo, tam;
    std::string nome, regiao;
    //Treinador
    int idade;
    std::string genero;
    Treinador *treinador;
    //Pokemon
    int vida, dano;
    std::string specialAtk, elemento;
    Pokemon *pokemon;

    std::ofstream arquivoSaida(fileName, std::ios::binary);

    for (size_t i = 0; i < seresVivos.size(); ++i)  {

        // Escrevendo tipo
        tipo = seresVivos[i]->getTipo();
        arquivoSaida.write(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        // Escrevendo o id 
        id = seresVivos[i]->getId();
        arquivoSaida.write(reinterpret_cast<char *>(&id), sizeof(id));

        // Escrevendo o nome
        nome = seresVivos[i]->getNome();
        tam = nome.size();
        arquivoSaida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        arquivoSaida.write(reinterpret_cast<char *>(&nome[0]), tam);
        
        //Escrevendo regiao
        regiao = seresVivos[i]->getRegiao();
        tam = regiao.size();
        arquivoSaida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        arquivoSaida.write(reinterpret_cast<char *>(&regiao[0]), tam);



        switch (tipo) {
            case POKEMON: {

                pokemon = dynamic_cast<Pokemon*>(seresVivos[i]);

                // Escrevendo Vida
                vida = pokemon->getVida();
                arquivoSaida.write(reinterpret_cast<char *>(&vida), sizeof(vida));

                // Escrevendo dano
                dano = pokemon->getDano();
                arquivoSaida.write(reinterpret_cast<char *>(&dano), sizeof(dano));

                // Escrevendo Atk especial 
                specialAtk= pokemon->getSpecialAtk();
                tam = specialAtk.size();
                arquivoSaida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                arquivoSaida.write(reinterpret_cast<char *>(&specialAtk[0]), tam);

                // Escrevendo Elemento
                elemento = pokemon->getElemento();
                tam = elemento.size();
                arquivoSaida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                arquivoSaida.write(reinterpret_cast<char *>(&elemento[0]), tam);

                break;
            }
            case TREINADOR: {

                treinador = dynamic_cast<Treinador*>(seresVivos[i]);

                // Escrevendo genero
                genero = treinador->getGenero();
                tam = elemento.size();
                arquivoSaida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                arquivoSaida.write(reinterpret_cast<char *>(&genero[0]), tam);

                // Escrevendo idade
                idade = treinador->getIdade();
                arquivoSaida.write(reinterpret_cast<char *>(&idade), sizeof(idade));


             break;
            }
        }
    }

    arquivoSaida.close();
}

void Cadastro::recupera() {

    //Ser Vivo
    int id, tipo, tam;
    std::string nome, regiao;
    //Treinador
    int idade;
    std::string genero;
    //Pokemon
    int vida, dano;
    std::string specialAtk, elemento;

    std::ifstream arquivoEntrada(fileName, std::ios::binary);
    
    if (arquivoEntrada.is_open()) {

        seresVivos.clear();

        // Lendo o tipo

        arquivoEntrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        while (arquivoEntrada.good()) {

            // Lendo o id 

            arquivoEntrada.read(reinterpret_cast<char *>(&id), sizeof(id));

            // Lendo o nome

            arquivoEntrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            nome.resize(tam);
            arquivoEntrada.read(reinterpret_cast<char *>(&nome[0]), tam);

            // Lendo a regiao
            arquivoEntrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            regiao.resize(tam);
            arquivoEntrada.read(reinterpret_cast<char *>(&regiao[0]), tam);

            switch (tipo) {
                case POKEMON: {
                    //Lendo vida
                    arquivoEntrada.read(reinterpret_cast<char *>(&vida), sizeof(vida));

                    // Lendo dano
                    arquivoEntrada.read(reinterpret_cast<char *>(&dano), sizeof(dano));

                    // Lendo Atk especial
                    arquivoEntrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    specialAtk.resize(tam);
                    arquivoEntrada.read(reinterpret_cast<char *>(&specialAtk[0]), tam);

                    // Lendo elemento
                    arquivoEntrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    elemento.resize(tam);
                    arquivoEntrada.read(reinterpret_cast<char *>(&elemento[0]), tam);
                    
                    seresVivos.push_back(new Pokemon(id, nome, regiao, vida, dano, specialAtk, elemento));
                    break;
                }
                case TREINADOR: {
                    // Lendo genero
                    arquivoEntrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    genero.resize(tam);
                    arquivoEntrada.read(reinterpret_cast<char *>(&genero[0]), tam);

                    // Lendo idade
                    arquivoEntrada.read(reinterpret_cast<char *>(&idade), sizeof(idade));

                    seresVivos.push_back(new Treinador(id, nome, regiao, genero, idade));
                    break;
                }
            }

            // Lendo o tipo

            arquivoEntrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
        }
    }
    arquivoEntrada.close();
}

bool Cadastro::adiciona(int tipo) {
    //Ser Vivo
    int id, tipo_do_pokemon;
    std::string nome, regiao;
    SerVivo *serVivo;
    //Treinador
    int idade;
    std::string genero;
    //Pokemon
    int vida, dano;
    std::string specialAtk, elemento;

    std::cin.ignore();
    std::cout << "ID: ";
    std::cin >> id;

    std::cin.ignore();
    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    std::cout << "Regiao: ";
    std::getline(std::cin, regiao);

    switch(tipo) {
        case POKEMON: {
            std::cin.ignore();
            std::cout << "vida: ";
            std::cin >> vida;

            std::cin.ignore();
            std::cout << "dano: ";
            std::cin >> dano;

            std::cin.ignore();
            std::cout << "Ataque Especial: ";
            std::getline(std::cin, specialAtk);

            std::cin.ignore();
            std::cout << "Elemento: ";
            std::getline(std::cin, elemento);

            serVivo = new Pokemon(id, nome, regiao, vida, dano, specialAtk, elemento);
            break;
        }
        case TREINADOR: {

            std::cin.ignore();
            std::cout << "Genero: ";
            std::getline(std::cin, genero);

            std::cin.ignore();
            std::cout << "idade: ";
            std::cin >> idade;

            serVivo = new Treinador(id, nome, regiao, genero, idade);
            break;
        }
    }

    seresVivos.push_back(serVivo);
    grava();
    return true;
}

bool Cadastro::atualiza(int id)
{
    std::string nome, regiao;
    int idade, vida, dano, opt;
    std::string specialAtk, elemento, genero;
    bool ok = false;
    int pos = indice(id);
    int tipo = seresVivos[pos]->getTipo();


    Pokemon *pokemon;
    pokemon = dynamic_cast<Pokemon*>(seresVivos[pos]);
    Treinador *treinador;
    treinador = dynamic_cast<Treinador*>(seresVivos[pos]);

    std::cout << "[1] Nome" << std::endl;
    std::cout << "[2] Regiao" << std::endl;
    switch(tipo)
    {
        case POKEMON:
        {
            std::cout << "[3] Vida" << std::endl;
            std::cout << "[4] Dano" << std::endl;
            std::cout << "[5] Ataque Especial" << std::endl;
            std::cout << "[6] Elemento" << std::endl;
        }
        case TREINADOR:
        {
            std::cout << "[3] Genero" << std::endl;
            std::cout << "[4] Idade" << std::endl;
        }
    }
    std::cout << "[0] Fim" << std::endl;
    std::cout << "> ";
    std::cin >> opt;
    if (pos != -1) 
    {
        switch(opt)
        {
            case 1:
            {

                std::cout << "Nome: ";
                std::cin >> nome;
                seresVivos[pos]->setNome(nome);
                break;
            }
            case 2:
            {
                std::cout << "Regiao: ";
                std::cin >> regiao;
                seresVivos[pos]->setRegiao(regiao);
                break;
            }
            case 3:
            {
                switch(tipo)
                {
                    case POKEMON:
                    {
                        std::cout << "Vida: ";
                        std::cin >> vida;
                        pokemon->setVida(vida);
                        break;
                    }
                     case TREINADOR:
                    {
                        std::cout << "Genero: ";
                        std::cin >> genero;
                        treinador->setGenero(genero);
                        break;
                    }
                }
            }
            case 4:
            {
                switch(tipo)
                {
                    case POKEMON:
                    {
                        std::cout << "Dano: ";
                        std::cin >> dano;
                        pokemon->setDano(dano);
                        break;
                    }
                    case TREINADOR:
                    {
                        std::cout << "Idade: ";
                        std::cin >> idade;
                        treinador->setIdade(idade);
                        break;
                    }
                }
            }
            case 5:
            {
                std::cout << "Ataque Especial: ";
                std::cin >> specialAtk;
                pokemon->setSpecialAtk(specialAtk);
                break;
            }
            case 6:
            { 
                std::cout << "Elemento: ";
                std::cin >> elemento;
                pokemon->setElemento(elemento);
                break;
            }
            
        }
        grava();
        ok = true;
    }

    return ok;
}

bool Cadastro::remove(int id) 
{
    bool ok = false;
    int pos = indice(id);

    if (pos != -1) 
    {
        seresVivos.erase(seresVivos.begin() + pos);
        grava();
        ok = true;
    }

    return ok;
}

int Cadastro::indice(int id) 
{

    for(size_t i = 0; i < seresVivos.size(); ++i)
    {
        if(seresVivos[i]->getId() == id)
        {
            return i;
        }
    }
    return -1;
}

void Cadastro::imprime(int id) 
{
    int pos = indice(id);

    if (pos != -1) 
    {
        seresVivos[pos]->imprime();
    }
    else 
    {
        std::cout << "Id não encontrado";
    }
}

void Cadastro::imprimeTime(int id)
{
    int pos = indice(id);
    Treinador *treinador;
    treinador = dynamic_cast<Treinador*>(seresVivos[pos]);
    if(pos != -1)
    {
        treinador->imprimeSeuTime();
    }
    else
    {
        std::cout << "Id não encontrado";
    }
}


int Cadastro::opcao() {
    int opt;
    std::cout << "[1] Imprime Ser Vivo" << std::endl;
    std::cout << "[2] Imprime Time" << std::endl;
    std::cout << "[3] Adiciona Teinador" << std::endl;
    std::cout << "[4] Adiciona Pokemon" << std::endl;
    std::cout << "[5] Atualiza Atributo" << std::endl;
    std::cout << "[6] Remove Ser Vivo"<< std::endl;
    std::cout << "[0] Fim" << std::endl;
    std::cout << "> ";
    std::cin >> opt;
    return opt;
}
