class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=0; i<=rowIndex; i++){
            vector<int> curCol;
            for(int j=0; j<=i; j++){
                if(j==0 || j==i) curCol.push_back(1);
                else{
                    int col1 = j-1;
                    int col2 = j;

                    curCol.push_back(res[col1] + res[col2]);
                }
            }
            res = curCol;
        }
        return res;
    }
};