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
					const char *sep = "",
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

			vector<int> a(n);
			for(auto& x: a) cin >> x;

			int score = solve(a, k); //Solver function (modify parameters accordingly)
			didOut(score);
		}

	private:
		int solve(const vector<int>& a, int k) {
			unordered_map<int, int> freq;
			for (const auto& x : a) freq[x]++;

			int score=0;
			for(int i=1; i<=(k>>1); i++) {
				if (i == k-i) {
					score += freq[i] >> 1;
					continue;
				}
				int mn = min(freq[i], freq[k-i]);
				score += mn;
				freq[i] -= mn;
				freq[k-i] -= mn;
			}

			return score;
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
