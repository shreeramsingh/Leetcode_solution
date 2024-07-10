class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(auto &v:logs){
            if(v=="../" ){
                depth--;
                if(depth<0) depth=0;
            }else if(v=="./"){
                continue;
            }else{
                depth++;
            }
        }
        return depth;
    }
};