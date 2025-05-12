#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

bool is_distinct(int year) {
	int d1 = year/1000;
	int d2 = (year/100)%10;
	int d3 = (year/10)%10;
	int d4 = year%10;

	return (d1 != d2 && d1 != d3 && d1 != d4 &&
			d2 != d3 && d2 != d4 &&
			d3 != d4);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int y;
	cin >> y;

	while (true) {
		if (is_distinct(++y)) {
			cout << y;
			break;
		}
	}
    
    return 0;
}

