#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

#define mp make_pair
#define loop(i, a, b) for(int i =(a); i<=(b); i++)
#define loop(i, a, b) for(int i =(b); i>=(b); i--)

void file_i_o(){
	freopen("input.txt", r, stdin);
}

int main(){
	file_i_o();

	ll n;
	cin>>n;
	vector<vector<ll>> dp(n, vector<ll>(3, 0));

	ll a, b, c;
	cin>>a>>b>>c;
	//initialize case
	dp[0][0] = a;
	dp[0][1] = b;
	dp[0][2] = c;

	loop(i, 1, n-1){
	if(i - 2 < 0) break;

	dp[i][2] = (c + max(dp[i-1][0], dp[i-1][1])); 
	dp[i][0] = (a + max(dp[i-1][1], dp[i-1][2]));
	dp[i][1] = (b + max(dp[i-1][2], dp[i-1][0]));
	}
	cout<< max({ dp[n-1][0], dp[n-1][1], dp[n-1][2] });
	
}