#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/servico.h"
#include "Aeroporto/Data.h"
#include "Aeroporto/passageiros.h"
#include "Aeroporto/transpTerr.h"
#include "Aeroporto/bagagem.h"

using namespace std;
void ReadFiles() {
    /*//já funciona!
    Aviao a;
    a.ReadVoo();
    a.VooInput();
    a.WriteVoo();
    a.listagemCompleta();
    a.listagemIncompleta();
    */
    /*//já funciona!
    Passageiro p;
    p.ReadBilhete();
    p.BilheteInput();
    p.WriteBilhete();
    p.listagemCompleta();
    p.listagemIncompleta();
    */

    GestaoBagagens g;
    g.ReadTapete();
    g.TapeteInput();
    g.WriteTapete();
    g.definirCarrinho();
    g.colocarMalas();

    //g.TapeteInput();
    //g.WriteTapete();

    //g.colocarMalas();

    /*
    Servico s;
    s.ReadServico();
    /*
    OpcoesTransporte o;
    o.readFile();
    */
}
/*
void checkTipoDeData(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
    servico s;
    string TipoDeDataClasse;
    cout << "What Type of Data do you want to Submit?" << endl;
    cin >> TipoDeDataClasse;
    if(TipoDeDataClasse == "Voo") {

    }
    if(TipoDeDataClasse == "Bagagem") {

    }
    if(TipoDeDataClasse == "Passageiro") {

    }
    if(TipoDeDataClasse == "Servico") {
        s.ServicoInput();
    }
}
*/
int main() {
    ReadFiles();

    return 0;
}

