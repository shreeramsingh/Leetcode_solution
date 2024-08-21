class Solution {
public:
    int t[1001][1001];
    int solve(int curA, int clipA, int n){
        if(curA ==n){
            return 0;
        }
        if(curA > n){
            return 100000;
        }
        if(t[curA][clipA]!=-1){
            return t[curA][clipA];
        }
        int copyallpast = 1 + 1 + solve(curA +curA, curA,n);
        int paste = 1 + solve(curA + clipA, clipA,n);

        return t[curA][clipA] = min(copyallpast,paste);
    }
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        memset(t,-1, sizeof(t));
        
        return 1+ solve(1, 1, n);
    }
};