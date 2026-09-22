#include "bits/stdc++.h"

using namespace std;
#define endl '\n'
map<string,vector<string>> grafo;


bool areCompatible(string a, string b){
    if(a.size() != b.size()) return false;

    //en cuantas letras difieren
    int delta = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i] != b[i]) delta++; 
    }

    if(delta == 1) return true;
    else return false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    //Entrada
    // ops:= 3 + 3*n +4 ---> O(n)
    int n; cin>>n;  //2
    vector<string> palabras; //1
    for(int i = 0; i<n; i++){ //n veces
        string s; cin>>s; //2
        palabras.push_back(s); //1 
    }
    string inicio,fin; cin>>inicio>>fin; //4
    
    //Construir el grafo
    // O(n**2)
    for(string indice: palabras){ // n veces
        for(string p: palabras){ // n veces
            if(areCompatible(indice, p)){  // 1
                grafo[indice].push_back(p); // 1
            }
        }
    }

    //recorrer el grafo
    map<string, int> distancia;
    map<string, bool> visitado;
    queue<string> cola;
    string actual = inicio;
    cola.push(actual);
    visitado[actual] = true;
    // O(|vertices| + |aristas|)
    // O(|n| + |aristas|)
    while(cola.size()){
        actual = cola.front();
        cola.pop();

        for(string vecino: grafo[actual]){
            if(visitado[vecino] == false && distancia[vecino]==0){
                distancia[vecino] = distancia[actual] + 1;
                cola.push(vecino);
                visitado[vecino] = true;
            }
        }
    }
    //O(n + n**2 + n + |aristas|)
    //O(n**2 + |aristas|)
    //O(n**2)
    cout<<"La distancia a "<<fin<<" es de "<<distancia[fin]<<endl;
}
