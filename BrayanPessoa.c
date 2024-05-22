#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#define LINHAS 30000
#define COLUNAS 80
#define BUFFER_X 82
#define BUFFER_Y 40
#define PAGINA 25

#include "tela.h"
#include "estrutura.h"
#include "help.h"
#include "util.h"
#include "controleCursor.h"
#include "setas.h"
#include "outrasTeclas.h"
#include "arquivos.h"
#include "info.h"
#include "teclasEspeciais.h"




void main()
{

    //mudarFonte(40,20);
    configuraTela();
    system("color 70");
    system("title WORD 2.0000000000000000000000002");
    //system("mode con: cols=81");

    setlocale(LC_ALL, "Portuguese");


    Linha* primeiraLinha = novaLinha(); // Inicializa a lista de linhas com uma linha vazia

    //imprimirEstrutura(primeiraLinha);
    //imprimirBuffer(primeiraLinha);
    int modo_cursor = 2;
    int cursorY = 0;
    int cursorX = 0;
    int qntLinhas = 0;
    int retornoSave;
    int imprimir = 0;
    //tamanhoCursor(10000);
    int c;
    // char[50] nomeArquivo;
    _setcursortype(modo_cursor);
    for(;;)
    {

        if (kbhit())
        {
            c = getch();

            if (c == 8)
            {
                int qntAux;
                Linha* aux = retornarLinha(primeiraLinha, cursorY);
                qntAux = contadorCaractereCol(aux);
                backFuncao(&primeiraLinha, &cursorY, &cursorX);
                if(qntAux == COLUNAS)
                {
                    realocarLinhas(&primeiraLinha,&cursorX,&cursorY, &qntAux);
                }
                ///Backspace
                //imprimirEstrutura(primeiraLinha);
                // imprimirBuffer(primeiraLinha, modo_cursor);

                imprimir = 1;
            }
            else if (c == 13)
            {
                enterFuncao(&primeiraLinha, &cursorY, &cursorX); ///Enter
                //imprimirEstrutura(primeiraLinha);
                //imprimirBuffer(primeiraLinha);
                imprimir = 1;
            }
            else if (c == 27)                                   ///Esc
            {
//                if(primeiraLinha == NULL)
//                {
//                   printf("Nada a ser salvo!\n");
//                    printf("\nEncerrando Aplicação ");
//                    Sleep(500);
//                    printf(". ");
//                    Sleep(510);
//                    printf(". ");
//                    Sleep(600);
//                    printf(". ");
//                    exit(0);
//                }
//                else
//                {
                confirmaSalvar(&primeiraLinha, &cursorY, &cursorX);
                exit(0);
                //}
            }
            else if (c == 224)
            {
                c = getch();

                if (c == 71)
                {
                    home(&cursorX);
                    imprimir = 0;
                }
                else if (c == 79)
                {
                    endFuncao(primeiraLinha, &cursorY, &cursorX);
                    imprimir = 0;
                }
                else if (c == 72)
                {
                    setaCima(&cursorX, &cursorY, &primeiraLinha);
                    imprimir = 0;
                }
                else if (c == 73)
                {
                    pageUp(&primeiraLinha,&cursorY,&cursorX);
                    imprimir = 0;
                }
                else if (c == 80)
                {
                    setaBaixo(&cursorX, &cursorY, &primeiraLinha);
                    imprimir = 0;
                }
                else if (c == 81)
                {
                    pageDown(&primeiraLinha,&cursorY,&cursorX);
                    imprimir = 0;
                }
                else if (c == 75)
                {
                    setaEsquerda(&cursorX, &cursorY, &primeiraLinha);
                    imprimir = 0;
                }
                else if (c == 77)
                {
                    setaDireita(&cursorX, &cursorY, &primeiraLinha);
                    imprimir = 0;
                }
                else if (c == 134)
                {
                    //imprimirEstrutura(primeiraLinha);
                    infoAluno();
                    //imprimirEstrutura(primeiraLinha);
                    //imprimirBuffer(primeiraLinha);
                    imprimir = 1;
                }
                else if (c == 83)
                {
                    int qntAux;
                    Linha* aux = retornarLinha(primeiraLinha, cursorY);
                    qntAux = contadorCaractereCol(aux);
                    deleteFuncao(&primeiraLinha, &cursorY, &cursorX);
                    if(qntAux == COLUNAS)
                    {
                        realocarLinhas(&primeiraLinha,&cursorX,&cursorY, &qntAux);
                    }

                    //imprimirEstrutura(primeiraLinha);
                    //imprimirBuffer(primeiraLinha);
                    imprimir = 1;
                }
                else if (c == 82) /// modo do insert
                {
                    if(modo_cursor == 2)
                    {
                        modo_cursor = 1;
                    }
                    else
                    {
                        modo_cursor = 2;
                    }
                    _setcursortype(modo_cursor);
                    //insertFuncao(&primeiraLinha, &cursorY, &cursorX, c);
                }
            }
            else if (c == 0)
            {
                c = getch();

                if (c == 59)
                {

                    abre_arq_ajuda();
                    //imprimirEstrutura(primeiraLinha);
                    //imprimirBuffer(primeiraLinha);
                    imprimir = 1;
                }
                else if (c == 60) // F2
                {
                    salvarArquivo(primeiraLinha, "BrayanPessoa_texto.txt");
                }
                else if (c == 68) // F10
                {
                    if(primeiraLinha->primeiraLetra != NULL)
                    {
                        confirmaSalvar(&primeiraLinha, &cursorY, &cursorX);
                    }
                    // zerarEstrutura(&primeiraLinha);
                    primeiraLinha = novaLinha();
                    lerArquivo(&primeiraLinha);
                    //imprimirEstrutura(primeiraLinha);
                    //imprimirBuffer(primeiraLinha, modo_cursor, qntLinhas, cursorY);
                    reposicionaCursorFinal(primeiraLinha, &cursorY, &cursorX);
                    imprimir = 1;
                    //mudarFonte(30,20);

                }
            }
            else if (c >= 32 && c <= 183)
            {
                int contador = 0;
                Linha* aul = retornarLinha(primeiraLinha, cursorY);
                Linha* proximaLinha = retornarLinha(primeiraLinha, cursorY+1);
                Letra* auc = aul->primeiraLetra;
                int posY;

                int qntCarac = contadorCaractereCol(aul);

                if (cursorX <= COLUNAS)
                {
                    if(modo_cursor == 2)
                    {

                        if (qntCarac == COLUNAS)
                        {

                            aul = retornarLinha(primeiraLinha, cursorY);


                            if(cursorX == COLUNAS) /// quebra de linha automática caso o cursor esteja no fim
                            {
                                enterFuncao(&primeiraLinha, &cursorY, &cursorX);
                                insereLetra(retornarLinha(primeiraLinha, cursorY), cursorX, c);
                                cursorX++;
                            }
                            else if(cursorX < qntCarac)
                            {
//                                int auxiliarCol = COLUNAS-1;
//                                if(aul->prox == NULL)
//                                {
//                                    posY = cursorY;
//                                    enterFuncao(&primeiraLinha, &cursorY, &auxiliarCol);
//                                }
//                                cursorY = posY;

                                //printf("\n\n\nAté aqui4");
                                realocarUltimoCaractereRec(aul, &primeiraLinha, cursorY);
                                insereLetra(retornarLinha(primeiraLinha, cursorY), cursorX, c);


                                //realocarUltimoCaractere(&primeiraLinha, &cursorY, qntCarac-1);
                                cursorX++;
                            }
//                            else if(cursorX == COLUNAS-1)
//                            {
//                                cursorX = 0;
//                                cursorY++;
//                            }
//                            else
//                            {
                            //printf("\n\nEntrou2");
//                                char auxc;
//                                Letra* ultimaLetra = aul->primeiraLetra;
//                                while(ultimaLetra->proxima != NULL)
//                                {
//                                    ultimaLetra = ultimaLetra->proxima;
//                                }
//
//                                Letra* aux = aul->primeiraLetra;
//                                while(aux->proxima != ultimaLetra)
//                                {
//                                    aux = aux->proxima;
//                                }
//                                aux->proxima = NULL;
//
//                                Linha* proximaLinha = retornarLinha(primeiraLinha, cursorY+1);
//
//                                Letra* primeiraLetra = proximaLinha->primeiraLetra;
//                                ultimaLetra->proxima = primeiraLetra;
//                                primeiraLetra = ultimaLetra;
                            //primeiraLetra = ultimaLetra;

                            //free(ultimaLetra);

                            //}

                            //}
                        }
                        else
                        {
                            insereLetra(retornarLinha(primeiraLinha, cursorY), cursorX, c);
                            cursorX++;
                        }


                        //printf("%c", c);
                    }
                    else if(modo_cursor == 1)
                    {
                        sobreescreverCaractere(retornarLinha(primeiraLinha, cursorY), &cursorX, c);
                    }

                }

                //imprimirBuffer(primeiraLinha);
                //imprimirEstrutura(primeiraLinha);
                // printf("%d", qntCarac);
                imprimir = 1;
            }
        }
        //imprimirEstrutura(primeiraLinha);



        int Xatual = 0;
        int Yatual = 0;

        Linha *aul = primeiraLinha;

        while (aul != NULL && Yatual < cursorY)
        {
            Yatual++;
            aul = aul->prox;
        }

        if (aul != NULL)
        {
            Letra *auc = aul->primeiraLetra;
            while (auc != NULL && Xatual < cursorX)
            {
                Xatual++;
                auc = auc->proxima;
            }
        }

        //  gotoxy(cursorX, cursorY);

        qntLinhas = contadorLinhas(primeiraLinha)+2;

        if(imprimir == 1)
        {
            //printf("   %d", qntLinhas) ;

            imprimirBuffer(primeiraLinha, modo_cursor, qntLinhas, cursorY);
            imprimir = 0;
        }


        gotoxy(Xatual, Yatual);

        Sleep(30);
    }

}

