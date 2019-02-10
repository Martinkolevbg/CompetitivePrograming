#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <bitset>
using namespace std;
int cnt;
string line,word;
bitset<26> alphab;
set<string> groups;

int main() {
	line.resize(500); line.clear();
	word.resize(51); word.clear();
	while (getline(cin, line)) {
		int size = line.size();
		for (int i = 0; i < size; ++i) {
			while (line[i] != ' ' && i < size) {
				alphab[line[i] - 97] = true;
				++i;
			}
			if (alphab.count() > 0) {
				for (int i = 0; i < 26; ++i)
					if (alphab[i]) word.push_back(i + 'a');
				groups.insert(word);
				word.clear();
				alphab.reset();
			}
		}
		cout << groups.size() << "\n";
		groups.clear();
	}
	return 0;
}
