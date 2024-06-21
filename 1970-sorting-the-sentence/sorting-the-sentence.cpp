class Solution {
public:
    string sortSentence(string s) {
       vector<string>ans(10);
        int count=0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                int pos=temp[temp.size()-1]-'0';//here '0' convert charater into integer
                temp.pop_back();
                ans[pos]=temp;
                temp="";
                count++;
            }else{
                temp+=s[i];
            }
        }
        //for last word there i not space so at last we push into vector
        int position=temp[temp.size()-1]-'0';
        temp.pop_back();
        ans[position]=temp;
        
        string answer;
        for(int i=1;i<=count+1;i++){
            if (!ans[i].empty()) {
                answer+=ans[i];
                answer+=' ';
            }
        }
        answer.pop_back();
        return answer;
    }
};