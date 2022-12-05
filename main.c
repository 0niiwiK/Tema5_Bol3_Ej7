#include <stdio.h>
#define TAM 50

// Prototipos
void pedirCadena(char *cad);
void cadenaArrayLimpio(char *cad, int tama, char *res, int *max, int *palabras);
int calculaTamanoCadena(char *cad);
void imprimirMatrizCadenas(int palabras, int max, char mat[][max]);
void cadenasAMatriz(char *cad, int max, int palabras, char mat[][max]);

int main() {
    char cadena[TAM];
    printf("Introduzca la cadena original: ");
    pedirCadena(cadena);
    int tama= calculaTamanoCadena(cadena);
    char cad[tama];
    int palabras=1, max=0;
    cadenaArrayLimpio(cadena,tama,cad,&max,&palabras);
    char matriz[palabras][max];
    cadenasAMatriz(cad,max,palabras,matriz);
    imprimirMatrizCadenas(palabras,max,matriz);
    return 0;
}

void pedirCadena(char *cad){
    scanf("%[^\n]", cad);
    fflush(stdin);
}

int calculaTamanoCadena(char *cad){
    int caracteres=0,i=0;
    do {
            caracteres++;
            i++;
    } while (cad[i]!='\0');
    caracteres++;
    return caracteres;
}

void cadenaArrayLimpio(char *cad, int tama, char *res, int *max, int *palabras){
    int i, j=0;
    for (i=0; i < tama-1; i++) {
        while (cad[j]=='\0')
            j++;
        res[i]=cad[j];
        j++;
        if (res[i]==' '){
            *max=0;
            *palabras=*palabras+1;
        }
        else
            *max=*max+1;
    }
    *max=*max+1;
    res[i++]=' ';
}

void imprimirMatrizCadenas(int palabras, int max, char mat[][max]){
    int letras,j,repeticiones;
    for (int i = 0; i < palabras; ++i) {
        letras=0;
        j=0;
        do {
            letras++;
            j++;
        } while (mat[i][j]!=' ');
        printf("\n");
        for (int k = 0; k < letras; ++k) {
            printf("%c",mat[i][k]);
        }
        printf(" - Longitud de palabra: %d",letras);
    }
    printf("\n");
    for (int i = 97; i <= 122 ; ++i) {
        repeticiones=0;
        for (int k = 0; k < palabras; ++k) {
            for (int l = 0; l < max; ++l) {
                if (mat[k][l]==i)
                    repeticiones++;
            }
        }
        if (repeticiones>3)
            printf("\nEl caracter %c aparece mas de tres veces.",i);
    }
}

void cadenasAMatriz(char *cad, int max, int palabras, char mat[][max]){
    int j,k=0;
    for (int i = 0; i < palabras; ++i) {
        j=0;
        do {
            mat[i][j]=cad[k];
            k++;
            j++;
        } while (cad[k]!=' ');
        while (j<max){
           mat[i][j]=' ';
           j++;
        }
        k++;
    }
}