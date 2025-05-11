#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    int w;
    cin >> w;
    
	if (w==2 || (w&1)) cout << "NO";
	else cout << "YES";
    
    return 0;
}

