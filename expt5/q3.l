%{
#include<stdio.h>
int operators = 0, identifier = 0, constants = 0, spSymbols = 0; 
%}
%%
_[_a-zA-Z0-9]+ {identifier++;}
[\/\+\-\*\%]+ {operators++;}
[a-zA-Z]* {constants++;}
. {spSymbols++;}

%%
int yywrap()
{ 
  return 1;
}

int main() {
printf("Enter the strings: "); 
yylex();

printf("No of identifiers: %d\n", identifier); 
printf("No of operators: %d\n", operators); 
printf("No of constants: %d\n", constants); 
printf("No of spSymbols: %d\n", spSymbols); 
}