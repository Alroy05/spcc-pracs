#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char label[10],opcode[10],operand[10];
    int mntc=1,mdtc=1;
    
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1 = fopen("input.txt","r");   //input
    fp2 = fopen("mnt.txt","w");     //output
    fp3 = fopen("mdt.txt","w");     //output
    fp4 = fopen("copyfile.txt","w");//output
    
    fscanf(fp1,"%s %s %s",label,opcode,operand);
    
    while(strcmp(opcode,"END")!=0) {
        if(strcmp(opcode,"MACRO")==0){
            fscanf(fp1,"%s %s %s",label,opcode,operand);
            fprintf(fp2,"%d %s %d\n",mntc,opcode,mdtc);
            mntc++;
            while(strcmp(opcode,"MEND")!=0){
                fprintf(fp3,"%d %s %s %s\n",mdtc,label,opcode,operand);
                mdtc++;
                fscanf(fp1,"%s %s %s",label,opcode,operand);
            }
            fprintf(fp3,"%d %s %s %s\n",mdtc,label,opcode,operand);
            mdtc++;
        }
        else{
            fprintf(fp4,"%s %s %s\n",label,opcode,operand);
        }
        fscanf(fp1,"%s %s %s",label,opcode,operand);
    }
    
    fprintf(fp4,"%s %s %s\n",label,opcode,operand);
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
        
    return 0;
}