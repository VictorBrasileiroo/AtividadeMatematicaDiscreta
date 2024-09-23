#include <stdio.h>

void mdc(int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        if (b == 1)
        {
            printf("Os numeros sao primos entre si ");
        }
        printf("o mdc eh: %d", b);
        return;
    }
    else
    {
        printf("(%d, %d)\n", a, b);
        mdc(b, r);
    }
}

int main()
{
    int a, b;
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite mais um numero: ");
    scanf("%d", &b);
    mdc(a, b);
}