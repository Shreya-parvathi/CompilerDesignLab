#include<stdio.h>
#include<string.h>
void key(char temp[],char kw[][15],int
*check);
void dlmtr(char temp[],char delim[],int
*check);
void oprtr(char temp[],char oper[],int
*check);
void ltrl(char temp[],int *check);
void idfr(char temp[],int *check);
void main()
{
FILE *fp;
int i=0,check;
char temp[10];
char
kw[][15]={"void","int","float","double","short",
"long","if","else","switch"
,"case","break","return","static","goto","main"
};
char delim[]={'(',')','{','}','[',']','.',',',';'};
char oper[]={'=','+','-','*','/','<','>'};
fp=fopen("input","r");
while(fscanf(fp,"%s",temp)!=EOF)
{
if(temp[0]=='/' && (temp[1]=='/' ||
temp[1]=='*'))
continue;
else if(temp[0]=='*' && temp[1]=='/')
continue;
check=0;
key(temp,kw,&check);
if(check==0)
dlmtr(temp,delim,&check);
if(check==0)
oprtr(temp,oper,&check);
if(check==0)ltrl(temp,&check);
if(check==0)
idfr(temp,&check);
if(check==0)
printf("%s Digit\n",temp);
}
}
void key(char temp[],char kw[][15],int
*check)
{
int i;
for(i=0;i<15;i++)
if(strcmp(temp,kw[i])==0)
{
printf("%s Keyword\n",temp);
*check=1;
break;
}
}
void dlmtr(char temp[],char delim[],int
*check)
{
int i;
for(i=0;i<9;i++)
if(temp[0]==delim[i])
{
printf("%s Delimiter\n",temp);
*check=1;
break;
}
}
void oprtr(char temp[],char oper[],int *check)
{
int i;
for(i=0;i<7;i++)
if(temp[0]==oper[i])
{printf("%s Operator\n",temp);
*check=1;
break;
}
}
void ltrl(char temp[],int *check)
{
if(temp[0]=='"')
{
printf("%s Literal\n",temp);
*check=1;
}
}
void idfr(char temp[],int *check)
{
if((temp[0]>='a' && temp[0]<='z') ||
(temp[0]>='A' && temp[0]<='Z'))
{
printf("%s Identifier\n",temp);
*check=1;
}
}
