#include <iostream>
#include <string>
#include<algorithm>
#define MAX_N 21
#define MAX_C 1001

//O(n^2)
using namespace std;


int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, C;
	int cost[MAX_N];
	int client[MAX_N];
	int dp[MAX_C * 101];

	int result = 0;

	fill_n(dp, MAX_C * 101, 100000);
	dp[0] = 0;
	
	std::cin >> C >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> cost[i] >> client[i];
		
	}
	//cout << "input";

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < C + 101; j++)
		{
			if (j - client[i] > -1)			//dp[0] 이 0인것을 활용해서 j-client[i]가 0일때 첫번째 도시값으로 초기화 하기
			{
				
				dp[j] = min(dp[j], dp[j - client[i]] + cost[i]);
				
			}
		}
	}

	
	result = dp[C];
	
	for (int i = C + 1; i < C + 101; i++)
	{
		result = min(result, dp[i]);
	}
	
	cout << result;

	return 0;
}