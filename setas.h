

void setaCima(int *posCursorCol, int *posCursorLinha, Linha **primeiraLinha)
{
    int qntcarac;

    if (*posCursorLinha > 0)
    {
        Linha* aul = retornarLinha(*primeiraLinha, *posCursorLinha-1);
        qntcarac = contadorCaractereCol(aul);

        (*posCursorLinha)--;

        if(*posCursorCol > qntcarac)
            (*posCursorCol)= qntcarac;
    }
    else
        return;
}

void setaBaixo(int *posCursorCol, int *posCursorLinha, Linha **primeiraLinha)   /// CORRIGIDO, AGORA SÓ FUNCIONA CASO EXISTA UMA LINHA ABAIXO
{
    int limite = contadorLinhas(*primeiraLinha);
    int qntcarac;

    if (*posCursorLinha < limite)
    {
        Linha* aul = retornarLinha(*primeiraLinha, *posCursorLinha+1);
        qntcarac = contadorCaractereCol(aul);

        (*posCursorLinha)++;

        if(*posCursorCol > qntcarac)
            (*posCursorCol)= qntcarac;

    }
    else
        return;
}

void setaDireita(int *posCursorCol, int *posCursorLinha, Linha **primeiraLinha)
{
    Linha *atual = retornarLinha(*primeiraLinha, *posCursorLinha);

    int limite = contadorCaractereCol(atual);

   // printf("%d", limite);

    if (*posCursorCol < limite)
    {
        (*posCursorCol)++;
    }
    else if(*posCursorCol == limite && atual->prox != NULL)
    {
        (*posCursorLinha)++;
        (*posCursorCol) = 0;
    }
}

void setaEsquerda(int *posCursorCol, int *posCursorLinha, Linha **primeiraLinha)
{


    if (*posCursorCol > 0)
    {
        (*posCursorCol)--;
    }
    else if(*posCursorCol == 0 && *posCursorLinha != 0)
    {
        Linha *atual = retornarLinha(*primeiraLinha, *posCursorLinha-1);

        int pos = contadorCaractereCol(atual);

        (*posCursorLinha)--;
        (*posCursorCol) = pos;
    }

}
