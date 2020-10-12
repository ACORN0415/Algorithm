#include<iostream>

using namespace std;

int N;
int W[17][17];
int dp[16][1 << 16];

int TSP(int curr, int visited) { 
	int result;
	int ret = dp[curr][visited];

	if (ret != 0) 

		return ret;

	if (visited == (1 << N) - 1) { 
		if (W[curr][0] != 0) { 
			return W[curr][0];
		}
		return 1000000000; 
	}

	ret = 1000000000;

	for (int i = 0; i < N; i++) {
		if ((visited & 1 << i) || (W[curr][i] == 0)) 
			continue;
		result = TSP(i, (visited | 1 << i)) + W[curr][i];
		if (result < ret)
			ret = result;

	}
	dp[curr][visited] = ret;

	return ret;

}
int main() {

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &W[i][j]);
		}
	}

	printf("%d\n", TSP(0, 1));

	return 0;
}
