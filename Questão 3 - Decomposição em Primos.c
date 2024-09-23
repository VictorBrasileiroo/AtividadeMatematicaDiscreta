#include <stdio.h>

int primo(int x, int div){
    if(x<= 1) return 0;
    
    if(div*div > x)return 1;

    if(x % div == 0) return 0;
    
    return primo(x, div+1);
}

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 2; i <= num; i++){
        if(primo(i, 2)){
        
            while(num % i == 0){
              if(num/i <= 1){
                printf("%d", i);
              }else{
                printf("%d x ", i);
              }
                num = num/i;
            }

        }

    }
    return 0;
}

