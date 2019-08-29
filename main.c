#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int np = 15, nc = 15, nl = 15;

//conversão
int ponto(int x, int y, int z){
    return (z*(nc*nl)) + (x*nl) + y;
}

//x² + y² + z² <= R²
void esfera(int *x, int a, int b, int c, int r){
    int i,j,k,equacao;
    for(i=0; i<np; i++){
        for(j=0; j<nc; j++){
            for(k=0; k<nl; k++){
                equacao = sqrt((pow((k-a),2))+(pow((j-b),2))+(pow((i-c),2)));
                if(equacao <= r){
                    x[ponto(k,j,i)] = 1;
                }
                else{
                    x[ponto(k,j,i)] = 0;
                }
            }
        }
    }
}

void planoEsfera(int *x, int k){
    int i,j;
    for(j=0; j<nc; j++){
        for(i=0; i<nl; i++){
            printf(" %d ", x[ponto(i,j,k)]);
        }
        printf("\n");
    }
}

int main(){
    int *x;
    x = (int*) malloc((np*nl*nc)*sizeof(int));

    int r, k;
    int Xc = 7, Yc = 7, Zc = 7;

    printf("Raio da esfera: ");
    scanf("%d", &r);

    printf("Qual plano de 0 a 14 que deseja imprimir a parte da esfera? ");
    scanf("%d", &k);

    esfera(x, Xc, Yc, Zc, r);

    planoEsfera(x, k);
}


