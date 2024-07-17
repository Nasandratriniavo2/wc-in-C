#include <stdio.h>
#include <stdlib.h>
#include "wcOption.h"
#include <string.h>
#include "wc.h"

void defaultWc(FILE* file,char* argv[])
{
    int linesNumber=0,byte=0,wordNumber=0;
    
    linesNumber=linesOption(file,argv);
    rewind(file);
    wordNumber=wordsOption(file,argv);
    rewind(file);
    byte=bytesOption(file,argv); 
    printf(" %d  %d %d  %s\n",linesNumber,wordNumber,byte,argv[1]);
}

int bytesOption(FILE* file,char* argv[])
{
    char line[100];
    int byte=0;
    while(fgetc(file)!=EOF)//Nombre de mots
        byte++;
    return(byte);    
}

int linesOption(FILE* file,char* argv[])
{
    int linesNumber=0;
    int test;
    char line[100];
    while((test=fgetc(file))!=EOF)
    {
        if (test=='\n')
            linesNumber++;
    }
    return(linesNumber);   
}

int wordsOption(FILE* file,char* argv[])
{
    int wordNumber=0;
    int isWord=0;
    char line[100];
    int c=0;

    while((c = fgetc(file)) != EOF)
    {
        if(!isWord)//Fausse
        {
            if(c!=' ' && c!='\n')
            {
                isWord=1;
                wordNumber++;
            }
        }
        else //Vraie
        {
            if(c==' '||c=='\n')
                isWord = 0;
        }    
    }
    return(wordNumber);
}

int maxLengthOption(FILE* file)
{
    int count=0,maxLength=0;
    char line[100];

    while(fgets(line,100,file)!=NULL) 
    {       
        if(maxLength<strlen(line))
            maxLength=strlen(line);
    }
    return(maxLength-1);
}

void helpOption() 
{
    FILE* file=NULL;
    char help[10000];
    file=fopen("help.txt","r+");
    exitWithError(file);
    while(fgets(help,1000,file)!=NULL)
        printf("%s",help);
}

void versionOption()
{
    FILE* file=NULL;
    char version[10000];
    file=fopen("version.txt","r+");
    exitWithError(file);
    while(fgets(version,1000,file)!=NULL)
        printf("%s",version);
}
