#include<iostream>
#include<string>
#include<math.h>
#include<memory.h>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

class Edge;

int room[10][10];
int chk[10][10];
vector<Edge> ver;

void makeIsland(int i, int j, int d, int N, int M) {
	
	chk[i][j] = d;
	
	if (i != 0) {
		if (room[i - 1][j] == 1 && chk[i - 1][j] == 0) {
			makeIsland(i - 1, j, d, N, M);
		}
	}if (j != 0) {
		if (room[i][j - 1] == 1 && chk[i][j - 1] == 0) {
			makeIsland(i, j - 1, d, N, M);
		}
	}if (i != N - 1) {
		if (room[i + 1][j] == 1 && chk[i + 1][j] == 0) {
			makeIsland(i + 1, j, d, N, M);
		}
	}if (j != M - 1) {
		if (room[i][j + 1] == 1 && chk[i][j + 1] == 0) {
			makeIsland(i, j + 1, d, N, M);
		}
	}
}

int getParent(int parent[], int i) {
	if (i == parent[i]) return i;
	else return getParent(parent, parent[i]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

class Edge {
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

void makeEdge(int a, int b, int dist) {
	int i, t;
	
	if (a == b) return;
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}

	for (i = 0; i < ver.size(); i++) {
		if (ver[i].node[0] == a && ver[i].node[1] == b) {
			if(ver[i].distance < dist) return;
			else ver[i].distance = dist;
		}
	}

	ver.push_back(Edge(a, b, dist));
}

void getBridge(int i, int j, int N, int M) {
	int a, b, n, k;
	a = chk[i][j];
	b = 0;
	n = 1;
	while (i - n >=0) {
		if (chk[i - n][j] != 0) {
			b = chk[i - n][j];
			break;
		}
		n++;
	}
	if (n > 2 && b != 0) makeEdge(a, b, n - 1);
	n = 1;
	b = 0;
	while (j - n >= 0) {
		if (chk[i][j - n] != 0) {
			b = chk[i][j - n];
			break;
		}
		n++;
	}
	if (n > 2 && b != 0) makeEdge(a, b, n - 1);
	n = 1;
	b = 0;
	while (i + n <= N - 1) {
		if (chk[i + n][j] != 0) {
			b = chk[i + n][j];
			break;
		}
		n++;
	}
	if (n > 2 && b != 0) makeEdge(a, b, n - 1);
	n = 1;
	b = 0;
	while (j + n <= M - 1) {
		if (chk[i][j + n] != 0) {
			b = chk[i][j + n];
			break;
		}
		n++;
	}
	if (n > 2 && b != 0) makeEdge(a, b, n - 1);
}

int main(int argc, char** argv)
{
	int i, j, k;
	int ans = 0;
	int N, M;
	int n;
	int parent[7];

	memset(chk, 0, sizeof(chk));

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> k;
			room[i][j] = k;
		}
	}

	k = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (room[i][j] == 1 && chk[i][j] == 0) {
				makeIsland(i, j, k, N, M);
				k++;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (chk[i][j] != 0) getBridge(i, j, N, M);
		}
	}

	sort(ver.begin(), ver.end());

	for (i = 0; i < 7; i++) {
		parent[i] = i;
	}

	for (i = 0; i < ver.size(); i++) {
		if (!findParent(parent, ver[i].node[0], ver[i].node[1])) {
			ans += ver[i].distance;
			unionParent(parent, ver[i].node[0], ver[i].node[1]);
		}
	}

	k = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (k < chk[i][j]) k = chk[i][j];
		}
	}

	for (i = 2; i <= k; i++) {
		if (!findParent(parent, 1, i)) {
			ans = -1;
			break;
		}
	}

	cout << ans << endl;

	ver.clear();

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
