#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int areSame(char* a,char* b)
{
	while(*a!='\0' && *b!='\0')
	{
		if(*a!=*b) return 0;
		a++;b++;
	}
	if(*a=='\0' && *b!='\0' || *a!='\0' && *b=='\0') return 0;
	return 1;
}
void viewUsername()
{
	FILE* username=fopen("username.txt","r");
	char* user=(char*)malloc(sizeof(char)*20);
	fscanf(username,"%s",user);
	fclose(username);
	cout<<"View username\n\n"<<user<<endl;
}
void viewPassword()
{
	FILE* password=fopen("password.txt","r");
	char* pass=(char*)malloc(sizeof(char)*20);
	fscanf(password,"%s",pass);
	fclose(password);
	cout<<"View password\n\n"<<pass<<endl;
}
void changeUsername()
{
	FILE* username=fopen("username.txt","r");
	char* user=(char*)malloc(sizeof(char)*20);
	fscanf(username,"%s",user);
	fclose(username);
	char* inputuser=(char*)malloc(sizeof(char)*20);
	cout<<"Old Username: ";
	cin>>inputuser;
	if(areSame(user,inputuser))
	{
		cout<<"New Username: ";
		cin>>inputuser;
		username=fopen("username.txt","w");
		fprintf(username, "%s", inputuser);
		fclose(username);
		cout<<"Username changed successfully\n";
	}
	else
		cout<<"Wrong Username"<<endl;

}
void changePassword()
{
	FILE* password=fopen("password.txt","r");
	char* pass=(char*)malloc(sizeof(char)*20);
	fscanf(password,"%s",pass);
	fclose(password);
	char* inputpass=(char*)malloc(sizeof(char)*20);
	cout<<"Old Password: ";
	cin>>inputpass;
	if(areSame(pass,inputpass))
	{
		cout<<"New Password: ";
		cin>>inputpass;
		password=fopen("Password.txt","w");
		fprintf(password, "%s", inputpass);
		fclose(password);
		cout<<"Password changed successfully\n";
	}
	else
		cout<<"Wrong Password"<<endl;

}
int main()
{
	FILE* username=fopen("username.txt","r");
	FILE* password=fopen("password.txt","r");
	char* user=(char*)malloc(sizeof(char)*20);
	char* pass=(char*)malloc(sizeof(char)*20);
	fscanf(username,"%s",user);
	fscanf(password,"%s",pass);
	fclose(username);
	fclose(password);
	char* inputuser=(char*)malloc(sizeof(char)*20);
	char* inputpass=(char*)malloc(sizeof(char)*20);
	int logged_in=0;
	do
	{
		cout<<"LOG IN\nUsername: ";
		cin>>inputuser;
		cout<<"Password: ";
		cin>>inputpass;
		if(areSame(inputuser,user) && areSame(inputpass,pass))
		{
			logged_in=1;
		}
		else
			cout<<"Username or password error\n";
	}while(!logged_in);
	int choice;
	cout<<"Menu\n\n1 - Change Username\n\n2 - Change Password\n\n3 - View Username\n\n4 - View Password\n\nChoice : ";
	cin>>choice;
	switch(choice)
	{
		case 1: changeUsername();break;
		case 2: changePassword();break;
		case 3: viewUsername();break;
		case 4: viewPassword();break;
		default: cout<<"Invalid input";break;
	}
	return 0;
}