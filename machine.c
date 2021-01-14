#include "header.h"

//tampilan arena
void *arena(void *arg){
	struct data *temp = (struct data*)arg;
	int i,j;
	while(stop != 1){
	/*pengulangan sampai permainan berakhir*/
		if(stop == 2){
			/*jika permainan masuk dalam tahap akan diberhentikan*/
			stop = 1;
			struct termios tio;
			tcgetattr(STDIN_FILENO, &tio); //get the terminal setting for stdin
			tio.c_lflag = ~ICANON; //canonical mode
			tcsetattr(STDIN_FILENO, TCSANOW, &tio); //set new setting immediately
		}
		system("clear"); //membersihkan layar
		printf("    __  ___            _         ____        __  __  __   \n");
		printf("   /  |/  /___ _____ _(_)____   / __ )____ _/ /_/ /_/ /__ \n");
		printf("  / /|_/ / __ `/ __ `/ / ___/  / __  / __ `/ __/ __/ / _ %c\n",92);
		printf(" / /  / / /_/ / /_/ / / /__   / /_/ / /_/ / /_/ /_/ /  __/\n");
		printf("/_/  /_/%c__,_/%c__, /_/%c___/  /_____/%c__,_/%c__/%c__/_/%c___/ \n",92,92,92,92,92,92,92);
		printf("             /____/                                       \n");
		printf("============================================================\n");
		printf(" Blue Team:                  || Red Team:\n");
		printf(" > PLAYER 1                  || > BOT 1:\n");
		printf(" > BOT Ally                  || > BOT 2:\n");
		printf("============================================================\n");
		printf("\n Log action PLAYER 1:        %c/ Log action BOT 1:\n", 92);
		i = L1.first;
		j = L2.first;
		while((i <= L1.last) || (j <= L2.last)){
			if (i<= L1.last)
			{
				printf(" - %s ", L1.action[i]);
			}else{
				printf("                             ");
			}
			if (j <= L2.last)
			{
				if(j==0)
					printf("%c/", 92);
				else
					printf("/%c", 92);
				printf(" - %s\n", L2.action[j]);
			}else{
				printf("\n");
			}
			i++;
			j++;
		}
		printf("************************************************************\n");
		printf("* PLAYER 1                   || BOT 1                      *\n");
		printf("************************************************************\n");

		if(temp->H_player < 0)
			/*jika healt player telah habis*/
			temp->H_player = 0;
		printf("* Health : %d/100           ", temp->H_player);
		if(temp->H_player < 10)
			printf("  ");
		else if(temp->H_player < 100)
			printf(" ");

		if(temp->H_bot[1] < 0)
			/*jika healt BOT 1 telah habis*/
			temp->H_bot[1] = 0;
		printf("|| Health : %d/100           ", temp->H_bot[1]);
		if(temp->H_bot[1] < 10)
			printf("  ");
		else if(temp->H_bot[1] < 100)
			printf(" ");

		printf("*\n* Mana   : %d/100           ", temp->M_player);
		if(temp->M_player < 10)
			printf("  ");
		else if(temp->M_player < 100)
			printf(" ");

		printf("|| Mana   : %d/100           ", temp->M_bot[1]);
		if(temp->M_bot[1] < 10)
			printf("  ");
		else if(temp->M_bot[1] < 100)
			printf(" ");
		printf("*\n************************************************************\n");

		printf("\n Log action Bot Ally:        %c/ Log action BOT 2:\n", 92);
		i = L3.first;
		j = L4.first;
		while((i <= L3.last) || (j <= L4.last)){
			if (i<= L3.last)
			{
				printf(" - %s ", L3.action[i]);
			}else{
				printf("                             ");
			}
			if (j <= L4.last)
			{
				if(j==0)
					printf("%c/", 92);
				else
					printf("/%c", 92);
				printf(" - %s\n", L4.action[j]);
			}else{
				printf("\n");
			}
			i++;
			j++;
		}
		printf("************************************************************\n");
		printf("* Bot Ally                   || BOT 2                      *\n");
		printf("************************************************************\n");

		if(temp->H_bot[0] < 0)
			/*jika healt Bot Ally telah habis*/
			temp->H_bot[0] = 0;
		printf("* Health : %d/100           ", temp->H_bot[0]);
		if(temp->H_bot[0] < 10)
			printf("  ");
		else if(temp->H_bot[0] < 100)
			printf(" ");

		if(temp->H_bot[2] < 0)
			/*jika healt Bot Ally telah habis*/
			temp->H_bot[2] = 0;
		printf("|| Health : %d/100           ", temp->H_bot[2]);
		if(temp->H_bot[2] < 10)
			printf("  ");
		else if(temp->H_bot[2] < 100)
			printf(" ");

		printf("*\n* Mana   : %d/100           ", temp->M_bot[0]);
		if(temp->M_bot[0] < 10)
			printf("  ");
		else if(temp->M_bot[0] < 100)
			printf(" ");

		printf("|| Mana   : %d/100           ", temp->M_bot[2]);
		if(temp->M_bot[2] < 10)
			printf("  ");
		else if(temp->M_bot[2] < 100)
			printf(" ");
		printf("*\n************************************************************\n");

		printf("+=========================================================================================+\n");
		printf("| A for Attack Bot 1(Require 30 Mana)        | J for Attack Bot 2(Require 30 Mana)        |\n");
		printf("| S for Super Attack Bot 1 (Require 90 Mana) | K for Super Attack Bot 2 (Require 90 Mana) |\n");
		printf("| D for Heal (Require 30 Mana)               | L for Mega Heal (Require 90 Mana)          |\n");
		printf("+=========================================================================================+\n");

		/*jika ada unit yg healt-nya habis*/
		if(stop == 0){
			/*jika permainan masih dalam tahap berjalan*/
			if((temp->H_player <= 0) && (temp->H_bot[0] <= 0)){
				/*jika semua anggota Blue Team mati*/
				stop = 2; //permainan masuk ke tahap akan diberhentikan
				add("Game Over                ", &L1);
				add("Red Team Win             ", &L1);
				add("Game Over", &L2);
				add("Red Team Win", &L2);
				add("Game Over                ", &L3);
				add("Red Team Win             ", &L3);
				add("Game Over", &L4);
				add("Red Team Win", &L4);
			}
			else if((temp->H_bot[1] <= 0) && (temp->H_bot[2] <= 0)){
				/*jika semua anggota Red Team mati*/
				stop = 2; //permainan masuk ke tahap akan diberhentikan
				add("Game Over                ", &L1);
				add("Blue Team Win            ", &L1);
				add("Game Over", &L2);
				add("Blue Team Win", &L2);
				add("Game Over                ", &L3);
				add("Blue Team Win            ", &L3);
				add("Game Over", &L4);
				add("Blue Team Win", &L4);
			}
		}
		usleep(50000); //tunggu 0.05 detik
	}
	return NULL;
}
//prosedur menambahkan mana
void *incMana(void *arg){
	struct data *temp = (struct data*)arg;
	while(stop == 0){
	/*pengulangan sampai permainan berakhir*/
		for(int i=0; i<3; i++){
			if((temp->M_bot[i] < 100) && (temp->H_bot[i] > 0)){
				pthread_mutex_lock(&lock);
				temp->M_bot[i] += 1; //mana bertambah 1 poin
				pthread_mutex_unlock(&lock);
			}
		}
		if((temp->M_player < 100) && (temp->H_player > 0)){
			pthread_mutex_lock(&lock);
			temp->M_player += 1; //mana bertambah 1 poin
			pthread_mutex_unlock(&lock);
		}
		usleep(250000); //tunggu seperempat detik
	}
}

