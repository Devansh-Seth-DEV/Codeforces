#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	ll n;
	cin >> n;

	int cnt=0;
	while(n>0) {
		int r=n%10;
		if (r==4 || r==7) cnt++;
		n/=10;
	}

	cout << ((cnt==4 || cnt==7) ? "YES" : "NO");

    return 0;
}

