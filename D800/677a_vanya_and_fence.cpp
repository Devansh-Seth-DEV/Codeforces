#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n, h;
	cin >> n >> h;

	int rw=0;
	REP(i,0,n) {
		int ph;
		cin >> ph;
		rw += (ph > h) ? 2 : 1;
	}

	cout << rw;
    
    return 0;
}

