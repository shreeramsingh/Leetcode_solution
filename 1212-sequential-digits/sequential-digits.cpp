class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<=8;i++){
            q.push(i);
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(t>=low && t<=high){
                ans.push_back(t);
            }
            int last_digit=t%10;
            if(last_digit+1<=9){
                q.push(t*10+(last_digit+1));
            }
        }
        return ans;
    }
};