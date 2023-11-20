#include <bits/stdc++.h>
using namespace std;

vector<int> di = {0, -1, 0, 1};
vector<int> dj = {-1, 0, 1, 0};

int INF = 1e9;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ground(n, vector<int>(m, 0));
	vector<vector<int>> wall(n, vector<int>(m, 0));
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	vector<pair<int,int>> fig;
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
	// multisource bfs desde alguna casilla del piso.
	// buscamos la distancia minima a cualquier casilla de la pared
	vector<vector<int>> dist(n, vector<int>(m, INF));
	queue<pair<int,int>> q;
	// contar cuantos intersectan
	int intersect = 0;
	for(auto p: fig){
		q.push(p);
		dist[p.first][p.second] = 0;
		if(wall[p.first][p.second]) intersect++;
	}
	int mindist;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[x][y];
		q.pop();
		if(wall[x][y]){
			mindist = d;
			break;
		}
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		for(int k = 0; k<4; k++){
			int xx = x+di[k];
			int yy = y+di[k];
			if(xx < 0 || xx >=n || yy < 0 || yy >= n || vis[xx][yy]) continue;
			q.push({xx,yy});
			dist[xx][yy] = d + 1;
		}
	}
	// la respuesta se puede descomponer en:
	// operaciones para dejar un bloque al lado de la figura final max(0, mindist-1)
	// operaciones para rellenar la figura final (tamaño de la figura - bloques ya intersectados)
	cout << max(0, mindist-1) + cntwall - intersect << '\n';
	return 0;
}
