#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

#define Min(X,Y) ((X) < (Y) ? (X) : (Y))
#define size 50

using namespace std;

string nameF;
ofstream out("output.txt", ios::out);

void knapsack(int i, int profit, int weight);
bool getBound(int i, int weight);

vector<int> outA;
int p[size];
int w[size];
int bestset[size];
int include[size];
int N, W, maxprofit;

int main(void) {

	int i, j, k, tmp, a, b;

	cout << "input file name? ";
	cin >> nameF;

	ifstream in(nameF, ios::in);
	char buf[100];

	maxprofit = 0;

	if (in.is_open()) {
		in >> N >> W;
		i = 1;
		while (!in.eof()) {
			in >> a >> b;
			p[i] = a; w[i] = b;
			i++;
		}
	}
	else {
		cout << "Cannot find" << endl;
	}

	knapsack(0, 0, 0);

	cout << maxprofit << endl;

	for (i = 1; i <= N; i++) {
		cout << bestset[i] << endl;
	}
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

void knapsack(int i, int profit, int weight) {
	int j;
	
	if (weight <= M && profit > maxprofit) {
		maxprofit = profit;
		for (j = 1; j <= n; j++) bestset[j] = include[j];
	}

	if (getBound(i,profit,weight) {
		include[i + 1] = 1;
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);

		include[i + 1] = 0;
		knapsack(i + 1, profit, weight);
	}
}

bool getBound(int i, int profit, int weight) {
	int j, k;
	int totweight;
	float bound;
	bool ans = true;

	if (weight >= M) ans = false;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;

		while (j <= N && totweight + w[j] <= M) {
			totweight += w[j];
			bound += p[j];
			j++;
		}
		k = j;
		if (k <= N) {
			bound += (M - totweight) * p[k] / w[k];
			ans = bound > maxprofit;
		}
	}
	return ans;
}