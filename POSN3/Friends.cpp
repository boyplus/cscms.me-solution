#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
vector<int> vec[maxn];
vector<pair<int,int> > edges;
int head[maxn];
bool visited[maxn];
void dfs(int u){
	visited[u] = true;
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		if(visited[v] == false){
			dfs(v);	
		}
	}
}
int findHead(int u){
	if(head[u] == u){
		return u;
	}
	return head[u] = findHead(head[u]);
}
int main(){
	int n,m,q,u,v,group = 0, cnt = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		edges.push_back(make_pair(u,v));
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		head[i] = i;
	}
	for(int i=1;i<=n;i++){
		if(visited[i] == false){
			group++;
			dfs(i);
		}
	}
	printf("%d\n",group);
	for(int i=0;i<(int)edges.size();i++){
		int hu = findHead(edges[i].first), hv = findHead(edges[i].second);
		if(hu != hv){
			head[hu] = hv;
			cnt++;
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&u,&v);
		int hu = findHead(u), hv = findHead(v);
		if(hu == hv){
			printf("Yes\n");
		} else{
			printf("No\n");
		}
	}
	return 0;
}