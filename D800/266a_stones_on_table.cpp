#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n;
	cin >> n;

	char prev, curr;
	cin >> prev;
    
	int cnt=0;
	REP(i,0,n-1) {
		cin >> curr;
		if (curr == prev) cnt++;
		prev = curr;
	}

	cout << cnt;

    return 0;
}

