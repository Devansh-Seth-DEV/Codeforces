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

	}
    
    return 0;
}
