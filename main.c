#include <stdio.h>
#include <stdlib.h>
#include "wc.h"
#include "wcOption.h"

int main(int argc,char* argv[])
{
    FILE* file=NULL;
    openFile(file,argc,argv);
    closeFile(file);
    return(0);
}