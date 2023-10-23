#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

#define inf 10e8 + 1
#define mp make_pair
#define loop(i, a, b) for(int i =(a); i<=(b); i++)
#define revloop(i, a, b) for(int i =(b); i>=(b); i--)

void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
		
		vector<int> graph[100005];
		int dp[100005];

		int findLongestpath(int src){
			if(dp[src] != -1) return dp[src];
			bool no_neighbour = true;

			int result = INT_MIN;
			for(int neighbour : graph[src]){
				no_neighbour = false;
				result = max(result , 1 + findLongestpath(neighbour));
			}
			return no_neighbour? 0 : result;
		}
int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();

		memset(dp, -1, sizeof(dp));
		int n, m;
		cin>>n>>m;
		while(m--){
			int x, y;
			cin>>x>>y;
			graph[x].push_back(y);
		}

		int result = INT_MIN; //for connected components loop.
		loop(i, 1, n){//loop on all possible sources.
			result = max(result, findLongestpath(i));
		}

		cout<<result;

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}