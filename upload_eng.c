/*
 Auto_uploader_to_github - v1.1. - 17 /08 / 2022
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
    system("cls");
    puts("******************");
    puts("\nAUTO UPLOAD TO GIT\n");
    puts("******************");
}

void warning( ){
    //warnings and verification
    puts("\nFirst check if you have git commands and configs in your windows, if not seartch here https://www.youtube.com/watch?v=Am46OOLgV4s"); //tutorial to download
    puts("\nLater put this .exe in your diretory upload past."); //local to execute program
    puts("\nIf it is in the correct folder PRESS ENTER"); //user confirmation
    getchar( );
}

void commands_cmd( ){
    char commit [MAX] = "git commit -m \"autoUP_byGuilherme_Henrique\" "; //comand to commit
    //test -> printf ("\n%s",commit);
    system("rd .git /S/Q"); //verification to delete all programs .git
    system("git init"); //create git repository
    system("git add ."); // add files
    system(commit); //put string "commit" in system cmd
    return;
}

void thanks ( ){
    system("cls");
    puts("\n\nYour files have been uploaded thanks to use!\n");
    puts("PROGRAM by GUILHERME HENRIQUE VIEIRA NASCIMENTO");
    puts("PUC - MINAS GERAIS");
    getchar( );
}

void credits( ){
    puts("Auto Uploader to GitHub [version 1.1]");
    puts("Copyright © 2022 Guilherme Henrique. Todos os direitos reservados.");
    return;
}

int main()
{
    credits( );
    apresentation( ); //go
    warning( ); //go
    
    system("cls"); //clear
    char repository[MAX]; //link at repository
    char cmd[MAX] = "git remote add origin "; //envite files to guit
    puts("now create repository in your git hub and copy link here:");
    gets (repository); //get link
    printf("\nthis your repository -> %s\n",repository); //check your repository
    puts("confirm your repository press ENTER");
    getchar( );//confirmation
    
    puts("\nWARNING!");
    puts("---------------------------------------------------------------------------------------------------------");
    puts(" If you cant use ctrl+v, check your cmd>properties>options and check box about comands ctrl+c and ctrl+v");
    puts("---------------------------------------------------------------------------------------------------------\n");

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
 1.1    17/08   Semi-final
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) funcionalidade do programa
*/