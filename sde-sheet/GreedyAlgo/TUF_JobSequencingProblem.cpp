/**
 *
 * Source:    TUF
 * Problem:   Job Sequencing Problem
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/job-sequencing-problem
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * sorting the jobs based on profit and then creating a slot vector to put the
 * job on farthest position possible
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct Job {
  int pos;
  int deadline;
  int profit;
};

bool comprator(Job j1, Job j2) { return j1.profit > j2.profit; }

vector<int> jobSequence(vector<vector<int>>& jobs) {
  int n = jobs.size();
  vector<Job> allJobs(n);
  int maxDeadline = 0;

  for (int i = 0; i < n; i++) {
    allJobs[i].pos = i;
    allJobs[i].deadline = jobs[i][1];
    allJobs[i].profit = jobs[i][2];
    maxDeadline = max(maxDeadline, jobs[i][1]);
  }

  sort(allJobs.begin(), allJobs.end(), comprator);
  vector<int> slot(maxDeadline + 1, -1);

  int jobCount = 0;
  int maxProfit = 0;
  for (auto job : allJobs) {
    for (int i = job.deadline; i > 0; i--) {
      if (slot[i] == -1) {
        slot[i] = job.pos;
        maxProfit += job.profit;
        jobCount++;
        break;
      }
    }
  }

  return {jobCount, maxProfit};
}

int main() {
  // vector<vector<int>> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1,
  // 30}};
  vector<vector<int>> jobs = {{1, 1, 10}, {2, 2, 100}, {3, 2, 90}};
  vector<int> sol = jobSequence(jobs);
  cout << sol[0] << ", " << sol[1];
  return 0;
}