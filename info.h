#include <locale.h>

void infoAluno()
{
    system("cls");
    system("color 07");
    int voltar;
    setlocale(LC_ALL, "Portuguese");

    printf("\033[1;33m\t\t... Informações do Desenvolvedor ...\033[0m\n\n");  // Cor amarela brilhante
    printf("\033[1;36m\t\t... Brayan Alexandre da Silva Pessoa ...\033[0m\n"); // Cor ciano brilhante
    printf("\033[1;36m\t\t... PE3014819 ...\033[0m\n");                      // Cor ciano brilhante
    printf("\033[1;36m\t\t... Bacharelado em Ciências da Computação ...\033[0m\n"); // Cor ciano brilhante
    printf("\033[1;36m\t\t... Ingresso em 2022 ...\033[0m\n");               // Cor ciano brilhante
    printf("\nPressione \033[1;31mESC\033[0m para voltar para a tela anterior\n"); // Cor vermelha brilhante

    do{
        voltar = getch();

    }while(voltar != 27);

    system("color 70");
    system("cls");
}
