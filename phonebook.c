#include<stdio.h>
#include<conio.h>
#define max 50
int createcontact(char name[],char phn[]);
int searchcontact(char name[]);
int removecontact(char name[]);
int uppercase(char n[]);
FILE *fp;
char name[max],str[max],phn[10];
int main()
{
	int option;
	printf("\n______________________________________ PHONE BOOK ______________________________________\n");
	do
	{
		printf("\n1.Contact list\n2.Create\n3.Search\n4.Remove\n5.Exit\n");
		printf("\nSelect option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n********** Contact List **********\n");
				contactlist();
				break;
			case 2:
				printf("\n********** Create Contact **********");
				printf("\nName: ");
				gets(name);
				gets(name);
				printf("Phn no: ");
				gets(phn);
				if(createcontact(name,phn))
					printf("Successfully created\n");
				break;
			case 3:
				printf("\n********** Search Contact **********");
				printf("\nName: ");
				gets(name);
				gets(name);
				if(searchcontact(name))
					printf("%s",str);
				else
					printf("No Match\n");
				break;
			case 4:
				printf("\n********** Remove Contact **********");
				printf("\nName: ");
				gets(name);
				gets(name);
				if(removecontact(name))
					printf("Successfully removed\n");
				break;
			case 5:
				exit(0);
			}
	}while(option!=4);
	return 0;
}
int contactlist()
{
	fp=fopen("contacts.txt","r");
	while((fgets(str,max,fp))!=NULL)
		printf("%s",str);
	return 1;
}
int createcontact(char name[],char phn[])
{
	fp=fopen("contacts.txt","a");
	uppercase(name);
	fprintf(fp,"%-20s - %-20s\n",name,phn);
	fclose(fp);
	return 1;
}
int searchcontact(char name[])
{
	char ch;
	int i;
	fp=fopen("contacts.txt","r");
	uppercase(name);
	while((ch=fgetc(fp))!=EOF)
	{
		i=0;
		if(ch==name[i])
		{
			do
			{
				ch=fgetc(fp);
				i++;
			}while(name[i]!='\0' && ch==name[i]);
			if(name[i]!='\0')
				continue;
			break;
		}
	}
	while((ch=fgetc(fp))!='\n')
		fseek(fp,-2,1);
	fgets(str,max,fp);
	fclose(fp);
	if(ch==EOF|| name[i]!='\0')
		return 0;
	else
		return 1;
	return 1;
}
int removecontact(char name[])
{
	int option;
	char str1[max];
	FILE *cfp;
	if(searchcontact(name))
	{
		printf("\nAre you sure to remove contact \n%s",str);
		printf("\n1.yes\t2.No");
		printf("\nselect option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				fp=fopen("contacts.txt","r");
				cfp=fopen("copycontacts.txt","w");
				while((fgets(str1,max,fp))!=NULL)
					if(strcmp(str1,str)!=0)
					{
						fprintf(cfp,"%s",str1);	
					}
				fclose(fp);
				fclose(cfp);
				fp=fopen("contacts.txt","w");
				cfp=fopen("copycontacts.txt","r");
				while((fgets(str1,max,cfp))!=NULL)
					fprintf(fp,"%s",str1);	
				fclose(cfp);
				fclose(fp);
				break;
				return;
			case 2:
				printf("Cancelled\n");
				return;
		}
	}
	else
	{
		printf("No Match\n");
		return 0;
	}
	return 1;
}
int uppercase(char n[])
{
	int i;
	for(i=0;name[i]!='\0';i++)
		if(name[i]>='a' && name[i]<='z')
			name[i]=name[i]-32;
	return 0;
}
