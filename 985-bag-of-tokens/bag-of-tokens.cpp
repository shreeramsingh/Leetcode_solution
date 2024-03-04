class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1;
        int score=0, maxscore=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score=score+1;
                i++;
                maxscore=max(maxscore,score);
            }else if(score>=1){
                power+=tokens[j];
                score=score-1;
                j--;
            }else{
                return maxscore;
            }
            
        }
        return maxscore;
    }
};