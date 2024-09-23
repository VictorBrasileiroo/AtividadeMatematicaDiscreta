#include <stdio.h>

int inverso(int a, int b, int x, int m)
{
    int resultado = (a * x) % m;

    if(x < m)
    {
        if(resultado == b)
        {
            printf("a solucao eh %d", x);
        }
        else
        {
            inverso(a, b, x+1, m);
        }
    }
    else
    {
        printf("Nao ha solucao para a = %d, b = %d e m = %d.\n", a, b, m);
    }
}

int main()
{
    int a, b, m;

    printf("Digite os valores de a, b e m: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &m);

    inverso(a, b, 1, m);

    return 0;
}

