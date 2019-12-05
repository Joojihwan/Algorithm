#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<utility>
#include<memory.h>

using namespace std;

int room[100][100];
int flag[101];

void setFlag() {
	int i;
	for (i = 0; i <= 100; i++) flag[i] = 0;
}

void doR(int r, int c) {
	int i, j, n, m, check;

	

	for (i = 0; i <= r; i++) {
		
		setFlag();
		
		for (j = 0; j <= c; j++) {
			flag[room[i][j]]++;
		}

		j = 0;
		for (n = 1; n <= 100; n++) {
			for (m = 1; m <= 100; m++) {
				if (flag[m] == n) {
					room[i][j] = m;
					room[i][j + 1] = n;
					j += 2;
				}
				if (j >= 100)break;
			}
			if (j >= 100) break;
			check = 0;
			for (m = 1; m <= 100; m++) {
				if (flag[m] > n) check = 1;
			}
			if (check == 0)break;
		}
		for (n = j; n < 100; n++) room[i][n] = 0;
	}
}

void doC(int r, int c) {
	int i, j, n, m, check;

	for (j = 0; j <= c; j++) {
		setFlag();
		for (i = 0; i <= r; i++) {
			flag[room[i][j]]++;
		}

		i = 0;
		for (n = 1; n <= 100; n++) {
			for (m = 1; m <= 100; m++) {
				if (flag[m] == n) {
					room[i][j] = m;
					room[i + 1][j] = n;
					i += 2;
				}
				if (i >= 100)break;
			}
			if (i >= 100) break;
			check = 0;
			for (m = 1; m <= 100; m++) {
				if (flag[m] > n) check = 1;
			}
			if (check == 0)break;
		}
		for (n = i; n < 100; n++) room[n][j] = 0;
	}
}

int main(int argc, char** argv)
{
	memset(room, 0, sizeof(room));

	int i, j, k, t;
	int R, C, K;
	int a, b;

	cin >> R >> C >> K;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> k;
			room[i][j] = k;
		}
	}

	t = 0;

	while (t <= 100) {
		a = 0; b = 0;

		if (room[R - 1][C - 1] == K) break;

		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				if (room[i][j] != 0) {
					if (i > a) a = i;
					if (j > b) b = j;
				}
			}
		}

		if (a >= b) doR(a, b);
		else doC(a, b);

		t++;
	}

	if (t > 100) t = -1;

	cout << t << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}