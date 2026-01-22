//Gretchen Pals Quiz 1
#include <stdio.h>
int findLength(char *strPtr);

int main (int argc, char * argv[])
{
  int i = 1; 
  if (argc > 1) 
  { 
    int len = findLength(argv[i]); 
    printf("Length: %d\n", len); 
  } 
  return 0;
}
int findLength (char * strPtr)
{
int len = 0;
  while(strPtr[len] != '\0')
  {
    len++;
  }
return len;
}
