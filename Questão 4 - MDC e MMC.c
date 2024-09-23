#include <stdio.h>
#include <math.h>

#define MAX 100

int primo(int x, int div){
    if(x<= 1) return 0;
    
    if(div*div > x)return 1;

    if(x % div == 0) return 0;
    
    return primo(x, div+1);
}

int fatoresDoPrimo(int num, int matriz[MAX][2])
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
    }

    return j;
}

int MMC(int numA, int numB, int matrizNumA[MAX][2], int matrizNumB[MAX][2])
{
    int tamLinhaMatrizA = fatoresDoPrimo(numA, matrizNumA);
    int tamLinhaMatrizB = fatoresDoPrimo(numB, matrizNumB);

    int mmc = 1;
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

int MDC(int numA, int numB, int matrizNumA[MAX][2], int matrizNumB[MAX][2])
{
    int tamLinhaMatrizA = fatoresDoPrimo(numA, matrizNumA);
    int tamLinhaMatrizB = fatoresDoPrimo(numB, matrizNumB);

    int mdc = 1;
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
    int numA, numB;
    scanf("%d%d", &numA, &numB);

    int fatoresNumA[MAX][2] = {0};
    int fatoresNumB[MAX][2] = {0};

    printf("O mmc de %d e %d eh: %d\n", numA, numB, MMC(numA, numB, fatoresNumA, fatoresNumB));
    printf("O mdc de %d e %d eh: %d\n", numA, numB, MDC(numA, numB, fatoresNumA, fatoresNumB));

    return 0;
}