#include "lzw.c"

int main(int argc, char const *argv[])
{
  char * text = "si ton tonton tond mon tonton";
 	Dict * dict = LZ_initEncDic(text, 7);

  printf("-------INITIAL STRING-------\n");
  printf("%s\n", text);

  printf("-------INITIAL DICTIONARY-------\n");
  D_print(dict);

  int a = 0;

  printf("-------ENCODED DICTIONARY------\n");

  Dict * newDict = D_new(7);

  char * str = LZ_encode(dict, text, &a);

  D_print(dict);

  printf("-------ENCODED STRING-------\n");

  printf("%s\n", str);

  dict = LZ_initEncDic(text, 7);

  char * result = LZ_decode(dict, &newDict, str, &a);

  printf("--------DECODED STRING-------\n");

  printf("%s\n", result);

  printf("-------ENCODED DICTIONARY------\n");

  D_print(newDict);


	return 0;
}
