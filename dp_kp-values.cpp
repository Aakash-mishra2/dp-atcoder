#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

#define inf 10e8 + 1

int main(){
	file_i_o();
	ll n, w;
	cin>>n>>w;
	vi val(n, 0);
	vi wt(n, 0);
	int dp1[n*1000 + 1];
	int dp2[n*1000 + 1];
	loop(i, 0, n-1){
		dp[i] = inf;
		dp[2] = inf;
	}

	loop(i, 0, n-1){
		cin>>wt[i]>>val[i];
	}
	dp1[0] = 0;
	dp1[val[0]] = wt[0];
	loop(i, 1, n-1){
		loop(j, 0, n*1000) {
			if(val[i] > j) {
				dp2[j] = dp1[j];
			} else {
				dp2[j] = min({dp2[j] , dp1[j], wt[i] + dp1[j - val[i]]});
			}
		}
		loop(k, 0, n*1000){
			dp1[k] = dp2[k];
			dp2[k] = inf;
		}
	}
	int result = 0;
	loop(i, 0, n*1000){
		if(dp[i] <= w) result = i;
	}
	cout<<result;

