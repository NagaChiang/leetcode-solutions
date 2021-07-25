// DFS
enum class NodeStatus : char {
    unvisited,
    visited,
    finished,
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        for (const vector<int>& p : prerequisites) {
            edges[p[1]].push_back(p[0]);
        }
        
        vector<NodeStatus> statuses(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (statuses[i] == NodeStatus::unvisited) {
                if (!dfs(i, edges, statuses)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool dfs(int node, vector<vector<int>>& edges, vector<NodeStatus>& statuses) {
        statuses[node] = NodeStatus::visited;
        for (int edge : edges[node]) {
            if (statuses[edge] == NodeStatus::visited) {
                return false;
            }
            
            if (statuses[edge] == NodeStatus::unvisited) {
                if (!dfs(edge, edges, statuses)) {
                    return false;
                }
            }
        }
        
        statuses[node] = NodeStatus::finished;
        return true;
    }
};

// BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inEdgeCounts(numCourses);
        for (const vector<int>& p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            inEdgeCounts[p[0]]++;
        }
        
        queue<int> nodeQueue;
        for (int i = 0; i < numCourses; i++) {
            if (inEdgeCounts[i] == 0) {
                nodeQueue.push(i);
            }
        }
        
        int visitCount = 0;
        while (!nodeQueue.empty()) {
            int node = nodeQueue.front();
            nodeQueue.pop();
            
            visitCount++;
            for (int edge : edges[node]) {
                inEdgeCounts[edge]--;
                if (inEdgeCounts[edge] == 0) {
                    nodeQueue.push(edge);
                }
            }
        }
        
        return visitCount == numCourses;
    }
};