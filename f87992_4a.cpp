// Martin Kolev - f87992 & Petar Dudov - f88232
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

bool cmp(string a, string b)
{
      int length1 = a.length();
      int length2 = b.length();

      if(length1 < length2)
      {
            return true;
      }
      if(length2 < length1)
      {
            return false;
      }
      for(int i = 0; i< length1; ++i)
            {
                  if(a[i] < b[i])
                  {
                        return true;
                  }
                  if(a[i] > b[i])
                  {
                        return false;
                  }
            }
      return false;
}
int main()
{




      string tempp;
      int temp;
      int sett;
      int n, m;
      vector<int> position;
      vector<string> str;

      string line;
      int k;
      cin>>sett;

      for(int j = 0; j< sett; ++j)
      {
            cin >> n>> m;

            for(int i=0; i<m; ++i)
            {
                  cin>> temp;
                  position.push_back(temp-1);
            }

            for(int i = 0; i<n; ++i)
            {
                  cin >> tempp;
                  str.push_back(tempp);
            }

            sort(str.begin(),str.end(), cmp);


            for (int i =0; i<position.size(); ++i)
            {
                  cout << str[position[i]]<<endl;
            }

            position.clear();
            str.clear();

      }


return 0;
}
