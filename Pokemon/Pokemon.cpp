include "Pokemon.h"

Pokemon::Pokemon(std::string& nome, int& vida, int& dano)
    :nome(nome), vida(vida), dano(dano) 
{
    pokemons.push_back(this->pokemon);
}

virtual void imprime() const
{
    std::cout << "Especie: " << this->nome << std::endl;
    std::cout << "Vida-> " << this->vida << "Dano-> " << this->dano << std::endl;
    std::string tipo;
    switch (this->getTipo()) 
    {
        case AGUA:
        {
            tipo = "Água";
            break;
        }
        case FOGO:
        {
            tipo = "Fogo";
            break;
        }
        case GRAMA:
        {
            tipo = "Grama";
            break;
        }
    }
    std::cout << "Tipo: " << tipo << std::endl;
}

static void luta(Pokemon* p1, Pokemon* p2)
{
    if((p1->dano > p2->vida) && (p2->dano < p1->vida))
    {
        std::cout << p1->nome << " saiu vitorioso." << std::endl;
        std::cout << "Infelizmente " << p2->nome << " acabou morrendo." << std::endl;
        removePokemon(p2);
    }
    else
    {
        if((p1->dano < p2->vida) && (p2->dano > p1->vida))
        {
            std::cout << p2->nome << " saiu vitorioso." << std::endl;
            std::cout << "Infelizmente " << p1->nome << " acabou morrendo." << std::endl;
            removePokemon(p1);
        }
        else
        {
            std::cout << "Ocorreu um empate!!" <<std::endl;
        }
    }
}
std::string getNome() const
{
    return this->nome;
}
void setNome(std::string nome)
{
    this->nome = nome;
}
int getVida() const
{
    return this->vida;
}
void setVida(int vida)
{
    this->vida = vida;
}
int getDano() const
{
    return this->dano;
}
void setDano(int dano)
{
    this->dano = dano;
}
bool removePokemon(Pokemon *pokemon)
{
    for(int i = 0; i < pokemons.size(); ++i)
    {
        if(pokemons[i] == pokemon)
        {
            pokemons.erase(pokemons.begin() + i);
            delete pokemon;
            return true;
        }
    }
    return false;
    std::cout << "Ocorreu algum erro e o pokemon não foi removido!!";
}
