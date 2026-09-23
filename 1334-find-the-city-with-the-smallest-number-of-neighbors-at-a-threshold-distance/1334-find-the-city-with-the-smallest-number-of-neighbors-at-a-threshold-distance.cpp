class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int,int>> adjList[V];
        for(auto it: edges){
            int src = it[0];
            int desti = it[1];
            int w = it[2];
            
            adjList[src].push_back({desti, w});
            adjList[desti].push_back({src,w});
        }
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int node = p.second;
            int w = p.first;
            
            if(dist[node]<w) continue;
            
            for(auto it: adjList[node]){
                int neigh = it.first;
                int weight = it.second;
                
                if(w+weight<dist[neigh]){
                    dist[neigh] = w+weight;
                    pq.push({w+weight, neigh});
                }
            }
        }
        return dist;
    }

    vector<int> bellmanFord(int V, vector<vector<int>> & edges, int src) {
		vector<int> dist(V, 1e8);
		dist[src] = 0;
		
		for (int i = 0; i<V - 1; i++) {
			for (int j = 0; j<edges.size(); j++) {
				int s = edges[j][0];
				int d = edges[j][1];
				int w = edges[j][2];
				
				if (dist[s] != 1e8 && dist[d]>dist[s]+w)
					dist[d] = dist[s] + w;

                if(dist[d] != 1e9 && dist[s] > dist[d] + w) 
                    dist[s] = dist[d] + w;
			}
		}		
		return dist;
	}

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> neighborsAtThresholdDis(n);

        vector<int> dist[n];
        for(int i=0; i<n; i++){
            vector<int> row;
            row = bellmanFord(n, edges, i);//we can use bellman ford or dijkstra

            dist[i]=row;
        }
        vector<int> neigh(n);
        for(int i=0; i<n; i++){
            int ans = 0;
            for(int j=0; j<n; j++) if(dist[i][j]<=distanceThreshold) ans++;
            neigh[i] = ans;
        }

        int res = n,ind;
        for(int i=0; i<n; i++){
            if(neigh[i]<=res){
                ind = i;
                res = neigh[i];
            }
        } 
        return ind;
    }
};