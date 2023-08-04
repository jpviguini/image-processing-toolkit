#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int col, lin, max;
    char form[3];
} imagem;


void aloca_matriz(int ***matriz_old, int ***matriz_new, imagem img) {

    /*Aloca a matriz original*/
    *matriz_old = malloc(img.lin * sizeof(int*));

    for(int i = 0;i < img.lin; i++) {
        (*matriz_old)[i] = malloc(img.col * sizeof(int));
    }

    /*Aloca a matriz nova*/
    *matriz_new = malloc(img.lin * sizeof(int*));

    for(int i = 0;i < img.lin; i++) {
        (*matriz_new)[i] = calloc(img.col, sizeof(int));
    }
}

void desaloca(int ***matriz_old, int ***matriz_new, imagem img) {

    for (int i = 0; i < img.lin; i++) {
        free((*matriz_old)[i]);
    }
    free(*matriz_old);
    
    for (int i = 0; i < img.lin; i++) {
        free((*matriz_new)[i]);
    }
    free(*matriz_new);
}

void read_img(FILE *fp_old, imagem *img, char comment[100]) {
    fscanf(fp_old, "%s ", (*img).form);
    fscanf(fp_old, "%[^\n]", comment); 
    fscanf(fp_old, "%d", &((*img).col));
    fscanf(fp_old, "%d", &((*img).lin));
    fscanf(fp_old, "%d", &((*img).max));
}

void generate_img(FILE *fp_new, imagem img, int **matriz_new) {

    fprintf(fp_new, "%s\n", "P2");
    fprintf(fp_new, "%s\n", "# CREATOR: Image Generator SCC-221 - ICC I");
    fprintf(fp_new, "%d ", img.col);
    fprintf(fp_new, "%d\n", img.lin);

    /* Procura pelo pixel de maior valor na nova imagem */
    int new_max = 0;
    for (int i = 0; i < img.lin; i++) {
        for (int j = 0; j < img.col; j++) {
            if (matriz_new[i][j] > new_max){
                new_max = matriz_new[i][j];
            }
        }
    }

    fprintf(fp_new, "%d\n", new_max); 

    /* Imprime os pixels de fato */
    for (int i = 0; i < img.lin; i++) {
        for (int j = 0; j < img.col; j++) {
            fprintf(fp_new, "%d\n", matriz_new[i][j]);
        }
    }
}

/* Operação 1 (logarítmo)*/
void calc_log(int **matriz_old, int ***matriz_new, imagem img) {
    
    float c = 255.0/log(1 + img.max);

    for (int i = 0; i < img.lin; i++) {
        for (int j = 0; j < img.col; j++) {
            (*matriz_new)[i][j] = (int) (c * log(1 + matriz_old[i][j]));
        }
    }
}

/* Operação 2 (contrast stretching) */
void stretch (int **matriz_old, int ***matriz_new, imagem img, int min) {

    for (int i = 0; i < img.lin; i++) {
        for (int j = 0; j < img.col; j++) {
            //(*matriz_new)[i][j] = (matriz_old[i][j] - min) / (img.max - min) * 255;
            (*matriz_new)[i][j] = (matriz_old[i][j] - min) * ((255)/(img.max - min));
        }
    }
    
}


/* Operação 3 (paintbrush) */
void flood_fill (int ***matriz_new, imagem img, int i, int j, int start_color) {

    int new_color = 100;

    if (i >= img.lin || j >= img.col || i < 0 || j < 0) {
        return;
    }

    if ((*matriz_new)[i][j] != start_color) { 
        return;
    }

    (*matriz_new)[i][j] = new_color;
    
    flood_fill (matriz_new, img, i - 1, j, start_color);
    flood_fill (matriz_new, img, i + 1, j, start_color);
    flood_fill (matriz_new, img, i, j - 1, start_color);
    flood_fill (matriz_new, img, i, j + 1, start_color);
}

/* Operação 4 (exponencial) */
void exponential (int **matriz_old, int ***matriz_new, imagem img) {

    for (int i = 0; i < img.lin; i++) {
        for (int j = 0; j < img.col; j++) {
            /* 10 e 1.01 são valores arbitrários por enquanto */
            (*matriz_new)[i][j] = (int) 10 * pow(1.01, matriz_old[i][j]);
        }
    }
}

/* Operação 5 (Image negative)*/
void img_negative (int **matriz_old, int ***matriz_new, imagem img) {

    for (int i = 0; i < img.lin; i++) {
        for (int j = 0; j < img.col; j++) {
            (*matriz_new)[i][j] = (img.max - 1 - matriz_old[i][j]);

            if ((*matriz_new)[i][j] < 0) {
                (*matriz_new)[i][j] = 0;
            }
        }
    }
}

/* Operação 6 - Mean Filter*/
void mean_filter(int **matriz_old, int ***matriz_new, imagem img) {

    int kernel[9];

    for (int i = 1; i < img.lin - 1; i++) {
        for (int j = 1; j < img.col - 1; j++) {

            int k = 0;

            /* Encontra os vizinhos */
            for (int n = -1; n <= 1; n++){
                for (int m = -1; m <= 1; m++){
                    kernel[k] = matriz_old[i + n][j + m];
                    k++;
                }
            }

            int sum = 0;
            for (int a = 0; a < 9; a++){
                sum += kernel[a];
            }

            /* Cada pixel é substituido pela média dos seus vizinhos */
            (*matriz_new)[i][j] = sum/9;
        }
    }
}

