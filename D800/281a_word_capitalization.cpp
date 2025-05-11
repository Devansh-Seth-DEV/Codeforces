#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	string s;
	cin >> s;
	cin.ignore();

	if (s[0]>90) s[0] = s[0]-32;

	cout << s;
    
    return 0;
}

