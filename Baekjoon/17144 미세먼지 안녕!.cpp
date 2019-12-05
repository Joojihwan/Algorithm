#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<utility>
#include<memory.h>

using namespace std;

int room[50][50];
int tmp[50][50];

void setRoom() {
	int i, j;
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			room[i][j] = 0;
		}
	}
}

void settmp() { // tmp 초기화
	int i, j;
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			tmp[i][j] = 0;
		}
	}
}

void addtmp() { // 확산된 먼지 더하기
	int i, j;
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			room[i][j] += tmp[i][j];
		}
	}
}

void mise(int care, int R, int C) {
	int i, j, d, k;

	settmp();

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			for (d = 0; d < 4; d++) {
				k = room[i][j] / 5;// 확산될 먼지
				if (k <= 0) break;
				if (d == 0) {
					if (i != 0 && room[i - 1][j] != -1) {
						tmp[i - 1][j] += k;
						tmp[i][j] -= k;
					}
				}
				else if (d == 1) {
					if (j != C - 1) {
						tmp[i][j + 1] += k;
						tmp[i][j] -= k;
					}
				}
				else if (d == 2) {
					if (i != R - 1 && room[i + 1][j] != -1) {
						tmp[i + 1][j] += k;
						tmp[i][j] -= k;
					}
				}
				else if (d == 3) {
					if (j != 0 && room[i][j - 1] != -1) {
						tmp[i][j - 1] += k;
						tmp[i][j] -= k;
					}
				}
			}
		}
	}
	tmp[care - 1][0] = 0;
	tmp[care][0] = 0;
	addtmp();
}

void clean(int care, int R, int C) {
	int i, j, k, t;
	int a, b;
	i = care - 2; //윗 공기 청소
	j = 0;

	while (i > 0) { // i == 0될때까지, j = 0
		room[i][j] = room[i - 1][j];
		i--;
	}
	while (j < C - 1) { // i = 0
		room[i][j] = room[i][j + 1];
		j++;
	}
	while (i < care - 1) { // j = C -1
		room[i][j] = room[i + 1][j];
		i++;
	}
	while (j > 1) {
		room[i][j] = room[i][j - 1];
		j--;
	}room[care - 1][1] = 0;
	
	i = care + 1; // 밑 청소
	j = 0;
	while (i < R - 1) {
		room[i][j] = room[i + 1][j];
		i++;
	}while (j < C - 1) {
		room[i][j] = room[i][j + 1];
		j++;
	}while (i > care) {
		room[i][j] = room[i - 1][j];
		i--;
	}while (j > 1) {
		room[i][j] = room[i][j - 1];
		j--;
	}room[care][1] = 0;
}

int main(int argc, char** argv)
{
	int i, j, k;
	int N;
	int R, C, T;
	int care;

	cin >> R >> C >> T;

	setRoom();

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> k;
			room[i][j] = k;
			if (k == -1) care = i; // 공기청정기 두번째 좌표 r 저장
		}
	}
	
	for (i = 0; i < T; i++) {
		mise(care, R, C);
		clean(care, R, C);
	}
	k = 2;
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			k += room[i][j];
		}
	}

	cout << k << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}