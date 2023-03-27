#include<stdio.h>

int fibonacci(int n, int fib[]){

	fib[0] = 0;
	fib[1] = 1;
	
	int i = 2;
	while (fib[i-1] < n)
	{
		fib[i] = fib[i-1] + fib[i-2];
		i++;
	}
	return i-1;
	
}

int pertenceFibonacci(int n, int fib[], int tamanho){

	for (int i = 0; i < tamanho; i++)
	{
		if (fib[i] == n)
		{
			return 1;
		}
		
	}
	return 0;
}

int main()
{
	int numero;
	printf("Informe um numero: ");
	scanf("%d", &numero);
	
	int fib[100];
	int tamanho = fibonacci(numero, fib);

	if (pertenceFibonacci(numero, fib, tamanho))
	{
		printf("O numero %d pertece à sequencia de Fibonacci", numero);
		for (int i = 0; i < tamanho; i++)
		{
			printf("%d", fib[i]);
		}
		printf("\n");
	}else
	{
		printf("O numero %d não pertence a sequencia Fibonacci",  numero);
		for (int i = 0; i < tamanho; i++)
		{
			printf("%d", fib[i]);
		}
		printf("\n");

	}
	
	return 0;
}















