// f87992 - Martin Kolev & f88232 - Petar Dudov
#include <iostream>
#include <sstream>

using namespace std;

void next(string  &word, int n){
    char temp;
    for(int i = 0; i<n; ++i ){
        temp = word[0];
        for(int j = 0; j<word.length(); ++j){
            word[j] = word[j+1];
        }
        word[word.length()-1] = temp;
    }
}

void print(string & word){
    if(word.length() <=10) cout << word<<endl;
    else{
        for(int i = 0 ; i< 10; ++i)cout << word[i];
        cout << endl;
    }
}

int main(){
    int n, k;
    string num, line;
    while (getline(cin, line)) {
        getline(cin, num);
        istringstream is(num);
        n = line.size();
        string next_line;
        while (is >> k or !is.eof()) {
            next_line = line;
            if (0 != n){
                  next(next_line, k % n);
                  print(next_line);
            }
            else{
                  print(next_line);
            }
        }
    }
return 0;
}
