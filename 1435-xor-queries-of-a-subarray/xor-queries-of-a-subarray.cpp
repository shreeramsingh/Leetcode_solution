class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> cumXor(n,0); //space : 0(n)

        cumXor[0] = arr[0];
        for(int i=1;i<n;i++){
            cumXor[i] = cumXor[i-1] ^ arr[i];
        }

        vector<int>answer;
        for(vector<int>& query : queries){
            int L = query[0];
            int R = query[1];

            int xor_val = cumXor[R] ^ (L== 0 ? 0 : cumXor[L-1]);
            answer.push_back(xor_val);
        }
        return answer;
    }
};