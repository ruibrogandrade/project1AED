#include <fstream>
#include <sstream>
#include "passageiros.h"
#include "bilhete.h"
#include "voo.h"

Passageiro::Passageiro() {}

Passageiro::Passageiro(string nome, Bilhete b)  {
    this->nome = nome;
    bilhetes.push_back(b);
}

string Passageiro::getNome() {
    return nome;
}

 //a função addBilhete não está totalmente bem..
void Passageiro::addBilhete(string & nome, Bilhete b) {
    Voo v; //como adicionar outro bilhete à mesma pessoa?
    if (v.getVagas() != 0){
        Passageiro p;
        p.nome = nome;
        bilhetes.push_back(b);
        v.setVagas(v.getVagas()-1);
    }
}

void Passageiro::BilheteInput() {
    cout << "Quantos bilhetes deseja adicionar? " << endl;
    cout << '>';
    int quant;
    cin >> quant;
    cout << endl;
    if (quant == 0) { cout << "Nao vai ser adicionado nenhum bilhete." << endl;}
    if (quant == 1) {cout << "Vamos adicionar um novo Bilhete." << endl;}
    if (quant > 1) {cout << "Vamos adicionar " << quant << " novos Bilhetes." << endl;}
    cout << endl;
    while(quant != 0){
        cout << "Insira o nr de Bilhete: " << endl;
        cout << '>';
        int nrBilhete;
        cin >> nrBilhete;
        cout << "Insira o numero de bagagens associadas ao Bilhete: " <<  endl;
        cout << '>';
        int nrBagagens;
        cin >> nrBagagens;
        cout << "Insira o numero do Voo associado ao Bilhete: " <<  endl;
        cout << '>';
        int nrVoo;
        cin >> nrVoo;
        cout << "Insira o nome do Passageiro: " <<  endl;
        cout << '>';
        string nomee;
        cin >> nomee;
        Bilhete b = Bilhete(nrBilhete, nrBagagens, nrVoo, nomee);
        bilhetes.push_back(b);
        cout << endl;
        quant--;
        if(quant != 0) {
            cout << "(Proximo Bilhete)";
            cout << endl;
        }
    }
}

void Passageiro::WriteBilhete() {
    ofstream file;
    file.open("bilhetes.txt");
    for (auto it = bilhetes.begin(); it != bilhetes.end(); it++){
        file << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ',' << (*it).getNumVoo() << ',' << (*it).getNome() << ",";
        if (next(it) == bilhetes.end()) continue;
        else file << endl;
    }
    file.close();
}

void Passageiro::ReadBilhete() {
    int nrBilh, quantBag, nrVoo;
    ifstream file("bilhetes.txt");
    string line;
    string nome;
    Bilhete b;
    int i = 0;
    while (getline(file, line, ',')){
        switch (i) {
            case (0):
                nrBilh = stoi(line);
                b.setNumBilhete(nrBilh);
                break;
            case (1):
                quantBag = stoi(line);
                b.setQuantBagagem(quantBag);
                break;
            case (2):
                nrVoo = stoi(line);
                b.setNumVoo(nrVoo);
                break;
            case (3):
                nome = line;
                b.setNome(nome);
                bilhetes.push_back(b);
                i = -1;
                break;
        }
        i++;
    }
    file.close();

    //for(auto it = bilhetes.begin(); it != bilhetes.end(); it++){
      //  cout << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ',' << (*it).getNumVoo() << endl;
    //}
}
/*
vector<Bilhete> Passageiro::getBilhetes() const{
    return bilhetes;
}

void Passageiro::setBilhetes(vector<Bilhete> bilhetes) {
    this->bilhetes=bilhetes;
}
*/
void Passageiro::listagemCompleta() {
    cout << endl;
    ifstream file("bilhetes.txt");
    string line;
    cout << "Conteudo do ficheiro de bilhetes:" << endl;
    cout << endl;
    while (getline(file, line)){
        cout << line << endl;
    }

}

