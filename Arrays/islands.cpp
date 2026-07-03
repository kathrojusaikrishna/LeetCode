#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& mat, int row,int col, vector<vector<bool>>& vis){
	vis[row][col]=true;

	//up
	if(row-1>=0 && mat[row-1][col]==1 && !vis[row-1][col]){
		dfs(mat,row-1,col,vis);
	}

	//down
	if(row+1 <=mat.size()-1 && mat[row+1][col]==1 && !vis[row+1][col]){
		dfs(mat,row+1,col,vis);
	}

	//left
	if(col-1 >=0 && mat[row][col-1]==1 && !vis[row][col-1]){
		dfs(mat,row,col-1,vis);
	}

	//right
	if(col+1<=mat[0].size()-1 && mat[row][col+1]==1 && !vis[row][col+1]){
		dfs(mat,row,col+1,vis);
	}

}

int solve(vector<vector<int>>& mat, int N,int M){
	int islands=0;
	vector<vector<bool>> vis(N,vector<bool>(M,false));

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(mat[i][j]==1 && !vis[i][j]){
				islands++;
				dfs(mat,i,j,vis);
			}
		}
	}

	return islands;
}
int main() {
	// Write your code here
	int N,M;
	cin>>N>>M;
	vector<vector<int>>mat(N,vector<int>(M));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>mat[i][j];
		}
	}
	int ans=solve(mat,N,M);
	cout<<ans<<endl;
	return 0;
}