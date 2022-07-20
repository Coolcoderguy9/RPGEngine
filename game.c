#include <stdio.h>
#include <string.h>

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
	
	return 0;
}

const char* characterName() {
	char uin[2];
	char name[50];
	while (strcmp(uin, "Y") != 0) {
		printf("Please enter a name for your character: ");
		scanf("%", name);
		if (strlen(name) < 1 || strlen(name) > 50) {
			printf("Please enter a valid name.\n");
			continue;
		}
		printf("\nIs %s the name you'd like to use? [Y/N] ", name);
		scanf(" %1c", uin);
		printf("\n");

	}
	
	return name;
}
