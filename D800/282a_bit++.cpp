#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n, x=0;
	cin >> n;
	cin.ignore();

	REP(i,0,n) {
		string s;
		cin >> s;

		if (s[0]=='X') {
			(s[1] == '+') ? x++ : x--;
		} else if (s[0]=='+') ++x;
		else --x;
	}

	cout << x;
    
    return 0;
}