/* Operação 7 - Median Filter */
void median_filter(int **matriz_old, int ***matriz_new, imagem img) {

    int kernel[9];

    for (int i = 1; i < img.lin - 1; i++) {
        for (int j = 1; j < img.col - 1; j++) {

            int k = 0;

            /* Encontra os vizinhos */
            for (int n = -1; n <= 1; n++){
                for (int m = -1; m <= 1; m++){
                    kernel[k] = matriz_old[i + n][j + m];
                    k++;
                }
            }
            
            /* Coloca os vizinhos em ordem crescente */
            for (int a = 0; a < 8; a++){
                for (int b = 0; b < 9; b++){
                    if (kernel[a] > kernel[b]){
                        int temp;
                        temp = kernel[a];
                        kernel[a] = kernel[b];
                        kernel[b] = temp;
                    }
                }
            }

            int median;

            if (k % 2 == 0){
                median = (kernel[4] + kernel[5]) / 2;
            } else {
                median = kernel[4];
            }

            (*matriz_new)[i][j] = median;
            
        }
    }
}

int main() {

    FILE *fp_old, *fp_new;
    int op;
    int min = 255;
    int **matriz_old, **matriz_new;
    char arquivo[20]; // Considerou-se que o nome do arquivo não passa de 20 caracteres para evitar realloc()
    char comment[100];
    imagem img;

    printf("/// Menu de operacoes ///\n");
    printf("-------------------------\n");
    printf("1. Logarithmic\n");
    printf("2. Contrast Stretching\n");
    printf("3. Floodfill\n");
    printf("4. Exponential\n");
    printf("5. Image Negative\n");
    printf("6. Mean Filter\n");
    printf("7. Median Filter\n");

    /* Lê o input do usuário*/
    printf("Insira o número da operacao desejada: ");
    scanf("%d", &op);
    printf("Digite o nome da imagem PGM a ser modificada: ");
    scanf("%s", arquivo);

    /* Abre o arquivo da imagem para leitura (formato binário)*/
    fp_old = fopen(arquivo, "rb");
    read_img(fp_old, &img, comment);
    

    aloca_matriz(&matriz_old, &matriz_new, img);


    /* Leitura formato ASCII*/
    if (img.form[1] == '2') {

        for (int i = 0; i < img.lin; i++) {
            for (int j = 0; j < img.col; j++) {
                fscanf(fp_old, "%d", &matriz_old[i][j]);
            }
        }
        /* Leitura formato binário */
    } else if (img.form[1] == '5') { 

        for (int i = 0; i < img.lin; i++) {
            for (int j = 0; j < img.col; j++) {

                unsigned char pixel; // Pixels vão de 0 a 255 (números positivos). Lendo cada char estamos lendo cada byte.
                // Utilizou-se o fread() e não o fscanf() pois estamos lendo bytes.
                fread(&pixel, sizeof(unsigned char), 1, fp_old); 
                matriz_old[i][j] = (int) pixel;

            }
        }

        img.form[1] = '2'; // Troca o formato P5 para P2.
    }

    switch(op) {

        /* Logarítmo */
        case 1: calc_log(matriz_old, &matriz_new, img);
        break;

        /* Contrast stretching */
        case 2: 
            /* Verificar quem é o menor pixel */
            for (int i = 0; i < img.lin; i++) {
                for (int j = 0; j < img.col; j++) {
                    if (matriz_old[i][j] < min) {
                        min = matriz_old[i][j];
                    }
                }
            }
            
            stretch(matriz_old, &matriz_new, img, min);
            break;

        /* Paintbrush (flood fill)*/
        case 3:
            /* Copia a imagem original para a nova imagem */
            for (int i = 0; i < img.lin; i++) {
                for(int j = 0; j < img.col; j++) {
                    matriz_new[i][j] = matriz_old[i][j];
                }
            }

            int start_color = matriz_new[img.lin/2][img.col/2]; // Define o pixel inicial (centro da imagem)
            
            flood_fill (&matriz_new, img, img.lin/2, img.col/2, start_color);
            break;

        /* --- Operações extras --- */

        /* Exponencial */
        case 4: exponential (matriz_old, &matriz_new, img);
        break;
        
        /* Image negative */
        case 5: img_negative (matriz_old, &matriz_new, img);
        break;

        /* --- Filtros --- */
        /* Mean filter */
        case 6: mean_filter(matriz_old, &matriz_new, img);
        break;

        /* Median filter */
        case 7: median_filter(matriz_old, &matriz_new, img);
        break;
    }

    /* Cria o arquivo da imagem modificada */
    fp_new = fopen("img_nova.pgm", "wb");
    generate_img(fp_new, img, matriz_new);
    
    /* Desaloca a memória reservada para as imagens original e modificada */
    desaloca(&matriz_old, &matriz_new, img);
    
    /* Fechar os arquivos */
    fclose(fp_old);
    fclose(fp_new);
    
}