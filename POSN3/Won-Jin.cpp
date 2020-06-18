#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 500005;
int arr[maxn];
int main(){
	int n,q,goodness;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		arr[i] = max(arr[i],arr[i-1]);
	}
	while(q--){
		scanf("%d",&goodness);
		int left = 1, right = n;
		int ans = 0;
		while(left <= right){
			int mid = (left+right)/2;
			if(arr[mid] <= goodness){
				ans = mid;
				left = mid+1;
			} else{
				right = mid-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}