class Node{
public:
    int val;
    int row;
    int col;
    
public:
    Node(int v, int r, int c){
        val = v;
        row = r;
        col = c;
    }
};

class Solution {
public:
struct comp{
    bool operator()(const Node &a, const Node &b){
        return a.val>b.val;
    }
};
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        priority_queue<Node, vector<Node>, comp>pq;
        for(int i=0; i<n; i++){
            pq.push({matrix[i][0],i,0});
        }
        int cnt = 0, res;
        while(!pq.empty() && cnt<k){
            Node cur = pq.top();
            pq.pop();
            cnt++;
            int v = cur.val;
            int r = cur.row;
            int c = cur.col;
            if(cnt==k) return v;
            if(c<m-1){
                pq.push({matrix[r][c+1],r,c+1});
            }
        }
        return 0;
    }
};