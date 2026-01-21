#include <stdio.h>
#include <stdlib.h> //for atoi
void convertToBinary(int decimal, char *strPtr, int numBits);
int convertToDecimal(char * strPtr, int numBits);
int binaryCheck(char *strPtr);

int main(int argc, char * argv[])
{
  int i;
  int isBinary = 1;
  for(i=1; i < argc; i++)
  {
    if(!binaryCheck(argv[i]))
    {
      isBinary = 0;
    }
  }
  if (isBinary)
  {
    int sum = 0;
    for(i=1; i < argc; i++)
      {
        int dec = convertToDecimal(argv[i], 8);
        printf("%s: %d\n", argv[i], dec);
        sum += dec;
      }
  
      char binary[9] = "00000000";
      convertToBinary(sum, binary, 8);
      printf("Sum in decimal: %d\nSum in binary: %s\n", sum, binary);

      return 0;
  }
  for (i = 1; i < argc; i++)
  {
    if(!binaryCheck(argv[i]))
    {
    printf("%s is not an 8-bit binary integer\n", argv[i]);
    }
  return 0;
  }
}

void convertToBinary(int dec, char * strPtr, int numBits)
{
  int i = numBits - 1;
  while(i>=0)
  {
    unsigned char digit = (unsigned char) (dec & 0x01);
    strPtr[i] = digit + '0';
    i--;
  }
}

int convertToDecimal(char * strPtr, int numBits)
{
  int i;
  int total = 0;
  int pow2 = 1;
  
  int isNeg = (strPtr[0] == '1');
  
  if (!isNeg)
  {
    for (i = numBits-1; i>=0; i--)
    {
      int digit = strPtr[i] - '0';
      total += digit * pow2;
      pow2 *= 2;
    }
    return total;
  }

  char temp[9];
  for (i = 0; i < numBits; i++)
  {
    temp[i] = (strPtr[i] == '0') ? '1' : '0';
  }
  for (i = numBits - 1; i >=0; i--)
  {
    if (temp[i] == '0')
    {
      temp[i] = '1';
      break;
    }
    else
    {
      temp[i] = '0';
    }
  }
  for (i = numBits-1; i>=0; i--)
    {
      int digit = temp[i] - '0';
      total += digit * pow2;
      pow2 *= 2;
    }
  return -total;
}

int binaryCheck (char * strPtr)
{
  int len = 0;
  while(strPtr[len] != '\0')
  {
    len++;
  }
  if (len != 8)
  {
    return 0;
  }

  for (int i = 0; i < 8; i++)
  {
    if(strPtr[i] != '0' && strPtr[i] != '1')
    {
      return 0;
    }
  }
  return 1;
}
