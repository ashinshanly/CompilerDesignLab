/*
After removing left recursion.
E: TE'  
E': +TE'/e
T: FT'
T': *FT'/e
F: (E)/id

*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

char exp[10];
int count=0;
int flag=0;

void check(){
	if(isalnum(exp[count])) { count++; }
	else if(exp[count]=='('){
		count++;
		E();
		if(exp[count]==')') { count++; }
		else { flag=1; }
	}
	else { flag=1; }
}

void Tprime(){
	if(exp[count]=='*'){
		count++;
		check();
		Tprime();
	}
}

void T(){
	check();
	Tprime();
}
void Eprime(){
	if(exp[count]=='+'){
		count++;
		T();
		Eprime();
	}
}
void E(){
	T();
	Eprime();
}

void main(){
	printf("Expression: ");
	scanf("%s",&exp);
	E();
	if(strlen(exp)==count && flag==0) { printf("Valid!"); }
	else { printf("Invalid"); }
}
