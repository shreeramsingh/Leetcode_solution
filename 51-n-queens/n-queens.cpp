class Solution {
public:
    void addSolution(vector<vector<string>>&ans,vector<string>&board,int n)
{
	// vector<string>temp;
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		temp.push_back(board[i][j]);
	// 	}
	// }
	ans.push_back(board);
}
bool isSafe(int row,int col,vector<string>&board,int n)
{
	int x=row;
	int y=col;
	//checking issafe in row in this my col is decrement
	while(y>=0){
		if(board[x][y]== 'Q'){
			return false;
		}
		y--;
	}
	//checking for upper dignoal where both row and col are decrement
	x=row;
	y=col;
	while(x>=0 && y>=0){
		if(board[x][y]=='Q'){
			return false;
		}
		x--;y--;
	}
	//checking for down dignoal where b row is incresing and col are decresing
	x=row;
	y=col;
	while(x<n && y>=0){
		if(board[x][y]=='Q'){
			return false;
		}
		x++;y--;
	}

	return true;
}
void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n)
{
	if(col==n){
		addSolution(ans,board,n);
		return;
	}
	//solve 1 case other recursion will take care
	for(int row=0;row<n;row++)
	{
		if(isSafe(row,col,board,n)){
			//if placing q is safe
			board[row][col]='Q';
			solve(col+1,ans,board,n);
			//bc
			board[row][col]='.';
		}
	}
}
vector<vector<string>> solveNQueens(int n) {
    string str="";
    for(int i=0;i<n;i++){
        str+='.';
    }
    vector<string> board(n, str);
    vector<vector<string>>ans;
    solve(0,ans,board,n);
    return ans;
    }
};




