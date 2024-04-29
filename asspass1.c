#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char label[10],opcode[10],operand[10],mnemonic[10];
    int locctr = 0;
    
    FILE *input,*mot,*output,*st;
    
    input = fopen("input.txt","r");   // input
    mot = fopen("mot.txt","r");     // input
    output = fopen("output.txt","w");  // output
    st = fopen("st.txt","w");      // output
    
    fscanf(input,"%s %s %s",label,opcode,operand); //opcode start
    
    fprintf(output,"%d %s %s %s\n",locctr,label,opcode,operand);
    
    fscanf(input,"%s %s %s",label,opcode,operand);//opcode using
    
    fprintf(output,"%d %s %s %s\n",locctr,label,opcode,operand);
    
    while(strcmp(opcode,"END")!=0){
        
        if(strcmp(opcode,"DC")==0 || strcmp(opcode,"DS")==0){
            fprintf(st,"%s %d\n",label,locctr);
            fprintf(output,"%d %s %s %s\n",locctr,label,opcode,operand);
            locctr += 4;
        }
        else{
            fscanf(mot,"%s",mnemonic);
            fprintf(output,"%d %s %s %s\n",locctr,label,opcode,operand);
            while(strcmp(mnemonic,"end")!=0){
                if(strcmp(opcode,mnemonic)==0){
                    locctr += 4;
                    break;
                }
                fscanf(mot,"%s",mnemonic);
            }
            rewind(mot);
        }
        
        fscanf(input,"%s %s %s",label,opcode,operand);
    }
    
    fprintf(output,"%d %s %s %s\n",locctr,label,opcode,operand);
    fclose(input);
    fclose(mot);
    fclose(output);
    fclose(st);
    
    return 0;
}