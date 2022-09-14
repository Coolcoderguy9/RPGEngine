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

struct chr mysteryBandit();

struct chr characterMake();

int main() {
	struct chr player;
	player = characterMake();
	struct chr bandit;
	bandit = mysteryBandit();	
	printf("\n'Welcome to our town %s! Today marks the millenial anniversary since the evil bad guy was defeated by the great hero, who happens to look exactly like you! I'm the innkeeper here, so feel free to ask me any questions while you're in town.'\n", player.n);
	printf("\nYou step outside the inn's doors and are greeted by a bustling fair filled with townsfolk and merchants alike. Traders from all over have come to profit, and attractions abound to celebrate the 1000th anniversary of the Day The Evil Was Beat.\n");
	printf("\nA glimmer down an alleyway catches your eye, and you proceed down it, eager to see what adventures might lie down it.\n");
	printf("\nBut it was a trap! You are attacked by a rogue bandit!\n");
	printf("You are fighting %s! What will you do?\n", bandit.n);
	return 0;
}

struct chr characterMake() {
	char uin = 0;
	char stat_conf = 0;
	char* stat_select = malloc(3 * sizeof(char));
	char* name = malloc (50 * sizeof(char));
	int h;
	int a;
	int d;
	int s;	
	int stat_pts;
	stat_pts = 5;
	//if (name == NULL)
	//	return NULL;
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
	struct chr player;
	strcpy(player.n, name);
	free(name);
	player.hp = 20;
	player.atk = 5;
	player.def = 5;
	player.spd = 5;
	printf("Player name is %s", player.n);
	printf("\nPlease allocate your character's stats: 5");
	printf("\nHp-health, Atk-damage output, Def-damage reduction, Spd-turn order/evasion rate");
	printf("\nBase stats are: Hp-%d, Atk-%d, Def-%d, Spd-%d", player.hp, player.atk, player.def, player.spd);
	while (toupper(stat_conf) != 'Y') {
		printf("\nEnter a stat to edit: ");
		scanf(" %s", stat_select);
		if (strcmp(stat_select, "hp") == 0) {
			printf("\nStat points available: %d\n", stat_pts);
			printf("\nEnter a number to give to Hp(%d): ", player.hp);
			scanf(" %d", &h);
			player.hp += h;
			stat_pts -= h;
		}
		else if (strcmp(stat_select, "atk") == 0) {
			printf("\nStat points available: %d\n", stat_pts);
			printf("\nEnter a number to give to Atk(%d): ", player.atk);
			scanf(" %d", &a);
			player.atk += a;
			stat_pts -= a;
		}
		else if (strcmp(stat_select, "def") == 0) {
			printf("\nStat points available: %d\n", stat_pts);
			printf("\nEnter a number to give to Def(%d): ", player.def);
			scanf(" %d", &d);
			player.def += d;
			stat_pts -= d;
		}
		else if (strcmp(stat_select, "spd") == 0) {
			printf("\nStat points available: %d\n", stat_pts);
			printf("\nEnter a number to give to Spd(%d): ", player.spd);
			scanf(" %d", &s);
			player.spd += s;
			stat_pts -= s;
		}
		printf("\n %d HP, %d Atk, %d Def, and %d Spd.\n", player.hp, player.atk, player.def, player.spd);
		printf("\nIs this the stat build you'd like to use?\n");	
		scanf(" %c", &stat_conf);
	}
	

	free(stat_select);
	printf("Player name is %s, and has %d HP, %d Atk, %d Def, and %d Spd.\n", player.n, player.hp, player.atk, player.def, player.spd);
	
	return player;
}


struct chr mysteryBandit() {
	struct chr bandit;
	strcpy(bandit.n, "Mystery Rogue");
	bandit.hp = 12;
	bandit.atk = 6;
	bandit.def = 6;
	bandit.spd = 7;
	return bandit;
}
