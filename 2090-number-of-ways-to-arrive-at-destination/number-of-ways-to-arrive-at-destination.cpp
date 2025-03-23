class Solution {
    const int MOD = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto& road : roads) {
            int u = road[0] , v = road[1] , t = road[2];
            graph[u].emplace_back(v,t);
            graph[v].emplace_back(u,t);

        }
        // Dijkstra's algorithm to find the shortest path from 0 to n-1
    vector<long long> dist(n, LLONG_MAX);
    vector<long long> ways(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[0] = 0;
    ways[0] = 1;
    pq.emplace(0, 0); // (distance, node)

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, time] : graph[u]) {
            long long newDist = d + time;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                ways[v] = ways[u]; // Update ways to reach v
                pq.emplace(newDist, v);
            } else if (newDist == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD; // Add ways to reach v
            }
        }
    }

    return ways[n - 1];
    }
};