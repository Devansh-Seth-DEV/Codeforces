#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	string s, t;
	cin >> s >> t;
	cin.ignore();

	if (s.size() != t.size()) {
		cout << "NO";
		return 0;
	}

	int j=s.size()-1;
	bool correct=true;
	REP(i,0,s.size()) {
		if (s[i] == t[j]) j--;
		else { correct=false; break; }
	}

	cout << ((correct) ? "YES" : "NO");
    
    return 0;
}

