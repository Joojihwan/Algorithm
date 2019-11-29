#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

#define Min(X,Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

int main(void) {

	int i, j, k, tmp, a, b, min;
	char nameF[50];
	vector< pair<int, int> > outA;
	int N;


	cout << "input file name? ";
	cin >> nameF;

	ofstream out("output.txt");

	freopen(nameF, "r", stdin);

	cin >> N;

	char *line;
	line = new char[N];
	// = (char *)malloc(sizeof(char) * N);
	int **room;
	room = new int*[N + 1];
	for (i = 0; i < N + 1; i++) {
		room[i] = new int[N + 1];
	}
	//= (int **)malloc(sizeof(int*) * N );

	int **length;
	length = new int*[N + 1];
	for (i = 0; i < N + 1; i++) {
		length[i] = new int[N + 1];
	}
	int **before;
	before = new int*[N + 1];
	for (i = 0; i < N + 1; i++) {
		before[i] = new int[N + 1];
	}

	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			room[i][j] = 1;
			length[i][j] = 9999999;
		}
	}

	for (i = 1; i <= N; i++) {
		cin >> line;
		for (j = 0; j < N; j++) {
			if (line[j] == '1') room[i][j + 1] = 0;
			else room[i][j + 1] = 1;
		}
	}

	length[1][1] = 0;

	while (true) {
		min = 9999999;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (length[i][j] >= 0 && length[i][j] <= min) { // 현재 최소인 경로 끝에서
					min = length[i][j];
					a = i;
					b = j;
				}
			}
		}

		if (a == N && b == N) break;

		if (a - 1 > 0 && length[a - 1][b] != -1) {
			length[a - 1][b] = length[a][b] + room[a - 1][b];
			before[a - 1][b] = 3; // 1,2,3,4 U,R,D,L
		}
		if (b - 1 > 0 && length[a][b - 1] != -1) {
			length[a][b - 1] = length[a][b] + room[a][b - 1];
			before[a][b - 1] = 2;
		}
		if (a + 1 <= N && length[a + 1][b] != -1) {
			length[a + 1][b] = length[a][b] + room[a + 1][b];
			before[a + 1][b] = 1;
		}
		if (b + 1 <= N && length[a][b + 1] != -1) {
			length[a][b + 1] = length[a][b] + room[a][b + 1];
			before[a][b + 1] = 4;
		}

		length[a][b] = -1; // 지나온 방

	}

	i = N;
	j = N;

	while (i != 1 || j != 1) {
		outA.push_back(make_pair(i, j));
		if (before[i][j] == 1) {
			i--;
		}
		else if (before[i][j] == 2) {
			j++;
		}
		else if (before[i][j] == 3) {
			i++;
		}
		else if (before[i][j] == 4) {
			j--;
		}
	}

	if (out.is_open()) {

		out << length[N][N] << endl;

		out << "1 1" << endl;

		k = outA.size();

		for (i = 0; i < k; i++) {
			out << outA.back().second << " " << outA.back().first << endl;
			outA.pop_back();
		}
	}

	cout << "Done" << endl;

	delete line;
	delete room;
	delete length;
	delete before;

	return 0;
}