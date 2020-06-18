#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100005;
int x[maxn],h[maxn];
vector<pair<int,int> > vec;
int f(int a){
	return a < 0 ? -a : a;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&h[i]);
		vec.push_back(make_pair(x[i],h[i]));
	}
	sort(vec.begin(),vec.end());
	double ans = 0;
	for(int i=1;i<n;i++){
		double deltaX = vec[i].first - vec[i-1].first;
		double h1 = f(vec[i].second - vec[i-1].second);
		double tri = 0.5*deltaX*h1;
		double rec = deltaX*min(vec[i].second,vec[i-1].second);
		ans+=tri+rec;
	}
	printf("%f\n",ans);
	return 0;
}