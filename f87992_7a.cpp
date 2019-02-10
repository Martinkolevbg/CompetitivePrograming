// Martin Kolev && Petar Dudov && Teodor Raykov
#include <iostream>
#include <sstream>
#include <vector>
#define MAX 100
#define MAXVALUE 200

using namespace std;


unsigned char can[MAX*MAXVALUE];

vector<int> m;

void solve(vector<int> m, int n)
{ unsigned long p;
 unsigned i, j;

 for (p = i = 0; i < n; p += m[i++]);

 for (i = 1; i <= p; i++)
can[i] = 0;
 can[0] = 1;

 for (i = 0; i < n; i++)
 for (j = p; j+1 > 0; j--)
 if (can[j])
can[j + m[i]] = 1;

 for (i = p / 2; i > 1; i--)
 if (can[i]) {
cout << i << " " << p-i<<endl;
 return;
 }
}
int main(void)
{
    string line;
    int n ;
    int nn;
    while(getline(cin,line))
{
    istringstream is(line);
    while(is>>n)
{
    m.push_back(n);

}

    nn = m.size();
 solve(m, nn);
 m.clear();
}
 return 0;
}
