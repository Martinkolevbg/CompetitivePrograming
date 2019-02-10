#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


int sz, n, k, x;
	while (cin >> sz >> n >> k) {
        srand(87992%100);
        vector<int> arr;

		for (int i = 0; i < sz; ++i) {
			x = rand() % k;
			arr.push_back(x);
		}
		sort(arr.begin(), arr.end());
		cout << arr[n-1] << "\n";
		arr.clear();
	}
}
