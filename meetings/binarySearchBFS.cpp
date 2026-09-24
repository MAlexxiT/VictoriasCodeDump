#include "bits/stdc++.h"

using namespace std;
#define endl '\n'

int rows, cols;
vector<vector<bool>> grid;
vector<vector<int>> dist;

bool isInsideGrid(int r, int c){
    if(r < 0 || r>=rows) return false;
    if(c < 0 || c>=cols) return false;
    return true;
}


bool isPossible(int minDist){
    map<int,map<int,bool>> vis;
    //(0,0) --> (rows-1, cols-1)
    stack<pair<int,int>> pila;
    pila.push({0,0});
    pair<int,int> current;
    while(pila.size() > 0){
        current = pila.top(); pila.pop();
        int r = current.first;
        int c = current.second;
        
        if(vis[r][c] == true) continue;
        vis[r][c] = true;

        // r,c --> (r-1,c), (r,c-1), (r+1,c), (r,c+1)
        if(isInsideGrid(r-1,c) && dist[r-1][c] >= minDist){
            pila.push({r-1,c});
        }
        if(isInsideGrid(r,c-1) && dist[r][c-1] >= minDist){
            pila.push({r,c-1});
        }
        if(isInsideGrid(r+1,c) && dist[r+1][c] >= minDist){
            pila.push({r+1,c});
        }
        if(isInsideGrid(r,c+1) && dist[r][c+1] >= minDist){
            pila.push({r,c+1});
        }
    }


    if(vis[rows-1][cols-1] == true){
        return true;
    }else{
        return false;
    }
}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //posicion
    //0,0 --> r-1, c-1
    //rows, cols
    //mala --> x,y
    cin>>rows>>cols;
    grid.resize(rows,vector<bool>()); 
    for(int r = 0; r<rows; r++){
        grid[r].resize(cols, false);
    }

    vector<pair<int,int>> badPeople;
    int m;cin>>m;
    for(int i = 0; i<m; i++){
        int badR, badC; 
        cin>>badR>>badC;
        grid[badR][badC] = true;
        badPeople.push_back({badR,badC});
    }
        
    //init distance grid
    dist.resize(rows,vector<int>()); 
    for(int r = 0; r<rows; r++){
        dist[r].resize(cols, -1);
    }
    
    for(pair<int,int> badPerson : badPeople){
        int r = badPerson.first;
        int c = badPerson.second;
        dist[r][c] = 0;
    }
    
    //bfs, para encontrar la distancia de cada celda a una persona mala
    queue<pair<int,int>> cola;
    for(pair<int,int> badPerson : badPeople){
        int r = badPerson.first;
        int c = badPerson.second;
        cola.push({r, c});
    }
   
    pair<int,int> current;
    while(cola.size() > 0){
        current = cola.front(); cola.pop();
        int r = current.first;
        int c = current.second;
        // r,c --> (r-1,c), (r,c-1), (r+1,c), (r,c+1)
        if(isInsideGrid(r-1,c) && dist[r-1][c] == -1){
            cola.push({r-1,c});
            dist[r-1][c] = dist[r][c] + 1;
        }
        if(isInsideGrid(r,c-1) && dist[r][c-1] == -1){
            cola.push({r,c-1});
            dist[r][c-1] = dist[r][c] + 1;
        }
        if(isInsideGrid(r+1,c) && dist[r+1][c] == -1){
            cola.push({r+1,c});
            dist[r+1][c] = dist[r][c] + 1;
        }
        if(isInsideGrid(r,c+1) && dist[r][c+1] == -1){
            cola.push({r,c+1});
            dist[r][c+1] = dist[r][c] + 1;
        }
    }

    int lower = 0;
    int upper = rows + cols - 1;

    int result = 0;
    //0,1
    //0,0
    /*
    0, 9
    4,9
    6
    
    F F T
    0,1,2 --> 1
    2,2,2
    */
    while(upper >= lower){
        int mid = (upper + lower)/2;
        //cout<<lower<<" "<<mid<<" "<<upper<<endl;

        if(isPossible(mid)){
            lower = mid+1;
            result = max(result, mid);
            
            //result = (result > mid ? result : mid);
        }else{
            upper = mid-1;
        }
    }

    cout<<"la distancia mas grande con un camino posible es de: "<<result<<endl;
    //5x3
    //...
    //...
    //...
    //...
    //...
    
}
