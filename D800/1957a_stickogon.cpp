#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define RI(i) int i; cin >> i
#define S second

typedef unordered_map<int, int> umapii;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n);
		umapii um;	
		int p=0;
		REP(i,0,n) {
			RI(x);
			auto it = um.find(x);
			if (it != um.end()) {
				if (it->S+1>=3) {
					p++;
					it->S=0;
					//cout << "ended at: " << i+1 << "\n";
				}
				else it->S+=1;
			} else um.insert({x, 1});
		}
		cout << p << "\n";
	}
    
    return 0;
}
