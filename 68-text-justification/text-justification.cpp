class Solution {
public:
    int MAX_WIDTH;

    string findline(int i, int j, int eachGaddhaSpace, int extraSpaceGaddha, vector<string>& words){
        string line;

        for(int k=i;k<j;k++){
            line+= words[k];

            if(k== j-1){//last word of my line - no space after last world of a line.
                //we would have already added the space in all other words apart from last word
                continue;
            }

            for(int z=1;z<=eachGaddhaSpace; z++){
                line+= " ";
            }
            if(extraSpaceGaddha>0){
                line+=" ";
                extraSpaceGaddha--;
            }
        }
        while(line.size()<MAX_WIDTH){
            line+= " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n=words.size();

        MAX_WIDTH= maxWidth;

        int i=0;
        while(i<n){
            int lettersCount = words[i].size();
            int j=i+1;
            int gaddhe=0;

            while(j<n && words[j].size()+1+gaddhe+lettersCount<= maxWidth){
                lettersCount+= words[j].size();
                gaddhe +=1;
                j++;
            }

            int remainingGaddhe = maxWidth - lettersCount;

            int eachGaddhaSpace = gaddhe == 0 ? 0 : remainingGaddhe/gaddhe;
            int extraSpaceGaddha = gaddhe == 0 ? 0: remainingGaddhe%gaddhe;

            if(j==n){ // last line - left justified
                eachGaddhaSpace = 1;
                extraSpaceGaddha = 0;
            }

            result.push_back(findline(i, j, eachGaddhaSpace, extraSpaceGaddha, words));
            i=j;
        }
        return result;
    }
};