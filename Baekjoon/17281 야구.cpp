#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<utility>
#include<memory.h>

using namespace std;

vector<int> arr;
int ball[50][9];
int base[3];
int flag[9];

int getNow(int N);

int perm(int i, int N, int max) {
	int a, b;

	/*if (arr.size() == 3) {
		arr.push_back(1);
	}*/
	if (arr.size() > 4) {
		if (arr[0] == 5 && arr[1] == 6 && arr[2] == 7) {
			b = 0;
		}
	}
	if (arr.size() == 8) {
		b = getNow(N);
		if (b > max) {
			max = b;
		}
			return max;
	}
	
	for (a = i; a < 9; a++) {
		if (flag[a] == 0) {
			flag[a] = 1;
			arr.push_back(a + 1);
			b = perm(1, N, max);
			flag[a] = 0;
			arr.pop_back();
			if (b > max) max = b;
		}
	}
	return max;
}

void baseSet() {
	int i = 0;
	for (i = 0; i < 4; i++) base[i] = 0;
}

int baseGo(int n) {
	int i, score = 0;
	if (n == 1) {
		score = base[2];
		base[2] = 0;
		for (i = 1; i >= 0; i--) {
			if (base[i] == 1) base[i + 1] = 1;
			else base[i + 1] = 0;
		}
		base[0] = 1;
	}
	else if (n == 2) {
		score = base[2] + base[1];
		base[2] = 0;
		base[1] = 0;
		if (base[0] == 1) base[2] = 1;
		base[1] = 1;
		base[0] = 0;
	}
	else if (n == 3) {
		for (i = 0; i < 3; i++) score += base[i];
		baseSet();
		base[2] = 1;
	}
	else if (n == 4) {
		for (i = 0; i < 3; i++) score += base[i];
		score += 1;
		baseSet();
	}

	return score;
}

int getNow(int N) {
	int i, j, k = 0;
	int out = 0;
	int now, max = 0;
	int s = 0;

	now = 0;
	
	for (i = 0; i < N; i++) {
		out = 0;baseSet();
		while (out < 3) {
			if (k == 3 && s == 0) {
				j = 0;
				s = 1;
				k--;
			}
			else j = arr[k] - 1;
			if (ball[i][j] == 0) {
				out++;
			}
			else {
				now += baseGo(ball[i][j]);
			}
			k++;
			if (k == 8) {
				k = 0;
				s = 0;
			}
		}
	}
	if (now > max) max = now;

	return max;
}

int main(int argc, char** argv)
{
	int i, j, k;
	int N;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &k);
			ball[i][j] = k;
		}
	}

	for (i = 0; i < 8; i++) flag[i] = 0;

	flag[0] = 1;

	i = perm(1, N, 0);

	printf("%d\n", i);

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}