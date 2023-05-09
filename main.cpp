#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
    void print(Nodo*,int);
    void write(const string, const vector<Nodo*>&, const vector<Nodo*>&);
    void bfs();
    void dfs();
    Arbol(string);
    ~Arbol();

};


void Arbol::addHijo(Nodo* padre, Nodo* hijo){
    padre -> hijos.push_back(hijo);
}

void Arbol::print(Nodo* root, int prof=0){
    //Espaciado de 4 en 4
    cout << string(prof,' ') <<  root->departamento <<endl;
    for(Nodo* hijo : root->hijos){
        print(hijo, prof+4);
    }
}

void Arbol::write(const string file_name, const vector<Nodo*>& frontier, const vector<Nodo*>& reached){

    ofstream out_file(file_name, ios::app);
    if (out_file.is_open()) {
        out_file << "Frontier: ";
        for (const auto& nodo : frontier) {
            out_file << nodo->departamento << " ";
        }
        out_file << endl;

        out_file << "Reached: ";
        for (const auto& nodo : reached) {
            out_file << nodo->departamento << " ";
        }
        out_file << endl;

        out_file << "-------------------" << endl;

        out_file.close();
    } else {
        cerr << "Error: Could not open file " << file_name << " for writing." << endl;
    }
}

void Arbol::bfs(){
    vector<Nodo*> frontier{root};
    vector<Nodo*> reached{root};

    while (!frontier.empty()) {
        Nodo* actual = frontier.front();
        frontier.erase(frontier.begin());

        for (Nodo* hijo : actual->hijos) {
            if (find(reached.begin(), reached.end(), hijo) == reached.end()) {
                reached.push_back(hijo);
                frontier.push_back(hijo);
            }
        }

        write("D:/UNSA/4/Inteligencia Artificial/IA-LAB1/bfs_out.txt", frontier, reached);
    }
}

void Arbol::dfs() {
    vector<Nodo*> frontier{root};
    vector<Nodo*> reached{root};

    while (!frontier.empty()) {
        Nodo* actual = frontier.back();
        frontier.pop_back();

        for (Nodo* hijo : actual->hijos) {
            if (find(reached.begin(), reached.end(), hijo) == reached.end()) {
                reached.push_back(hijo);
                frontier.push_back(hijo);
            }
        }

        write("D:/UNSA/4/Inteligencia Artificial/IA-LAB1/dfs_out.txt", frontier, reached);
    }
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

    tree->print(tree->root);

    tree->bfs();
    tree->dfs();

    return 0;
}