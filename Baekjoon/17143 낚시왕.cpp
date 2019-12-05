#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<utility>
#include<memory.h>

using namespace std;

int room[100][100][3];
int tmp[100][100][3];

void settmp(int n) {
	int i, j;
	if (n == 1) { // 초기화만
		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				tmp[i][j][0] = 0;
				tmp[i][j][1] = 0;
				tmp[i][j][2] = 0;
			}
		}
	}
	else if (n == 2) { // 복사 후 초기화
		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				room[i][j][0] = tmp[i][j][0];
				room[i][j][1] = tmp[i][j][1];
				room[i][j][2] = tmp[i][j][2];
				tmp[i][j][0] = 0;
				tmp[i][j][1] = 0;
				tmp[i][j][2] = 0;
			}
		}
	}
}

int getShark(int j, int R) {
	int i,a;
	for (i = 0; i < R; i++) {
		if (room[i][j][2] > 0) {
			room[i][j][0] = 0;
			room[i][j][1] = 0;
			a = room[i][j][2];
			room[i][j][2] = 0;
			return a; 
		}
	}
	return 0;
}

void moveShark(int i, int j, int R, int C) { // i,j 에 위치한 상어 움직이기
	int s, d, z, t;
	s = room[i][j][0];
	d = room[i][j][1];
	z = room[i][j][2];
	t = s;

	while (s > 0) {
		if (d == 1) {
			if (i == 0) {
				d = 2;
				i++;
			}
			else i--;
		}
		else if (d == 2) {
			if (i == R - 1) {
				d = 1;
				i--;
			}
			else i++;
		}
		else if (d == 3) {
			if (j == C - 1) {
				d = 4;
				j--;
			}
			else j++;
		}
		else if (d == 4) {
			if (j == 0) {
				d = 3;
				j++;
			}
			else j--;
		}
		s--;
	}

	if (tmp[i][j][2] > z) return;
	else {
		tmp[i][j][0] = t;
		tmp[i][j][1] = d;
		tmp[i][j][2] = z;
	}
}
int main(int argc, char** argv)
{
	int i, j, k;
	int N;
	int R, C, M;
	int r, c, s, d, z;
	int a, b;
	int ans = 0;

	cin >> R >> C >> M;

	for (i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		room[r - 1][c - 1][0] = s;//속력
		room[r - 1][c - 1][1] = d;//방향
		room[r - 1][c - 1][2] = z;//크기
	}

	settmp(1);

	for (j = 0; j < C; j++) {
		ans += getShark(j, R);
		for (a = 0; a < R; a++) {
			for (b = 0; b < C; b++) {
				if (room[a][b][2] > 0) {
					moveShark(a, b, R, C); 
				}
			}
		}
		settmp(2);
	}
	
	cout << ans << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}