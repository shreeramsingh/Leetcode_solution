class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[hand[i]]++;
        }
        while(!m.empty()){
        int currElement = m.begin()->first;//second:->frequency
            for(int i=0;i<groupSize;i++){
                if(m[currElement+i]==0){
                    return false;
                }
                m[currElement+i]--;
                if(m[currElement+i]<1){
                    m.erase(currElement+i);
                }
            }
        }
        return true;
    }
};