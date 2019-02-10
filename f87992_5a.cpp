// F87992 Martin Kolev & F88232 Petar Dudov
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long double ld;

int const fnum = 87992 % 100;
ld const tol = 1.0e-20L;

ld f(long double x, long a) {
	ld fX = pow(x, 5) - 2 * pow(x, 3) - a * x * x - x - fnum ;
	return fX;
}
void solve(long a) {
    ld min =0L, max = 10L;
    ld funMax = f(max, a);
    if(funMax < 0){cout<< "NO SOLUTION"<<endl; return;}
    ld mid = 1 + (max - 1) / 2.0L;
    ld prevMid = mid + 1;
    ld minFun = f(min , a);
    ld funMid = f(mid, a);
    while(fabs(funMid)> tol && mid != prevMid){
        if(minFun * funMid > 0){min = mid; minFun = funMid;}
        else{ max = mid; funMax = funMid;}
        prevMid = mid;
        mid = min + (max - min) / 2.0L;
        funMid = f(mid, a);
    }
    cout << setprecision(20) << mid << endl;
}
int main() {
	long a;
	while (cin >> a) solve(a);
	return 0;
}
