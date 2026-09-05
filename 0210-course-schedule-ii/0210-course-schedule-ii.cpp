class Solution {
public:
    void topoSort(vector<vector<int>> &adj, vector<int> &indegree, int n, vector<int> &res){
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) {
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    res.push_back(v);
                    q.push(v);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<int> res;
        topoSort(adj,indegree, numCourses, res);
        vector<int> emptyRes;
        return res.size()==numCourses?res:emptyRes;
    }
};