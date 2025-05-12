#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n, in=0, cap=0;
	cin >> n;

	REP(i,0,n) {
		int a, b;
		cin >> a >> b;
		in = in - a + b;
		cap = max(cap, in);
	}

	cout << cap;
    
    return 0;
}

