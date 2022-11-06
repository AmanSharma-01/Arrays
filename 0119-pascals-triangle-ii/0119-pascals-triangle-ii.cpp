class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> lastRow;
        lastRow.push_back({1});
        
        for(int i=1;i<=n;i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++) {
                int a = lastRow[j]+lastRow[j-1];
                temp.push_back(a);
            }
            temp.push_back(1);
            lastRow = temp;
        }
        return lastRow;
    }
};