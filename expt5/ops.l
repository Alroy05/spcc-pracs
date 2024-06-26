%{
#include<stdio.h>
int operators=0, operands=0;
%}

%%
[\+\-\*\/\=]+ {operators++;} 
[0-9a-zA-Z]+ {operands++;}
%%

int yywrap(){ 
  return 1;
}

int main() {
  printf("Enter the equation: "); 
  yylex();
  printf("No of operators: %d\n", operators); 
  printf("No of operands: %d\n", operands);
}