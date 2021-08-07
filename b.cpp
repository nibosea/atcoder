#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define N 110
#define K 10010
char s[N];int aa[N],num[N][K],n;
int main(){
    scanf("%d",&n);scanf("%s",s+1);int k=1e9;++n;
    for(int i=1;i<=n;++i) scanf("%d",&aa[i])/*,k=min(k,aa[i])*/;
    for(int i=1;i<n;++i) k=min(k,abs(aa[i]-aa[i+1]));
    printf("%d\n",k);
    for(int i=1;i<=n;++i){
        int g=aa[i]%k;
        for(int j=1;j<=k-g;++j) num[i][j]=aa[i]/k;
        for(int j=k-g+1;j<=k;++j) num[i][j]=aa[i]/k+1;
    }
    for(int i=1;i<=k;++i){for(int j=1;j<=n;++j) printf("%d ",num[j][i]);printf("\n");}
    return 0;
}
