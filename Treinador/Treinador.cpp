#include "Treinador.h"

Treinador::Treinador(int& id, std::string& nome, std::string& regiao, std::string& genero, int& idade)
    :SerVivo(id,nome, regiao), genero(genero), idade(idade) {}

int Treinador::getTipo() const
{
    return TREINADOR; 
}
void Treinador::imprime() const
{
    SerVivo::imprime();
    std::cout << "Idade: " << this->idade << std::endl;
}

void Treinador::imprimeSeuTime()
{
    for(size_t i = 1; i < time.size(); ++i)
    {
        time[i-1]->imprime();
    }
    std::cout << "--------------------" << std::endl;

}
bool Treinador::removePokemon(std::string nome)
{
    for(int i = 0; i < 3; ++i)
    {
        if(time[i]->getNome() == nome)
        {
            time.erase(time.begin() + i);
            totalPokemons--;
            return true;
        }
    }
    std::cout << "Esse pokemon não está no seu time." << std::endl;
    return false;
}
bool Treinador::adcionaPokemon(Pokemon *pokemon)
{
    if(totalPokemons < 3)
    {
        time.push_back(pokemon);
        totalPokemons++;
        return true;
    }
    std::cout << "Seu time está cheio." << std::endl;
    return false;
}

bool Treinador::temPokemon()
{
    if(time.size())
    {
        return true;
    }
    return false;
}

int Treinador::getIdade() const
{
    return this->idade;
}

void Treinador::setIdade(int idade)
{
    this->idade = idade;
}

std::string Treinador::getGenero() const
{
    return this->genero;
}

void Treinador::setGenero(std::string genero)
{
    this->genero = genero;
}


