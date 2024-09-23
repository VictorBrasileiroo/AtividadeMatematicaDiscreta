#include <stdio.h>

int mdc(int a, int b) 
{

    if (b == 0)
    {
        return a;
    }
    else
    {
        mdc(b, a % b);
    }
}

void inverso(int a, int b) 
{
    if (mdc(a, b) != 1) 
    {
        printf("O inverso multiplicativo não existe, pois a e b não são coprimos.\n");
        return;
    }

    for (int x = 1; x < b; x++) 
    {
        if ((a * x) % b == 1) 
        {
            printf("O inverso multiplicativo de %d no modulo %d eh %d\n", a, b, x);
            return;
        }
    }

    printf("Inverso multiplicativo não encontrado.\n");
}

int main() 
{
    int a, b;

    printf("Digite os valores de a e b: ");
    scanf("%d", &a);
    scanf("%d", &b);

    inverso(a, b);

    return 0;
}