//prosedur untuk action player
void *action_player(void *arg){
	struct data *temp = (struct data*)arg;
	int c; //untuk menangkap karakter
	struct termios old_tio, new_tio;
	tcgetattr(STDIN_FILENO, &old_tio); //get the terminal setting for stdin
	new_tio = old_tio; //we want to keep the old setting to restore them a the end
	new_tio.c_lflag = ICANON & ECHOE; //disable canonical mode (buffered i/o) and local echo
	tcsetattr(STDIN_FILENO, TCSANOW, &new_tio); //set new setting immediately
	while((stop == 0) && (temp->H_player > 0)){
		/*pengulangan sampai permainan berakhir dan masih memiliki healt lebih dari 0*/
		c = getchar(); //menangkap inputan player
		if(temp->H_player > 0){
			/*jika player masih hidup*/
			if(c == 'a' || c == 'A'){
				/*jika player menyerang bot 1 dengan kekutan biasa*/
				if((temp->M_player >= 30) && (temp->H_bot[1] > 0)){
					/*jika mananya cukup (lebih dari atau sama dengan 30 poin)*/
					add("Attacks BOT 1 in 3       ", &L1);
					sleep(1);
					add("Attacks BOT 1 in 2       ", &L1);
					sleep(1);
					add("Attacks BOT 1 in 1       ", &L1);
					sleep(1);
					pthread_mutex_lock(&lock);
					int act = -1;
					act = rand() % 2;
					if(act == 1){
						add("BOT 1 block the attack   ", &L1);
						add("BOT 1 block attack", &L2);
					}else{
						temp->M_player -= 30; //mengurangi mana player sebesar 30 poin
						temp->H_bot[1] -= 10; //mengurangi healt bot 1 sebesar 10 poin
						add("Attacks BOT 1            ", &L1);
						add("Attacked by PLAYER 1", &L2);
					}
					/*jika BOT 1 mati saat diserang*/
					if(temp->H_bot[1] <= 0){
						add("BOT 1 has died           ", &L1);
						add("BOT 1 has died", &L2);
						add("BOT 1 has died           ", &L3);
						add("BOT 1 has died", &L4);
					}
					pthread_mutex_unlock(&lock);
				}
			}
			else if(c == 's' || c == 'S'){
				/*jika player menyerang bot 1 dengan kekuatan super*/
				if((temp->M_player >= 90) && (temp->H_bot[1] > 0)){
					/*jika mananya cukup (lebih dari atau sama dengan 90 poin)*/
					add("Super attack BOT 1 in 3  ", &L1);
					sleep(1);
					add("Super attack BOT 1 in 2  ", &L1);
					sleep(1);
					add("Super attack BOT 1 in 1  ", &L1);
					sleep(1);
					pthread_mutex_lock(&lock);
					temp->M_player -= 90; //mengurangi mana player sebesar 90 poin
					temp->H_bot[1] -= 35; //mengurangi healt bot 1 sebesar 35 poin
					add("Super attack on BOT 1    ", &L1);
					add("Super attacked by PLAYER 1", &L2);
					/*jika BOT 1 mati saat diserang*/
					if(temp->H_bot[1] <= 0){
						add("BOT 1 has died           ", &L1);
						add("BOT 1 has died", &L2);
						add("BOT 1 has died           ", &L3);
						add("BOT 1 has died", &L4);
					}
					pthread_mutex_unlock(&lock);
				}
			}
			else if(c == 'd' || c == 'D'){
				/*jika player menyembuhkan dirinya*/
				if(temp->M_player >= 30){
					/*jika mananya cukup (lebih dari atau sama dengan 30 poin)*/
					pthread_mutex_lock(&lock);
					temp->M_player -= 30; //mengurangi mana player sebesar 30 poin
					if(temp->H_player < 85){
					/*jika healt player kurang dari 85*/
						temp->H_player += 15; //menambah healt player sebasar 15 poin
						add("Self Healing             ", &L1);
					}
					pthread_mutex_unlock(&lock);
				}
			}
			else if(c == 'j' || c == 'J'){
				/*jika player menyerang bot 2 dengan kekuatan biasa*/
				if((temp->M_player >= 30) && (temp->H_bot[2] > 0)){
					/*jika mananya cukup (lebih dari atau sama dengan 30 poin)*/
					add("Attacks BOT 2 in 3       ", &L1);
					sleep(1);
					add("Attacks BOT 2 in 2       ", &L1);
					sleep(1);
					add("Attacks BOT 2 in 1       ", &L1);
					sleep(1);
					pthread_mutex_lock(&lock);
					int act = -1;
					act = rand() % 2;
					if(act == 1){
						add("BOT 2 block the attack   ", &L1);
						add("BOT 2 block attack", &L4);
					}else{
						temp->M_player -= 30; //mengurangi mana player sebesar 30 poin
						temp->H_bot[2] -= 10; //mengurangi healt bot 2 sebesar 10 poin
						add("Attacks BOT 2            ", &L1);
						add("Attacked by PLAYER 1", &L4);
					}
					/*jika BOT 2 mati saat diserang*/
					if(temp->H_bot[2] <= 0){
						add("BOT 2 has died           ", &L1);
						add("BOT 2 has died", &L2);
						add("BOT 2 has died           ", &L3);
						add("BOT 2 has died", &L4);
					}
					pthread_mutex_unlock(&lock);
				}
			}
			else if(c == 'k' || c == 'K'){
				/*jika player menyerang bot 2 dengan kekuatan super*/
				if((temp->M_player >= 90) && (temp->H_bot[2] > 0)){
					/*jika mananya cukup (lebih dari atau sama dengan 90 poin)*/
					add("Super attack BOT 2 in 3  ", &L1);
					sleep(1);
					add("Super attack BOT 2 in 2  ", &L1);
					sleep(1);
					add("Super attack BOT 2 in 1  ", &L1);
					sleep(1);
					pthread_mutex_lock(&lock);
					temp->M_player -= 90; //mengurangi mana player sebesar 90 poin
					temp->H_bot[2] -= 35; //mengurangi healt bot 2 sebesar 35 poin
					add("Super attack on BOT 2    ", &L1);
					add("Super attacked by PLAYER 1", &L4);
					/*jika BOT 2 mati saat diserang*/
					if(temp->H_bot[2] <= 0){
						add("BOT 2 has died           ", &L1);
						add("BOT 2 has died", &L2);
						add("BOT 2 has died           ", &L3);
						add("BOT 2 has died", &L4);
					}
					pthread_mutex_unlock(&lock);
				}
			}
			else if(c == 'l' || c == 'L'){
				/*jika player melakukan penyembuhan mega*/
				if(temp->M_player >= 90){
					/*jika mananya cukup (lebih dari atau sama dengan 90 poin)*/
					pthread_mutex_lock(&lock);
					/*jika healt player kurang dari 50*/
					temp->M_player -= 90; //mengurangi mana player sebesar 90 poin
					if(temp->H_player < 50){
						temp->H_player += 50; //menambah healt player sebasar 50 poin
						add("Self Mega Healing        ", &L1);
					}
					pthread_mutex_unlock(&lock);
				}
			}
		}
	}
	return NULL;
}

