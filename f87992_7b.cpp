// Martin Kolev && Petar Dudov && Teodor Raykov
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){

int n;
int temp;

vector<int> v;

while(cin>>n)
{
    for(int i = 0; i<n; ++i){
        cin>>temp;
        v.push_back(temp);
    }

    int dynamicTable[v.size()];
    for(int i = 0; i < v.size(); ++i)
    {
    dynamicTable[i]=0;
    }
    for(int i = v.size() - 1; i >= 0; --i) {
        for(int j = i+1 ; j < v.size(); ++j) {
            if(v[i] <= v[j]){
            dynamicTable[i] = max(dynamicTable[j], dynamicTable[i]);
            }
        }
        dynamicTable[i]++;
    }
    sort(dynamicTable,dynamicTable+v.size());
    cout << dynamicTable[v.size()-1]<<endl;
    v.clear();
}
return 0;
}
