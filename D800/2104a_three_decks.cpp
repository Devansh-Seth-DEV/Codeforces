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
        int a, b, c;
        cin >> a >> b >> c;
		
        solve(a, b, c); //Solver function (modify parameters accordingly)
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
    void solve(const int a, const int b, const int c) {
		int sum=a+b+c;
		if (sum%3 != 0) { didShowOutput("NO"); return; }
		
		int x = sum/3;
		string res = (b<=x) ? "YES" : "NO";
        didShowOutput(res); // Display's the result on console
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
