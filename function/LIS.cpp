/*最長増加部分列 Longest Incremental Subsequence (LIS) */
int LIS(vector<int> A){
	int N = A.size(); 
	vector<int> dp(N+1,inf);
	/* dp[i]:=長さiのLISを作る時、i項目の値 */
	dp[0] = 0;/*配列Aの値は1以上*/
	int ans = 0;
	rep(i,N){
		/* A[i]<XとなるXの位置を見つける */
		int pos = lower_bound(dp.begin(),dp.end(),A[i]+1) -dp.begin();
		chmax(ans,pos);
		dp[pos] = A[i];
	}
	return ans;
}
