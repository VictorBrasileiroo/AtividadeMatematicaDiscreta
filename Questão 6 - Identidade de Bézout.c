#include <stdio.h>
int euclidesEstendido(int a, int b, int *s, int *t) {
    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }

    int s_temp, t_temp;
    int mdc = euclidesEstendido(b, a % b, &s_temp, &t_temp);
    
    *s = t_temp;
    *t = s_temp - (a / b) * t_temp;
    
    return mdc;
}

int main() {
    int a, b, s, t;
    scanf("%d %d", &a, &b);
    int mdc = euclidesEstendido(a, b, &s, &t);
    printf("Coeficientes: MDC: %d || s = %d, t = %d\n", mdc, s, t);
    
    return 0;
}
