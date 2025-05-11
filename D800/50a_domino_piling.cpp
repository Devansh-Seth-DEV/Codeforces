#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int M, N;
	cin >> M >> N;

	int cnt = M * (N>>1);

	int v=0;
	if (N & 1) {
		if (M==2) v = 1;
		else if (M>2) v = M>>1;
	}
	cnt += v;

	cout << cnt;
    return 0;
}

