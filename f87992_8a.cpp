#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <list>
#include <vector>
using namespace std;

const int MAXN = 2022;
bool A[MAXN][MAXN];
bitset<MAXN> used;
vector<int> queue(MAXN);

void BFS(const unsigned& i, const unsigned& maxV) {
	unsigned k, j, p, currentVert, levelVertex, queueEnd;
	for (int i = 0; i < maxV; ++i) {
		queue[i] = 0; used[i] = 0;
	}
	queue[0] = i;  used[i] = 1;
	currentVert = 0; levelVertex = 1; queueEnd = 1;
	while (currentVert < queueEnd) {
		for (p = currentVert; p < levelVertex; p++) {
			cout << queue[p] + 1 << " ";
			currentVert++;
			for (j = 0; j < maxV; j++)
				if (A[queue[p]][j] && used[j] == 0) {
					queue[queueEnd++] = j;
					used[j] = 1;
				}
		}
		levelVertex = queueEnd;
	}
}

int main(void) {
	int Enum = 0, x, y, maxV = 0;
	while (cin >> Enum) {
		maxV = 0;
		for (int i = 0; i < Enum; ++i) {
			cin >> x >> y; --x, --y;
			used[x] = 1; used[y] = 1;
			A[x][y] = 1;
			A[y][x] = 1;
			maxV = (x > maxV) ? x : maxV;
			maxV = (y > maxV) ? y : maxV;
		}
		int x = (87992 % used.count());
		if (used[x] == 1) {
			used.reset();
			BFS(x, maxV + 1);
		}
		cout << "\n";
		used.reset();
		for (int i = 0; i < maxV + 1; ++i) for (int j = 0; j < maxV + 1; ++j) A[i][j] = 0;
	}
	return 0;
}
