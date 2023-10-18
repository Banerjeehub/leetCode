class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n = quiet.size();
    vector<vector<int>> graph(n);
    vector<int> answer(n, -1);

    // Build the directed graph
    for (const auto& edge : richer) {
        graph[edge[1]].push_back(edge[0]);
    }

    // Perform topological sort
    vector<int> topologicalOrder;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSort(i, graph, visited, topologicalOrder);
        }
    }

    // Process people in topological order
    for (int person : topologicalOrder) {
        answer[person] = person; // Initialize with the current person as the quietest
        for (int neighbor : graph[person]) {
            if (quiet[answer[neighbor]] < quiet[answer[person]]) {
                answer[person] = answer[neighbor];
            }
        }
    }

    return answer;
}

void topologicalSort(int person, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& topologicalOrder) {
    visited[person] = true;
    for (int neighbor : graph[person]) {
        if (!visited[neighbor]) {
            topologicalSort(neighbor, graph, visited, topologicalOrder);
        }
    }
    topologicalOrder.push_back(person);
}

};