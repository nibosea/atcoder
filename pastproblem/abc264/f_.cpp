int now = S[0][0];
rep(i,h){
	rep(j,w){
		bool same = (now == S[i][j+1]);
		bool same2 = (now == S[i+1][j]);
		rep(x,2){
			rep(y,2){
				// dp[i][j][x][y]からの繊維
				if((same && x) || (!same && !x)){
					chmin(dp[i][j+1][x][1], dp[i][j][x][y] + C[j+1]);
				} else {
					chmin(dp[i][j+1][x][0], dp[i][j][x][y]);
				}
				if((same2 && y) || (!same2 && !y)){
					chmin(dp[i+1][j][1][y], dp[i][j][x][y] + R[i+1]);
				}else {
					chmin(dp[i+1][j][0][y], dp[i][j][x][y] );
				}
			}
		}
	}
}
