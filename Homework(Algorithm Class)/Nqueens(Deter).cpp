#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

#define Min(X,Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

string nameF;
ofstream out("output.txt", ios::out);

void queens(int i);
bool promising(int i);
void monte(int i);

vector<int> outA;
int col[10001] = { 0, };
int N;

int main(void) {

	int i, j, k, tmp, a, b;

	cout << "input file name? ";
	cin >> nameF;

	ifstream in(nameF, ios::in);
	char buf[100];


	if (in.is_open()) {
		while (!in.eof()) {
			in >> N;
		}
	}
	else {
		cout << "Cannot find" << endl;
	}

	queens(0);

	/*if (out.is_open()) {

		for (i = 0; i < N; i++) {
			out << outA.back() << endl;
			outA.pop_back();
		}
	}

	outA.clear();
	*/
	cout << "Done" << endl;

	return 0;
}

void queens(int i) {
	int j;
	if (promising(i)) {
		if (i == N) {
			if (out.is_open()) {
				for (j = 1; j <= N; j++) {
					out << col[j];
					if (j != N) out << endl;
				}
			}

			exit(1);
		}
		else {
			for (j = 1; j <= N; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
}

bool promising(int i) {
	int k = 1;
	bool ans = true;

	while (k < i && ans) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k)) {
			ans = false;
		}k++;
	}

	return ans;
}