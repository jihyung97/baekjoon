#include <stdio.h>

int tab[20][20] = { 0 };


int list[16] = { 0 };
char check_arr[35000][20][16] = { 0 };
int	power = 1, nb = 0, max = 1;


void	painting(int i, int n, int count, int price)//count max는 1로 시작
{
	if (max == n)
		return;


	nb = 0;
	power = 1;
	for (int l = 0;l < n;l++)
	{
		nb = nb + power * list[l];
		power = 2 * power;
	}

	list[i] = 1;

	for (int k = 0;k < n;k++)
	{
		if ((list[k] == 0) && (tab[i][k] >= price) && (check_arr[nb][i][k] != 1))
		{
			if (count + 1 >= max)
				max = count + 1;

			check_arr[nb][i][k] = 1;
			painting(k, n, count + 1, tab[i][k]);

		}

	}
	list[i] = 0;
	return;

}

int main()
{



	int n;
	
	scanf_s("%d", &n);



	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf_s("%1d", &tab[i - 1][j - 1]);
	}
	
	painting(0, n, 1, 0);

	printf("%d", max);



}






/*
for (int k = 0;k < n - count + 1;k++)
{
	if (list[k] == i)
	{
		p = k;
		break;
	}
}
for (int k = p;k < n - count;k++)
	list[k] = list[k + 1];

	*/


/*
int add(int a, int b)
{
	return(a + b);
}

int fibo(int n) {
	if (n == 0) return 0;
	else
		if (n == 1) return 1;
		else
			return(add(fibo(n - 1), fibo(n - 2)));
}

int main()
{
	printf("%d",fibo(20));
}
*/

/*
char penta(int nb)
{
	if (nb > 9)
		return ('a' + nb - 10);
	return (nb);
}

void quickSort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
	int temp;
	do
	{
		while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
			left++;
		while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
			right--;
		if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			/*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동
			left++;
			right--;
		}
	} while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 

	
	if (L < right)
		quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 

	if (left < R)
		quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}  
*/