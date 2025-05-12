#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n, k;
	cin >> n >> k;

	REP(i,0,k) {
		int r = n%10;
		if (r>0) n--;
		else n/=10;	
	}

	cout << n;
    
    return 0;
}

