#include <bits/stdc++.h>

using namespace std;
#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n, k;
	cin >> n >> k;

	int a[50];
	REP(i,0,n) {
		cin >> a[i];
	}

	int total=0;
	REP(i,0,n) {
		if (a[i] > 0 && a[i] >= a[k-1]) total++;
	}

	cout << total;
    
    return 0;
}

