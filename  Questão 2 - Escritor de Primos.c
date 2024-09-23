#include <stdio.h>
#include <math.h>
#include <time.h>

int primo(int div, int x)
{
    while (1)
    {
        if(x<= 1) return 0;
        
        if(div*div > x)return 1;

        if(x % div == 0) return 0;
        
        div++;

    }
}

void escreveprimo(int contador)
{
    int primos = 0;
    time_t inicio, agora;

    time(&inicio);

    while(1)
    {
        time(&agora);

        if (difftime(agora, inicio) >= 60)
        {
            printf("ACABOU");
            break;
        }

        if (primo(2, contador)) 
        {
            primos++;
            printf("%d - eh o %d numero primo.\n", contador, primos);
        }
        contador++;
    }
}


int main()
{
    escreveprimo(2);
}