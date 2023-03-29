#include <stdio.h>
#include <stdlib.h>


int main()
{
    int largura, altura;
    int i, j;
    char formato[4];
    char aux[100];
    int valor_maximo;

    int largura2, altura2;
    int i2, j2;
    char formato2[4];
    char aux2[100];
    int valor_maximo2;

    //Imagem original - sulfixo[1]
    FILE *arq1;
    arq1 = fopen("lena256.pgm", "r");
    if (arq1 == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    fscanf(arq1, "%[^\n]\n", formato);
    fscanf(arq1, "%[^\n]\n", aux );
    fscanf(arq1, "%d %d\n", &largura, &altura);
    fscanf(arq1, "%d\n", &valor_maximo);

    printf("L1: %d A1: %d\n\n", largura, altura);

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



    // Imagem alterda - sulfixo[2]
    FILE *arq2;
    arq2 = fopen("lena256CONTRASTE.pgm", "r");
    fscanf(arq2, "%s\n", formato2);
    fscanf(arq2, "%d %d\n", &largura2, &altura2);
    fscanf(arq2, "%d\n", &valor_maximo2);

    printf("L2: %d A2: %d\n\n", largura2, altura2);

    // Alocar memória para a imagem
    int **imagem2 = malloc(altura2 * sizeof(int *));
    for (i2 = 0; i2 < altura2; i2++)
    {
        imagem2[i2] = malloc(largura2 * sizeof(int));
    }



        for (i2 = 0; i2 < altura2; i2++)
        {
            for (j2 = 0; j2 < largura2; j2++)
            {
                int pixel_valor2;
                fscanf(arq2, "%d\n", &pixel_valor2);
                imagem2[i2][j2] = pixel_valor2;
            }
        }
    printf("Passou");


    //Contas
    for ( i = 0; i < altura; i++)
        {
        for ( j = 0; j < largura; j++)
        {
            printf("i: %d j: %d\n", i, j);
            if(imagem[i][j]-imagem2[i][j]<0){
                 imagem[i][j] = 0;
            }
            else{
                imagem[i][j] = imagem[i][j]-imagem2[i][j];
            }
        }
        }
printf("Passou");

    // Salvar a imagem resultante em um novo arquivo
    FILE *arq3;
    arq3 = fopen("lena256SUBTRAIDA.pgm", "w");
    fprintf(arq3, "%s\n", formato);
    fprintf(arq3, "%d %d\n", largura, altura);
    fprintf(arq3, "%d\n", valor_maximo);
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            fprintf(arq3, "%d\n", imagem[i][j]);
        }
    }


     // Liberar a memória alocada
    for (i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);

     // Liberar a memória alocada
    for (i2 = 0; i2 < altura2; i2++)
    {
        free(imagem[i2]);
    }
    free(imagem2);

    fclose(arq2);
    fclose(arq1);

}
