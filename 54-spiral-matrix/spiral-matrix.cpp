class Solution {
public:
    /*
  top-> 1 5 6
        8 9 2
  down->7 6 4
        |    |
      left   right
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();    //row
        int n=matrix[0].size(); //cols

        int dir=0;

        int top=0;
        int down=m-1;

        int left=0;
        int right = n-1;
        /*
            dir=0 : left to right
            dir=1 : top to down
            dir=2 : right to left
            dir=3 : down to top
        */
        vector<int>result;
        while(top<=down && left <= right){
            if(dir==0){
                //left to right
                //const :  row(top)
                for(int i=left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                //top to down
                //constant : column (right)

                for(int i=top;i<=down;i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }

            if(dir==2){
                //right to left
                //constant : row (down)

                for(int i=right;i>=left;i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
            }

            
            if(dir==3){
                //down to top
                //constant : column (left)

                for(int i=down;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4){
                dir=0;
            }
        }
        return result;
    }
};