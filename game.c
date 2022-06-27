#include <stdio.h>

// txt based adventure game in c

//character struct and damage formula

struct chr {
	int hp;
	int atk;
	int def;
	int spd;
};

int main() {
	char name[50];
	printf("Please enter a name for your character: ");	
	scanf("%s", name);
	printf("\nIs %s the name you'd like to use?\n", name);
	return 0;
}
