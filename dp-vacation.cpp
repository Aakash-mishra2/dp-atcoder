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

int happinessDP(int n, vector<vector<int>> points ){
    vector<vector<int>> dp(n, vector<int>(3, 0));
    int curr = 0;
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    for(int i = 1; i<n; i++){
        dp[i][0] = points[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = points[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = points[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}

int main(){
	file_i_o();
	int n; cin>>n;
    vector<vector<int>> points(n, vector<int> (3, 0));
    for(int j = 0; j<n; j++)
    for( int i = 0; i<3; i++){
        cin>>points[j][i];
    }
    int ans = happinessDP(n, points);
    cout<<ans<<endl;
    return 0;
	
}
