#ifndef ESTRUTURA_H
#define ESTRUTURA_H


typedef struct letra
{
    char letra;
    struct letra* proxima;
} Letra; // estrutura definida para armazenar os caracteres de uma Letra

// Definição da estrutura da Linha
typedef struct linha
{
    struct linha* prox;
    Letra* primeiraLetra;
} Linha;



// FUNÇÕES DE INSERÇÃO NA ESTRUTURA(CRIAÇÃO DE LINHA E INSERÇÃO DE NÓS DE CARACTERES)

/// Criando um nó para um caractere

Letra* getnodeLetra()
{
    return (Letra *) malloc (sizeof(Letra));
}

/// inserindo o caractere no nó
Letra* novaLetra(char letra)
{
    Letra* q = getnodeLetra();
    q->letra = letra;
    q->proxima = NULL;
    return q;
}

/// Criando um nó para uma linha

Linha* getnodeLinha()
{
    return (Linha *) malloc (sizeof(Linha));
}

/// inicializando a linha

Linha* novaLinha()
{
    Linha* q = getnodeLinha();
    q->primeiraLetra = NULL;
    q->prox = NULL;
    return q;
}

//Funções úteis para poupar trabalho
Linha* retornarLinha(Linha* primeiraLinha, int linha) ///Função para retornar a linha desejada (linha = numero da linha)
{
    int contador = 0;
    Linha* atual = primeiraLinha;

    while (atual != NULL)
    {
        if (contador == linha)
        {
            return atual;
        }
        contador++;
        atual = atual->prox;
    }

    return NULL;
}

int contadorCaractereCol(Linha* linha)
{
    int contador = 0;
    Letra* posColuna = linha->primeiraLetra;

    while (posColuna != NULL)
    {
        contador++;
        posColuna = posColuna->proxima;
    }

    return contador;
}

int contadorLinhas(Linha* primeiraLinha)
{
    int contador = 0;
    Linha* aul = primeiraLinha;

    while (aul->prox != NULL)
    {
        contador++;
        aul = aul->prox;
    }

    return contador;
}


void insereLetra(Linha* linha, int posicao, char letra)/// Inserir em uma posição específica na linha
{
    int contador = 0;
    Letra* q = novaLetra(letra);

    if (linha->primeiraLetra == NULL || posicao == 0)
    {
        q->proxima = linha->primeiraLetra;
        linha->primeiraLetra = q;
    }
    else
    {
        Letra* atual = linha->primeiraLetra;

        while (atual->proxima != NULL && contador < posicao - 1)
        {
            atual = atual->proxima;
            contador++;
        }

        q->proxima = atual->proxima;
        atual->proxima = q;
    }
}

void sobreescreverCaractere(Linha* linha, int* cursorX, char letra)/// Inserir em uma posição específica na linha(insert)
{
    int contador = 0;


    Letra* atual = linha->primeiraLetra;

    if(atual != NULL)
    {
        while (atual->proxima != NULL && contador < *cursorX)
        {
            atual = atual->proxima;
            contador++;
        }
        atual->letra = letra;
        (*cursorX)++;
    }
    else
        return;

}

//FUNÇÃO DE EXCLUSÃO DA ESTRUTURA
void removeChar(Linha* linha, int posicao)/// Função para remover um caractere de uma posição específica
{
    int contador = 0;
    if (!(linha->primeiraLetra == NULL))
    {

        Letra* auc = linha->primeiraLetra;
        if (posicao == 0)
        {
            linha->primeiraLetra = auc->proxima;
            free(auc);
        }
        else
        {
            Letra* anterior = NULL;

            while (auc != NULL && contador < posicao)
            {
                anterior = auc;
                auc = auc->proxima;
                contador++;
            }
            if (auc == NULL)
            {
                return;
            }
            anterior->proxima = auc->proxima;
            free(auc);
        }
    }
    else
    {
        return;
    }
}

