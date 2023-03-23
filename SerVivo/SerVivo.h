#ifndef _SERVIVO_H
#define _SERVIVO_H

#include <string>
#include <iostream>

class SerVivo
{
private:
    int id;
    std::string nome;
    std::string regiao;
public:
    SerVivo(int& id, std::string nome, std::string regiao);

    virtual string getTipo() const = 0;
    virtual void imprime() const;

    int getId() const;
    void setId(int);
    std::string getNome() const;
    void setNome(std::string);
    std::sring getRegiao() const;
    void setRegiao(std::string);
};

#endif /* _SERVIVO_H */
