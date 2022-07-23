#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// txt based adventure game in c

//character struct and damage formula


struct chr {
	int hp;
	int atk;
	int def;
	int spd;
};

const char* characterName();

int main() {
	characterName();	
	printf("Function return success.\n");	
	printf("%s", name);	
	return 0;
}

const char* characterName() {
	char uin = 0;
	char name[50];
	while (toupper(uin) != 'Y') {
		printf("Please enter a name for your character: ");
		scanf("%s", name);
		if (strlen(name) < 1 || strlen(name) > 50) {
			printf("Please enter a valid name.\n");
			continue;
		}
		printf("\nIs %s the name you'd like to use? [Y/N] ", name);
		scanf(" %c", &uin);
		printf("\n");

	}
	
	return name;
}
