class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses , 0);

        for(auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        queue<int> q;
        for(int i=0 ; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for(int neighbour : graph[curr]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        if(order.size() == numCourses) return order;
        return {};
    }  
};