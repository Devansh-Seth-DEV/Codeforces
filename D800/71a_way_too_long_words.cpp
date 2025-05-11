#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int n;
	string word;

	cin >> n;

	REP(i,0,n) {
		cin >> word;
		int len = word.size();
		if (len > 10) cout << word[0] << len-2 << word[len-1] << "\n";
		else cout << word << "\n";
	}
    
    return 0;
}

