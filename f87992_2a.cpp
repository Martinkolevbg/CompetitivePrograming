//f87992 - Martin Kolev
//f88232 - Petar Dudov
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void primes(bool *arr)
{
    for(int i = 0; i<2001; ++i)
    {
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;
	int nsqrt = sqrt(2001);
	for(int i = 2; i<=nsqrt; ++i)
    {
        if(arr[i])
        {
            for(int j = i*i;j<=2001;j+=i)
            {
				arr[j]=false;
			}
        }
    }
}
int main(){
    bool isprime[2001];
    primes(isprime);
    unsigned int N, i, j;
    unsigned short k;
    unsigned int counter = 0;
    while(cin >> k >>N){
    for( i=1; i<N; ++i)
    {
        int temp = (  ((1+sin(0.1*i))*k)+1 );
        if(isprime[temp])
        {
            j = i;
            while(temp== (  ((1+sin(0.1*(j+1)))*k)+1 ) );
            {
                counter++;
                j++;
            }
        }

    }
    cout << counter<<endl;
    }
return 0;
}
