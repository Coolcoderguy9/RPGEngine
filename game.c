#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// txt based adventure game in c

//character struct and damage formula

struct chr {
	char n[49];
	int hp;
	int atk;
	int def;
	int spd;
};

const char* characterName();

int main() {
	char* name = characterName();
	int h;
	int a;
	int d;
	int s;	
	printf("Function return success.\n");	
	struct chr player;
	strcpy(player.n, name);
	player.hp = 20;
	player.atk = 5;
	player.def = 5;
	player.spd = 5;
	printf("Player name is %s", player.n);
	printf("\nPlease allocate your character's stats: 5");
	printf("\nHp-health, Atk-damage output, Def-damage reduction, Spd-turn order/evasion rate");
	printf("\nBase stats are: Hp-%d, Atk-%d, Def-%d, Spd-%d", player.hp, player.atk, player.def, player.spd);
	printf("\nEnter a number to give to Hp: ");
	scanf(" %d", &h);
	printf("\nEnter a number to give to Atk: ");
	scanf(" %d", &a);
	printf("\nEnter a number to give to Def: ");
	scanf(" %d", &d);
	printf("\nEnter a number to give to Spd: ");
	scanf(" %d", &s);
	player.hp += h;
	player.atk += a;
	player.def += d;
	player.spd += s;
	printf("\nIs this the stat build you'd like to use?\n");	
	printf("Player name is %s, and has %d HP, %d Atk, %d Def, and %d Spd.\n", player.n, player.hp, player.atk, player.def, player.spd);
	return 0;
}

const char* characterName() {
	char uin = 0;
	char* name = malloc (50 * sizeof(char));
	if (name == NULL)
		return NULL;
	while (toupper(uin) != 'Y') {
		printf("Please enter a name for your character: ");
		scanf("%49s", name);
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
