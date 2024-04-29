#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main() {
  FILE *input = fopen("input.txt","r");
  FILE *output = fopen("output.txt","w");

  if(input == NULL || output == NULL) {
    printf("Error fetching input and output files");
    return 1;
  }

  char ch;
  char str[50];
  int isKeyword = 0;
  int lineNumber = 1;
  int tokenNumber = 0;
  int i = 0;

  char *keyword[] = {
     "int", "main", "if", "else", "do", "while", "include", "stdio", 
        "malloc", "for", "printf", "scanf", "ctype", "stdlib", "string", 
        "math", "void", "char", "getchar", "type", "isalpha", "toascii", 
        "switch", "case", "break", "exit", "return", "float"
  };

  fprintf(output,"Line Number\t\tToken Number\t\tType\t\tCharacter\n");

  while((ch = fgetc(input)) != EOF) {
    if(ch == '\n') {
      lineNumber++;
    }
    else if(strchr("+-%*/",ch)) {
      fprintf(output,"%d\t\t%d\t\tOperator\t\t%c\n",lineNumber,tokenNumber++,ch);
    }
    else if(strchr(";{}()?!^&",ch)) {
      fprintf(output,"%d\t\t%d\t\tSpecial\t\t%c\n",lineNumber,tokenNumber++,ch);
    }
    else if(isdigit(ch)) {
      fprintf(output,"%d\t\t%d\t\tDigit\t\t%c\n",lineNumber,tokenNumber++,ch);
    }
    else if(isalpha(ch)) {
      i = 0;
      str[i++] = ch;
      while(isalnum(ch = fgetc(input)) && ch != ' ') {
        str[i++] = ch;
      }
      str[i] = '\0';

      isKeyword = 0;
      for(i =0;i < sizeof(keyword) / sizeof(keyword[0]);i++) {
        if(strcmp(str,keyword[i]) == 0) {
          isKeyword = 1;
          break;
        }
      }

      if(isKeyword == 1) {
        fprintf(output,"%d\t\t%d\t\tKeyword\t\t%s\n",lineNumber,tokenNumber,str);
      }
      else {
        fprintf(output,"%d\t\t%d\t\tIdentifier\t\t%s\n",lineNumber,tokenNumber,str);
      }
    }
  }
  fclose(input);
  fclose(output);
  return 0;
}