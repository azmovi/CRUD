#include "Cadastro.h"
#include <algorithm>
#include <fstream>

Cadastro::Cadastro(std::string fileName) : fileName(fileName) {
    recupera();
}

Cadastro::~Cadastro() {}

void Cadastro::grava() {
    //Ser Vivo
    int id, tipo;
    std::string nome, regiao;
    //Treinador
    int idade;
    std::string genero;
    Treinador *treinador;
    //Pokemon
    int vida, dano;
    std::string specialAtk, elemento;
    Pokemon *pokemon;

    ofstream arquivoSaida(fileName, ios::binary);

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
                especialAtk = seresVivos[i]->getEspecialAtk();
                tam = especialAtk.size();
                arquivoSaida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                arquivoSaida.write(reinterpret_cast<char *>(&especialAtk[0]), tam);

                // Escrevendo Elemento
                elemento = seresVivos[i]->getElemento();
                tam = elemento.size();
                arquivoSaida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                arquivoSaida.write(reinterpret_cast<char *>(&elemento[0]), tam);

                break;
            }
            case TREINADOR: {

                treinador = dynamic_cast<Treinador*>(seresVivos[i]);

                // Escrevendo genero
                genero = seresVivos[i]->getGenero();
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
    int id, tipo;
    std::string nome, regiao;
    //Treinador
    int idade;
    std::string genero;
    //Pokemon
    int vida, dano;
    std::string specialAtk, elemento;

    ifstream arquivoEntrada(fileName, ios::binary);
    
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
            arquivoentrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            regiao.resize(tam);
            arquivoentrada.read(reinterpret_cast<char *>(&regiao[0]), tam);

            switch (tipo) {
                case POKEMON: {
                    //Lendo vida
                    arquivoEntrada.read(reinterpret_cast<char *>(&vida), sizeof(vida));

                    // Lendo dano
                    arquivoEntrada.read(reinterpret_cast<char *>(&dano), sizeof(dano));

                    // Lendo Atk especial
                    arquivoentrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    specialAtk.resize(tam);
                    arquivoentrada.read(reinterpret_cast<char *>(&specialAtk[0]), tam);

                    // Lendo elemento
                    arquivoentrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    elemento.resize(tam);
                    arquivoentrada.read(reinterpret_cast<char *>(&elemento[0]), tam);
                    
                    seresVivos.push_back(new Pokemon(id, nome, regiao, vida, dano, especialAtk, elemento));
                    break;
                }
                case TREINADOR: {
                    // Lendo genero
                    arquivoentrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    genero.resize(tam);
                    arquivoentrada.read(reinterpret_cast<char *>(&genero[0]), tam);

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
    int id, tipo;
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

    std::cin.ignore();
    std::cout << "Regiao: ";
    std::getline(std::cin, nome);

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

            f = new Pokemon(id, nome, regiao, vida, dano, specialAtk, elemento);
            break;
        }
        case TREINADOR: {

            std::cin.ignore();
            std::cout << "Genero: ";
            std::getline(std::cin, genero);

            std::cin.ignore();
            std::cout << "idade: ";
            std::cin >> idade;

            f = new Treinador(id, nome, regiao, genero, idade);
            break;
        }
    }

    seresVivos.push_back(f);
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

    cout << "[1] Nome" << endl;
    cout << "[2] Regiao" << endl;
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
    cout << "[0] Fim" << endl;
    cout << "> ";
    cin >> opt;
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
                        seresVivos[pos]->setVida(vida);
                        break;
                    }
                     case TREINADOR:
                    {
                        std::cout << "Genero: ";
                        std::cin >> genero;
                        seresVivos[pos]->setGenero(genero);
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
                        std::cint >> dano;
                        seresVivos[pos]->setDano(dano);
                        break;
                    }
                    case TREINADOR:
                    {
                        std::cout << "Idade: ";
                        std::cin >> idade;
                        seresVivos[pos]->setIdade(idade);
                        break;
                    }
                }
            }
            case 5:
            {
                std::cout << "Ataque Especial: ";
                std::cin >> specialAtk;
                seresVivos[pos]->setSpecialAtk(specialAtk);
                break;
            }
            case 6:
            { 
                std::cout << "Elemento: ";
                std::cin >> elemento;
                seresVivos[pos]->setElemento(elemento);
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
    return -1
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
        cout << "Id não encontrado";
    }
}


int Cadastro::opcao() {
    int opt;
    cout << "[1] Imprime Ser Vivo" << endl;
    cout << "[2] Imprime Time" << endl;
    cout << "[3] Adiciona Teinador" << endl;
    cout << "[4] Adiciona Pokemon" << endl;
    cout << "[5] Atualiza Atributo" << endl;
    cout << "[6] Remove Ser Vivo"<< endl;
    cout << "[0] Fim" << endl;
    cout << "> ";
    cin >> opt;
    return opt;
}
