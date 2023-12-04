// partial should pass subtask 1 & 2

#include <bits/stdc++.h>
using namespace std;

vector<int> di = {0, -1, 0, 1};
vector<int> dj = {-1, 0, 1, 0};

int INF = 1e9;

int dist(pair<int,int> u, pair<int,int> v){
	int x1 = u.first;
	int y1 = u.second;
	int x2 = v.first;
	int y2 = v.second;
	return abs(x2-x1) + abs(y2-y1);
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ground(n, vector<int>(m, 0));
	vector<vector<int>> wall(n, vector<int>(m, 0));
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	vector<pair<int,int>> fig;
	vector<pair<int,int>> fig2;
	int cntground = 0;
	int cntwall = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> ground[i][j];
			cntground += ground[i][j];
			if(ground[i][j]) fig.push_back({i,j});
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> wall[i][j];
			cntwall += wall[i][j];
			if(wall[i][j]) fig2.push_back({i,j});
		}
	}
	// caso borde: la cantidad de 1's en las dos grillas es distinta
	if(cntground != cntwall){
		cout << "IMPOSIBLE" << '\n';
		return 0;
	}
	if(cntground == 1){
		pair<int,int> p = fig[0];
		if(wall[p.first][p.second]){
			cout << 0 << '\n';
		}
		else{
			cout << "IMPOSIBLE" << '\n';
		}
		return 0;
	}
	// en vez de multisource comparamos todos los pares
	// buscamos la distancia minima a cualquier casilla de la pared
	
	// contar cuantos intersectan
	int intersect = 0;
	for(auto p: fig){
		if(wall[p.first][p.second]) intersect++;
	}
	int mindist = 1e9;
	for(int i = 0; i<fig.size(); i++){
		for(int j = 0; j<fig2.size(); j++){
			mindist = min(mindist, dist(fig[i], fig2[j]));
		}
	}
	// la respuesta se puede descomponer en:
	// operaciones para dejar un bloque al lado de la figura final max(0, mindist-1)
	// operaciones para rellenar la figura final (tamaño de la figura -)
	cout << max(0, mindist-1) + cntwall - intersect << '\n';
	return 0;
}
