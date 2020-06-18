#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1005, maxm = 1005;
char str[maxn][maxm] = {""};
int ans[maxn][maxm], area = 0,n,m;
bool visited[maxn][maxm];
vector<pair<int,int> > vec;
void bfs(int i,int j,char x){
	queue<pair<int,int> > q;
	q.push(make_pair(i,j));
	while(!q.empty()){
		int i = q.front().first;
		int j = q.front().second;
		area++;
		visited[i][j] = true;
		vec.push_back(make_pair(i,j));
		q.pop();
		if(visited[i][j-1]==false && str[i][j-1] == x && j-1>=0){
			visited[i][j-1] = true;
			q.push(make_pair(i,j-1));
		}
		if(visited[i][j+1]==false && str[i][j+1] == x && j+1<m){
			visited[i][j+1] = true;
			q.push(make_pair(i,j+1));
		}
		if(visited[i-1][j]==false && str[i-1][j] == x && i-1>=0){
			visited[i-1][j] = true;
			q.push(make_pair(i-1,j));
		}
		if(visited[i+1][j]==false && str[i+1][j] == x && i+1<n){
			visited[i+1][j] = true;
			q.push(make_pair(i+1,j));
		}
	}
}
int main(){
	int q,cnt = 0,y,x;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++){
		scanf("%s",str[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j] == false){
				cnt++;
				area = 0;
				vec.clear();
				bfs(i,j,str[i][j]);
				for(int k=0;k<vec.size();k++){
					int y = vec[k].first, x = vec[k].second;
					ans[y][x] = area;
				}
			}
		}
	}
	printf("%d\n",cnt);
	while(q--){
		scanf("%d %d",&y,&x);
		printf("%d\n",ans[y-1][x-1]);
	}
	return 0;
}