//prosedur untuk action bot ally
void *action_ally(void *arg){
	struct data *temp = (struct data*)arg;
	int act = -1;
	while((stop == 0) && (temp->H_bot[0] > 0)){
		//memilih action
		if(act == -1){
			srand(time(NULL));
			act = rand() % 6;
		}
		//malakukan action
		switch(act){
			case 0:
				/*action: attack BOT 1*/
				if(temp->H_bot[1] > 0){
					/*jika BOT 1 belum mati*/
					if(temp->M_bot[0] >= 30){
						/*jika mananya cukup*/
						add("Attacks BOT 1 in 3     ", &L3);
						sleep(1);
						add("Attacks BOT 1 in 2     ", &L3);
						sleep(1);
						add("Attacks BOT 1 in 1     ", &L3);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[0] > 0){
							/*jika Bot Ally masih hidup*/
							int actr = -1;
							actr = rand() % 2;
							if(actr == 1){
								add("BOT 1 block the attack   ", &L3);
								add("BOT 1 block attack", &L2);
							}else{
								temp->M_bot[0] -= 30;
								temp->H_bot[1] -= 10;
								add("Attacks BOT 1            ", &L3);
								add("Attacked by Bot Ally", &L2);
							}
							/*jika BOT 1 mati saat diserang*/
							if(temp->H_bot[1] <= 0){
								add("BOT 1 has died           ", &L1);
								add("BOT 1 has died", &L2);
								add("BOT 1 has died           ", &L3);
								add("BOT 1 has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika BOT 1 sudah mati*/
					act = -1;
				}
			break;
			case 1:
				/*action: super attack BOT 1*/
				if(temp->H_bot[1] > 0){
					/*jika BOT 1 belum mati*/
					if(temp->M_bot[0] >= 90){
						/*jika mananya cukup*/
						add("Super attack BOT 2 in 3  ", &L3);
						sleep(1);
						add("Super attack BOT 2 in 2  ", &L3);
						sleep(1);
						add("Super attack BOT 2 in 1  ", &L3);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[0] > 0){
							/*jika Bot Ally masih hidup*/
							temp->M_bot[0] -= 90;
							temp->H_bot[1] -= 35;
							add("Super attack on BOT 1    ", &L3);
							add("Super attacked by Bot Ally", &L2);
							/*jika BOT 1 mati saat diserang*/
							if(temp->H_bot[1] <= 0){
								add("BOT 1 has died           ", &L1);
								add("BOT 1 has died", &L2);
								add("BOT 1 has died           ", &L3);
								add("BOT 1 has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika BOT 1 sudah mati*/
					act = -1;
				}
			break;
			case 2:
				/*action: attack BOT 2*/
				if(temp->H_bot[2] > 0){
					/*jika BOT 2 belum mati*/
					if(temp->M_bot[0] >= 30){
						/*jika mananya cukup*/
						add("Super attack BOT 2 in 3  ", &L3);
						sleep(1);
						add("Super attack BOT 2 in 2  ", &L3);
						sleep(1);
						add("Super attack BOT 2 in 1  ", &L3);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[0] > 0){
							/*jika Bot Ally masih hidup*/
							int actr = -1;
							actr = rand() % 2;
							if(actr == 1){
								add("BOT 2 block attack", &L4);
								add("BOT 2 block the attack   ", &L3);
							}else{
								temp->M_bot[0] -= 30;
								temp->H_bot[2] -= 10;
								add("Attacks BOT 2            ", &L3);
								add("Attacked by Bot Ally", &L4);
							}
							/*jika BOT 2 mati saat diserang*/
							if(temp->H_bot[2] <= 0){
								add("BOT 2 has died           ", &L1);
								add("BOT 2 has died", &L2);
								add("BOT 2 has died           ", &L3);
								add("BOT 2 has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika BOT 2 sudah mati*/
					act = -1;
				}
			break;
			case 3:
				/*action: super attack BOT 2*/
				if(temp->H_bot[2] > 0){
					/*jika BOT 2 belum mati*/
					if(temp->M_bot[0] >= 90){
						/*jika mananya cukup*/
						add("Super attack BOT 2 in 3  ", &L3);
						sleep(1);
						add("Super attack BOT 2 in 2  ", &L3);
						sleep(1);
						add("Super attack BOT 2 in 1  ", &L3);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[0] > 0){
							/*jika Bot Ally masih hidup*/
							temp->M_bot[0] -= 90;
							temp->H_bot[2] -= 35;
							add("Super attack on BOT 2    ", &L3);
							add("Super attacked by Bot Ally", &L4);
							/*jika BOT 2 mati saat diserang*/
							if(temp->H_bot[2] <= 0){
								add("BOT 2 has died           ", &L1);
								add("BOT 2 has died", &L2);
								add("BOT 2 has died           ", &L3);
								add("BOT 2 has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika BOT 2 sudah mati*/
					act = -1;
				}
			break;
			case 4:
				/*action: heal*/
				if(temp->H_bot[0] <= 85){
					/*jika healt kurang dari atau sama dengan 85*/
					if(temp->M_bot[0] >= 30){
						/*jika mananya cukup*/
						pthread_mutex_lock(&lock);
						if(temp->H_bot[0] > 0){
							/*jika Bot Ally masih hidup*/
							temp->M_bot[0] -= 30;
							temp->H_bot[0] += 15;
							add("Self Healing             ", &L3);
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika healt lebih dari 85*/
					act = -1;
				}
			break;
			case 5:
				/*action: mega heal*/
				if(temp->H_bot[0] <= 50 ){
					/*jika healt kurang dari atau sama dengan 50*/
					if(temp->M_bot[0] >= 90){
						/*jika mananya cukup*/
						pthread_mutex_lock(&lock);
						if(temp->H_bot[0] > 0){
							/*jika Bot Ally masih hidup*/
							temp->M_bot[0] -= 90;
							temp->H_bot[0] += 50;
							add("Self Mega Healing        ", &L3);
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika healt lebih dari 50*/
					act = -1;
				}
			break;
		}
	}
	return NULL;
}

//prosedur untuk action bot enemy1
void *action_enm1(void *arg){
	struct data *temp = (struct data*)arg;
	int act = -1;
	while((stop == 0) && (temp->H_bot[1] > 0)){
		//memilih action
		if(act == -1){
			srand(time(NULL));
			act = rand() % 6;
		}
		//malakukan action
		switch(act){
			case 0:
				/*action: attack PLAYER 1*/
				if(temp->H_player > 0){
					/*jika PLAYER 1 belum mati*/
					if(temp->M_bot[1] >= 30){
						/*jika mananya cukup*/
						add("Attacks PLAYER 1 in 3", &L2);
						sleep(1);
						add("Attacks PLAYER 1 in 2", &L2);
						sleep(1);
						add("Attacks PLAYER 1 in 1", &L2);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[1] > 0){
							/*jika BOT 1 masih hidup*/
							temp->M_bot[1] -= 30;
							temp->H_player -= 10;
							add("Attacks PLAYER 1", &L2);
							add("Attacked by BOT 1        ", &L1);
							/*jika PLAYER 1 mati saat diserang*/
							if(temp->H_player <= 0){
								add("PLAYER 1 has died        ", &L1);
								add("PLAYER 1 has died", &L2);
								add("PLAYER 1 has died        ", &L3);
								add("PLAYER 1 has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika PLAYER 1 sudah mati*/
					act = -1;
				}
			break;
			case 1:
				/*action: super attack PLAYER 1*/
				if(temp->H_player > 0){
					/*jika PLAYER 1 belum mati*/
					if(temp->M_bot[1] >= 90){
						/*jika mananya cukup*/
						add("Super attack PLAYER 1 in 3  ", &L2);
						sleep(1);
						add("Super attack PLAYER 1 in 2  ", &L2);
						sleep(1);
						add("Super attack PLAYER 1 in 1  ", &L2);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[1] > 0){
							/*jika BOT 1 masih hidup*/
							temp->M_bot[1] -= 90;
							temp->H_player -= 35;
							add("Super attack on PLAYER 1", &L2);
							add("Super attacked by BOT 1  ", &L1);
							/*jika PLAYER 1 mati saat diserang*/
							if(temp->H_player <= 0){
								add("PLAYER 1 has died        ", &L1);
								add("PLAYER 1 has died", &L2);
								add("PLAYER 1 has died        ", &L3);
								add("PLAYER 1 has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika PLAYER 1 sudah mati*/
					act = -1;
				}
			break;
			case 2:
				/*action: attack BOT Ally*/
				if(temp->H_bot[0] > 0){
					/*jika Bot Ally belum mati*/
					if(temp->M_bot[1] >= 30){
						/*jika mananya cukup*/
						add("Attacks Bot Ally in 3", &L2);
						sleep(1);
						add("Attacks Bot Ally in 2", &L2);
						sleep(1);
						add("Attacks Bot Ally in 1", &L2);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[1] > 0){
							/*jika BOT 1 masih hidup*/
							temp->M_bot[1] -= 30;
							temp->H_bot[0] -= 10;
							add("Attacks Bot Ally", &L2);
							add("Attacked by BOT 1        ", &L3);
							/*jika Bot Ally mati saat diserang*/
							if(temp->H_bot[0] <= 0){
								add("Bot Ally has died        ", &L1);
								add("Bot Ally has died", &L2);
								add("Bot Ally has died        ", &L3);
								add("Bot Ally has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika Bot Ally sudah mati*/
					act = -1;
				}
			break;
			case 3:
				/*action: super attack Bot Ally*/
				if(temp->H_bot[0] > 0){
					/*jika Bot Ally belum mati*/
					if(temp->M_bot[1] >= 90){
						/*jika mananya cukup*/
						add("Super attack Bot Ally in 3  ", &L2);
						sleep(1);
						add("Super attack Bot Ally in 2  ", &L2);
						sleep(1);
						add("Super attack Bot Ally in 1  ", &L2);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[1] > 0){
							/*jika BOT 1 masih hidup*/
							temp->M_bot[1] -= 90;
							temp->H_bot[0] -= 35;
							add("Super attack on Bot Ally", &L2);
							add("Super attacked by BOT 1  ", &L3);
							/*jika Bot Ally mati saat diserang*/
							if(temp->H_bot[0] <= 0){
								add("Bot Ally has died        ", &L1);
								add("Bot Ally has died", &L2);
								add("Bot Ally has died        ", &L3);
								add("Bot Ally has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika Bot Ally sudah mati*/
					act = -1;
				}
			break;
			case 4:
				/*action: heal*/
				if(temp->H_bot[1] <= 85){
					/*jika healt kurang dari atau sama dengan 85*/
					if(temp->M_bot[1] >= 30){
						/*jika mananya cukup*/
						pthread_mutex_lock(&lock);
						if(temp->H_bot[1] > 0){
							/*jika BOT 1 masih hidup*/
							temp->M_bot[1] -= 30;
							temp->H_bot[1] += 15;
							add("Self Healing", &L2);
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika healt lebih dari 85*/
					act = -1;
				}
			break;
			case 5:
				/*action: mega heal*/
				if(temp->H_bot[1] <= 50 ){
					/*jika healt kurang dari atau sama dengan 50*/
					if(temp->M_bot[1] >= 90){
						/*jika mananya cukup*/
						pthread_mutex_lock(&lock);
						if(temp->H_bot[1] > 0){
							/*jika BOT 1 masih hidup*/
							temp->M_bot[1] -= 90;
							temp->H_bot[1] += 50;
							add("Self Mega Healing", &L2);
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika healt lebih dari 50*/
					act = -1;
				}
			break;
		}
	}
	return NULL;
}

//prosedur untuk action bot enemy2
void *action_enm2(void *arg){
	struct data *temp = (struct data*)arg;
	int act = -1;
	while((stop == 0) && (temp->H_bot[2] > 0)){
		//memilih action
		if(act == -1){
			srand(time(NULL));
			act = rand() % 6;
		}
		//malakukan action
		switch(act){
			case 0:
				/*action: attack PLAYER 1*/
				if(temp->H_player > 0){
					/*jika PLAYER 1 belum mati*/
					if(temp->M_bot[2] >= 30){
						/*jika mananya cukup*/
						add("Atacks PLAYER 1 in 3", &L4);
						sleep(1);
						add("Atacks PLAYER 1 in 2", &L4);
						sleep(1);
						add("Atacks PLAYER 1 in 1", &L4);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[2] > 0){
							/*jika BOT 2 masih hidup*/
							temp->H_player -= 10;
							temp->M_bot[2] -= 30;
							add("Atacks PLAYER 1", &L4);
							add("Attacked by BOT 2        ", &L1);
							/*jika PLAYER 1 mati saat diserang*/
							if(temp->H_player <= 0){
								add("PLAYER 1 has died        ", &L1);
								add("PLAYER 1 has died", &L2);
								add("PLAYER 1 has died        ", &L3);
								add("PLAYER 1 has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika PLAYER 1 sudah mati*/
					act = -1;
				}
			break;
			case 1:
				/*action: super attack PLAYER 1*/
				if(temp->H_player > 0){
					/*jika PLAYER 1 belum mati*/
					if(temp->M_bot[2] >= 90){
						/*jika mananya cukup*/
						add("Super attack PLAYER 1 in 3  ", &L4);
						sleep(1);
						add("Super attack PLAYER 1 in 2  ", &L4);
						sleep(1);
						add("Super attack PLAYER 1 in 1  ", &L4);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[2] > 0){
							/*jika BOT 2 masih hidup*/
							temp->M_bot[2] -= 90;
							temp->H_player -= 35;
							add("Super attack on PLAYER 1", &L4);
							add("Super attacked by BOT 2  ", &L1);
							/*jika PLAYER 1 mati saat diserang*/
							if(temp->H_player <= 0){
								add("PLAYER 1 has died        ", &L1);
								add("PLAYER 1 has died", &L2);
								add("PLAYER 1 has died        ", &L3);
								add("PLAYER 1 has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika PLAYER 1 sudah mati*/
					act = -1;
				}
			break;
			case 2:
				/*action: attack BOT Ally*/
				if(temp->H_bot[0] > 0){
					/*jika Bot Ally belum mati*/
					if(temp->M_bot[2] >= 30){
						/*jika mananya cukup*/
						add("Attacks Bot Ally in 3", &L4);
						sleep(1);
						add("Attacks Bot Ally in 2", &L4);
						sleep(1);
						add("Attacks Bot Ally in 1", &L4);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[2] > 0){
							/*jika BOT 2 masih hidup*/
							temp->M_bot[2] -= 30;
							temp->H_bot[0] -= 10;
							add("Attacks Bot Ally", &L4);
							add("Attacked by BOT 2        ", &L3);
							/*jika Bot Ally mati saat diserang*/
							if(temp->H_bot[0] <= 0){
								add("Bot Ally has died        ", &L1);
								add("Bot Ally has died", &L2);
								add("Bot Ally has died        ", &L3);
								add("Bot Ally has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika Bot Ally sudah mati*/
					act = -1;
				}
			break;
			case 3:
				/*action: super attack Bot Ally*/
				if(temp->H_bot[0] > 0){
					/*jika Bot Ally belum mati*/
					if(temp->M_bot[2] >= 90){
						/*jika mananya cukup*/
						add("Super attack Bot Ally in 3  ", &L4);
						sleep(1);
						add("Super attack Bot Ally in 2  ", &L4);
						sleep(1);
						add("Super attack Bot Ally in 1  ", &L4);
						sleep(1);
						pthread_mutex_lock(&lock);
						if(temp->H_bot[2] > 0){
							/*jika BOT 2 masih hidup*/
							temp->M_bot[2] -= 90;
							temp->H_bot[0] -= 35;
							add("Super attack on Bot Ally", &L4);
							add("Super attack by Bot Ally ", &L3);
							/*jika Bot Ally mati saat diserang*/
							if(temp->H_bot[0] <= 0){
								add("Bot Ally has died        ", &L1);
								add("Bot Ally has died", &L2);
								add("Bot Ally has died        ", &L3);
								add("Bot Ally has died", &L4);
							}
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika Bot Ally sudah mati*/
					act = -1;
				}
			break;
			case 4:
				/*action: heal*/
				if(temp->H_bot[2] <= 85){
					/*jika healt kurang dari atau sama dengan 85*/
					if(temp->M_bot[2] >= 30){
						/*jika mananya cukup*/
						pthread_mutex_lock(&lock);
						if(temp->H_bot[2] > 0){
							/*jika BOT 2 masih hidup*/
							temp->M_bot[2] -= 30;
							temp->H_bot[2] += 15;
							add("Self Healing", &L4);
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika healt lebih dari 85*/
					act = -1;
				}
			break;
			case 5:
				/*action: mega heal*/
				if(temp->H_bot[2] <= 50 ){
					/*jika healt kurang dari atau sama dengan 50*/
					if(temp->M_bot[2] >= 90){
						/*jika mananya cukup*/
						pthread_mutex_lock(&lock);
						if(temp->H_bot[2] > 0){
							/*jika BOT 2 masih hidup*/
							temp->M_bot[2] -= 90;
							temp->H_bot[2] += 50;
							add("Self Mega Healing", &L4);
						}
						pthread_mutex_unlock(&lock);
						act = -1;
					}
				}
				else{
					/*jika healt lebih dari 50*/
					act = -1;
				}
			break;
		}
	}
	return NULL;
}

//membuat log kosong
void crtEmpty(log *L){
	(*L).first = -1;
	(*L).last = -1;
}

//prosedur del log action terlama jika sudah penuh
void del(log *L){
	if((*L).last == 0){
		/*jika log berisi 1 elemen*/
		(*L).first = -1;
		(*L).last = -1;
	}
	else{
		/*jika log berisi lebih dari 1 elemen*/
		if((*L).first != -1){
			/*jika log tidak kosong*/
			int i;
			/*menggeser elemen ke depan*/
			for(i=((*L).first+1); i<=(*L).last; i++){
				strcpy((*L).action[i-1], (*L).action[i]);
			}
			(*L).last = (*L).last-1;
		}
	}
}

//prosedur add ke log action
void add(char action[], log *L){
	if((*L).first == -1){
		/*jika log kosong*/
		(*L).first = 0;
		(*L).last = 0;
		strcpy((*L).action[0], action);
	}
	else{
		/*jika log tidak kosong*/
		if((*L).last == 2)
			del(L);
		(*L).last += 1;
		strcpy((*L).action[(*L).last], action);
	}
}