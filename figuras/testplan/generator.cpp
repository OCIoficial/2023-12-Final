/*
 * Outputs random number between 1 and 10^6, inclusive.
 * To generate different values, call "igen.exe" with different parameters.
 * For example, "igen.exe 1" returns 504077, but "igen.exe 3" returns 808747.
 * 
 * It is typical behaviour of testlib generator to setup randseed by command line.
 */

#include <bits/stdc++.h>
#include <random>

using namespace std;

vector<int> di = {0, -1, 0, 1};
vector<int> dj = {-1, 0, 1, 0};

int getRandomNumber(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(gen);
}
// generateGrid
// n: número de filas
// m: número de columnas
// (i0, j0): posición inicial desde donde se propaga la figura
// cnt: número de 1's en la figura
//
// genera una grilla aleatoria conexa de la siguiente manera:
// se escoge un punto (i0, j0) al azar.
// luego se ejecuta un BFS desde ese punto utilizando una priority queue, asignando prioridades al azar a los elementos
// cosa de que al escogerlos se tome un elemento aleatorio adyacente a los que ya estan puestos.
vector<vector<bool>> generateGrid(int n, int m, int i0, int j0, int cnt){
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    priority_queue<pair<int,pair<int,int>>> q;
    q.push({-1,{i0, j0}});
    while(!q.empty() && cnt > 0){
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        cnt--;
        vector<pair<int,int>> possible;
        for(int k = 0; k<4; k++){
            int xx = x+di[k];
            int yy = y+dj[k];
            if(xx < 0 || xx >=n || yy < 0 || yy >= n) continue;
            q.push({getRandomNumber(1, n*m + 1), {xx,yy}});
        }
    }
    return vis;
}


int main(int argc, char *argv[]) {
    // generamos la grilla acorde a las dimensiones n*m < 2*1e5
    int n = getRandomNumber(1, 2*100000);
    int m = (2*100000)/n;
    cout << n << " " << m << '\n';

    // generamos un número que indica cuantos 1's habrá en la grilla
    int cnt = getRandomNumber(1, n*m);

    // para ambas grillas, escogemos coordenadas al azar desde las cuales se generará la figura
    int i0 = getRandomNumber(0, n-1);
    int j0 = getRandomNumber(0, m-1);
    int i1 = getRandomNumber(0, n-1);
    int j1 = getRandomNumber(0, m-1);

    // generamos la figura con los parámetros generados.
    vector<vector<bool>> grid1 = generateGrid(n, m, i0, j0, cnt);
    vector<vector<bool>> grid2 = generateGrid(n, m, i1, j1, cnt);
    
    // printeamos las grillas
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << grid1[i][j] << " ";
        }
        cout << '\n';
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << grid2[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}