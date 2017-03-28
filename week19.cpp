// week 19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"


typedef struct
{
	char username[50];
	char firstname[50];
	char lastname[50];
	char displayname[100];
	char jobtitle[50];
	char department[50];
	char officenum[50];
	char officephone[50];
	char mobilephone[50];
	char fax[50];
	char address[100];
	char city[50];
	char state[50];
	char states[100];
	char postalcode[50];
	char region[100];


}contact;


int readFile(char *fileName);
void initialiseResults();

void printResult(contact *aContact);
int numContacts = 0;

contact *contacts[10];

int main()
{

	char fileName[] = "F:\\contacts.txt";
	int i = 0;



	void initialiseResults();

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}

	while (contacts[i] != NULL)
	{
		printResult(contacts[i]);
		i++;
	}

	return 0;



}

int readFile(char *fileName)
{
	char *token;
	char delim[] = ",";
	char readLine[300];
	FILE *fptr;

	fptr = fopen(fileName, "r");
	fgets(readLine, 300, fptr);

	while (!feof(fptr)) {
		fgets(readLine, 300, fptr);
		contacts[numContacts] = (contact *)malloc(sizeof(contact));

		token = strtok(readLine, delim);
		strcpy(contacts[numContacts]->username, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->firstname, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->lastname, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->displayname, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->jobtitle, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->department, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->officenum, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->officephone, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->mobilephone, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->fax, token);


		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->address, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->city, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->state, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->postalcode, token);



		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->region, token);


		numContacts++;
	}
	fclose(fptr);

return 1;
}

void initialiseResults()
{
	for (int i = 0; i < 10; i++) {
		*(contacts + i) = NULL;
	}
}

void printResult(contact *aContact)
{
	printf("Username:%s\n First Name:%s\n Last name:%s\n Display Name:%s\n Job Title:%s\n Department:%s\n Office Number:%s\n Office Phonenum:%s\n Mobile Phone:%s\n Fax:%s\n Address:%s\n City: %s\n State: %s\n Postal Code:%s\n Regiom:%s\n\n", aContact->username, aContact->firstname, aContact->lastname, aContact->displayname, aContact->jobtitle, aContact->department, aContact->officenum, aContact->officephone, aContact->mobilephone, aContact->fax, aContact->address, aContact->city, aContact->state, aContact->postalcode, aContact->region);
}
