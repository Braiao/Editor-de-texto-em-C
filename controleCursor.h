void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void reposicionaCursorFinal(Linha** primeiraLinha, int *posCursorLinha, int *posCursorCol)
{
    *posCursorCol = 0;
    *posCursorLinha = 0;

    Linha* aul = primeiraLinha;
    Letra* auc = NULL;


    while(aul->prox != NULL)
    {
        aul = aul->prox;
        (*posCursorLinha)++;
    }


    auc = aul->primeiraLetra;
    if(auc == NULL)
    {
        *posCursorCol = 0;
    }
    else
    {
        while(auc->proxima != NULL)
        {
            auc = auc->proxima;
            (*posCursorCol)++;
        }
    }


    //gotoxy(posCursorCol, posCursorLinha);
}

void _setcursortype(int cursor_type) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    switch (cursor_type) {
        case 0:
            cursorInfo.bVisible = FALSE;
            break;
        case 1:
            cursorInfo.bVisible = TRUE;
            cursorInfo.dwSize = 25;
            break;
        case 2:
            cursorInfo.bVisible = TRUE;
            cursorInfo.dwSize = 90;
            break;
        default:

            return;
    }

    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}




/*
typedef struct Cursor{
    int x;
    int y;
}CURSOR;

void moverCursor(int x, int y) {
    SetCursorPos(x, y);
}

void obterPosicaoXCursor() {
    POINT cursorPos;
    int x;
    GetCursorPos(&cursorPos);
    x = cursorPos.x;
}
*/
