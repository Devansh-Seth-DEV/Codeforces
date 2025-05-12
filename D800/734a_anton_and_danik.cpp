#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n, awin=0;
	cin >> n;

	REP(i,0,n) {
		char c;
		cin >> c;
		if (c=='A') awin++;
	}

	int dwin=n-awin;
	if (awin > dwin) cout << "Anton";
	else if (awin < dwin) cout << "Danik";
	else cout << "Friendship";
    
    return 0;
}