//void zerarEstrutura(Linha** primeiraLinha)
//{
//    Linha* aul = primeiraLinha;
//    Linha* auldois = primeiraLinha; /// auxiliar de linha
//    while (aul != NULL)
//    {
//        Letra* auc = aul->primeiraLetra;
//        Letra* aucdois = aul->primeiraLetra; /// auxiliar de coluna
//        while (auc != NULL)
//        {
//            aucdois = auc;
//            auc = auc->proxima;
//            free(aucdois);
//        }
//        auldois = aul;
//        aul = aul->prox;
//        free(auldois);
//    }
//}
void imprimirEstrutura(Linha* primeiraLinha)
{
    system("cls");

    Linha* aul = primeiraLinha; /// auxiliar de linha
    while (aul != NULL)
    {
        Letra* auc = aul->primeiraLetra; /// auxiliar de coluna
        while (auc != NULL)
        {
            putchar(auc->letra);
            auc = auc->proxima;
        }
        putchar('\n');
        aul = aul->prox;
    }
}


//void imprimirBuffer(Linha* primeiraLinha, int cursor_type, int linhas, int posCursorY)
//{
//    char buffer[linhas][COLUNAS + 1]; // Buffer de tela
//    Linha* aul = primeiraLinha; // auxiliar de linha
//    int diferenca = 0;
//
//    // Preencher o buffer com espaços em branco por padrão
//    for (int y = 0; y < linhas+1; ++y)
//    {
//        for (int x = 0; x < COLUNAS; ++x)
//        {
//            buffer[y][x] = ' ';
//        }
//        buffer[y][COLUNAS] = '\0'; // Null-terminate a linha
//    }
//
//    int y = 0;
//
//    // Calcular a diferença entre o cursor e o início do buffer
//    diferenca = posCursorY - BUFFER_Y;
//
//    // Ajustar a posição inicial da linha
//    while (aul != NULL && y < diferenca)
//    {
//        aul = aul->prox;
//        ++y;
//    }
//
//    // Preencher o buffer com o conteúdo visível
//    while (aul != NULL && y < linhas+1)
//    {
//        Letra* auc = aul->primeiraLetra; // auxiliar de coluna
//        int x = 0;
//        while (auc != NULL && x < COLUNAS)
//        {
//            buffer[y][x] = auc->letra;
//            ++x;
//            auc = auc->proxima;
//        }
//        ++y;
//        aul = aul->prox;
//    }
//
//    // Imprimir o buffer de uma vez
//    _setcursortype(0);
//
//    for (int i = 0; i <= linhas; i++)
//    {
//        gotoxy(0, i);
//        printf("%s", buffer[i]);
//    }
//
//    _setcursortype(cursor_type);
//}
//void imprimirBuffer(Linha* primeiraLinha, int cursor_type, int linhas, int posCursorY)
//{
//   // system("cls"); // Limpar o console antes de imprimir o buffer
//
//    int diferenca = 0;
//    diferenca = posCursorY - BUFFER_Y;
//    if (diferenca > 0)
//    {
//        linhas = linhas - diferenca;
//    }
//
//    char buffer[linhas][COLUNAS + 1]; // Buffer de tela
//    Linha* aul = primeiraLinha; // auxiliar de linha
//
//    // Preencher o buffer com espaços em branco por padrão
//    for (int y = 0; y < linhas; ++y)
//    {
//        for (int x = 0; x < COLUNAS; ++x)
//        {
//            buffer[y][x] = ' ';
//        }
//        buffer[y][COLUNAS] = '\0'; // Null-terminate a linha
//    }
//
//    int y = 0;
//
//    while (aul != NULL && y < linhas)
//    {
//        Letra* auc = aul->primeiraLetra; // auxiliar de coluna
//        int x = 0;
//        while (auc != NULL && x < COLUNAS)
//        {
//            buffer[y][x] = auc->letra;
//            ++x;
//            auc = auc->proxima;
//        }
//        ++y;
//        aul = aul->prox;
//    }
//
//    _setcursortype(0);
//
//    for (int i = 0; i < linhas; i++)
//    {
//        gotoxy(0, i + diferenca);
//        printf("%s", buffer[i]);
//    }
//
//    _setcursortype(cursor_type);
//}


