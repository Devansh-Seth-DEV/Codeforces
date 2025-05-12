#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	string s;
	cin >> s;
	cin.ignore();

	int ucnt=0;
	REP(i,0,s.size()) {
		if (s[i] >= 65 && s[i] <= 90) ucnt++;
	}

	int lcnt=s.size()-ucnt;

	REP(i,0,s.size()) {
		if (lcnt==ucnt || lcnt > ucnt) {
			cout << (char) ((s[i]<=90) ? s[i]+32 : s[i]);
		} else {
			cout << (char) ((s[i]>90) ? s[i]-32 : s[i]);
		}
	}
    
    return 0;
}

