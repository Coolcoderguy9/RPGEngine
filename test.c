#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


struct guy {
	int hp;
	int atk;
	int def;
	int spd;
};


int battle(struct guy x, struct guy y);
int dmg_deal(struct guy a);
int dmg_calc(struct guy a);
int self_calc(struct guy a);

int main() {
	struct guy hero, bad;
	hero.hp = 10;
	hero.atk = 5;
	hero.def = 5;
	hero.spd = 5;
	bad.hp = 6;
	bad.atk = 4;
	bad.def = 4;
	bad.spd = 3;
	battle(hero, bad);
	return 0;
}

int battle(struct guy x, struct guy y) {
        while (1) {
                char choice[2];
                printf("\nPlease choose a battle option.\n");
                printf("a. Attack b. Guard c. Item d. Flee\n");
                fgets(choice, sizeof(choice), stdin);
                printf("\nYou chose %s\n", choice);
		if(!strchr(choice, '\n')) {
            		while(fgetc(stdin)!='\n');
        	}
		if (x.hp == 0) {
			printf("Oh no! You were defeated!");
			break;
		}
		if (y.hp == 0) {
			printf("Victory!");
			break;
		}
        }
        return 0;

}

int dmg_deal(struct guy a) {
	int dmg;
	dmg = (1.375 * a.atk);
	return dmg;	
}

int dmg_calc(struct guy a, int hit) {
	int calc;
	calc = -(1.625 * a.def) + hit;
	return calc;
}

int self_calc(struct guy a) {
	int dmtk;
}

/*char choice[2];
    
    do {
        printf("\nPlease choose a menu option.\n");
        printf("a. Inventory b. Equipment c. Travel d. Exit\n");
        fgets(choice, sizeof(choice), stdin);
        printf("\nYou chose %s\n", choice);
        if(!strchr(choice, '\n')) {
            while(fgetc(stdin)!='\n');
        }
    } while(*choice != *"d"); //derefs choice and string literal d to acces chars for comparison
    return 0;*/