void Passageiro::listagemIncompleta() {
    cout << endl << endl;
    cout << "Escolha uma opcao para visualizar os Bilhetes:" << endl;
    cout << endl;
    cout << "1) " << "Visualizar bilhetes com numero de bagagens superior a <?>." << endl;
    cout << "2) " << "Visualizar bilhetes pertencentes ao voo numero <?>." << endl;
    cout << "3) " << "Visualizar bilhetes ordenados por um parâmetro específico." << endl;
    cout << "4) Visualizar bilhetes de um certo passageiro." << endl;
    cout << ">";
    int escolha;
    cin >> escolha;
    ifstream file("bilhetes.txt");
    string line;
    if(escolha == 1){
        cout << "Deseja visualizar os bilhetes associados a mais que 0, 1, 2, 3... bagagens? "
                "(Insira o numero de bagagens pretendido): " << endl;
        cout << ">";
        int nrBagagens;
        cin >> nrBagagens;
        bool flag = false;
        for (auto it = bilhetes.begin(); it != bilhetes.end(); it++){
            if((*it).getQuantBagagem() > nrBagagens){
                flag = true;
                cout << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ','
                << (*it).getNumVoo() << ',' << (*it).getNome() << ","  << endl;
            }
        }
        if(!flag) cout << "---> Nao existem bilhetes com mais que esse numero de bagagens." << endl;
        cout << endl << endl;
    }
    if (escolha == 2){
        cout << "Deseja visualizar os bilhetes associados ao voo numero? (Insira o respetivo numero de voo): " << endl;
        cout << ">";
        int nrVoo;
        cin >> nrVoo;
        bool flag = false;
        for (auto it = bilhetes.begin(); it != bilhetes.end(); it++){
            if((*it).getNumVoo() == nrVoo){
                flag = true;
                cout << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ','
                     << (*it).getNumVoo() << ','  << (*it).getNome() << ","  << endl;
            }
        }
        if(!flag) cout << "---> Nao existem bilhetes associados a esse voo." << endl;
        cout << endl << endl;
    }
    if (escolha == 3){
        cout << endl;
        cout << "Deseja visualizar os bilhetes ordenados pelo.. " << endl;
        cout << "(A) Numero de bilhete;" << endl;
        cout << "(B) Quantidade de bagagem;" << endl;
        cout << "(C) Numero de voo." << endl;
        cout << ">";
        char opcao;
        cin >> opcao;
        bool flag = false;
        vector<Bilhete> aux = bilhetes;
        if (opcao == 'A'){
            for (auto it = aux.begin(); it != aux.end(); it++){
                //Selection Sort
                if (aux.size() > 1) {
                    for (int i = 0; i < aux.size(); i++) {
                        for (unsigned i = 0; i < aux.size() - 1; i++) {
                            unsigned imin = i;
                            for (int j = i + 1; j < aux.size(); j++)
                                if (aux[j].getNumBilhete() < aux[imin].getNumBilhete())
                                    imin = j;
                            swap(aux[i], aux[imin]);
                        }
                    }
                }
            }
            for (auto it = aux.begin(); it != aux.end(); it++){
                flag = true;
                cout << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ','
                     << (*it).getNumVoo() << ','  << (*it).getNome() << ","  << endl;
            }
            if(!flag) cout << "---> Nao existem bilhetes." << endl;
            cout << endl << endl;
        }
        if (opcao == 'B') {
            for (auto it = aux.begin(); it != aux.end(); it++) {
                //Selection Sort
                if (aux.size() > 1) {
                    for (int i = 0; i < aux.size(); i++) {
                        for (unsigned i = 0; i < aux.size() - 1; i++) {
                            unsigned imin = i;
                            for (int j = i + 1; j < aux.size(); j++)
                                if (aux[j].getQuantBagagem() < aux[imin].getQuantBagagem())
                                    imin = j;
                            swap(aux[i], aux[imin]);
                        }
                    }
                }
            }
            for (auto it = aux.begin(); it != aux.end(); it++) {
                flag = true;
                cout << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ','
                     << (*it).getNumVoo() << ',' << (*it).getNome() << ","  << endl;
            }
            if (!flag) cout << "---> Nao existem bilhetes." << endl;
            cout << endl << endl;
        }
        if (opcao == 'C') {
            for (auto it = aux.begin(); it != aux.end(); it++) {
                //Selection Sort
                if (aux.size() > 1) {
                    for (int i = 0; i < aux.size(); i++) {
                        for (unsigned i = 0; i < aux.size() - 1; i++) {
                            unsigned imin = i;
                            for (int j = i + 1; j < aux.size(); j++)
                                if (aux[j].getNumVoo() < aux[imin].getNumVoo())
                                    imin = j;
                            swap(aux[i], aux[imin]);
                        }
                    }
                }
            }
            for (auto it = aux.begin(); it != aux.end(); it++) {
                flag = true;
                cout << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ','
                     << (*it).getNumVoo() << ',' << (*it).getNome() << ","  << endl;
            }
            if (!flag) cout << "---> Nao existem bilhetes." << endl;
            cout << endl << endl;
        }
    }
    if (escolha == 4) {
        cout << "Deseja visualizar os bilhetes associados ao Passageiro? (Insira o nome do Passageiro): " << endl;
        cout << ">";
        string passageiro;
        cin >> passageiro;
        bool flag = false;
        for (auto it = bilhetes.begin(); it != bilhetes.end(); it++) {
            if ((*it).getNome() == passageiro) {
                flag = true;
                cout << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ','
                     << (*it).getNumVoo() << ',' << (*it).getNome() << "," << endl;
            }
        }
        if (!flag) cout << "---> Nao existem bilhetes associados a esse passageiro." << endl;
        cout << endl << endl;
    }
    file.close();
}


