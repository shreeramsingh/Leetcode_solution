class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<long long>lastAvailableAt(n,0);
        vector<int>roomsusescount(n,0);

        for(vector<int>&meet: meetings){
            int start=meet[0];
            int end=meet[1];
            int duration = end-start;
            bool found=false;

            long long earlyEndRoomtime = LLONG_MAX;
            int earlyEndRoom=0;

            for(int room=0;room<n;room++){
                if(lastAvailableAt[room]<=start){
                    lastAvailableAt[room]=end;
                    roomsusescount[room]++;
                    found=true;
                    break;
                }
                if(lastAvailableAt[room]<earlyEndRoomtime){
                    earlyEndRoomtime=lastAvailableAt[room];
                    earlyEndRoom=room;
                }
            }
            if(!found){
                lastAvailableAt[earlyEndRoom] +=duration;
                roomsusescount[earlyEndRoom]++;
            }
        }
        int resultRoom=0,maxUse=0;
        for(int room=0;room<n;room++){
            if(roomsusescount[room]>maxUse){
                maxUse=roomsusescount[room];
                resultRoom=room;
            }
        }
        return resultRoom;
    }
};