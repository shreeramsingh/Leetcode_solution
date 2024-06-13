class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=seats.size();

        vector<int>position_seat(101,0);
        vector<int>position_student(101,0);

        for(int &pos:seats){
            position_seat[pos]++;
        }
        
        for(int &pos:students){
            position_student[pos]++;
        }

        int i=0,j=0,ans=0;

        while(i<=100 && j<=100)
        {
            if(position_seat[i]==0) i++;
            if(position_student[j]==0) j++;

            while(i<=100 && j<=100 && position_seat[i]!=0 && position_student[j]!=0){
                ans+=abs(i-j);
                position_seat[i]--;
                position_student[j]--;
            }
        }

        return ans;

        
    }
};