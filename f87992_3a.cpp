#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int arr[20];
int n, sz, cnt, b;
bool sequeIsEqualToB;
string nums;
stringstream ss;
string signs[25];

void fun(int i = 0, int num = arr[0], int sum = 0) {  
	sum += num;
	if (i == sz - 1) {
		if (sum == b) sequeIsEqualToB = true;
		return;
	}
	if (!sequeIsEqualToB) {
		signs[i] = '+';
		fun(i + 1, +arr[i + 1], sum);
	}
	if (!sequeIsEqualToB) {
		signs[i] = '-';
		fun(i + 1, -arr[i + 1], sum);
	}
}

int main() {
	while (getline(cin, nums)) {
		ss << nums;
		int i = 0;
		while (ss) ss >> arr[i++];
		sz = i - 2;
		b = arr[sz];
		sequeIsEqualToB = false;
		fun();
		if (sequeIsEqualToB) {
			int i = 0;
			for (i = 0; i < sz - 1; ++i)
				cout << arr[i] << signs[i];
			cout << arr[i] << "=" << b << "\n";
		}
		else cout << "\n";
		ss.clear();
	}
}