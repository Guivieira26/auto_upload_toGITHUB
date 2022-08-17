/*
 Auto_uploader_to_github - v1.2. - 17 /08 / 2022
 Author: Guilherme Henrique Vieira Nascimento
 
 Para compilar em uma janela de comandos (terminal):

 No Linux : gcc -o upload upload.c
 No Windows: gcc -o upload.exe upload.c
 Para executar em uma janela de comandos (terminal):
 No Linux : ./upload
 No Windows: upload.exe
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80

void apresentation( ){
    //apresentation program
    puts("******************");
    puts("\nAUTO UPLOAD TO GIT\n");
    puts("******************");
}

void warning( ){
    //warnings and verification
    puts("\nPrimeiro verifique se no seu computador esta presente e configurado o comando git, caso nao esteja corrija aqui https://www.youtube.com/watch?v=Am46OOLgV4s"); 
    //tutorial para baixar e configurar o .git para o proprio usuario
    puts("\nDepois coloque o executavel na pasta desejada para upload");
    //local onde o programa ira rodar
    puts("\nSe tudo estiver correto, pressione ENTER"); //user confirmation
    getchar( );
}

void commands_cmd( ){
    char commit [MAX] = "git commit -m \"autoUP_byGuilherme_Henrique\" "; //comando commit
    //test -> printf ("\n%s",commit);
    system("rd .git /S/Q"); // verificação para evitar erro
    system("git init"); // criar repositorio local
    system("git add ."); // adicionar os arquivos
    system(commit); //string commit no cmd
    return;
}

void thanks ( ){
    //system("cls");
    puts("\n\nSeus arquivos foram enviados com SUCESSO!\n");
    puts("© PROGRAM by GUILHERME HENRIQUE VIEIRA NASCIMENTO ©");
    puts("  PUC - MINAS GERAIS");
    getchar( );
}

void credits( ){
    system("cls");
    puts("Auto Uploader to GitHub [version 1.2-ptbr]");
    puts("Copyright © 2022 Guilherme Henrique. Todos os direitos reservados.\n");
    return;
}

int main()
{
    credits( );
    apresentation( ); //chamar função
    warning( ); //chamar função
    
    system("cls"); //clear
    char repository[MAX]; //link que o usuario vai por do repositorio
    char cmd[MAX] = "git remote add origin "; //Enviar arquivos para o git
    puts("Agora crie o repositorio no git hub e cole o link aqui: "); //Link repositorio
    gets (repository); //getch repositorio
    printf("\nEsse e seu repositorio -> %s\n",repository); //Cheuqe seu repositorio
    puts("Para confirmar o repositorio aperte ENTER");
    getchar( );//confirmação
    
    puts("\nAVISO!");
    puts("----------------------------------------------------------------------------------------------------------------------------------");
    puts(" Se estiver com problemas no comando ctrl+v va para o cmd e olhem em propriedades>opcoes e verifique a caixa de comandos com ctrl");
    puts("----------------------------------------------------------------------------------------------------------------------------------\n");

    commands_cmd( );

    strncat(cmd, repository, MAX);
    //test -> printf("\n%s",cmd);
    //getchar( );
    system(cmd);
    system("git push -u origin master");
    
    thanks( );

    return 0;
} // end main ( )
// ------------------------------------------- testes
/*

-> fiz testes durante o programa na linha 82 e 37 para saber se estava 
guardando corretamente as strings usadas posteriormentes no system cmd

---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios
17/08/22
-> o programa poderia ter ficado melhor na situalçao de estuar tudo fora da main, futuramente irei desenvolver melhor essa parte.

---------------------------------------------- previsao de testes
Tudo ocorreu corretamente, após o uso da biblioteca string.h
---------------------------------------------- historico
Versao  Data    Modificacao
 1.2    17/08   Semi-final
---------------------------------------------- testes
Versao      Teste
 0.1 02.    ( OK ) funcionalidade do programa
*/