#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int f1=0, f2=0, f3=0;
	string s;

	cin >> s;
	cin.ignore();

	REP(i,0,s.size()) {
		if (s[i] == '1') f1++;
		else if (s[i] == '2') f2++;
		else if (s[i] == '3') f3++;
	}

	while(f1-->0) {
		cout << 1;
		if (f1>0 || (f1==0 && (f2>0 || f3>0))) cout << "+";
	}
	while (f2-->0) {
		cout << 2;
		if (f2>0 || (f2==0 && f3>0)) cout << "+";
	}
	while (f3-->0){
		cout << 3;
		if (f3>0) cout << "+";
	}
    
    return 0;
}

