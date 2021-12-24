class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegress(numCourses, 0);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegress[pre[0]]++;
        }

        vector<int> ret;
        queue<int> que;
        for (int i = 0; i < inDegress.size(); ++i) {
            if (inDegress[i] == 0) {
                que.push(i);
            }
        }
        
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            ret.push_back(node);
            for (auto& n : graph[node]) {
                inDegress[n]--;
                if (inDegress[n] == 0) {
                    que.push(n);
                }
            }
        }

        if (ret.size() != numCourses) {
            return {};
        }       
        return ret;
    }
};
