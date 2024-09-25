#include <stdio.h>
#include <math.h>

#define MAX 1000

unsigned long long int primo(unsigned long long int x, unsigned long long int div)
{
    if(x<= 1) return 0;
    
    if(div*div > x)return 1;

    if(x % div == 0) return 0;
    
    return primo(x, div+1);
}

unsigned long long int fatoresDoPrimo(unsigned long long int num, unsigned long long int matriz[MAX][2])
{
    int j = 0;

    for(int i = 2; i <= num; i++)
    {
        if(primo(i, 2))
        {
            matriz[j][0] = i;
            matriz[j][1] = 0;

            while(num % i == 0 && num != 0)
            {
                matriz[j][1] += 1;
                num = num/i;
            }

            j++;
        }

        if (num == 1) break;
    }

    return j;
}

unsigned long long int MMC(unsigned long long int numA, unsigned long long int numB, unsigned long long int matrizNumA[MAX][2], unsigned long long int matrizNumB[MAX][2])
{
    int tamLinhaMatrizA = fatoresDoPrimo(numA, matrizNumA);
    int tamLinhaMatrizB = fatoresDoPrimo(numB, matrizNumB);

    unsigned long long int mmc = 1;
    int i = 0;
    int j = 0;

    while (i < tamLinhaMatrizA || j < tamLinhaMatrizB)
    {
        if (matrizNumA[i][0] == matrizNumB[j][0])
        {
            if (matrizNumA[i][1] >= matrizNumB[j][1]) mmc *= pow(matrizNumA[i][0], matrizNumA[i][1]);
            else mmc *= pow(matrizNumA[i][0], matrizNumB[j][1]);
            
            i++;
            j++;
        }
        else if (matrizNumA[i][0] > matrizNumB[j][0]) 
        {
            mmc *= pow(matrizNumA[i][0], matrizNumA[i][1]);
            i++;
        }
        else if (matrizNumB [j][0] > matrizNumA[i][0])
        {
            mmc *= pow(matrizNumB[j][0], matrizNumB[j][1]);
            j++;
        }
    }
    
    return mmc;
}

unsigned long long int MDC(unsigned long long int numA, unsigned long long int numB, unsigned long long int matrizNumA[MAX][2], unsigned long long int matrizNumB[MAX][2])
{
    int tamLinhaMatrizA = fatoresDoPrimo(numA, matrizNumA);
    int tamLinhaMatrizB = fatoresDoPrimo(numB, matrizNumB);

    unsigned long long int mdc = 1;
    int i = 0;
    int j = 0;

    while (i < tamLinhaMatrizA || j < tamLinhaMatrizB)
    {
        if (matrizNumA[i][0] == matrizNumB[j][0])
        {
            if (matrizNumA[i][1] <= matrizNumB[j][1]) mdc *= pow(matrizNumA[i][0], matrizNumA[i][1]);
            else mdc *= pow(matrizNumA[i][0], matrizNumB[j][1]);
            
            i++;
            j++;
        }
        else if (matrizNumA[i][0] > matrizNumB[j][0]) 
        {
            i++;
        }
        else if (matrizNumB [j][0] > matrizNumA[i][0])
        {
            j++;
        }
    }
    
    return mdc;
}

int main()
{
    unsigned long long int numA, numB;
    scanf("%llu%llu", &numA, &numB);

    unsigned long long int fatoresNumA[MAX][2] = {0};
    unsigned long long int fatoresNumB[MAX][2] = {0};

    printf("O mmc de %llu e %llu eh: %llu\n", numA, numB, MMC(numA, numB, fatoresNumA, fatoresNumB));
    printf("O mdc de %llu e %llu eh: %llu\n", numA, numB, MDC(numA, numB, fatoresNumA, fatoresNumB));

    return 0;
}