#include <stdio.h>

int list[1000001] = { 0 };
int few_list[1000001] = { 0 };

int main()
{
	long long n, m;
	int ans;
	ans = 0;
	
	for (int i = 2; i <= 1000; i++)
	{
		if (list[i] == 0)
		{
			for (int j = 2; j * i <= 1000000; j++)
				list[i * j] = 1;
		}
	}
	
	//for (int i = 1; i <= 100; i++)
		//printf("%d\n", list[i]);
		
	
	scanf_s("%lld %lld", &n, &m);
	
	for (long long i = 2; i <= 1000000; i++)
	{
		if (list[i] == 0)
		{
			if (n % (i * i) != 0)
			{
				for (long long k = (i * i) * ((n / (i * i)) + 1);k <= m; k += i * i)
					few_list[k - n] = 1;
			}
			else if (n % (i * i) == 0)
			{
				for (long long k = n; k <= m; k += i * i)
					few_list[k - n] = 1;
			}
		}
	}
	
	for (int i = 0; i <= m - n;i++)
	{
		if (few_list[i]== 0)
			ans++;
	}
	
	
	printf("%d", ans);
}
