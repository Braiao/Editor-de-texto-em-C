void deleteFuncao(Linha **primeiraLinha, int *posCursorLinha, int *posCursorCol)
{
    Linha* Latual = retornarLinha(*primeiraLinha, *posCursorLinha);

    if(*posCursorLinha == 0 && *posCursorCol == 0 && Latual->primeiraLetra == NULL)
    {
        return;
    }

    else if (*posCursorCol >= 0)
    {
        removeChar(Latual, *posCursorCol);
        //(*posCursorCol)--;
    }
    else if(*posCursorCol == 0 && Latual->primeiraLetra == NULL)
    {
//        while (Latual->prox != NULL)
//        {
//            Linha *proximaLinha = Latual->prox;
//
//            // Se a próxima linha não estiver vazia, move o primeiro caractere para a linha atual
//            if (proximaLinha->primeiraLetra != NULL)
//            {
//                Letra *primeiroCaractereProxima = proximaLinha->primeiraLetra;
//
//                insereLetra(Latual, 0, primeiroCaractereProxima->letra);
//                removeChar(proximaLinha, 0);
//                break; // Para o loop, pois já puxou uma linha
//            }
//
//            // Se a próxima linha estiver vazia, continua para a próxima
//            Latual = proximaLinha;
//            (*posCursorLinha)++;
//        }
    }
//    else if(*posCursorCol == 0)
//    {
//        removeChar(Latual, *posCursorCol);
//    }
//    else if (*posCursorLinha > 0 && Latual->primeiraLetra == NULL && *posCursorCol == 0)
//    {
//        Linha* anterior = retornarLinha(*primeiraLinha, *posCursorLinha - 1);
//        Letra* atual = anterior->primeiraLetra;
//        while (atual->proxima != NULL)
//        {
//            atual = atual->proxima;
//        }
//
//        atual->proxima = Latual->primeiraLetra;
//        anterior->prox = Latual;
//        //free(Latual);
//        (*posCursorLinha)--;
//        *posCursorCol = contadorCaractereCol(anterior);
//    }
}


void endFuncao(Linha *primeiraLinha, int *posCursorLinha, int *posCursorCol)
{
    int fim = 0;
    int coluna = 0;
    Linha *aul = retornarLinha(primeiraLinha, *posCursorLinha);
    Letra *auc = aul->primeiraLetra;

    if (aul != NULL)
    {
        while (coluna < COLUNAS && auc != NULL)
        {
            if (auc->letra != ' ')
            {
                fim = coluna + 1;
            }
            auc = auc->proxima;
            coluna++;
        }
        if (fim > 0)
        {
            *posCursorCol = fim;
        }
    }
}


void home(int *cursor_col)
{
    *cursor_col = 0;
}


void pageUp(Linha** primeiraLinha, int *posCursorY, int *posCursorX)
{
    int qntCaracPrimeira = 0;
    int numLinhas = contadorLinhas(*primeiraLinha);

    if(*posCursorY == 0)
    {
        return;
    }
    else if(numLinhas <= PAGINA)
    {
        //printf("ou aqui");
        *posCursorY = 0;
        qntCaracPrimeira = contadorCaractereCol(*primeiraLinha);
        //printf("\n\n%d", qntCaracPrimeira);
        if(qntCaracPrimeira < *posCursorX)
            *posCursorX = qntCaracPrimeira;
    }
    else
    {
        int qntLinhasPag = *posCursorY%PAGINA;
        int novaPos = *posCursorY - qntLinhasPag;



        if(qntLinhasPag != 0)
        {
            *posCursorY = novaPos;
            *posCursorX = contadorCaractereCol(retornarLinha(*primeiraLinha, *posCursorY));
        }
        else
        {
            *posCursorY = *posCursorY - PAGINA;
            *posCursorX = contadorCaractereCol(retornarLinha(*primeiraLinha, *posCursorY));
        }


       // printf("\n\n%d", qntLinhasPag);

        //printf("\n\n%d", numLinhas);

    }

}

void pageDown(Linha** primeiraLinha, int *posCursorY, int *posCursorX)
{
    int numLinhas = contadorLinhas(*primeiraLinha);
    int qntCaracAul = 0;
    int qntCaracAtual = 0;


    if(*posCursorY == numLinhas)
    {
        //printf("\n\nEntrou");
        return;
    }
    else if(numLinhas <= PAGINA)
    {

        *posCursorY = numLinhas;
        //printf("%d", *posCursorY);
        Linha* aul = retornarLinha(*primeiraLinha, *posCursorY);
        qntCaracAul = contadorCaractereCol(aul);
        ///printf("Erro 4");
        //qntCaracAtual = contadorCaractereCol(atual);
        if(*posCursorX > qntCaracAul)
            (*posCursorX) = qntCaracAul;
    }

    else
    {
        int qntLinhasPag = *posCursorY%PAGINA;
        int falta = PAGINA - qntLinhasPag;
        int novaPos = 0;




        if(qntLinhasPag != 0)
        {

            novaPos = *posCursorY + falta;
            //*posCursorX = contadorCaractereCol(retornarLinha(*primeiraLinha, *posCursorY));

        }
        else
        {
            novaPos = *posCursorY + PAGINA;
            //*posCursorY = *posCursorY + PAGINA;

        }

         if(novaPos <= numLinhas)
                *posCursorY = novaPos;
            else
                *posCursorY = numLinhas;

        *posCursorX = contadorCaractereCol(retornarLinha(*primeiraLinha, *posCursorY));
       // printf("\n\n%d", qntLinhasPag);

        //printf("\n\n%d", numLinhas);
    }


}