void imprimirBufferTESTE(Linha* primeiraLinha, int cursor_type, int linhas, int posCursorY)
{
    //printf("%d", linhas);
    int diferenca = 0;
    diferenca = posCursorY - BUFFER_Y;
    if(diferenca > 0)
    {
        linhas = linhas - diferenca;
    }

    char buffer[linhas][COLUNAS+1]; // Buffer de tela
    Linha* aul = primeiraLinha; // auxiliar de linha


    //system("cls");

    for (int y = 0; y < linhas; ++y)
    {
        for (int x = 0; x < COLUNAS; ++x)
        {
            buffer[y][x] = ' ';
        }
        buffer[y][COLUNAS] = '\0'; // Null-terminate a linha
    }

    if(posCursorY <= BUFFER_Y+1)
    {


        // Preencher o buffer com espaços em branco por padrão
        // Atualizar o buffer de tela
        int y = 0;

        while (aul != NULL && y < BUFFER_Y)
        {
            Letra* auc = aul->primeiraLetra; // auxiliar de coluna
            int x = 0;
            while (auc != NULL && x < COLUNAS)
            {
                buffer[y][x] = auc->letra;
                ++x;
                auc = auc->proxima;
            }
            ++y;
            aul = aul->prox;
        }

        _setcursortype(0);

        for (int i = 0; i < linhas; i++)
        {
            gotoxy(0, i);
            printf("%s", buffer[i]);
        }
        _setcursortype(cursor_type);

    }
    else
    {
        int y = 0;

        //printf("%d", diferenca);

        aul = retornarLinha(primeiraLinha, diferenca+1);

        while (aul != NULL && y < linhas)
        {
            Letra* auc = aul->primeiraLetra; // auxiliar de coluna
            int x = 0;
            while (auc != NULL && x < COLUNAS)
            {
                buffer[y][x] = auc->letra;
                ++x;
                auc = auc->proxima;
            }
            ++y;
            aul = aul->prox;
        }

        _setcursortype(0);

        for (int i = 0; i < linhas; i++)
        {
            gotoxy(0, i + diferenca+1);
            printf("%s", buffer[i]);
        }
        _setcursortype(cursor_type);

    }
}



void imprimirBuffer(Linha* primeiraLinha, int cursor_type, int linhas, int posCursorY)
{
    //printf("%d", linhas);
    int diferenca = 0;
    diferenca = posCursorY - BUFFER_Y;
    if(diferenca > 0)
    {
        linhas = linhas - diferenca;
    }

    char buffer[linhas][COLUNAS+1]; // Buffer de tela
    Linha* aul = primeiraLinha; // auxiliar de linha


    //system("cls");

    for (int y = 0; y < linhas; ++y)
    {
        for (int x = 0; x < COLUNAS; ++x)
        {
            buffer[y][x] = ' ';
        }
        buffer[y][COLUNAS] = '\0'; // Null-terminate a linha
    }

    if(posCursorY <= BUFFER_Y+1)
    {


        // Preencher o buffer com espaços em branco por padrão
        // Atualizar o buffer de tela
        int y = 0;

        while (aul != NULL && y < linhas)
        {
            Letra* auc = aul->primeiraLetra; // auxiliar de coluna
            int x = 0;
            while (auc != NULL && x < COLUNAS)
            {
                buffer[y][x] = auc->letra;
                ++x;
                auc = auc->proxima;
            }
            ++y;
            aul = aul->prox;
        }

        _setcursortype(0);

        for (int i = 0; i < linhas; i++)
        {
            gotoxy(0, i);
            printf("%s", buffer[i]);
        }
        _setcursortype(cursor_type);

    }
    else
    {
        int y = 0;

        //printf("%d", diferenca);

        aul = retornarLinha(primeiraLinha, diferenca+1);

        while (aul != NULL && y < linhas)
        {
            Letra* auc = aul->primeiraLetra; // auxiliar de coluna
            int x = 0;
            while (auc != NULL && x < COLUNAS)
            {
                buffer[y][x] = auc->letra;
                ++x;
                auc = auc->proxima;
            }
            ++y;
            aul = aul->prox;
        }

        _setcursortype(0);

        for (int i = 0; i < linhas; i++)
        {
            gotoxy(0, i + diferenca+1);
            printf("%s", buffer[i]);
        }
        _setcursortype(cursor_type);

    }
    // Imprimir o buffer de uma vez



}


