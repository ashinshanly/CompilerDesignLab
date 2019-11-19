#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


int isKeyword(char buffer[]){
	
	char key[8][10]={"int", "return", "char", "FILE", "if", "else", "for", "while"};
	int i;
	for(i=0;i<8;i++){
		if(strcmp(buffer, key[i])==0){
			return 1;
		}
	}
	return 0;
}

int main()
{
	char buffer[100];
	char op[]="+-/*%=", ch;
	int i=0,j=0;

	FILE *fp;
	fp=fopen("sample.txt","r");

	if(fp!=NULL){
	while((ch = fgetc(fp)) != EOF){

		for(i=0;i<6;i++){
			if(ch == op[i]){ printf("%c is an operator!\n",ch); }
		}

		if(ch == ';') { printf("%c is a separator!\n",ch); }

		else if(isalnum(ch)){ buffer[j++]=ch; }

		else if((ch == ' ' || ch == '\n') && (j!=0)){
			buffer[j]='\0';
			j=0;
			if(isKeyword(buffer) == 1){ printf("%s is a Keyword!\n", buffer); }

			else{ printf("%s is an Identifier!\n", buffer); }
			
		}
	}
	}
	fclose(fp);
	return 0;
}


