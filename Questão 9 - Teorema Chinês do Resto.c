#include <stdio.h>

int mdc(int a, int b) 
{
    if (b == 0)
    {
        return a;
    }
    return mdc(b, a % b);
}

int coprimos(int a, int b, int c)
{
    if (mdc(a, b) == 1 && mdc(a, c) == 1 && mdc(b, c) == 1)
    {
        return 1;
    }
    else
    {
        printf("Os módulos não são coprimos.\n");
        return 0;
    }
}

int inverso(int a, int b, int x)
{
    if (x == b)
    {
        return 0;
    }
    if ((a * x) % b == 1)
    {
        return x;
    }
    return inverso(a, b, x + 1);
}

int main()
{
    int resto_a, resto_b, resto_c, m1, m2, m3;

    // Entrada das congruências
    printf("Digite a primeira congruência: mod: ");
    scanf("%d", &m1);
    printf("e o resto: ");
    scanf("%d", &resto_a);

    printf("Digite a segunda congruência: mod: ");
    scanf("%d", &m2);
    printf("e o resto: ");
    scanf("%d", &resto_b);

    printf("Digite a terceira congruência: mod: ");
    scanf("%d", &m3);
    printf("e o resto: ");
    scanf("%d", &resto_c);

    if (!coprimos(m1, m2, m3))
    {
        return 1; 
    }

    int Mtotal = m1 * m2 * m3;
    int M1 = Mtotal / m1;
    int M2 = Mtotal / m2;
    int M3 = Mtotal / m3;

    int s1 = inverso(M1, m1, 1);
    int s2 = inverso(M2, m2, 1);
    int s3 = inverso(M3, m3, 1);

    if (s1 == 0 || s2 == 0 || s3 == 0)
    {
        printf("Inverso multiplicativo não encontrado.\n");
        return 1;
    }

    int x0 = (M1 * s1 * resto_a) + (M2 * s2 * resto_b) + (M3 * s3 * resto_c);
    int solucao = x0 % Mtotal;

    printf("A solução é: %d\n", solucao);

    return 0;
}