void realocarLinhas(Linha **primeiraLinha, int *posCursorCol, int *posCursorLinha, int *qnt)
{
    Linha* linhaAtual = retornarLinha(*primeiraLinha,*posCursorLinha);
    if (linhaAtual->prox == NULL)
    {
        return;
    }



    Linha *linhaProxima = linhaAtual->prox;

    Letra *ultimoCaractereAtual = linhaAtual->primeiraLetra;
    while (ultimoCaractereAtual->proxima != NULL)
    {
        ultimoCaractereAtual = ultimoCaractereAtual->proxima;
    }

    Letra *primeiroCaractereProxima = linhaProxima->primeiraLetra;

    if(primeiroCaractereProxima != NULL)
    {
        insereLetra(linhaAtual, qnt, primeiroCaractereProxima->letra);
        removeChar(linhaProxima, 0);
    }
    else
        return;



}

void daEnter(Linha* primeiraLinha, int poscursorY)
{
    int auxiliarCol = COLUNAS - 1;
    enterFuncao(&primeiraLinha, &poscursorY, &auxiliarCol);
}

void realocarUltimoCaractereRec(Linha *linhaAtual, Linha **primeiraLinha, int poscursorY)
{
    if(linhaAtual->prox == NULL)
    {
        daEnter(*primeiraLinha, poscursorY);
    }

    Linha *linhaProxima = linhaAtual->prox;

    int qntcarac = contadorCaractereCol(linhaProxima);

    if (qntcarac >= COLUNAS-1)
    {
        realocarUltimoCaractereRec(linhaProxima, primeiraLinha, poscursorY+1);
    }

    Letra *ultimoCaractereAtual = linhaAtual->primeiraLetra;

    while (ultimoCaractereAtual->proxima != NULL)
    {
        ultimoCaractereAtual = ultimoCaractereAtual->proxima;
    }


    insereLetra(linhaProxima, 0, ultimoCaractereAtual->letra);

    removeChar(linhaAtual, COLUNAS-1);
}


//void realocarUltimoCaractere(Linha **primeiraLinha, int *posCursorLinha, int *qnt)
//{
//
//    int qntProx;
//
//    Linha* linhaAtual = retornarLinha(*primeiraLinha,*posCursorLinha);
////    if (linhaAtual->prox == NULL) {
////        enterFuncao(*primeiraLinha, *posCursorLinha, *qnt);
////    }
//
//    Linha *linhaProxima = linhaAtual->prox;
//
//    Letra *ultimoCaractereAtual = linhaAtual->primeiraLetra;
//    while (ultimoCaractereAtual->proxima != NULL)
//    {
//        ultimoCaractereAtual = ultimoCaractereAtual->proxima;
//    }
//
//    if (contadorCaractereCol(linhaProxima) == COLUNAS) {
//        (*posCursorLinha)++;
//        realocarUltimoCaractere(&primeiraLinha,&posCursorLinha, contadorCaractereCol(linhaProxima)-1);
//    }
//
//    insereLetra(linhaProxima, 0, ultimoCaractereAtual->letra);
//
//    removeChar(linhaAtual, qnt);
//}



#endif // LINHA_H


