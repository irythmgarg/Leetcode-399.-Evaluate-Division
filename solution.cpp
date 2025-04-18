class Solution {
public:
    /**
     * Depth-First Search (DFS) helper function to compute the division result from 'from' to 'to'.
     *
     * @param from The current node (numerator).
     * @param to The target node (denominator).
     * @param visited Keeps track of visited nodes to avoid cycles.
     * @param mp Adjacency list representing the graph with edge weights.
     * @param ans Stores the result once the path is found.
     * @param count Accumulates the product of weights along the DFS path.
     */
    void dfs(string from, string to, unordered_map<string, bool>& visited,
             unordered_map<string, vector<pair<string, double>>>& mp,
             double& ans, double count) {
        visited[from] = true;
        for (auto& a : mp[from]) {
            if (!visited[a.first]) {
                double new_count = count * a.second;
                if (a.first == to) {
                    ans = new_count;  // Found target, store result
                    return;
                }
                dfs(a.first, to, visited, mp, ans, new_count);
            }
        }
    }

    /**
     * Main function to evaluate division equations.
     *
     * @param equations List of string pairs representing equations like A / B.
     * @param values List of corresponding values for the equations.
     * @param queries List of string pairs for which results are to be calculated.
     * @return A vector of double values containing results for each query.
     */
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;

        // Step 1: Build the graph with both directions
        for (int i = 0; i < equations.size(); i++) {
            string from = equations[i][0];
            string to = equations[i][1];
            mp[from].push_back({to, values[i]});
            mp[to].push_back({from, 1.0 / values[i]});
        }

        vector<double> ans;

        // Step 2: Resolve each query using DFS
        for (int i = 0; i < queries.size(); i++) {
            string from = queries[i][0];
            string to = queries[i][1];

            // If either variable is not in the graph, answer is -1.0
            if (mp.find(from) == mp.end() || mp.find(to) == mp.end()) {
                ans.push_back(-1.0);
            }
            // If querying the same variable, answer is 1.0
            else if (from == to) {
                ans.push_back(1.0);
            }
            else {
                unordered_map<string, bool> visited;
                double res = -1.0;
                dfs(from, to, visited, mp, res, 1.0);
                ans.push_back(res);
            }
        }

        return ans;
    }
};
