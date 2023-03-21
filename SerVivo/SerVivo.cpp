#include "SerVivo.h"

SerVivo::SerVivo(std::string nome, std::string regiao);

void getTipo() = 0;
void imprime() const;

std::string getNome() const;
void setNome(std::string nome);
std::sring getRegiao() const;
void setRegiao(std::string regiao);
