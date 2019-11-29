#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define Min(X,Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

string nameF;
vector<int> outA;
int N, M, L, R;
int PP[1001][1001][3] = { 0, };
int EE[1001][1001][3] = { 0, };
vector<int> D, W, WS;

int main(void) {

	int i, j, k, tmp, a, b;

	cout << "input file name? ";
	cin >> nameF;

	ifstream in(nameF);
	ofstream out("output.txt");
	char buf[100];

	D.push_back(0);
	W.push_back(0);
	WS.push_back(0);

	if (in.is_open()) {
		in >> N >> M;
		while (!in.eof()) {
			in >> i >> j;
			D.push_back(i);
			W.push_back(j);
		}
	}
	else {
		cout << "Cannot find" << endl;
	}

	for (i = 1; i < W.size(); i++) {
		tmp = 0;
		for (j = 1; j <= i; j++) {
			tmp += W[j];
		}
		WS.push_back(tmp);
	}
	
	for (i = 1; i <= N; i++) {
		EE[i][i][1] = EE[i][i][2] = 1000000;
		PP[i][i][1] = PP[i][i][2] = 0;
	}
	EE[M][M][1] = EE[M][M][2] = 0;

	for (i = 1; i < N; i++) {
		for (j = 1; i + j <= N; j++) {
			L = j;
			R = i + j;

			a = EE[L + 1][R][1] + ((D[L + 1] - D[L]) *(WS[N] - (WS[R] - WS[L])));
			b = EE[L + 1][R][2] + ((D[R] - D[L]) *(WS[N] - (WS[R] - WS[L])));
			EE[L][R][1] = Min(a, b);
			if (a < b) PP[L][R][1] = L + 1;
			else PP[L][R][1] = R;

			a = EE[L][R - 1][1] + ((D[R] - D[L]) *(WS[N] - (WS[R - 1] - WS[L - 1])));
			b = EE[L][R - 1][2] + ((D[R] - D[R - 1]) *(WS[N] - (WS[R - 1] - WS[L - 1])));
			EE[L][R][2] = Min(a, b);
			if(a < b) PP[L][R][2] = L;
			else PP[L][R][2] = R - 1;
			
		}
	}
	
	outA.clear();

	L = 1;
	R = N;

	if (EE[1][N][1] > EE[1][N][2]) outA.push_back(N);
	else outA.push_back(1);

	while (true) {
		if (L == R) break;
		if (EE[L][R][1] < EE[L][R][2]) {
			outA.push_back(PP[L][R][1]);
			L++;
		}
		else {
			outA.push_back(PP[L][R][2]);
			R--;
		}
	}
	
	if (out.is_open()) {
		out << Min(EE[1][N][1], EE[1][N][2]) << endl;

		for (i = 0; i < N; i++) {
			out << outA.back() << endl;
			outA.pop_back();
		}
	}

	cout << "Done" << endl;
	return 0;
}