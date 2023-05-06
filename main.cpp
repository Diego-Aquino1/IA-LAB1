#include <iostream>
#include <vector>

using namespace std;

class Nodo{
public:
    string departamento;
    vector<Nodo*> hijos;

    Nodo(string);
    ~Nodo();
};

Nodo::Nodo(string departamento_){
    this->departamento=departamento_;
}

Nodo::~Nodo(){
    for(auto hijo : hijos){
        delete hijo;
    }
}

class Arbol{
public:
    Nodo* root;

    void addHijo(Nodo*, Nodo*);
    void anchura();
    void profundidad();
    Arbol(string);
    ~Arbol();
};

void Arbol::addHijo(Nodo* padre, Nodo* hijo){
    padre -> hijos.push_back(hijo);
}



Arbol::Arbol(string valorRoot){
    root = new Nodo(valorRoot);
}

Arbol::~Arbol(){
    delete root;
}

int main() {
    Arbol* tree = new Arbol("ICA");
    Nodo* AYA = new Nodo("AYA");
    Nodo* LIM = new Nodo("LIM");
    tree->addHijo(tree->root, AYA);
    tree->addHijo(tree->root, LIM);
    Nodo* LLI = new Nodo("LLI");
    Nodo* AQP = new Nodo("AQP");
    tree->addHijo(AYA, LLI);
    tree->addHijo(AYA, AQP);
    Nodo* ANC = new Nodo("ANC");
    Nodo* JUN = new Nodo("JUN");
    Nodo* PAS = new Nodo("PAS");
    tree->addHijo(LIM, ANC);
    tree->addHijo(LIM, JUN);
    tree->addHijo(LIM, PAS);
    Nodo* LAM = new Nodo("LAM");
    Nodo* CAJ = new Nodo("CAJ");
    tree->addHijo(LLI, LAM);
    tree->addHijo(LLI, CAJ);
    Nodo* CUS = new Nodo("CUS");
    tree->addHijo(AQP, CUS);
    Nodo* SMA = new Nodo("SMA");
    tree->addHijo(ANC, SMA);
    Nodo* LOR = new Nodo("LOR");
    tree->addHijo(JUN, LOR);
    Nodo* UCA = new Nodo("UCA");
    tree->addHijo(PAS, UCA);
    Nodo* AMA = new Nodo("AMA");
    tree->addHijo(LOR, AMA);

    return 0;
}