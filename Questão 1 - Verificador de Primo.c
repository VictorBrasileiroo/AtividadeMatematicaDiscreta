#include <stdio.h>

int ehPrimo(int a, int b) {
    if (a <= 1) return 0;
    if (b * b > a) return 1;
    if (a % b == 0) return 0;
    return ehPrimo(a, b + 1);
}

int main() {
    int valor;
    scanf("%d", &valor);
    printf(ehPrimo(valor, 2) ? "É PRIMO!" : "NÃO É PRIMO.");
    return 0;
}
