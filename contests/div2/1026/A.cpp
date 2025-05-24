#include <bits/stdc++.h>
using namespace std;

#define INIT_NEW_NUM_ARGS_IMPL(_1, _2, _3, _4, _5, N, ...) N
#define INIT_NEW_NUM_ARGS(...) INIT_NEW_NUM_ARGS_IMPL(__VA_ARGS__, 5, 4, 3, 2)

#define INIT_NEW_ARGS_2(src,n) REP(i,0,n) src[i] = 0
#define INIT_NEW_ARGS_3(src,n,v) REP(i,0,n) src[i] = v
#define INIT_NEW_ARGS_4(src,n,v,inc) \
    int temp=v;\
    REP(i,0,n) {\
        src[i] = temp;\
        temp += inc;\
    }
#define INIT_NEW_ARGS_5(src,n,v,opr,op) \
	int temp=v;\
	REP(i,0,n) {\
		src[i] = temp;\
		temp = temp op opr;\
	}

#define INIT_NEW_CHOOSER(...) INIT_NEW_NUM_ARGS(__VA_ARGS__)

#define INIT_NEW_EXPAND_HELPER(count, ...) INIT_NEW_ARGS_##count(__VA_ARGS__)
#define INIT_NEW_EXPAND(count, ...) INIT_NEW_EXPAND_HELPER(count, __VA_ARGS__)


#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r) \
	int temp=a[r]; \
	a[r]=a[l]; \
	a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define INIT_NEW(...) INIT_NEW_EXPAND(INIT_NEW_CHOOSER(__VA_ARGS__), __VA_ARGS__)

#define RI(i) int i; cin >> i

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n);
		int *a = NEW(n, int);
		int maxi,mini;
		int op=0;

		REP(i,0,n) cin >> a[i];
		sort(a, a+n);

		maxi=a[n-1]; mini=a[0];
		int sum=maxi+mini;
		if (sum&1) {
			if (maxi&1) {
				int epos=1;
				REPR(i,n-2,-1) {
					if ((a[i]&1)==0) break;
					epos++;
				}
				int opos=1;
				REP(i,1,n) {
					if ((a[i]&1)==1) break;
					opos++;
				}
				op = min(epos, opos);
			} else {
				int opos=1;
				REPR(i,n-2,-1) {
					if ((a[i]&1)==1) break;
					opos++;
				}
				int epos=1;
				REP(i,1,n) {
					if ((a[i]&1)==0) break;
					epos++;
				}
				op = min(epos, opos);
			}
		}

		cout << op << "\n";
		free(a);
	}
    
    return 0;
}
