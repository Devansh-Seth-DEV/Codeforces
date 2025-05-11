#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n, cnt=0;
	cin >> n;

	REP(i,0,n) {
		int p, v, t;
		cin >> p >> v >> t;

		if(p+v+t >= 2) cnt++;
	}	
    
	cout << cnt;
    return 0;
}

