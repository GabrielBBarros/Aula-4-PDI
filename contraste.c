#include <stdio.h>
#include <stdlib.h>
int largura, altura;
int i, j;
char formato[4];
char aux[100];
int valor_maximo;

int contraste(int aux_a, int aux_b, int aux_valor1, int aux_valor2, int**imagem){


for ( i = 0; i < altura; i++)
    {
        for ( j = 0; j < largura; j++)
        {
            if((imagem[i][j]>=aux_a)&&(imagem[i][j]<=aux_b)){
                imagem[i][j] = aux_valor1;
            }
            else{
                imagem[i][j] = aux_valor2;
            }
        }
    }
    return 1;

}

int main()
{


    int a;
    int b;
    int valor1;
    int valor2;

    FILE *arq1;
    arq1 = fopen("lena256.pgm", "r");
    if (arq1 == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    fscanf(arq1, "%[^\n]\n", formato);
    printf("%s\n",formato);
    fscanf(arq1, "%[^\n]\n", aux );
    fscanf(arq1, "%d %d\n", &largura, &altura);
    printf("%d %d\n",largura, altura);
    fscanf(arq1, "%d\n", &valor_maximo);
    printf("Lido");
    printf("\nInsira o primeiro numero do intervalo: ");
    scanf("%d", &a);
    printf("\nInsira o primeiro numero do intervalo: ");
    scanf("%d", &b);
    printf("\nInsira o valor maximo: ");
    scanf("%d", &valor1);
    printf("\nInsira o valor minimo: ");
    scanf("%d", &valor2);

    // Alocar memória para a imagem
    int **imagem = malloc(altura * sizeof(int *));
    for (i = 0; i < altura; i++)
    {
        imagem[i] = malloc(largura * sizeof(int));
    }



        for (i = 0; i < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                int pixel_valor;
                fscanf(arq1, "%d\n", &pixel_valor);
                imagem[i][j] = pixel_valor;
            }
        }


contraste(a,b,valor1,valor2, imagem);



    // Salvar a imagem resultante em um novo arquivo
    FILE *arq2;
    arq2 = fopen("lena256CONTRASTE.pgm", "w");
    fprintf(arq2, "%s\n", formato);
    fprintf(arq2, "%d %d\n", largura, altura);
    fprintf(arq2, "%d\n", valor_maximo);
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            fprintf(arq2, "%d\n", imagem[i][j]);
        }
    }
    fclose(arq2);

    // Liberar a memória alocada
    for (i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);

    fclose(arq1);
    return 0;
}
