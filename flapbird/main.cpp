/*Versão beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <conio.h> ///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P P Y B I R D (M2 Algoritmos)
    - Lembrando: não permitido o uso de funções e variáveis compostas como structs, vetores e matrizes
    - Corrigir os rastros (pássaro e obstáculos)
    - Implementar colisão
    - Implementar pontuação (mais um ponto para cada obstáculo superado)
    - Fazer 2 obstáculos simultâneos (obstaculo1 e obstaculo2)
    - Deixar a pontuação visível durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


    int bird_x=5, bird_y=10;
    int abird_x, abird_y;
    int obstaculo_x=129, obstaculo_y;
    char tecla;

    ///DESENHO DO CENÁRIO
    cout<<"----------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"----------------------------------------------------------------------------------------------------------------------------------";





    while (true) { //esse laço faz o jogo rodar para sempre

        ///POSICIONA O PÁSSARO
        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);
        abird_x=bird_x; abird_y=bird_y;

        ///POSICIONA O OBSTÁCULO
        obstaculo_y=1;
        while(obstaculo_y<20){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y<5 || obstaculo_y>7){
                cout<<char(219);
            } else {
                cout<<" ";
            }

            obstaculo_y++;
        }


        ///VERIFICA COLISÃO




        ///TEMPO DE ESPERA
        Sleep(200); ///espera por x milisegundos


        ///dos obstaculos
        obstaculo_y=1;
        while(obstaculo_y<20){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<" ";


            obstaculo_y++;
        }

        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" ";
        abird_x=bird_x; abird_y=bird_y;

        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }


        ///PÁSSARO CAI 1 POSIÇÃO SE NÃO FOI PRESSIONADO PARA SUBIR
        if ( tecla=='w' ){
            bird_y--;
            tecla='0';
        } else {
            bird_y++;
        }

        ///OBSTÁCULO AVANÇA UMA POSIÇÃO PARA ESQUERDA
        obstaculo_x--;

    }





    return 0;
}
