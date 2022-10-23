bool compare(vector<int>& a, vector<int>& b) {
    return a[1]<b[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare);
        priority_queue<int> q;
        int time=0;
        
        for(auto co: courses) {
            time += co[0];
            q.push(co[0]);
            if(time > co[1]) {
                time -= q.top();
                q.pop();
            }
        }
        
        return q.size();
    }
};