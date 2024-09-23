#include <stdio.h>

int mdc(int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        if (b == 1)
        {
            return 1;
        }else{
            return 0;
        }
    }
    else
    {
        mdc(b, r);
    }
}

int mod(int x, int a, int m, int result){
    if(( x* result )%m == a%m){
        return result;
    }

    return mod(x, a, m, result+1);
}


int main(){

    //quantos tu quer?
    int qtd;
    printf("Quantos Argumentos voce quer incluir = ");
    scanf("%d", &qtd);

    int a[qtd][4];

    
    //loop
    //  função de atrubuição a um array com 3 espaçoes cada( array[x][4])   (0 = x)(1 = a)(2 = m)(3 = result)

    printf("Colocar somente numeros educados, sem bagunca de numero nos milhares\n");
    
    for(int i = 0; i < qtd; i++){
        printf("%dº Argumento\n Modulo => ", i+1); 
        scanf("%d", &a[i][2]);
        printf("\n");
        
        printf("%dº Argumento\n Resto => ", i+1);
        scanf("%d", &a[i][1]);
        printf("\n_________________________________________\n");
    }
    
    //verifica se é comprimo os [x][2]

    for(int i = 0; i < qtd; i++){

        for(int j = i+1; j< qtd; j++){

            if( !(mdc( a[i][2], a[j][2] ) ) ){
                printf("%d e %d nao sao comprimos\n", a[i][2] , a[j][2] );
                return -1;
            }

        }
    }


    //  Se Não: Informa
    //  Se sim: usa Função do Mod 

    
    //o resto, é facil ver

    //  pega os RESULTAOD E MULTIPLICA

    int M_zao = 1;

    for(int i = 0; i < qtd; i++){
        M_zao = M_zao * a[i][2];
    }
    int M_Dessa[qtd];

    for(int i = 0; i < qtd; i++){
        M_Dessa[i] = M_zao/a[i][2];
        a[i][3] = mod(M_Dessa[i], 1, a[i][2], 1);
    }

    int Numeros[qtd];

    for(int i = 0; i < qtd; i++){
        Numeros[i] =   a[i][3] * M_Dessa[i] * a[i][1];

    }

    int soma = 0;

    for(int i = 0; i < qtd; i++){
        soma += Numeros[i];
    }

    while(soma > M_zao){
        soma -= M_zao;
    }



    printf("x _=_ %d (mod %d)", soma, M_zao );

    return 0;

}