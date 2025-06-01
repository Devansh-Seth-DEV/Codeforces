#include <bits/stdc++.h>
using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; i++)
#define FOR_REV(i,s,e) for (int i=s; i>e; i--)

#define SWP(A,i,j) \
	int temp=A[j]; \
	A[j]=A[i]; \
	A[i]=temp;

#define INIT_NEW_NUM_ARGS_IMPL(_1, _2, _3, _4, _5, N, ...) N
#define INIT_NEW_NUM_ARGS(...) INIT_NEW_NUM_ARGS_IMPL(__VA_ARGS__, 5, 4, 3, 2)

#define INIT_NEW_ARGS_2(src,n) FOR(i,0,n) src[i] = 0
#define INIT_NEW_ARGS_3(src,n,v) FOR(i,0,n) src[i] = v
#define INIT_NEW_ARGS_4(src,n,v,inc) \
    int temp=v;\
    FOR(i,0,n) {\
        src[i] = temp;\
        temp += inc;\
    }
#define INIT_NEW_ARGS_5(src,n,v,oprnd,op) \
	int temp=v;\
	FOR(i,0,n) {\
		src[i] = temp;\
		temp = temp op oprnd;\
	}

#define INIT_NEW_CHOOSER(...) INIT_NEW_NUM_ARGS(__VA_ARGS__)

#define INIT_NEW_EXPAND_HELPER(count, ...) INIT_NEW_ARGS_##count(__VA_ARGS__)
#define INIT_NEW_EXPAND(count, ...) INIT_NEW_EXPAND_HELPER(count, __VA_ARGS__)


#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define INIT_NEW(...) INIT_NEW_EXPAND(INIT_NEW_CHOOSER(__VA_ARGS__), __VA_ARGS__)

#define RI(i) int i; cin >> i

#define PB push_back
#define F first
#define S second

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n);
		vpii a;

		FOR(i,0,n) { RI(x); a.PB({abs(x), i}); }
		sort(a.begin(), a.end());

		int m=(n>>1)+1;
		bool isF=false;
		FOR(i,0,m) {
			if (a[i].S==0) { isF=true; break; }
		}

		cout << (isF ? "YES\n" : "NO\n");
	}
    
    return 0;
}
