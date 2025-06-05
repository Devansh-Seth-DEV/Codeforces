#include <bits/stdc++.h>
using namespace std;

class SolutionDelegate:
	public enable_shared_from_this<SolutionDelegate>
{
	public:
		weak_ptr<SolutionDelegate> getWeakPtr() { return shared_from_this(); }

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


		virtual ~SolutionDelegate() = default;

		virtual void didExecute() = 0;
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
			if (hasTestCases) cin >> t;
			auto d = delegate.lock();
			if (!d) {
				cout << "[Error]: Delegate is not set. Stoping execution.\n";
				return;
			}

			while(t--) {
				d->didExecute();
			}
		}
};

class ProblemSolver: public SolutionDelegate {
	public:
		void didExecute() override {
			int n;
			cin >> n;
			// Write your input logic here 

			solve(n); //Solver function (modify parameters accordingly)
		}

	private:
		void solve(const int n) {
			// Write your problem logic here 

			didOut(n); // Display's the result on console
		}
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	SolutionDelegateFactory::reg<ProblemSolver>("ps");
	
	auto problemManager = Problem(true);
	auto solver = SolutionDelegateFactory::create("ps");
	
	problemManager.setDelegate(solver->getWeakPtr());
	
	problemManager.run();
	
	solver.reset();
	
	return 0;
}
