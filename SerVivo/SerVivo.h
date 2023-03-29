#ifndef _SERVIVO_H
#define _SERVIVO_H

#include <string>
#include <iostream>

enum Tipo {

    TREINADOR,
    POKEMON
};

class SerVivo
{
private:
    int id;
    std::string nome;
    std::string regiao;
public:
    SerVivo(int& id, std::string& nome, std::string& regiao);

    virtual int getTipo() const = 0;
    virtual void imprime() const;

    int getId() const;
    void setId(int);
    std::string getNome() const;
    void setNome(std::string);
    std::string getRegiao() const;
    void setRegiao(std::string);
};

#endif /* _SERVIVO_H */
