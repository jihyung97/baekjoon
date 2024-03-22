#include <stdio.h>
#include <stdlib.h>	

long long	step_number(int N)
{

	long long  list[103][7][15] = { 0 };
	long long total = 0;

	for (int i = 1; i < 9; i++)
		list[1][0][i] = 1;
	list[1][2][9] = 1;

	for (int n = 2; n <= N; n++)
	{
		for (int i = 1; i < 9; i++)
		{
			for (int p = 0; p < 4; p++)
				list[n][p][i] = list[n - 1][p][i - 1] % 1000000000 + list[n - 1][p][i + 1] % 1000000000;
		}
		list[n][1][0] = list[n - 1][1][1] % 1000000000 + list[n - 1][0][1] % 1000000000;
		list[n][3][0] = list[n - 1][2][1] % 1000000000 + list[n - 1][3][1] % 1000000000;
		list[n][2][9] = list[n - 1][0][8] % 1000000000 + list[n - 1][2][8] % 1000000000;
		list[n][3][9] = list[n - 1][1][8] % 1000000000 + list[n - 1][3][8] % 1000000000;
	}
	for (int i = 0; i < 10; i++)
		total += list[N][3][i] % 1000000000;
	return(total % 1000000000);

}

int	main()
{
	int	nb;
	scanf_s("%d", &nb);
	printf("%lld", step_number(nb));
}

/*
int main()
{
	long long answer = 0;
	for (int i = 0; i <= 40; i++)
		answer += step_number(i);
	printf("%lld", answer);
 }
 */