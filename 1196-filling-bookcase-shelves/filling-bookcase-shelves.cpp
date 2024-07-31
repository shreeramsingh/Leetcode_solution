class Solution {
public:
    int n;
    int width;
    int t[1001][1001];
    int solve(vector<vector<int>>& books, int i, int remainw, int maxHt){
        if(i>=n){
            return maxHt;
        }
        if(t[i][remainw] != -1){
            return t[i][remainw];
        }
        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        //keep
        if(bookW<= remainw){
            keep = solve(books, i+1, remainw- bookW, max(maxHt, bookH));
        }

        //skip and put in next shelf
        skip = maxHt + solve(books, i+1, width - bookW, bookH);

        return t[i][remainw] = min(keep, skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(t, -1, sizeof(t));
        n=books.size();
        width = shelfWidth;

        int remainw =shelfWidth;
        return solve(books, 0, remainw, 0);
    }
};