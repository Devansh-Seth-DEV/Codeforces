#include <bits/stdc++.h>
using namespace std;

class SolutionDelegate:
	public enable_shared_from_this<SolutionDelegate>
{
	protected:
		bool canShowlog = false;
	public:
		weak_ptr<SolutionDelegate> getWeakPtr() { return shared_from_this(); }

		void enableLog() { canShowlog = true; }
		void disableLog() { canShowlog = false; }
		
		bool canLog() { return canShowlog; }

		template <typename T>
			void didOut(const vector<T>& out,
					const char *sep = " ",
					const char *end = "\n") {
				for(const auto& o: out) cout << o << sep;
				cout << end;
			}

		template <typename T>
			void didOut(const T& out, const char *end = "\n") {
				cout << out << end;
			}

		void willExecute() {
			didOut("[Info]: About to start the execution.");
		}
		
		void didExecute() {
			didOut("[Info]: Execution finish.");
		}

		virtual ~SolutionDelegate() = default;

		virtual void execute() = 0;
};

class SolutionDelegateFactory {
	public:
		using Creator = function<shared_ptr<SolutionDelegate>()>;

		template <typename T>
			static void reg(const string& name) {
				getReg()[name] = []() {
					return make_shared<T>();
				};
			}

		static shared_ptr<SolutionDelegate> create(const string& name) {
			auto it = getReg().find(name);
			if (it != getReg().end()) return it->second(); // call the creator function
			return nullptr;
		}

	private:
		static unordered_map<string, Creator>& getReg() {
			static unordered_map<string, Creator> registry;
			return registry;
		}
};
 
 
class Problem {
	private:
		weak_ptr<SolutionDelegate> delegate;
		bool hasTestCases = true;
		int t=1;
	public:
		Problem(const bool _hasTestCases): hasTestCases(_hasTestCases) {}

		Problem(const int totalTestCases): hasTestCases(false), t(totalTestCases) {}

		void setDelegate(weak_ptr<SolutionDelegate> d) { delegate = d; }

		void run() {
			int cases=t;
			if (hasTestCases) cin >> cases;
			auto d = delegate.lock();
			if (!d) {
				cout << "[Error]: Delegate is not set. Stoping execution.\n";
				return;
			}

			while(cases--) {
				if (d->canLog()) d->willExecute();
				d->execute();
				if (d->canLog()) d->didExecute();
			}
		}
};

class ProblemSolver: public SolutionDelegate {
	public:
		void execute() override {
			int n, k;
			cin >> n >> k;

			auto res = solve(n, k); //Solver function (modify parameters accordingly)
			didOut(res); // Display's the result on console
		}

	private:
		string solve(int n, int k) {
			string res(n,'0');
			int zc = n-k;

			for(int i=0; i<n; i++) {
				if(i>0 && zc>1) {zc--; continue;}
				if (k && i<n-1) { res[i] = '1'; k--; }
				else if (k && i==n-1 && zc==0) { res[i] = '1'; k--; }
			}

			return res; // Return the result of the problem
		}
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	SolutionDelegateFactory::reg<ProblemSolver>("ps");
	
	auto problemManager = Problem(true);
	auto solverPtr = SolutionDelegateFactory::create("ps");
	auto& solver = *solverPtr;
	
	problemManager.setDelegate(solver.getWeakPtr());
	
	problemManager.run();
	
	solverPtr.reset();
	
	return 0;
}
