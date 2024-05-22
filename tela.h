
void configuraTela()
{
    //HWND consoleWindow = GetConsoleWindow();
    //ShowWindow(consoleWindow, SW_MAXIMIZE);
    //HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND consoleWindow = GetConsoleWindow();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //DWORD consoleMode;
    RECT desktopRect;
    GetWindowRect(GetDesktopWindow(), &desktopRect);

    int consoleWidth = BUFFER_X;  // Ajuste conforme necessário
    int consoleHeight = BUFFER_Y;

    int consoleX = (desktopRect.right - consoleWidth) / 3;
    int consoleY = (desktopRect.bottom - consoleHeight) / 5;

    SMALL_RECT windowSize = {0, 0, consoleWidth - 1, consoleHeight - 1};
    //COORD bufferSize = {consoleWidth, consoleHeight};

    // Definir a posição e o tamanho da janela do console

    //SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

    // Mover a janela para o centro da tela
    SetWindowPos(consoleWindow, HWND_TOP, consoleX, consoleY, 0, 0, SWP_NOSIZE);

//    GetConsoleMode(console, &consoleMode);
//    SetConsoleMode(console, consoleMode | ENABLE_WRAP_AT_EOL_OUTPUT);
//
//    HWND consoleWindow = GetConsoleWindow();

      //Desabilitar o redimensionamento do console
      SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_SIZEBOX);

          // Define o tamanho do console para corresponder ao tamanho do buffer
//        CONSOLE_SCREEN_BUFFER_INFO csbi;
//        GetConsoleScreenBufferInfo(hConsole, &csbi);
//        COORD newSize;
//        newSize.X = csbi.dwSize.X;
//        newSize.Y = csbi.dwSize.Y;
//        SetConsoleScreenBufferSize(hConsole, newSize);

//
//    // Esconder a barra de rolagem vertical
//    ShowScrollBar(consoleWindow, SB_VERT, FALSE);
//
//    COORD bufferSize = {80, 25};
//
//    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);

//    COORD bufferSize = {320, 40};
//    SetConsoleScreenBufferSize(console, bufferSize);
//
//    SMALL_RECT windowSize = {0 ,0 , 319, 39};
//    SetConsoleWindowInfo(console, TRUE, &windowSize);
      ShowScrollBar(consoleWindow, SB_VERT, FALSE);
      ShowScrollBar(consoleWindow, SB_HORZ, FALSE);
}
