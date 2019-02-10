// f87992 - Martin Kolev & f88232 - Petar Dudov
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string ma(vector<string>& vec, int& n)
{
    int mid = n/2;
    int count = 0;
    string temp = vec[0];
    for(int i = 1; i<vec.size(); ++i){
        if(vec[i] == temp){
            ++ count;
            temp = vec[i];
            if(count >= mid){return temp;}
        }
        else {temp = vec[i]; count = 0;}
    }
      return "---";
}
int main(){
string temp;
vector<string> vec;
int n;
while(cin>>n){
    for(int i = 0; i<n; ++i){
        cin >> temp;
        vec.push_back(temp);
    }
sort(vec.begin(), vec.end());
cout <<  ma(vec, n)<<endl;
vec.clear();
}
return 0;
}
