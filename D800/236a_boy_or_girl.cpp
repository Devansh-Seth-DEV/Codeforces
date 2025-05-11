#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	string s;
	int dist=0, f[26] = {0};

	cin >> s;
	cin.ignore();

	REP(i,0,s.size()) {
		int index = (int) s[i] - 97;
		f[index]++;
		if (f[index] == 1) dist++;
	}

	if (dist & 1) cout << "IGNORE HIM!";
	else cout << "CHAT WITH HER!";
    
    return 0;
}

