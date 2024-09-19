class Solution {
    // Helper DFS function to find the result for a query
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if (graph[start].find(end) != graph[start].end()) {
            return graph[start][end];  // Direct edge case
        }

        visited.insert(start);  // Mark the node as visited

        // Traverse neighbors
        for (auto& neighbor : graph[start]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double result = dfs(neighbor.first, end, graph, visited);
                if (result != -1.0) {  // If a valid path is found
                    return neighbor.second * result;  // Multiply the current edge's value
                }
            }
        }
        return -1.0;  // No valid path found
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0], B = equations[i][1];
            double value = values[i];
            graph[A][B] = value;         // A / B = value
            graph[B][A] = 1.0 / value;   // B / A = 1 / value
        }

        vector<double> result;

        // Process each query
        for (auto& query : queries) {
            string C = query[0], D = query[1];

            // If either variable is not present in the graph, answer is -1.0
            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                result.push_back(-1.0);
            }
            // If the variables are the same, answer is 1.0
            else if (C == D) {
                result.push_back(1.0);
            }
            else {
                unordered_set<string> visited;
                result.push_back(dfs(C, D, graph, visited));
            }
        }

        return result;
    }
};
