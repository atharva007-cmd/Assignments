#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Job {
	int id;
	int deadline;
	int profit;

	Job (int id, int deadline, int profit)
		: id(id), deadline(deadline), profit(profit)
	{}
};

ostream& operator<< (ostream&, const Job&);
void printjobs (const vector<Job>&);

int main (int argc, char* argv[]) {

	vector<Job> jobs;
	jobs.reserve(5);

	jobs.emplace_back( 1, 2, 60);
	jobs.emplace_back( 2, 1, 100);
	jobs.emplace_back( 3, 3, 20);
	jobs.emplace_back( 4, 2, 40);
	jobs.emplace_back( 5, 1, 20);

	int maxDeadline = 3;
	int totalProfit = 0;

	// Print jobs
	printjobs(jobs);

	// Sort the jobs wrt profit in descending order
	sort(jobs.begin(), jobs.end(),
		[](Job& one, Job& two) { 
			return one.profit > two.profit;
		});

	// Initialize arrays to store result
	int result[maxDeadline];
	memset (result, -1, sizeof(result));
	bool slot[jobs.size()];
	memset (slot, false, sizeof(slot));

	// Print jobs to be scheduled in sequence
	cout << "\nJob details in slots:" << endl;
	for (Job job: jobs) {
		for (int j = job.deadline-1; j>=0; j--) {
			if ( j<maxDeadline && !slot[j] ) {
				slot[j] = true;
				result[j] = job.id;
				totalProfit += job.profit;
				cout << job;
				break;
			}
		}
	}

	// Print job sequence and max profit that can be generated
	cout << "\nSequence: ";
	for (int i=0; i<maxDeadline; i++) {
		cout << result[i] << " ";
	}
	cout << "\nTotal profit generated: " << totalProfit << endl;

	return 0;
}

ostream& operator<< (ostream& stream, const Job& job) {
	cout << job.id << "\t    " << job.deadline << "    \t   " << job.profit << endl;
}

void printjobs (const vector<Job> &jobs) {
	cout << "\nId\tDeadline\tProfit\n";
	for (Job job: jobs) {
		cout << job;
	}
}