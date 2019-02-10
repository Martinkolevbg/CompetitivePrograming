// Martin Kolev - f87992 & Petar Dudov - f88232
#include <iostream>
#include <set>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int main()
{
    unsigned b;
    std::set<unsigned long long> val;
    std::set<unsigned long long>::iterator it;

    while(cin >> b)
    {
        srand(b);
        for( unsigned i = 0; i  < 10 ; i++)
        {
            val.insert(i);
        }
        for(unsigned long long i = 0; i < 10000;i++)
        {
            unsigned long long temp = rand()%100000;
            it = val.begin();

            if(temp > *it)
            {
                val.insert(temp);
                if (val.size() > 10){
                    val.erase (*it);
                }
            }

        }
    for (it = val.end(), --it; it != val.begin(); it--)
    {
        std::cout << *it << " ";
    }
    cout << *val.begin() <<endl;
    val.clear();
    }

    return 0;
}
