#include <stdio.h>

int cup[3] = {1, 2, 3};

void swap_elem(int X, int Y)
{
    int temp = cup[X];
    cup[X] = cup[Y];
    cup[Y] = temp;
}

int main(void)
{
	int M;
	scanf("%d", &M);
	
	int X, Y, temp;
	
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &X, &Y);
		if (X == Y)
			continue;
		
		for (int j = 0; j < 2; j++)
		{
			for (int k = j + 1; k < 3; k++)
			{
				if ((cup[j] == X && cup[k] == Y) || (cup[j] == Y && cup[k] == X))
				{
                    swap_elem(j, k);
				}
			}
		}
	}
	
	printf("%d \n", cup[0]);
	return 0;
}