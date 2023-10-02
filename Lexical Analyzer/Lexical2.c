#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char delim[10] = { '(', ')', '{', '}', '[', ']', ',', '.', ';' };
char keyword[][20] = { "void", "int", "float", "double", "short", "long", "if", "else", "switch", "case", "break", "return", "static", "goto", "main" };
char operator[8] = { '=', '+', '-', '*', '/', '<', '>' };
char code[20];
int isKeyword(char txt[20]);
int isOperator(char txt[20]);
int isDelimiter(char txt[20]);
int isLiteral(char txt[20]);
int isDigit(char txt[20]);
int isComment(char txt[20]);
int main(){
	FILE *fp = fopen("input.txt", "r");
	int inComment = 0;
	while (fscanf(fp, "%s", code) != EOF){
		if (isComment(code) == 1){
			inComment = 1;
			continue;
}
		if (inComment){
		if (strchr(code, '*') != NULL && strchr(code, '/') != NULL){
		inComment = 0;
		continue;
			}
		}
		if (isKeyword(code) == 1)
	printf("%s \t Keyword\n", code);
	else if (isOperator(code) == 1)
	printf("%s \t Operator\n", code);
	else if (isDelimiter(code) == 1)
	printf("%s \t Delimiter\n", code);
	else if (isLiteral(code) == 1)
	printf("%s \t Literal\n", code);
	else if (isDigit(code) == 1)
	printf("%s \t Digit\n", code);
	else
	printf("%s \t Identifier\n", code);
	}
	fclose(fp);
	return 0;
}

int isKeyword(char txt[20]){
	for (int i = 0; i < 15; i++){
	if (strcmp(txt, keyword[i]) == 0)
			return 1;
	}
	return 0;
}
int isOperator(char txt[20]){
	for (int i = 0; i < 8; i++){
		if (txt[0] == operator[i])
			return 1;
	}
	return 0;
}
int isDelimiter(char txt[20]){
	for (int i = 0; i < 10; i++){
		if (txt[0] == delim[i])
			return 1;
	}
	return 0;
}
int isDigit(char txt[20]){
	if (isalpha(txt[0]) == 0)
		return 1;
	return 0;
}
int isLiteral(char txt[20]){
	if (txt[0] == '"')
		return 1;
	return 0;
}
int isComment(char txt[20]){
	if (txt[0] == '/' && txt[1] == '*')
		return 1;
	return 0;
}
