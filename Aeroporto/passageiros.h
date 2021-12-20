#ifndef PROJETO1_PASSAGEIROS_H
#define PROJETO1_PASSAGEIROS_H

#include <iostream>
#include <vector>
#include <list>
#include "voo.h"
#include "bilhete.h"


class Passageiro {
private:
    string nome;
    vector<Bilhete> bilhetes;
    int numBilhetesAdquiridos = bilhetes.size();
public:
    Passageiro();
    Passageiro(string nome, Bilhete b);
    string getNome();
    vector<Bilhete> getBilhetes() const;
    void setBilhetes(vector<Bilhete> bilhetes);
    void addBilhete(string & nome, Bilhete b);
    void BilheteInput();
    void WriteBilhete();
    void ReadBilhete();
    void listagemCompleta();
    void listagemIncompleta();

};

#endif //PROJETO1_PASSAGEIROS_H
