#ifndef HELP_H
#define HELP_H
#include<locale.h>

void abre_arq_ajuda()
{
    system("color 07");
    setlocale(LC_ALL, "Portuguese");
    system("cls");
//    tela = 1;
    char texto_ajuda[1000];
    FILE *ajuda;
    ajuda = fopen("BrayanPessoa_ajuda.txt", "r");

    while(!feof(ajuda))
    {
        if(fgets(texto_ajuda, 1000, ajuda))
            printf("%s", texto_ajuda);
    }
    fclose(ajuda);


    printf("\n ESC para voltar à tela anterior");
    int tecla;
    do
    {
        tecla = getch();
    }while(tecla != 27);

    system("color 70");
    system("cls");

}
#endif //HELP_H
