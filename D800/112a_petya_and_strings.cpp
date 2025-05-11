#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	string s1, s2;

	cin >> s1 >> s2;
	cin.ignore();

	int l1=0, l2=0;
	int cmp=0;

	REP(i,0,s1.size()) {
		l1 = (s1[i] > 90) ? s1[i]-32 : s1[i];
		l2 = (s2[i] > 90) ? s2[i]-32 : s2[i];
		if (l1 < l2) { cmp = -1; break; }
		else if (l1 > l2) { cmp = 1; break; }
	}

	cout << cmp;
    
    return 0;
}

