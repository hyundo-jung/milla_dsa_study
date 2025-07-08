#include <stdio.h>

void bubbleSort(int *arr, int len) // 오름차순으로 정렬
{
	int temp;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[9], sum = 0;
	for (int i = 0; i < 9; i++)
	{
			scanf("%d", &arr[i]); // 입력값 받기
			sum += arr[i];
	}

    bubbleSort(arr, 9); // 먼저 정렬하기
	
	int a, b;
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != j && sum - arr[i] - arr[j] == 100)
			{
				a = i; // 난쟁이 둘 찾기
				b = j;
				break;
			}
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
		if (i != a && i != b)
			printf("%d \n", arr[i]);
	}
	return 0;	
}