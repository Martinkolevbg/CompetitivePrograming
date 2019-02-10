// f87992 Martin Kolev && f88232 Petar Dudov
#include <stdio.h>
#include <iostream>
#define MAX 101

using namespace std;
const int s = 1;
int A[MAX][MAX];
const int MAX_VALUE = 10000;
int T[MAX], d[MAX];
int pred[MAX];
void dijkstra(int s,int n)
{
	for (int i = 0; i < n; i++)
		if (A[s][i] == 0){ d[i] = MAX_VALUE; pred[i] = -1;}
		else{
			d[i] = A[s][i]; pred[i] = s;
		}
	for (int i = 0; i < n; i++){
		T[i] = 1;
	}
	T[s] = 0;
	pred[s] = -1;
	while (1){
		int j = -1;
		int di = MAX_VALUE;
		for (int i = 0; i < n; i++){
			if (T[i] && d[i] < di)
			{
				di = d[i];
				j = i;
			}
		}
		if (j == -1) break;
		T[j] = 0;
		for (int i = 0; i < n; i++)
			if (T[i] && A[j][i] != 0)
				if (d[i] > d[j] + A[j][i]){
					d[i] = d[j] + A[j][i];
					pred[i] = j;
				}
	}
}

void printPath(int s, int j)
{
	if (pred[j] != s){
		printPath(s, pred[j]);
	}
	cout << j + 1 << " ";
}
void printResult(int s, int n){
    for (int i = 0; i < n; i++){
		if (i != s){
			if (d[i] == MAX_VALUE){
				cout << -1 << " ";
			}
			else{
				cout << d[i] << " ";

			}
		}
		else{
			if (d[i] == MAX_VALUE){
				cout << 0 << " ";
			}
			else{
				cout << d[i] << " ";
			}
		}
	}
	cout << endl;
}

int main(){
	int cnt, a, b, c, n;
	while (cin >> cnt){
		for (int i = 0; i < MAX; i++){
			for (int j = 0; j < MAX; j++) A[i][j] = 0;
		}
		int temp = 0;
		for (int i = 0; i < cnt; i++){
			cin >> a >> b >> c;
			if (a > temp){
				temp = a;
			}
			if (b > temp){
				temp = b;
			}
			A[a - 1][b - 1] = c;
		}
		n = temp;

		for (int i = 0; i < n; i++){
			int s = i;
			dijkstra(s , n);
			printResult(s, n);
		}

	}
}
