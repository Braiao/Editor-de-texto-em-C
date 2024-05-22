void enterFuncao(Linha **primeiraLinha, int *posCursorLinha, int *posCursorCol)
{
//    if (*posCursorLinha < LINHAS - 1)
//    {
    Linha* atual = retornarLinha(*primeiraLinha, *posCursorLinha);
    Linha* q = novaLinha();

    if (atual->primeiraLetra != NULL)
    {
        Letra* letra = atual->primeiraLetra;

//            if(*posCursorCol == 0)
//            {
//                q->primeiraLetra = letra;
//                return;
//                //letra->proxima = NULL;
//            }

        if(*posCursorCol == 0)
        {
            q->primeiraLetra = atual->primeiraLetra;
            atual->primeiraLetra = NULL;
        }
        else
        {
            int contador = 0;
            while (letra != NULL && contador < *posCursorCol-1)
            {
                letra = letra->proxima;
                contador++;
            }

            q->primeiraLetra = letra->proxima;
            letra->proxima = NULL;
        }

    }
//        else
//        {
//            q->primeiraLetra = NULL;
//            atual->primeiraLetra->proxima = NULL;
//        }

    q->prox = atual->prox;
    atual->prox = q;

    (*posCursorLinha)++;
    *posCursorCol = 0;

}


void backFuncao(Linha **primeiraLinha, int *posCursorLinha, int *posCursorCol)
{
    Linha* Latual = retornarLinha(*primeiraLinha, *posCursorLinha);
    Linha* anterior = retornarLinha(*primeiraLinha, *posCursorLinha - 1);

    if(*posCursorLinha == 0 && *posCursorCol == 0)
    {
        return;
    }

    else if (*posCursorCol > 0)
    {
        removeChar(Latual, *posCursorCol - 1);
        (*posCursorCol)--;
    }
    else if (Latual->primeiraLetra == NULL)
    {
        if(anterior->primeiraLetra != NULL)
        {
            Letra* ultimaant = anterior->primeiraLetra;

            while(ultimaant->proxima != NULL)
            {
                ultimaant = ultimaant->proxima;
            }

            ultimaant->proxima = Latual->primeiraLetra;
            anterior->prox = Latual->prox;

        }
        else
        {
            anterior->primeiraLetra = Latual->primeiraLetra;
            anterior->prox = Latual->prox;
        }


        free(Latual);
        (*posCursorLinha)--;
        *posCursorCol = contadorCaractereCol(anterior);
    }
    else if (*posCursorLinha > 0 && *posCursorCol == 0)
    {
        int contador = 1;
        int aux;
        int qntCarac;
        int espacoDisponivel;
        int espacoNecessario=0;
        int pos = 0;

        Letra* primeiraLetraAnterior = anterior->primeiraLetra;
        qntCarac = contadorCaractereCol(anterior);
        //printf("\n\n%d", qntCarac);
        espacoDisponivel = COLUNAS - qntCarac;
        //printf("\n\n%d", espacoDisponivel);

        if(espacoDisponivel <= 0)
        {
            (*posCursorCol) = qntCarac;
            (*posCursorLinha)--;
            return;
        }
        else
        {
            pos =  contadorCaractereCol(anterior); // onde o cursor vai ficar depois

            if(primeiraLetraAnterior == NULL) // manda a linha inteira pra cima e apaga a debaixo
            {
                anterior->primeiraLetra = Latual->primeiraLetra;
                anterior->prox = Latual->prox;

                free(Latual);

                (*posCursorLinha)--;
                *posCursorCol = 0;

                return;
            }

            while (primeiraLetraAnterior->proxima != NULL) // vai até o fim da linha anterior
            {
                primeiraLetraAnterior = primeiraLetraAnterior->proxima;
            }

             // define a continuacao como o inicio da proxima

            espacoNecessario = contadorCaractereCol(Latual); //ve o quanto de espaço precisa

            if(espacoNecessario <= espacoDisponivel)
            {
                 contador = 0;
                //primeiraLetraAnterior->proxima = Latual->primeiraLetra;

                anterior->prox = Latual->prox;

                Letra* auc;
                while(contador < espacoNecessario)
                {
                    auc = Latual->primeiraLetra;
                    primeiraLetraAnterior->proxima = auc;
                    Latual->primeiraLetra = Latual->primeiraLetra->proxima;
                    primeiraLetraAnterior = primeiraLetraAnterior->proxima;
                    contador++;
                }
                //primeiraLetraAnterior = primeiraLetraAnterior->proxima;
                //primeiraLetraAnterior->proxima = NULL;
                //free(Latual);
                (*posCursorLinha)--;
                *posCursorCol = pos;
                return;
            }
            else
            {
                contador = 0;
                aux = espacoNecessario - espacoDisponivel;

                //printf("\n\nEspaço necess: %d", espacoNecessario);

                //printf("\n\nEspaço dispo: %d", espacoDisponivel);
                //printf("\n\n\n%d", aux);
                Letra* auc;
                while(contador < espacoDisponivel)
                {
                    auc = Latual->primeiraLetra;
                    primeiraLetraAnterior->proxima = auc;
                    //insereLetra(anterior, pos+1, auc->letra);
                    //removeChar(Latual,0);
                    Latual->primeiraLetra = Latual->primeiraLetra->proxima;
                    primeiraLetraAnterior = primeiraLetraAnterior->proxima;
                    contador++;
                }
                primeiraLetraAnterior->proxima = NULL;
            }
//            anterior->prox = Latual->prox;
//                free(Latual);
//                (*posCursorLinha)--;
//                *posCursorCol = pos;
//                return;
//            else
//            {
//                free(Latual);
//                enterFuncao(*primeiraLinha, *posCursorLinha, COLUNAS+1);
//            }

        }
    }
}




//void enterFuncao(Linha **primeiraLinha, int *posCursorLinha, int *posCursorCol)
//{
//    int contador = 0;
//    Linha* Latual = retornarLinha(*primeiraLinha, *posCursorLinha);
//    Linha* nova = novaLinha();
////
////    if(*posCursorCol >= COLUNAS -1)
////    {
////        return;
////    }
//    if(*posCursorCol < COLUNAS -1)
//    {
//        if (Latual->primeiraLetra != NULL)
//        {
//            Linha* atual = Latual->primeiraLetra;
//
//            while (atual != NULL && contador < *posCursorCol - 1)
//            {
//                atual = atual->prox;
//                contador++;
//            }
//
//            nova->primeiraLetra = atual->prox;
//            atual->prox = NULL;
//        }
//
//        nova->prox = Latual->prox;
//        Latual->prox = nova;
//
//        (*posCursorLinha)++;
//        *posCursorCol = 0;
//    }
//}




