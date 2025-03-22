class Solution {
    void dfs(int i , vector<bool>& visited , vector<vector<int>>& graph , int& nodeCount , int& edgeCount) {
        visited[i] = true;
        nodeCount ++;

        for(auto neighbour : graph[i]) {
            edgeCount++;
            if(!visited[neighbour]) {
                dfs(neighbour , visited , graph , nodeCount  , edgeCount);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); // n vertices
        // adjacency list

        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n , false);
        int completeComponentsCount = 0;

        for(int i=0 ; i < n ; i++ ) {
            if(!visited[i]) {
                int nodeCount = 0  , edgeCount = 0;
                dfs(i , visited , graph , nodeCount , edgeCount);
                edgeCount /= 2;
                if (edgeCount == nodeCount * (nodeCount - 1) / 2) {
                    completeComponentsCount++;
                }
            }
        }
        return completeComponentsCount;
    }
};