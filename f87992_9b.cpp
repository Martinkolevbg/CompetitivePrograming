#include <iostream>
#include <bitset>

using namespace std;

#define MAXN 2020

unsigned n;
int A[MAXN][MAXN];

const int MAX_VALUE = 10000;

char used[MAXN];
unsigned minCycle[MAXN], cycle[MAXN];
int curSum, minSum;

bool noCycle = true;
void printCycle()
{
	if (noCycle) { cout << "-1"; return; };
	cout << 1 << " ";
	for (int i = 0; i < n - 1; i++) cout << minCycle[i] + 1 << " ";
}

void hamilton(unsigned i, unsigned level)
{
	unsigned k;
	if ((0 == i) && (level > 0)) {
		if (level == n) {
			noCycle = false;
			minSum = curSum;
			for (k = 0; k < n; k++) minCycle[k] = cycle[k];
		}
		return;
	}
	if (used[i]) return;
	used[i] = 1;
	for (k = 0; k < n; k++)
		if (A[i][k] && k != i) {
			cycle[level] = k;
			curSum += A[i][k];
			if (curSum < minSum)
				hamilton(k, level + 1);
			curSum -= A[i][k];
		}
	used[i] = 0;
}

bitset<MAXN> us;
int main(void) {
	int Enum, x, y, len, maxV;
	while (cin >> Enum) {
		noCycle = true;
		maxV = 0;
		for (int i = 0; i < Enum; ++i) {
			cin >> x >> y >> len;
			--x, --y;
			us[x] = 1; us[y] = 1;
			A[x][y] = len; A[y][x] = len;
			maxV = (x > maxV) ? x : maxV;
			maxV = (y > maxV) ? y : maxV;
		}
		n = maxV + 1;
		for (int i = 0; i < n; ++i)
			used[i] = minCycle[i] = cycle[i] = 0;
		minSum = MAX_VALUE;
		curSum = 0;
		cycle[0] = 1;
		hamilton(0, 0);
		printCycle(); cout << "\n";

		us.reset();
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) A[i][j] = 0;
	}
	return 0;
}
