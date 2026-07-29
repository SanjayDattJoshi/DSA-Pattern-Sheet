class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0);
        for(char &ch:tasks){
            mpp[ch-'A']++;
        }

        priority_queue<int> pq;

        for(auto it: mpp){
            if(it>0 )pq.push(it);
        }

        int time = 0;
        while(!pq.empty()){
           int cycle = n+1;
           vector<int> store;
           int taskCount = 0;
           while(cycle>0 && !pq.empty()){
                cycle--;
                int cur = pq.top();
                if(cur>1){
                    store.push_back(cur-1);
                }
                pq.pop();
                taskCount++ ;
           }
            for(auto it: store){
                pq.push(it);
            }
            if(pq.empty()) time += taskCount;
            else time += n+1;
        }
        return time;
    }
};