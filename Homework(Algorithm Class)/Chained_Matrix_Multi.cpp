#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define Min(X,Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

string nameF;
string s;
vector<int> inM;
vector<char> outA;
int M[100][100];
int P[100][100];
char cnt = '1';

void print_order(int i, int j) {
	int k;

	if (i == j) {
		outA.push_back(cnt++);
	}
	else {
		k = P[i][j];
		outA.push_back('(');
		print_order(i, k);
		print_order(k + 1, j);
		outA.push_back(')');
	}
}

int main(void) {

	int i, j, k, diagonal, tmp, p;

	cout << "input file name? ";
	cin >> nameF;

	ifstream in(nameF);
	ofstream out("output.txt");
	char buf[100];

	if (in.is_open()) {
		while (!in.eof()) {
			in >> k;
			inM.push_back(k);
		}
	}
	else {
		cout << "Cannot find" << endl;
	}

	for (i = 1; i <= inM.size(); i++) {
		M[i][i] = 0;
	}
	
	for (diagonal = 1; diagonal < inM.size(); diagonal++) {
		for (i = 1; i < inM.size() - diagonal; i++) {
			j = i + diagonal;
			tmp = 100000;
			for (k = i; k < j; k++) {
				p = tmp;
				tmp = Min(tmp, (M[i][k] + M[k+1][j] + (inM[i - 1] * inM[k] * inM[j])));
				if (p > tmp) P[i][j] = k;
			}
			M[i][j] = tmp;
		}
	}

	print_order(1, inM.size() - 1);
	
	i = 0;

	if (out.is_open()) {
		while (i < outA.size()) {

			out << outA[i++];
		}
	}

	cout << "Done" << endl;
	return 0;
}