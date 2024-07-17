#ifndef __WC_OPTION_H__
#define __WC_OPTION_H__
#include <stdio.h>

    void defaultWc(FILE* file,char* argv[]);
    int bytesOption(FILE* file,char* argv[]);
    int linesOption(FILE* file,char* argv[]);
    int wordsOption(FILE* file,char* argv[]);
    int maxLengthOption(FILE* file);
    void helpOption();
    void versionOption();
    void charsAndBytesOptionsCombinaison(FILE* file,char** argv);
    void linesOptionCombinaison(FILE* file,char** argv);
    void wordsOptionCombinaison(FILE* file,char** argv);

#endif