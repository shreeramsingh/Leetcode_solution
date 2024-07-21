class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int, vector<int>> rowgraph;
        unordered_map<int, vector<int>> colgraph;

        for (const auto& x : rowConditions) {
            rowgraph[x[0]].push_back(x[1]);
        }
        for (const auto& x : colConditions) {
            colgraph[x[0]].push_back(x[1]);
        }

        auto topologicalsort = [&](unordered_map<int, vector<int>>& graph) {
            deque<int> stack;
            unordered_set<int> visited;
            unordered_set<int> check_cycle;
            bool cycle = false;

            function<void(int)> topoHelper = [&](int x) {
                if (cycle) return;

                visited.insert(x);
                check_cycle.insert(x);
                for (int i : graph[x]) {
                    if (check_cycle.find(i) != check_cycle.end()) {
                        cycle = true;
                        return;
                    }
                    if (visited.find(i) == visited.end()) {
                        topoHelper(i);
                    }
                }
                check_cycle.erase(x);
                stack.push_front(x);
            };

            for (int i = 1; i <= k; ++i) {
                if (cycle) return vector<int>();
                if (visited.find(i) == visited.end()) {
                    topoHelper(i);
                }
            }
            return vector<int>(stack.begin(), stack.end());
        };

        vector<int> rows = topologicalsort(rowgraph);
        vector<int> columns = topologicalsort(colgraph);

        if (rows.empty() || columns.empty()) {
            return {};
        }

        unordered_map<int, int> d;
        for (int i = 0; i < rows.size(); ++i) {
            d[rows[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < columns.size(); ++i) {
            matrix[d[columns[i]]][i] = columns[i];
        }

        return matrix;
    }
};