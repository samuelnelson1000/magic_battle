//gcc *.c -o maba.exe -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <pthread.h>
#include <termios.h>
#include <string.h>

/*Version 0.6
 - Memperbaiki error pada log action ketika ada unit yang mati
*/

//struct
struct data { //data sharing
	int H_bot[3], M_bot[3]; //[0]: Ally, [1]: Enemy1. [2]: Enemy2
	int H_player, M_player;
};

typedef struct{ //log action
	int first, last;
	char action[3][100];
}log;

log L1,L2,L3,L4;

//variabel untuk penanda permainan berakhir
int stop;

//mutex
pthread_mutex_t lock;

//tampilan arena
void *arena(void *arg);
//prosedur menambahkan mana
void *incMana(void *arg);
//prosedur untuk action player
void *action_player(void *arg);
//prosedur untuk action bot ally
void *action_ally(void *arg);
//prosedur untuk action bot enemy1
void *action_enm1(void *arg);
//prosedur untuk action bot enemy2
void *action_enm2(void *arg);
//membuat log kosong
void crtEmpty(log *L);
//prosedur del
void del(log *L);
//prosedur add
void add(char action[], log *L);