#include "dict.c"

//casts int to string, return char *

char *intToStr(int n)
{
	if (n == 0)
		return "0";
	int count = 0;
	int cpN = n;
	while(cpN != 0)
    {
        cpN /= 10;
        ++count;
    }
    int cpCount = count;
    char *str = (char *)malloc(count * sizeof(char));
    for (int i = 0; i < cpCount; i++){
    	cpN = n%10;
    	*(str+count-1) = (char)(cpN + 48);
    	n = n/10;
    	count--;
    }
    return str;
}

//concatenates two strings into one, returns char *

char *Concat(char * str1, char * str2)
{
	int size = strlen(str1) + strlen(str2) + 1;
	char * str = (char *)malloc(size * sizeof(char));
	for (int i = 0; i < strlen(str1); i++)
		*(str+i) = str1[i];
	for (int i = 0; i < strlen(str2); i++)
		*(str+strlen(str1)+i) = str2[i];
	return str;
}

//initializes dictinary to encode

Dict *LZ_initEncDic(char *plainText, int size)
{
	Dict * dict = D_new(size);
	for (; *plainText != '\0'; *plainText++){
	    char *str = (char *)malloc(sizeof(char));
		*str = *plainText;
		D_put(dict, str, intToStr(dict->size));
	}
	return dict;
}

//encodes given text by using given dictionary, return array of strings

char * LZ_encode(Dict *pEncDic, char *plainText, int * size)
{
	char * result = (char *)malloc(1000 * sizeof(char));
	result = "";
	char * str = (char *)malloc(sizeof(char));
	str = "";
	int i;
	for (i = 0; *plainText != '\0'; *plainText++){
		char * c = (char *)malloc(sizeof(char));
		*c = *plainText;
		if (D_search(pEncDic, Concat(str, c)))
			str = Concat(str, c);
		else {
			result = Concat(result, Concat(D_search(pEncDic, str), " "));
			(*size)++;
			D_put(pEncDic, Concat(str, c), intToStr(pEncDic->size));
			str = c;
			i++;
		}
	}
	result = Concat(result, Concat(D_search(pEncDic, str), " "));
	(*size)++;
	return result;
}

//decodes given string of numbers

char *LZ_decode(Dict *pEncDic, Dict ** dict, char *encodedText, int * len){
	char * result = (char *)malloc((*len) * sizeof(char));
	*dict = D_duplicate(pEncDic);
	char * old = (char *)malloc(10 * sizeof(char));
	while (*encodedText != ' '){
		char * tmp = (char *)malloc(10 * sizeof(char));
		*tmp = *encodedText;
		old = Concat(old, tmp);
		*len++;
		*encodedText++;
	}
	char * c = (char *)malloc(10 * sizeof(char));
	char * tr = D_search(*dict, old);
	result = Concat(result, tr);
	char * str = (char *)malloc(10 * sizeof(char));
	char * val = (char *)malloc(10 * sizeof(char));
	while (*encodedText != '\0'){
		val = "";
		if (*encodedText == ' '){
			*encodedText++;
			continue;
		}
		while (*encodedText != ' ')
		{
			char * tmp = (char *)malloc(10 * sizeof(char));
			*tmp = *encodedText;
			val = Concat(val, tmp);
			*len++;
			*encodedText++;
		}
		if (!D_search(*dict, val)){
			str = D_search(*dict, old);
			str = Concat(str, c);
		}
		else str = D_search(*dict, val);
		result = Concat(result, str);
		*c = *str;
		D_putDup(*dict, Concat(D_search(*dict, old), c), intToStr((*dict)->size));
		D_put(pEncDic, Concat(D_search(*dict, old), c), intToStr(pEncDic->size));

		old = val;
	}
	return result;
}
