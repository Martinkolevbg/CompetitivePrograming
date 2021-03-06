// f87992 Martin kolev & Teodor Raykov
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int gcd(const int& a, const int& b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int lcm(const int& x, const int& y) {
	int least_common = x * y / gcd(max(x, y), min(x, y));
	return least_common;
}
class Fraction {
public:
	Fraction() : a(0), b(1) {}
	Fraction(int _a, int _b) : a(_a), b(_b) {}
	bool isNatural() {
		if (gcd(a, b) == b) return true;
		return false;
	};
	void factorize() {
		int common_f = gcd(max(abs(a), b), min(abs(a), b));
		if (common_f == 1) return;
		a /= common_f;
		b /= common_f;
	}
	void print_fract() {
		factorize();
		if (b == 1) cout << a << endl;
		else cout << a << '/' << b << endl;
	}
	Fraction operator+(Fraction y) {
		if (b == y.b) return Fraction(a + y.a, b);
		int common_m = lcm(b, y.b);
		int x_m = common_m / b;
		int y_m = common_m / y.b;
		return Fraction(a * x_m + y.a * y_m, common_m);
	}
	Fraction operator-(Fraction& y) {
		if (b == y.b) return Fraction(a - y.a, b);
		int common_m = lcm(b, y.b);
		int x_m = common_m / b;
		int y_m = common_m / y.b;
		return Fraction(a * x_m - y.a * y_m, common_m);
	}
private:
	int a, b;
};

int main() {
	string line;
	int k, j;
	char sign, dash;
	while (getline(cin, line))
	{
		istringstream is(line);
		is >> k >> dash >> j;
		Fraction sum = Fraction(k, j);
		while (!is.eof()) {
			is >> sign >> k >> dash >> j;
			if (sign ==  '+') {
				sum = sum + Fraction(k, j);
			}
			else {
				sum = sum + Fraction(-k, j);
			}
		}
		sum.print_fract();
	}
	return 0;
}
