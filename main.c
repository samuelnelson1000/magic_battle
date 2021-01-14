#include "header.h"

int main(){
//deklarasi variabel

	struct data *unit = (struct data *) malloc(sizeof(struct data));
	pthread_t t_arena, t_incMana, t_actPlayer, t_actAlly, t_actEnm1, t_actEnm2;
	int i;

	//inisialisasi log action
	crtEmpty(&L1);
	add("Game begin               ", &L1);
	crtEmpty(&L2);
	add("Game begin", &L2);
	crtEmpty(&L3);
	add("Game begin               ", &L3);
	crtEmpty(&L4);
	add("Game begin", &L4);

	//inisialisasi nilai awal healt dan mana
	for(i=0; i<3; i++){
		unit->H_bot[i] = 100;
		unit->M_bot[i] = 0;
	}
	unit->H_player = 100;
	unit->M_player = 0;

	//set stop dengan nilai 0
	stop = 0;
	//membuat thread tampilan permainan
	pthread_create(&t_arena, NULL, arena, (void *)unit);
	//membuat thread penambah mana
	pthread_create(&t_incMana, NULL, incMana, (void *)unit);
	//membuat thread aksi player
	pthread_create(&t_actPlayer, NULL, action_player, (void *)unit);
	//membuat thread aksi ally
	pthread_create(&t_actAlly, NULL, action_ally, (void *)unit);
	//membuat thread aksi enemy1
	pthread_create(&t_actEnm1, NULL, action_enm1, (void *)unit);
	//membuat thread aksi enemy2
	pthread_create(&t_actEnm2, NULL, action_enm2, (void *)unit);
	pthread_join(t_actPlayer, NULL);
	pthread_join(t_actAlly, NULL);
	pthread_join(t_actEnm1, NULL);
	pthread_join(t_actEnm2, NULL);
	pthread_join(t_arena, NULL);
	//printf("nilai stop: %d\n", stop);
	pthread_exit(NULL);

	return 0;
}