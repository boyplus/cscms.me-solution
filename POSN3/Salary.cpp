#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 500005;
vector<int> vec[maxn];
long long dp[maxn],salary[maxn];
bool chk[maxn];
long long dfs(int u){
	if(dp[u]){
		return dp[u];
	}
	long long sum = 0;
	for(int i=0;i<vec[u].size();i++){
		sum += dfs(vec[u][i]);
	}
	return dp[u] = salary[u]+sum;
}
int main(){
	int n,m,q,a,b,u;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%lld",&salary[i]);
	}
	int root = 0;
	for(int i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		vec[a].push_back(b);
		chk[b] = true;
	}
	for(int i=0;i<n;i++){
		if(chk[i] == false){
			root = i;
			break;
		}
	}
	dfs(root);
	while(q--){
		scanf("%d",&u);
		printf("%lld\n",dp[u]);
	}
	return 0;
}