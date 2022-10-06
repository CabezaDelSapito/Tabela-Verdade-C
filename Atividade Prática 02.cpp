#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void binario(int n, int *bi, int id){
    if(n == 0){
    	int i;
		for(i = 0; i <= id; i++){
        	bi[i] = n;
    	}
    }else{
        binario(n/2, bi, id-1);
        bi[id] = n % 2;
    }
}

int main(){
	char linha[10], resultado[100]="", expressao[100]="";
	char *letras[]= {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	int  n = 0, i, j, quant, contador = 0;
    
	printf("Digite a quantidade de variaveis: ");
	scanf("%d", &quant);

	j = pow(2.0, quant);
	int bi[quant], saida[j];
	
	FILE *file;
	file = fopen("imput.txt" , "r");
	
	while(fgets(linha, 10, file)){
		saida[n] = atoi(linha);
		binario(n, bi, quant-1);
		for(i = 0; i < quant; i++){
        	printf("%d ", bi[i]);
    	}
    	printf("| %d\n", saida[n]);
		if(saida[n] == 1){		
			if(contador> 0)
	        	strcat(resultado," + ");
			for(i = 0; i < quant; i++){
   				if(bi[i] == 1){
		   			strcpy(expressao, letras[i]);
		   		}
		   		if(bi[i] == 0){
		   			strcpy(expressao, letras[i]);
		   			strcat(expressao, "'");
		   		}
		   		strcat(resultado, expressao);
				contador++; 
			}
		}
		n++;	
	}	
	
	printf("\n\n%s",resultado);
		
	fclose(file);
	free(letras);
	return 0;
}
