#include <stdio.h>

int abs(int n)
{
	if (n < 0)
		return (-n);
	return(n);
}
int list[2500][7];
int	mix_list[400000][6];
int nb = 0, nb_mix = 0, result = 100;
int	check[10][10] = { 0 };
int	board[5] = { -1,-1,-1,-1,-1 };
int  temp[6] = { 0 }, check_path[6] = { 0 }, temp_list[6] = {0};



void make(int n, int i, int j, int count, int k)
{

	if (i < 0 || i > 4 || j < 0 || j > 4 )
		return;

	if (check[i][j] == 0)
	{
		k++;
		//n--;
		board[k - 1] = 10 * i + j;
	}
	check[i][j] = check[i][j] + 1;
	//printf("%d,", check[i][j]);
	count--;
	//printf("%d", count);
	if (k == n)
	{
		for (int p = 0; p < 5 ; p++)
			list[nb][p] = board[p];
		nb++;
		check[i][j] = check[i][j] - 1;
		board[k - 1] = -1;
		//n++;
		//count++;
		return;
	}

	if (count == 0)
	{
		check[i][j] = check[i][j] - 1;
		if (check[i][j] == 0)
		{
			board[k - 1] = -1;
			//n++;
		}
		//count++;
		
		return;
	}
	
	make(n, i + 1 , j, count, k);
	make(n, i, j + 1, count, k);
	make(n, i - 1, j, count, k);
	make(n, i, j - 1, count, k);

	check[i][j] = check[i][j] - 1;
	if (check[i][j] == 0)
	{
		board[ k - 1] = -1;
		
	}
	return;
}


void mix( int n, int j, int *list)
{
	if (j == n)
	{
		for (int i = 0; i < n; i++)
			mix_list[nb_mix][i] = temp[i];
		nb_mix++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		
		if (check_path[i] == 0)
		{
			check_path[i] = 1;
			temp[j] = list[i];
			mix(n, j + 1,list);
			check_path[i] =  0;
			
		}
	}
	
	//nb++;
	//printf("%d \n", nb);
	//return;
	return;
}



int	main()
{
	
	int n = 0;
	int n_fac;
	int	sum = 0;
	int p, q;
	char input[7][7];
	int dot_list[5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf_s(" %c", &input[i][j]);
			if (input[i][j] == '*')
				dot_list[n++] = 10 * i + j;
		}

	}

	

	/*
	for (int i = 0; i < n; i++)
	{
		
		scanf_s("%d", &p);
		//scanf_s("%d", &q);
		dot_list[i] = p;
	}
	*/
	//for (int i = 0; i < n; i++)
	//	printf("%d", dot_list[i]);
	make(n, 2, 2, 2 * (n - 1),0);
	mix(n, 0, list[0]);

	n_fac = nb_mix;
	//printf("%d", nb_mix);
	for (int i = 1; i < nb; i++)
		mix(n, 0, list[i]);
	//printf("%d", nb_mix);
	//printf("%d", nb);
	
	
	for (int i = 0; i < nb_mix; i += n_fac)
	{
		int min_i = mix_list[i][0] / 10, max_i = mix_list[i][0] / 10, min_j = mix_list[i][0] % 10, max_j = mix_list[i][0] % 10;
		for (int j = 1; j < n; j++)
		{
			if (mix_list[i][j] / 10 < min_i)
				min_i = mix_list[i][j] / 10;
		}
		for (int j = 1; j < n; j++)
		{
			if (max_i < mix_list[i][j] / 10)
				max_i = mix_list[i][j] / 10;
		}
		for (int j = 1; j < n; j++)
		{
			if (mix_list[i][j] % 10 < min_j)
				min_j = mix_list[i][j] % 10;
		}
		for (int j = 1; j < n; j++)
		{
			if (max_j < mix_list[i][j] % 10)
				max_j = mix_list[i][j] % 10;
		}
		for (int k = 0; k < n_fac; k++)
		{
			for (int l = 0; l < n; l++)
			{
				mix_list[i + k][l] -= 10 * min_i + min_j;
				
			}
			for (int m = 0; m <= 4 - (max_i - min_i); m++)
			{
				for (int j = 0; j <= 4 - (max_j - min_j); j++)
				{
					for (int l = 0; l < n; l++)
						temp_list[l] = mix_list[i + k][l] + 10 * m + j;
					sum = 0;
					for (int l = 0; l < n; l++)
					{
						
						sum += abs(temp_list[l] / 10 - dot_list[l] / 10) + abs(temp_list[l] % 10 - dot_list[l] % 10);
					}
					if (sum < result)
						result = sum;
					
				}
			}
		}

	}
	
	printf("%d", result);



	
}