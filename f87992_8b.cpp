#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <list>
#include <vector>
#include <cstdbool>
using namespace std;

const int MAXN = 2022;
bool A[MAXN][MAXN];
bitset<MAXN> used;

void DFS(unsigned i, const int& n)
{
	unsigned k;
	used[i] = 1;
	cout << i + 1 << " ";
	for (k = 0; k < n; k++)
		if (A[i][k] && !used[k]) DFS(k, n);
}

int main(void) {
	int Enum = 0, x, y, maxV = 0;
	while (cin >> Enum) {
		maxV = 0;
		for (int i = 0; i < Enum; ++i) {
			cin >> x >> y;
			--x, --y;
			used[x] = 1; used[y] = 1;
			A[x][y] = 1;
			A[y][x] = 1;
			maxV = (x > maxV) ? x : maxV;
			maxV = (y > maxV) ? y : maxV;
		}
		int x = 87992 % used.count();
		if (used[x] == 1) {
			used.reset();
			DFS(x, maxV + 1);
		}
		cout << "\n";
		used.reset();
		for (int i = 0; i < maxV + 1; ++i) for (int j = 0; j < maxV + 1; ++j) A[i][j] = 0;
	}
	return 0;
}