void Passageiro::ApagarPassageiro() {
    cout << endl << endl;
    cout << "Escolha uma opcao para visualizar os Bilhetes:" << endl;
    cout << endl;
    cout << "1) " << "Apagar bilhetes com numero de bagagens superior a <?>." << endl;
    cout << "2) " << "Apagar bilhetes pertencentes ao voo numero <?>." << endl;
    cout << "3) Apagar bilhetes de um certo passageiro." << endl;
    cout << ">";
    int escolha;
    cin >> escolha;
    ifstream file("bilhetes.txt");
    string line;
    if(escolha == 1){
        cout << "Deseja apagar os bilhetes associados a mais que 0, 1, 2, 3... bagagens? "
                "(Insira o numero de bagagens pretendido): " << endl;
        cout << ">";
        int nrBagagens;
        cin >> nrBagagens;
        vector<Bilhete> apagar;
        bool flag = false;
        bool flag2 = false;
        for (auto it = bilhetes.begin(); it != bilhetes.end(); it++){
            if((*it).getQuantBagagem() > nrBagagens){
                flag = true;
                flag2 = true;
                auto et = it++;
                apagar.push_back(*it);
                bilhetes.erase(it);
                it = et;
            }
            if (!flag2) it++;

        }

        for (auto et = apagar.begin(); et != apagar.end(); et++) {
            cout << (*et).getNumBilhete() << ',' << (*et).getQuantBagagem() << ','
                 << (*et).getNumVoo() << ',' << (*et).getNome() << "," << endl;
        }
        if(!flag) cout << "---> Nao existem bilhetes com mais que esse numero de bagagens." << endl;
        cout << endl << endl;
    }
    if (escolha == 2){
        cout << "Deseja apagar os bilhetes associados ao voo numero? (Insira o respetivo numero de voo): " << endl;
        cout << ">";
        int nrVoo;
        cin >> nrVoo;
        vector<Bilhete> apagar;
        bool flag = false;
        bool flag2 = false;
        for (auto it = bilhetes.begin(); it != bilhetes.end(); it++){
            if((*it).getNumVoo() == nrVoo){
                flag = true;
                flag2 = true;
                auto et = it++;
                apagar.push_back(*it);
                bilhetes.erase(it);
                it = et;
            }
            if (!flag2) it++;

        }

        for (auto et = apagar.begin(); et != apagar.end(); et++) {
            cout << (*et).getNumBilhete() << ',' << (*et).getQuantBagagem() << ','
                 << (*et).getNumVoo() << ',' << (*et).getNome() << "," << endl;
        }
        if(!flag) cout << "---> Nao existem bilhetes associados a esse voo." << endl;
        cout << endl << endl;
    }
    if (escolha == 3) {
        cout << "Deseja apagar os bilhetes associados ao Passageiro? (Insira o nome do Passageiro): " << endl;
        cout << ">";
        string passageiro;
        vector<Bilhete> apagar;
        cin >> passageiro;
        bool flag = false;
        bool flag2 = false;
        for (auto it = bilhetes.begin(); it != bilhetes.end(); it++) {
            if ((*it).getNome() == passageiro) {
                flag = true;
                flag2 = true;
                auto et = it++;
                apagar.push_back(*it);
                bilhetes.erase(it);
                it = et;
            }
            if (!flag2) it++;
        }
        for (auto et = apagar.begin(); et != apagar.end(); et++) {
            cout << (*et).getNumBilhete() << ',' << (*et).getQuantBagagem() << ','
                 << (*et).getNumVoo() << ',' << (*et).getNome() << "," << endl;
        }
        if (!flag) cout << "---> Nao existem bilhetes associados a esse passageiro." << endl;
        cout << endl << endl;
    }
    file.close();
}