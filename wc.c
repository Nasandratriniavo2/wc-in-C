#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"
#include "wcOption.h"

void closeFile(FILE* file)
{
    if(file!=NULL)
        fclose(file);
}
void exitWithError(FILE* file)
{
    if(file==NULL)
    {
        printf("Error!!\n");
        exit(1);
    }
}

void openFile(FILE* file,int argc,char* argv[])
{
    if(argc==1)
        while(1);
    if(argc==2)
    {
        if(strcmp(argv[1],"--help")==0)
            helpOption();
        else if(strcmp(argv[1],"--version")==0)
            versionOption();
        else
        {
        file=fopen(argv[1],"r+");
        exitWithError(file);
        defaultWc(file,argv);    
        }
    }
    else
    {
        file=fopen(argv[2],"r+");
        exitWithError(file);

        if(strcmp(argv[1],"-m")==0 ||strcmp(argv[1],"--chars")==0 ||strcmp(argv[1],"-c")==0 ||strcmp(argv[1],"--bytes")==0) 
            printf("%d %s\n",bytesOption(file,argv),argv[2]);       
        else if(strcmp(argv[1],"-l")==0 ||strcmp(argv[1],"--lines")==0)
            printf("%d %s\n",linesOption(file,argv),argv[2]);
        else if(strcmp(argv[1],"-w")==0 ||strcmp(argv[1],"--words")==0)
            printf("%d %s\n",wordsOption(file,argv),argv[2]);
        else if(strcmp(argv[1],"-L")==0 ||strcmp(argv[1],"--max-line-length")==0)
            printf("%d %s\n",maxLengthOption(file),argv[2]);
    }
}