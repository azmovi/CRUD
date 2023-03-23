#include "SerVivo.h"

SerVivo::SerVivo(int& id, std::string nome, std::string regiao)
    :id(id), nome(nome), regiao(regiao) {};

void SerVivo::imprime() const
{
    std::cout << "-----------" << this->getTipo() << "-----------" << std::endl;
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Regiao: " << this->regiao << std::endl;

}
int SerVivo::getId() const
{
    return this->id;
}
void SerVivo::setId(int id)
{
    this->id = id;
}

std::string SerVivo::getNome() const
{
    return this->nome;
}
void SerVivo::setNome(std::string nome)
    this->nome = nome;
std::string SerVivo::getRegiao() const
{
    return this->regiao;
}
void SerVivo::setRegiao(std::string regiao)
{
    this->regiao = regiao;
}
