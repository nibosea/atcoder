#include<bits/stdc++.h>
using namespace std;

#define   N   200

// 頂点
typedef struct vtex {
	double  x,y;  // 座標値
} VTEX;

// ２次元ベクトル
typedef struct vec2 {
	double  x,y;  // ベクトルのｘ、ｙ成分
} VEX2;

// 線分（辺）
typedef struct edge {
	VTEX    s,e;  // 始点、終点
} EDGE;

// 線分をベクトル形式に変換する
VEX2 vectors(EDGE ln){
	VEX2  v;
	v.x = ln.e.x-ln.s.x;
	v.y = ln.e.y-ln.s.y;
	return v;
}

// ２次元ベクトルの外積を返す
double exterp(VEX2 vi,VEX2 vj){
	double  p;
	return p = vi.x*vj.y - vi.y*vj.x;
}

int main(void){
	int     n=4;    // 多角形の頂点数
	//std:vector<int> x(n), y(n);
	//for(int i =0; i< 4;i++) cin >> x[i] >> y[i];
	EDGE    ln[4]; // 多角形の辺集合：
	for(int i = 0; i < 4; i++){
		double zz, yy;
		cin >> zz>> yy;
		ln[i] = {zz,yy};
	}
	int     convex; // 凹多角形判定フラグ
	int     i,j;    // 辺要素インデクス
	VEX2    vi;     // 辺ｉのベクトル
	VEX2    vj;     // 辺ｊのベクトル

	convex = 0;
	for(int j=1;j<n;j++){ i = j-1;
		vi = vectors(ln[i]);
		vj = vectors(ln[j]);
		convex = exterp(vi,vj)<0;
		if(convex) break;
	}
	if(convex){
		printf("凹多角形です\n");
	}else{
		printf("凸多角形です\n");
	}

	return 0;
}
