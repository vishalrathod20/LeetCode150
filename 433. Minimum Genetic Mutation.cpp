class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end()); // quick access

        unordered_set<string> visited;

        queue<string> q;
        q.push(startGene); // Fixed variable name

        visited.insert(startGene); // Fixed variable name
        int level = 0;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string curr = q.front(); // Fixed function name
                q.pop(); // Fixed variable name

                if (curr == endGene) // Fixed variable name
                {
                    return level;
                }

                for (char ch : "ACGT") { // Fixed typo: changed "ACGI" to "ACGT"
                    for (int i = 0; i < curr.length(); i++) {
                        string neighbour = curr;
                        neighbour[i] = ch;
                        if (visited.find(neighbour) == visited.end() && bankset.find(neighbour) != bankset.end()) {
                            visited.insert(neighbour);
                            q.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
