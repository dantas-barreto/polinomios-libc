    // Um polinomio de grau g pode ser representado por um vetor v com g + 1 elementos, representando os coeficientes do polinomio: v[i] = a
    // Assim, o polinomio 2x^3 + 8x + 5 pode ser representado por um vetor com 4 elementos: v[0] = 5, v[1] = 8, v[2] = 0 e v[3] = 2.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

float avalia(int n, float *v, float x) {
    float y = 0.0f;
    for (int i = 0; i < n; i++) {
        y = y + v[i] * pow(x, i);
    }
    return y;
}

int igualdade(int n, float *a, float *b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void soma(int n, float *a, float *b, float *c) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

void produto(int n, float *a, float *b, float *c) {
    int m = 2 * n - 1;
    for (int k = 0; k < m; k++) {
        c[k] = 0.0;
        for (int i = 0; i <= k; i++) {
            if (i < n && k-i < n) {
                c[k] = c[k] + a[i] * b[k - i];
            }
        }
    }    
}

void derivada(int n, float *a, float *d) {
    for (int i = 0; i < n - 1; i++) {
        d[i] = (i + 1) * a[i + 1];
    }
}

void captura(int n, float *x) {
    printf("Entre com os valores do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
}

int main(void) {
    
    int n, x;
    float v[N];

    printf("Entre com o numero de valores do vetor: ");
    scanf("%d", &n);

    if (n > N) {
        printf("Valor ultrapassa o limite de %d.\n", N);
        return 1;
    }
    
    printf("Entre com o valor de x: ");
    scanf("%d", &x);

    captura(n, v);

    float polinomioAvaliado = avalia(n, v, x);

    printf("O polinomio e igual a %f", polinomioAvaliado);
    return 0;
}
