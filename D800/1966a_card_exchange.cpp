#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define RI(i) int i; cin >> i
#define F first
#define S second 

typedef unordered_map<int, int> umpii;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n); RI(k);
		umpii um;	
		int maxi=1;
		REP(i,0,n) {
			RI(x);
			if (maxi>=k) continue;
			auto it = um.find(x);
			if (it != um.end()) {
				it->S+=1;
				if (it->S > maxi) maxi=it->S;
			} else um.insert({x, 1});
		}
		if(maxi<k) cout << n << "\n";
		else cout << k-1 << "\n";
	}
    
    return 0;
}
