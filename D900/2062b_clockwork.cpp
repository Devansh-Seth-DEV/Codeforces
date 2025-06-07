#include <bits/stdc++.h>
using namespace std;
 
 
class SolutionDelegate: public enable_shared_from_this<SolutionDelegate> {
public:
    static shared_ptr<SolutionDelegate> getSharedPtr() {
        return make_shared<SolutionDelegate>();
    }
    
    weak_ptr<SolutionDelegate> getWeakPtr() {
        return shared_from_this();
    }
    
    void didTakeInput() {
        int n;
        cin >> n;
		vector<int> clocks(n);
		for(auto& c: clocks) cin >> c;
		
        solve(clocks); //Solver function (modify parameters accordingly)
    }
    
    template <typename T>
    void didShowOutput(const vector<T>& out, const char *sep = "", const char *end = "\n") {
        for(const auto& o: out) cout << o << sep;
        cout << end;
    }
    
    template <typename T>
    void didShowOutput(const T& x, const char *end = "\n") {
        cout << x << end;
    }
    
 
private:
    void solve(const vector<int>& clocks) {
		int i=0, flag=0;
		for(const auto c: clocks) {
			int r = clocks.size()-i-1;
			if (c<=i<<1 || c <= r<<1) flag=1;
			i++;
		}
		didShowOutput(flag ? "NO" : "YES");
    }
};

 
class Solution {
private:
    weak_ptr<SolutionDelegate> delegate;
    bool hasTestCases = true;
    int t=1;
public:
    Solution() {}
    
    Solution(bool testCases): hasTestCases(testCases) {}
    
    Solution(int cases): hasTestCases(false), t(cases) {}
    
    void enableTestCases() { hasTestCases = true; }
    void disableTestCases() { hasTestCases = false; }
    void setTestCases(int cases) { t = cases; }
    
    void setDelegate(weak_ptr<SolutionDelegate> d) { delegate = d; }
    
    void run() {
        if (hasTestCases) cin >> t;
        auto d = delegate.lock();
        if (!d) {
            //cout << "[Warning]: Delegate is not set\n";
        }
        
        while(t--) {
            if (d) d->didTakeInput();
            else {
                /* code to execute without delegate (if any) */
            }
        }
    }
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	Solution solveManager = Solution(true);
	shared_ptr<SolutionDelegate> solver = SolutionDelegate::getSharedPtr();
	
	solveManager.setDelegate(solver->getWeakPtr());
	
	solveManager.run();
	
	solver.reset();
	
	return 0;
}
