void mudarFonte(int altura, int largura)
{
    // Obter o identificador do console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Definir as informações da fonte do console
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    fontInfo.nFont = 0;
    fontInfo.dwFontSize.X = largura; // Largura da fonte
    fontInfo.dwFontSize.Y = altura; // Altura da fonte
    fontInfo.FontFamily = FF_DONTCARE;
    fontInfo.FontWeight = FW_NORMAL;
    wcscpy(fontInfo.FaceName, L"Consolas"); // Nome da fonte

    // Aplicar as alterações à fonte do console
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

}
