//f87992 - Martin Kolev
#include <iostream>
using namespace std;

void primes(int low){
    int high = low*2;
    int i = 0;
    int flag = 0;
    int res = 0;

    while (low < high){
        flag = 0;
        for(i = 2; i <= low/2; ++i){
            if(low % i == 0){flag = 1; break;}
        }
            if (flag == 0)res++;low++;
    }
    cout << res <<endl;
}
int main(){
    int n;
    while(cin >> n)primes(n);
    return 0;
}
