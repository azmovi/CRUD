#include "SerVivo.h"

SerVivo::SerVivo(std::string nome, std::string regiao)
    :nome(nome), regiao(regiao) {};

void SerVivo::imprime() const
{
    std::cout << "-----------" << this->getTipo() << "-----------" << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Regiao: " << this->regiao << std::endl;

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
