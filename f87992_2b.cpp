// f87992 - Martin Kolev
// f88232 - Petar Dudov
#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

bool prime(unsigned long long &n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (unsigned long long i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

unsigned long long result(unsigned long long &k, int &N ){
     vector<unsigned long long> vec;
     unsigned long long i;
     unsigned long long counter = 0;
     for(i=1; i<=N; ++i)
     {
          vec.push_back(  ((1+sin(0.1*i))*k)+1 );
     }

      for(i = 0; i<vec.size(); ++i)
      {
            if(prime(vec[i]))
            {
                  unsigned long long j = i;
                  while(vec[j]==vec[j+1])
                  {
                        i++;
                        counter++;
                        j++;
                  }
                  counter++;
                 // i += skip;
            }


            else{
            unsigned long long j = i;
            while(vec[i] == vec[j+1])
            {
                  i ++;
                  j++;
            }
            //i +=skip;
            }
      }
      return counter;
}

int main(){

int n1;
unsigned long long k1;
while(cin>>k1>>n1)
{
    cout << result(k1,n1)<<endl;
}

return 0;
}
