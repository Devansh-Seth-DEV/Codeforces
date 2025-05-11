#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int x;
	cin >> x;
	
	int cnt=0;
	while(x>0) {
		cnt++;
		int k=5;
		if (x < k) k=x;
		x -= k;
	}

	cout << cnt;
    
    return 0;
}

