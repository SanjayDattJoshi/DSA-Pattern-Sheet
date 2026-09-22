class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        if(n==1 || n==0) return 0;

        queue<pair<int,int>> q;
        set<pair<int,int>> vis;

        for(int i=0; i<n; i++){
            int maskValue = (1<<i);

            q.push({i,maskValue});

            vis.insert({i,maskValue});
        }

        int allVisitedState = (1<<n)-1;

        int path = 0;

        while(!q.empty()){
            int size = q.size();
            path++;
            while(size--){
                auto cur = q.front();
                q.pop();

                int curNode = cur.first;
                int mask = cur.second;

                for(int &adj: graph[curNode]){
                    int nextMask = mask | (1<<adj);

                    if(nextMask == allVisitedState){
                        return path;
                    }

                    if(vis.find({adj,nextMask})==vis.end()){
                        vis.insert({adj,nextMask});
                        q.push({adj,nextMask});
                    }
                }
            }
        }
        return -1;
    }
};