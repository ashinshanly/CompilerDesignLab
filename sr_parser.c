/*
E –> 2E2
E –> 3E3
E –> 4
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[10], input[10], action_shift[10], action_reduce[10];
int i=0, j=0, k=0, length=0;


void check(){
	strcpy(action_reduce, "REDUCE");

	for(k=0; k<length; k++){
		if(stack[k]=='4'){                                               // Checking for E->4
			stack[k]='E';
			stack[k+1]='\0';

			printf("%s \n", action_reduce);
			printf("$%s    %s$    ", stack, input);
		}
	}

	for(k=0; k<length-2; k++){
		if(stack[k]=='2' && stack[k+1]=='E' && stack[k+2]=='2'){           // Checking for E->2E2
			stack[k]='E';
			stack[k+1]='\0';
			stack[k+2]='\0';
			
			printf("%s \n", action_reduce);
			printf("$%s    %s$    ", stack, input);
			i-=2;
		}
	}

	for(k=0; k<length-2; k++){
		if(stack[k]=='3' && stack[k+1]=='E' && stack[k+2]=='3'){           // Checking for E->3E3
			stack[k]='E';
			stack[k+1]='\0';
			stack[k+2]='\0';
			
			printf("%s \n", action_reduce);
			printf("$%s    %s$    ", stack, input);
			i-=2;
		}
	}
	return;
}


void main(){
	strcpy(action_shift, "SHIFT");

	printf("Expression: ");
	scanf("%s", input);
	length=strlen(input);

	printf("STACK    INPUT    ACTION");	
	printf("\n$    %s$    ", input);

	for(i=0, j=0; j<length; i++, j++){

		printf("%s\n", action_shift);
		stack[i] = input[j];

		stack[i+1] = '\0';		
		input[j] = ' ';
		
		printf("$%s    %s$    ", stack, input);
		check();
	}

	check();

	if(stack[0]=='E' && stack[1]=='\0') { printf("\nAccepted!"); }
	else { printf("\nRejected!"); }

}
