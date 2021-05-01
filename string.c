#include<stdio.h>
#include<string.h>
int find(char str[100][100],char st[50],int lr);
int find(char str[100][100],char st[50],int lr)
{
    char sup[50];
    int flag=0;
    for(int i=0;i<lr;i++)
    {
        for(int j=0;j<strlen(st);j++)
        sup[j]=str[i][j];
        if(strcmp(st,sup)==0)
        {
            flag++;
        }
        for(int j=0;j<strlen(st);j++)
        sup[j]='\0';
    }
    return flag==3?strlen(st):0;
    return 0;
}
int main()
{
    char arr[100][100];
    char sup[50];
    int l,low,pos,max=0;
    printf("please enter number of words you want to input\n");
    scanf("%d",&l);
    printf("plese enter %d words\n",l);
    
    for(int i=0;i<l;i++)
    scanf("%s",arr[i]);
    
    low=strlen(arr[0]);

    for(int i=0;i<l;i++)
    {
        if(low>=strlen(arr[i]))
        {
            low=strlen(arr[i]);
            pos=i;
        }
    }
    //printf("%s",arr[pos]);
    for(int i=0;i<strlen(arr[pos]);i++)
    {
        sup[i]=arr[pos][i];
        int len=find(arr,sup,l);
        if(len>max)
        {
            max=len;
        }
    }
    if(max==0)
    printf("no common prefix\n");
    else
    {
        printf("the commom prefix is:-");
        for(int i=0;i<max;i++)
        {
            printf("%c",arr[pos][i]);
        }
    }
    return 0;
}