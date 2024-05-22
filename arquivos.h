

//void salvarEditorEmArquivo(EDITOR* editor, char nomeArquivo[]) {
//    FILE* arquivo = fopen(nomeArquivo, "w"); // Abre o arquivo para escrita
//
//    if (arquivo == NULL) {
//        printf("Erro ao abrir o arquivo para escrita.\n");
//        return;
//    }
//
//    EDITOR* aux;
//
//    while(aux->linha_anterior != NULL){
//        aux->linha = aux->linha_anterior;
//    }
//
//    //COL* linhaAtual = editor->linha;
//
//    while (linhaAtual != NULL) {
//        fprintf(arquivo, "%s\n", linhaAtual->data);
//        linhaAtual = linhaAtual->data[0] != '\0' ? linhaAtual + 1 : NULL;
//    }
//
//    fprintf(arquivo, "\nCursor: %d\n", editor->cursor);
//
//    fclose(arquivo); // Fecha o arquivo
//}



void salvarArquivo(Linha* primeiraLinha, const char* nomeArquivo)
{
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.");
        return;
    }

    Linha* aul = primeiraLinha;
    while (aul != NULL)
    {
        Letra* auc = aul->primeiraLetra;
        while (auc != NULL)
        {
            fputc(auc->letra, arquivo);
            auc = auc->proxima;
        }
        fputc('\n', arquivo); // Inserir uma quebra de linha ao final de cada linha
        aul = aul->prox;
    }

    fclose(arquivo);
}


void lerArquivo(Linha** primeiraLinha)
{
    system("cls");
    int posCol = 0;
    int cont = 0;
    int posLinha = 0;
    char nomeArquivo[50];
    char caractere;
    printf("Informe o nome do arquivo a ser lido:\n");
    scanf("%s", nomeArquivo);


    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para Leitura.");
        return;
    }

    Linha* atual = retornarLinha(*primeiraLinha, posLinha);
    Linha* aul = NULL;
    Letra* auc = NULL;

    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if (caractere == '\n' || cont == COLUNAS-1)
        {
            posLinha++;
            aul = novaLinha();// Reinicia a lista de letras para a próxima linha
            posCol = 0;
            cont = 0;
            atual->prox = aul;
            atual = aul;
        }
        else
        {
            insereLetra(atual,posCol,caractere);
            cont++;
            posCol++;
        }

    }

    fclose(arquivo);
    system("cls");
}


void confirmaSalvar(Linha** primeiraLinha, int *cursorY, int *cursorX)
{

    char salvar;
    do
    {
        reposicionaCursorFinal(primeiraLinha, &cursorY, &cursorX);
        gotoxy(cursorX, cursorY);
        //sys
        printf("\nSalvar Arquivo atual?(s/n)");
        fflush(stdin);
        scanf("%c", &salvar);
        if(salvar == 115)
        {
            printf("\nSalvando");
            Sleep(600);
            printf(". ");
            Sleep(610);
            printf(". ");
            Sleep(620);
            printf(". ");
            salvarArquivo(*primeiraLinha, "BrayanPessoa_texto.txt");
            //exit(0);
            //retorno = 1;
        }
        else if(salvar == 110)
        {
            printf("\nDescartando Arquivo");
            Sleep(500);
            printf(". ");
            Sleep(510);
            printf(". ");
            Sleep(600);
            printf(". ");
            //exit(0);
            //retorno = 0;
        }
        else
        {
            printf("\nOpção inválida\n");
        }
    }
    while(salvar != 115 && salvar != 110);
}

