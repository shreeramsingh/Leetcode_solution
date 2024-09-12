class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int masks = 0;
        for(char &ch :allowed){
            masks |= (1 << (ch-'a'));
        }
        int cnt=0;
        for(string &word: words){
            bool Allchar =true;
            for(char &ch :word){
                if((masks >>(ch - 'a')& 1)==0){
                    Allchar = false;
                    break;
                }
            }
            if(Allchar){
                cnt++;
            }
        }
        return cnt;
    }
};