#ifndef PROJETO1_AVIAO_H
#define PROJETO1_AVIAO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "voo.h"
#include "servico.h"

using namespace std;

class Aviao {
private:
    string matricula;
    int capacidade;
    string tipo;
    list<Voo> listaVoo;
    static list<Aviao> listAviao;
    queue<Servico> servicos;
public:
    Aviao();
    Aviao(string matric, int cap){
        this->matricula = matric;
        this->capacidade = cap;
    };
    Aviao(string matricula, int capacidade, list<Voo> listaVoo, string tipo);
    list<Voo> getListaVoo() const;
    string getMatricula() const {return matricula;};
    int getCapacidade() const {return capacidade;};
    list<Aviao> getListAviao() const;
    void setListAviao();
    void novoservico(servico novo); //new
    //void atualizarservicos(vector<servico> sf);
    //void atualizarservicos(queue<servico> spf, vector<servico> sf);
    void VooInput();
    void WriteVoo();
    void ReadVoo();
    void AviaoInput();
    void WriteAviao();
    void ReadAviao();

};

#endif //PROJETO1_AVIAO_H
