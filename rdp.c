#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SUCCESS 1
#define FAILED 0

// E -> T Edash
// Edash -> + T Edash | $
// T -> F Tdash
// Tdash -> * F Tdash | $
// F -> ( E ) | i

int E(); 
int Edash(); 
int T(); 
int Tdash(); 
int F();

const char *pt;
char grammer[100];

int main() {
  printf("Enter an expression to be parsed:-");
  scanf("%s",grammer);

  pt = grammer;

  if(E() && *pt == '\0') {
    printf("Expression parsed successfully by the compiler!!\n");
    return 0;
  } else
  {
    printf("Failed to parse the expression!!\n");
    return 1;
  }
}

int E() {

  printf("%-16s \t\t E -> T E'\n",pt);

  if(T() && Edash()) {
    return SUCCESS;
  } 
  else 
  {
    return FAILED;
  }
}

// Edash -> + T E' | ε
int Edash() {
  if(*pt == '+') {
    printf("%s \t\tEdash -> + T E'\n",pt);
    pt++;

    if(T() && Edash()) {
      return SUCCESS;
    }
    else {
      return FAILED;
    }
  }
  else
    {
      printf("%s \t\tEdash -> $\n",pt);
      return SUCCESS;
    }
}

// T -> F T'
int T() {
  printf("%s \t\t T -> F T'\n",pt);

  if(F() && Tdash()) {
    return SUCCESS;
  } else {
    return FAILED;
  }
}

// Tdash -> * F T' | ε
int Tdash() {
  if(*pt == '*') {
    printf("%s \t\tTdash -> * F T'\n",pt);
    pt++;

    if(F() && Tdash()) {
      return SUCCESS;
    } else {
      return FAILED;
    }
  }
  else {
    printf("%s \t\tTdash -> $\n",pt);
    return SUCCESS;
  }
}

// F -> ( E ) | i

int F() {
  if(*pt == '(') {
    printf("%-16s \t\t F -> ( E )\n",pt);
    pt++;

    if(E() && *pt == ')') {
      pt++;
      return SUCCESS;
    } else {
      return FAILED;
    }
  } else if(*pt == 'i') {
    printf("%-16s F -> i\n",pt);
    pt++;
    return SUCCESS;
  } else {
    return FAILED;
  }
}
