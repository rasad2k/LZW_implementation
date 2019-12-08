#ifndef LZW
#define LZW

#include "dict.h"

char *intToStr(int n);
char *Concat(char * str1, char * str2);
int strToInt (char *data);
Dict *LZ_initEncDic(char *plainText, int size);
char *LZ_encode(Dict *pEncDic, char *plainText, int * size);
char *LZ_decode(Dict *pEncDic, Dict ** newDict, char *encodedText, int * len);

#endif
