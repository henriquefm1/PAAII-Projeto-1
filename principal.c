#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 100
#define MAX_COLUNAS 100

char mapa[MAX_LINHAS][MAX_COLUNAS];
int n; // Número de linhas
int m; // Número de colunas

//Função de backtracking
int encontraCaminho(int linha, int coluna) {

    //Casos base de falha
    if (linha < 0 || linha >= n || coluna < 0 || coluna >= m || mapa[linha][coluna] == '.') {
        return 0;
    }

    //Caso base
    if (mapa[linha][coluna] == '*') {
        return 1;
    }

    // 3. Salvar o estado do caminho
    char tipo_caminho = mapa[linha][coluna];

    //Marca um "rastro" para que o programa não volte para o caminho usado
    mapa[linha][coluna] = '.';

    //Checa o tipo de caminho
    if (tipo_caminho == 'H') {
        if (encontraCaminho(linha, coluna - 1) == 1) { //Tenta esquerda
            return 1;
        }
        if (encontraCaminho(linha, coluna + 1) == 1) { //Tenta direita
            return 1;
        }
    } else if (tipo_caminho == 'V') {
        if (encontraCaminho(linha - 1, coluna) == 1) { //Tenta cima
            return 1;
        }
        if (encontraCaminho(linha + 1, coluna) == 1) { //Tenta baixo
            return 1;
        }
    }

    return 0;
}

//Função Main
int main() {
    int inicial_linha, inicial_coluna;

    //Parte de leitura de dados do arquivo
    FILE *arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 1; //Termina o programa com erro
    }

    //Lê o número de andares
    fscanf(arquivo, "%d", &n);

    //Lê o mapa, linha por linha
    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%s", mapa[i]);
    }

    //Lê a posição inicial
    fscanf(arquivo, "%d %d", &inicial_linha, &inicial_coluna);
    
    //Fecha o arquivo
    fclose(arquivo);

    //Descobre o número de colunas medindo o tamanho da primeira linha do mapa
    m = strlen(mapa[0]);

    //Chamada Inicial da Recursão
    if (encontraCaminho(inicial_linha, inicial_coluna) == 1) {
        printf("Chave encontrada no Edifício João Calvino!\n");
    } else {
        printf("Não conseguimos encontrar a chave no Edifício João Calvino.\n");
    }

    return 0;
}



