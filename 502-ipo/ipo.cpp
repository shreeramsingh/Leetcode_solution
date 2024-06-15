class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();

        vector<pair<int,int>>v(n);

        for(int i=0;i<n;i++){
            v[i]= {capital[i],profits[i]};
        }
        //Vector sort according to captial
        sort(v.begin(),v.end());

        int i=0;
        priority_queue<int>pq;
        while(k--)
        {
            while(i<n && v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                // If the priority queue is empty, break out of the loop as no further projects can be funded
                break;
            }
        }
        return w;

    }
};