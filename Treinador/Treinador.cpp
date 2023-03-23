#include "Treinador.h"

Treinador(std::string& nome, std::string& regiao, int& idade)
    :SerVivo(nome, regiao), idade(idade) {};

std::string getTipo() const override
{
    return "TREINADOR";
}
void imprime() const override
{
    SerVivo::imprime();
    std::cout << "Idade: " << this->idade << std::endl;
}

void Treinador::listaTime()
{
    for(int i = 1; i < 4; ++i)
    {
        std::cout << "------- POKEMON -> " << i << " -------" << std::endl;
        time[i]->imprime();
    }
    std::cout << "--------------------" << std::endl;

}
bool Treinador::removePokemon(std::string nome)
{
    for(int i = 0; i < 3; ++i)
    {
        if(time[i]->getNome() == nome)
        {
            time.erase(time.begin() + 1);
            totalPokemons--;
            return true;
        }
    }
    std::cout << "Esse pokemon não está no seu time."; << std::endl;
    return false;
}
bool Treinador::adcionaPokemon(Pokemon pokemon)
{
    if(totalPokemons < 3)
    {
        time.push_back(&pokemon);
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

