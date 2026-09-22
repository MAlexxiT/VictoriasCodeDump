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
    int n; cin>>n;  
    vector<string> palabras;
    for(int i = 0; i<n; i++){
        string s; cin>>s;
        palabras.push_back(s);
    }
    string inicio,fin; cin>>inicio>>fin;
    //Construir el grafo
    for(string indice: palabras){
        for(string p: palabras){
            if(areCompatible(indice, p)){
                grafo[indice].push_back(p);
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
    
    cout<<"La distancia a "<<fin<<" es de "<<distancia[fin]<<endl;
}
/*
input: 

13

hat  cat  bat  bad  hit  hut cot  cop  cog  dog  log  doe sky

hit doe


output:
La distancia a doe es de 6
*/

