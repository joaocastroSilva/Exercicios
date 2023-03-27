#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_DIAS 31
#define MAX_BUFFER 1024

typedef struct 
{
    int dia;
    float valor;
} Faturamento;

int main() {
    FILE *arquivo;
    char buffer[MAX_BUFFER];
    int qtd_dias = 0;
    float faturamentoTotal = 0;
    float mediaMensal = 0;
    float MenorValor = INFINITY;
    float MaiorValor = -INFINITY;
    int diasAcimaMedia = 0;
    Faturamento faturamento[MAX_DIAS];

    arquivo = fopen("dados.json", "r");
    if (arquivo == NULL)
    {
       printf("Eroo ao abrir arquivo :)");
       return 1;
    }
    
    while (fgets(buffer, MAX_BUFFER, arquivo))
    {
        int dia;
        float valor;
        if(sscanf(buffer, "{\"dia\":%d,\"valor\":%f}", &dia, &valor) == 2)
        {
            faturamento[qtd_dias].dia = dia;
            faturamento[qtd_dias].valor = valor;
            qtd_dias++;

            faturamentoTotal += valor;
            if (valor < MenorValor) MenorValor = valor;
            if (valor > MaiorValor) MaiorValor = valor;
            
            
        }
    }
    
    fclose(arquivo);

    if (qtd_dias > 0)
    {
        mediaMensal = faturamentoTotal / qtd_dias;
    }

    for (int i = 0; i < qtd_dias; i++)
    {
       if (faturamento[i].valor > mediaMensal)
       {
        diasAcimaMedia++;
       }
       
    }
    printf("Maior Valor: %.2f\n", MaiorValor);
    printf("Menor Valor: %.2f\n", MenorValor);
    printf("Dias com o faturamento acima da média: %d\n", diasAcimaMedia);

    return 0;
    
}

