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
    int CPF, CRE;
    double salario;
    string nome, especialidade;
    Funcionario* f;

    cin.ignore();
    cout << "Nome: ";
    getline(cin, nome);
    cout << "CPF: ";
    cin >> CPF;
    cout << "Salário: ";
    cin >> salario;

    switch(tipo) {
        case ENFERMEIRO: {
            cout << "CRE: ";
            cin >> CRE;
            f = new Enfermeiro(CPF, nome, salario, CRE);
            break;
        }
        case MEDICO: {
            cout << "Especialidade: ";
            cin.ignore();
            getline(cin, especialidade);
            f = new Medico(CPF, nome, salario, especialidade);
            break;
        }
    }

    seresVivos.push_back(f);
    grava();
    return true;
}

bool Cadastro::atualiza(int CPF) 
{
    double salario;
    bool ok = false;
    int pos = indice(CPF);

    if (pos != -1) 
    {
        
        cout << "Salário: ";
        cin >> salario;
        seresVivos[pos]->setSalario(salario);
        grava();
        ok = true;
    }

    return ok;
}

bool Cadastro::remove(int id) 
{
    bool ok = false;
    int pos = indice(CPF);

    if (pos != -1) 
    {
        seresVivos.erase(seresVivos.begin() + pos);
        grava();
        ok = true;
    }

    return ok;
}

int Cadastro::indice(int CPF) 
{

    for(size_t i = 0; i < sereVivos.size(); ++i)
    {
        if(sereVivos[i]->getId() == id)
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
        cout << "CPF não encontrado";
    }
}


int Cadastro::opcao() {
    int opt;
    cout << "[1] Imprime todos" << endl;
    cout << "[2] Adiciona Enfermeiro" << endl;
    cout << "[3] Adiciona Médico" << endl;
    cout << "[4] Atualiza salário (por CPF)" << endl;
    cout << "[5] Remove (por CPF)" << endl;
    cout << "[0] Fim" << endl;
    cout << "> ";
    cin >> opt;
    return opt;
}
