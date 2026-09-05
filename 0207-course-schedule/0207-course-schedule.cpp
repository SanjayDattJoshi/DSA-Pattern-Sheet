class Solution {
public:
    bool topoSort(unordered_map<int, vector<int>> &adj, vector<int> &indegree, int n){
        queue<int> q;
        int count = 0;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) {
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }
        }
        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses,0);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        return topoSort(adj,indegree, numCourses);
    }
};