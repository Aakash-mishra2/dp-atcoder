#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

#define inf 10e8 + 1
#define mp make_pair
#define loop(i, a, b) for(int i =(a); i<=(b); i++)
#define revloop(i, a, b) for(int i =(a); i>=(b); i--)

void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
		
		double dp[3005][3005]; //dp[i][x] => probability to get atleast x heads from i coins
		double coins(vector<double>& arr, int i, int x){
			if(x==0) return 1;
			if(i==0) return 0;
			if(dp[i][x] > -0.9) return dp[i][x]; //-0.5 etc bhi bas -1 se bada number showing kuch toh calculation hui hai is case ispe. 

			return dp[i][x] = coins(arr, i-1, x-1)*(arr[i]) + coins(arr, i-1, x)*(1-arr[i]);
		}

int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();

		memset(dp, -1, sizeof(dp));
		int n;
		cin>>n;
		vector<double> arr(n+1);
		loop(i, 1, n) cin>>arr[i];
		cout<<fixed<<setprecision(10)<<coins(arr, n, (n+1)/2); //prob getting atleast this many heads makes total heads greter than nu. of tales.


		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}