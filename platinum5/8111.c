#include<stdio.h>

int comb_list[11][20001];
int cnt_list[20001];

int graph[101];
int cnt;
int N;
/*
int to_decimal(long long b) {
	int n = 0;
	int pow = 1;
	for (int i = b; i > 0; i /= 2) {
		n += pow * (i % 2);
		pow *= 10;
	}
	return n;
}
long long to_binary(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++)
		res *= 2;
	return(res);
}
*/
int remain[11][20010];

void print(int i, int n) {

	printf("1");
	if (graph[n] != 0)
	{
		for (int k = comb_list[i][n] - 1; k > comb_list[i][graph[n]]; k--)
			printf("0");
		print(i,graph[n]);
	}
	
	else {
		for (int k = comb_list[i][n] - 1; k >= 1; k--)
			printf("0");
		printf("\n");
		return 0;
	}

}
void gsg(int i, int n) {
	
	remain[i][0] = 1;
	remain[i][1] = 10 % n;
	int check[20001] = { 0, };
	for (int j = 2; j < 100; j++)
		remain[i][j] = (remain[i][j - 1] * 10) % n; //  j는 자리수, 10 ^ j 에서  N으로 나눴을 때 나머지 리스트
	/*
	for (int j = 0; j < 100; j++)
		printf("%d ", remain[i][j]);
*/
	for (int j = 0; j < 100; j++) {
		int temp[20001] = { 0, };
		int cnt = 0;
		int original = remain[i][j];  // original은 기존의 나머지 리스트에 있는 수
		if (check[original] == 0) {
			comb_list[i][original] = j + 1;
			temp[cnt++] = original;
		}
		
		//original 들의 graph의 값은 0 이다. 즉 다른 값들로 연결되지 않으므로, graph의 종점
		for (int k = 0; k < n; k++)
		{

			int newRemain = (k + original) % n;
			if (check[k] != 0 && check[newRemain] == 0 && newRemain != 0) {
				comb_list[i][newRemain] = j + 1;
				graph[newRemain] = k;
				temp[cnt++] = newRemain;
			}
			if (check[k] != 0 && newRemain == 0) {
				comb_list[i][k + remain[i][j]] = j + 1;
				graph[(k + remain[i][j])] = k;
				//printf("k+remain은  %d", k + remain[i][j]);
				print(i, k + remain[i][j]);
				return 0;

			}
			
		}
		
		for (int k = 0; k < cnt; k++) {
			check[temp[k]] = 1;
		}

	}
}
int main(){

	int T = 0;
	
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf_s("%d", &N);
		gsg(i, N);
		
	}
	printf("\n ");
	//for (int j = 0; j < 100; j++)
	//	printf("%d ", comb_list[0][j]);


}