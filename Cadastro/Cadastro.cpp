#include "Cadastro.h"
#include "Enfermeiro.h"
#include "Medico.h"
#include <algorithm>
#include <fstream>
using namespace std;

Cadastro::Cadastro(string fileName) : fileName(fileName) {
    recupera();
}

Cadastro::~Cadastro() {}

void Cadastro::grava() {

    int CPF, CRE, tipo, tam;
    string nome, especialidade;
    double salario;
    Enfermeiro *e1;
    Medico *m1;

    ofstream saida(fileName, ios::binary);

    for (long unsigned int i = 0; i < funcionarios.size(); i++)  {

        // Escrevendo o tipo de funcionario (ENFERMEIRO ou MEDICO)

        tipo = funcionarios[i]->getProfissao();
        saida.write(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        // Escrevendo o CPF

        CPF = funcionarios[i]->getCPF();
        saida.write(reinterpret_cast<char *>(&CPF), sizeof(CPF));

        // Escrevendo o nome

        nome = funcionarios[i]->getNome();
        tam = nome.size();

        // Escrevendo o tamanho da string (nome)
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));

        // Escrevendo os caracteres da string (nome)
        saida.write(reinterpret_cast<char *>(&nome[0]), tam);

        // Escrevendo o salario
        salario = funcionarios[i]->getSalario();
        saida.write(reinterpret_cast<char *>(&salario), sizeof(salario));

        // Escreve as caracteristicas especificas Funcionário
        // (atributos da classe Enfermeiro ou Medico)

        switch (tipo) {
            case ENFERMEIRO: {
                // Escrevendo o CRE

                e1 = dynamic_cast<Enfermeiro *>(funcionarios[i]);
                CRE = e1->getCRE();
                saida.write(reinterpret_cast<char *>(&CRE), sizeof(CRE));

                break;
            }
            case MEDICO: {
                // Escrevendo a especialidade

                m1 = dynamic_cast<Medico *>(funcionarios[i]);
                especialidade = m1->getEspecialidade();
                tam = especialidade.size();

                // Escrevendo o tamanho da string (especialidade)
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));

                // Escrevendo os caracteres da string (especialidade)
                saida.write(reinterpret_cast<char *>(&especialidade[0]), tam);

             break;
            }
        }
    }

    saida.close();
}

void Cadastro::recupera() {

    int CPF, CRE, tipo, tam;
    double salario;
    string nome, especialidade;

    ifstream entrada(fileName, ios::binary);
    
    if (entrada.is_open()) {

        funcionarios.clear();

        // Lendo o tipo

        entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        while (entrada.good()) {

            // Lendo o CPF

            entrada.read(reinterpret_cast<char *>(&CPF), sizeof(CPF));

            // Lendo o nome

            // Lendo o tamanho da string (nome)
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            nome.resize(tam);

            // Lendo os caracteres da string (nome)
            entrada.read(reinterpret_cast<char *>(&nome[0]), tam);

            // Lendo o salário

            entrada.read(reinterpret_cast<char *>(&salario), sizeof(salario));

            // Lendo as caracteristicas especificas Funcionário
            // (atributos da classe Enfermeiro ou Medico)

            switch (tipo) {
                case ENFERMEIRO: {

                    // Lendo o CRE
                    entrada.read(reinterpret_cast<char *>(&CRE), sizeof(CRE));

                    funcionarios.push_back(new Enfermeiro(CPF, nome, salario, CRE));
                    break;
                }
                case MEDICO: {

                    // Lendo a especialidade

                    // Lendo o tamanho da string (especialidade)
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    especialidade.resize(tam);

                    // Lendo os caracteres da string (especialidade)
                    entrada.read(reinterpret_cast<char *>(&especialidade[0]), tam);

                    funcionarios.push_back(new Medico(CPF, nome, salario, especialidade));
                    break;
                }
            }

            // Lendo o tipo

            entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
        }
    }
    entrada.close();
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

    funcionarios.push_back(f);
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
        funcionarios[pos]->setSalario(salario);
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
        funcionarios.erase(funcionarios.begin() + pos);
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
        funcionarios[pos]->imprime();
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
