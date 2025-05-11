#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int k, n, w;
	cin >> k >> n >> w;

	int rate = k * ((w * (w+1)) >> 1);
	
	if (n >= rate) cout << 0;
	else cout << rate - n;
    
    return 0;
}

