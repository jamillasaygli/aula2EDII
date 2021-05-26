#include <stdio.h>
#include <locale.h>

void insertionsort(int *x, int n){
  int i, k, y;

  for (k = 1; k < n; k++){
    y = x[k];
    for (i = k-1; i >= 0 && y < x[i]; i--){
      x[i+1] = x[i]; 
    }
    x[i+1] = y;
  }
}

void shellsort(int *x, int n, int *inc, int num){
  int i, j, k, span, y;
  
  for(i = 0; i < num; i++){
    span = inc[i];
    for(j = span; j < n; j++){
      y = x[j];
      for(k = j - span; k >=0 && y < x[k]; k-=span){
        x[k+span] = x[k];
      }
      x[k+span] = y;
    }
  }
}

void imprimir(int *x, int n){
  int i;
  printf ("[ ");
  for (i = 0; i < n; i++){
    printf("%d", x[i]);
  }
  printf("]\n\n");
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  int arquivo[]= {4,3,2,10,12,1,5,6};
  int arq[]= {5, 3, 1};
  int tam = sizeof(arquivo)/sizeof(int);
  int t = sizeof(arq)/sizeof(int);
  imprimir(arquivo, tam);
  shellsort(arquivo, tam, arq, t);
  //insertionsort(arquivo, tam);
  imprimir(arquivo, tam);
}