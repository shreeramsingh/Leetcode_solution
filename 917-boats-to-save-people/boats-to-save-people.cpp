class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int s=0;
        int e=people.size()-1;
        int cnt=0;
        while(s<=e){
            int sum=people[s]+people[e];
            if(sum<=limit){
                cnt++;
                s++;
                e--;
            }
            else{
                cnt++;
                e--;
            }
        }
        return cnt;
    }
};