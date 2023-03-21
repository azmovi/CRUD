#ifndef _SERVIVO_H
#define _SERVIVO_H

#include <string>
#include <iostream>

enum tipo {TREINADOR, POKEMON};
class SerVivo
{
private:
    std::string nome;
    std::string regiao;
public:
    SerVivo(std::string nome, std::string regiao);
    
    virtual void getTipo() = 0;
    virtual void imprime() const;

    std::string getNome() const;
    void setNome(std::string);
    std::sring getRegiao() const;
    void setRegiao(std::string);
};

#endif /* _SERVIVO_H */
