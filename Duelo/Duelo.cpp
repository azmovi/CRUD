#include "Duelo.h"

Duelo(std::string& fileName)
    :fileName(fileName)
{
    recupera();
}
void Duelo::grava()
{
    //Ser Vivo
    int id;
    std::string tipo, nome, regiao;
    //Pokemon
    Pokemon *pokemon;
    int vida, dano;
    std::string specialAtk, elemento;
    //Treinador
    Treinador *treinador;
    int idade;
    std::string genero;
    //Auxiliar
    int tam;
    ofstream arquivoSaida(fileName, ios::binary);

    for(size_t i = 0; i < seresVivos.size(); ++i)
    {
        id = seresVivos[i]->getId();
        arquivoSaida.write(
                reinterpret_cast<char *>(&id),
                sizeof(id)
                );

        tipo = seresVivos[i]->getTipo();
        tam = tipo.size();
        arquivoSaida.write(
                reinterpret_cast<char *>(&tam),
                sizeof(tam)
                );
        arquivoSaida.write(
                reinterpret_cast<char *>(&tipo[0]),
                tam
                );

        nome = seresVivos[i]->getNome();
        tam = nome.size();
        arquivoSaida.write(
                reinterpret_cast<char *>(&tam),
                sizeof(tam)
                );
        arquivoSaida.write(
                reinterpret_cast<char *>(&nome[0]),
                tam
                );

        regiao = seresVivos[i]->getRegiao();
        tam = regiao.size()
        arquivoSaida.write(
                reinterpret_cast<char *>(&tam),
                sizeof(tam)
                );
        arquivoSaida.write(
                reinterpret_cast<char *>(&regiao[0]),
                tam
                );

        if(tipo == "POKEMOM")
        {
            pokemon = dynamic_cast<Pokemon *>(funcionarios[i]);
            //Escrita dos Atributos
            vida = pokemon->getVida();
            arquivoSaida.write(
                    reinterpret_cast<char *>(&vida),
                    sizeof(vida));

            dano = pokemon->getDano();
            arquivoSaida.write(
                    reinterpret_cast<char *>(&vida),
                    sizeof(vida)
                    );

            specialAtk = pokemon->getSpecialAtk();
            tam = specialAtk.size();
            arquivoSaida.write(
                    reinterpret_cast<char *>(&tam),
                    sizeof(tam)
                    );
            arquivoSaida.write(
                    reinterpret_cast<char *>(&specialAtk[0]),
                    tam
                    );

            elemento = pokemon->getElemento();
            tam = elemento.size();
            arquivoSaida.write(
                    reinterpret_cast<char *>(&tam),
                    sizeof(tam)
                    );
            arquivoSaida.write(
                    reinterpret_cast<char *>(&elemento[0]),
                    tam
                    );

        }
        else
        {
            if(tipo == "TREINADOR")
            {
                treinador = dynamic_cast<Treinador *>(funcionarios[i]);
                //Escrita de Atributos
                genero = treinador->getGenero();
                tam = elemento.size();
                arquivoSaida.write(
                        reinterpret_cast<char *>(&tam),
                        sizeof(tam)
                        );

                idade = treinador->getIdade();
                arquivoSaida.write(
                        reinterpret_cast<char *>(&idade),
                        sizeof(idade)
                        );
            }
        }
    }
    arquivoSaida.close();
}
void Duelo::recupera()
{
    //Ser Vivo
    int id;
    std::string tipo, nome, regiao
    //Pokemon
    int vida, dano;
    std::string specialAtk, elemento;
    //Treinador
    int idade;
    //Auxiliar
    int tam;

    ifstream arquivoEntrada(fileName, ios::binary);
    
    if(arquivoEntrada.is_open())
    {
        seresVivos.clear();

        //id
        arquivoEntrada.read(
                reinterpret_cast<char *>(&id),
                sizeof(id)
                );

        while(arquivoEntrada.good())
        {
            //tipo
            arquivoEntrada.read(
                    reinterpret_cast<char *>(&tam),
                    sizeof(tam)
                    );
            tipo.resize(tam);
            arquivoEntrada.read(
                    reinterpret_cast<char *>(&tipo[0]),
                    tam
                    );

            //nome
            arquivoEntrada.read(
                    reinterpret_cast<char *>(&tam),
                    sizeof(tam)
                    );
            nome.resize(tam);
            arquivoEntrada.read(
                    reinterpret_cast<char *>(&nome[0]),
                    tam
                    );

            //regiao
            arquivoEntrada.read(
                    reinterpret_cast<char *>(&tam),
                    sizeof(tam)
                    );
            regiao.resize(tam);
            arquivoEntrada.read(
                    reinterpret_cast<char *>(&regiao[0]),
                    tam
                    );

            //Atributos Especificos
            if(tipo == "POKEMON")
            {
                arquivoEntrada.read(
                        reinterpret_cast<char *>(&vida),
                        sizeof(vida)
                        );

                arquivoEntrada.read(
                        reinterpret_cast<char *>(&dano),
                        sizeof(dano)
                        );

                arquivoEntrada.read(
                        reinterpret_cast<char *>(&tam),
                        sizeof(tam)
                        );
                specialAtk.resize(tam);
                arquivoEntrada.read(
                        reinterpret_cast<char *>(&specialAtk[0]),
                        tam
                        );

                arquivoEntrada.read(
                        reinterpret_cast<char *>(&tam),
                        sizeof(tam)
                        );
                elemento.resize(tam);
                arquivoEntrada.read(
                        reinterpret_cast<char *>(&elemento[0]),
                        tam
                        );

                seresVivos.push_back(
                        new Pokemon(
                            id, nome, regiao,
                            vida,dano, specialAtk, elemento
                            )
                        );
            }
            else
            {
                if(tipo == "TREINADOR")
                {
                    arquivoEntrada.read(
                            reinterpret_cast<char *>(&idade),
                            sizeof(idade)
                            );
                    seresVivos.push_back(
                            new Treinador(
                                id, nome, regiao,
                                idade, genero
                                )
                            )
                }
            }
            arquivoEntrada.read(
                    reinterpret_cast<char *>(&id),
                    sizeof(id)
                    );
        }
    }
    arquivoEntrada.close();
}
bool Duelo::adciona(std::string tipo)
{
    //Ser Vivo
    int id;
    std::string tipo, nome, regiao;
    SerVivo *novoObjeto;
    //Pokemon
    int vida, dano;
    std::string specialAtk, elemento;
    //Treinador
    int idade;
    std::string genero;

    std::cin.ignore();
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Nome: ";
    std::getline(std::cin, nome);
    std::cout << "Região: ";
    std::getline(std::cin, regiao);

    if(tipo == "POKEMON")
    {
        std::cout << "Vida: ";
        std::cin >> vida;
        std::coud << "Dano: ";
        std::cin >> dano;
        std::cout << "Ataque Especial: ";
        std::getline(std::cin, specialAtk);
        std::cout << "Elemento: ";
        std::getline(std::cin, elemento);
        novoObjeto = new Pokemon(
                id, nome, regiao,
                vida, dano, specialAtk, elemento
                );
        
    }
    else
    {
        if(tipo == "TREINADOR")
        {
            std::cout << "Genêro: ";
            std::getline(std::cin, genero);
            std::cout << "Idade: ";
            std::cin >> idade;
            novoObjeto = new Treinador(
                    id, nome, regiao,
                    genero, idade
                    );
        }
    }
    seresVivos.push_back(novoObjeto);
    grava();
    return true;

}
bool Duelo::atualiza(int id, std::string tipo)
{
    
}
void Duelo::Batalha(Treinador t1, Treinador t2)
{
    
}
int Duelo::opcaoPrincipal()
{
    int opt;
    cout << "[1] Cria Treinador" << endl;
    cout << "[2] Cria Pokemon" << endl;
    cout << "[3] Atualiza Atributos Ser Vivo" << endl;
    cout << "[4] Remove Ser Vivo" << endl;
    cout << "[5] Duelo entre Treinadores" << endl;
    cout << "[6] Imprime Dados" << endl;
    cout << "[0] Fim" << endl;
    cout << "> ";
    cin >> opt;
    return opt;
}
int Duelo::atualizaAtributosTreinador()
{
    int opt;
    cout << "[1] Nome" << endl;
    cout << "[2] Regiao" << endl;
    cout << "[3] Genero" << endl;
    cout << "[4] Idade" << endl;
    cout << "[0] Fim" << endl;
    cout << "> ";
    cin >> opt;
    return opt;
}
int Duelo::atualizaAtributosPokemon()
{
    int opt;
    cout << "[1] Nome" << endl;
    cout << "[2] Regiao" << endl;
    cout << "[3] Vida" << endl;
    cout << "[4] Dano" << endl;
    cout << "[5] Ataque Especial" << endl;
    cout << "[6] Elemento" << endl;
    cout << "[0] Fim" << endl;
    cout << "> ";
    cin >> opt;
    return opt;
}
int Duelo::opcaoImprime()
{
    int opt;
    cout << "[1] Treinadores" << endl;
    cout << "[2] Time de um Treinador" << endl;
    cout << "[3] Pokemons Selvagens" << endl;
    cout << "[0] Fim" << endl;
    cout << "> ";
    cin >> opt;
    return opt;
}
