struct Project {
    int capital, profit;
};

class Solution {
    static bool compare(Project a, Project b) {
        return a.capital < b.capital;
    }

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<Project> projects(n);

        // Construct the projects array with capital and profit
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }

        // Sort projects by capital in ascending order
        sort(projects.begin(), projects.end(), compare);

        priority_queue<int> maxHeap;
        int i = 0;

        // Process up to k projects
        while (k--) {
            // Add all projects that can be started with current capital to the maxHeap
            while (i < n && projects[i].capital <= w) {
                maxHeap.push(projects[i].profit);
                i++;
            }

            // If max-heap is empty, no more projects can be started
            if (maxHeap.empty()) {
                break;
            }

            // Pop the project with the maximum profit and add it to the capital
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};
