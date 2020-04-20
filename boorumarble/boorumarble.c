#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <time.h>
typedef struct diceResult {
	int dice1;
	int dice2;
}diceResult;
typedef struct city {
	char name[20];
	int landPrice;
	int motelPrice;
	int hotelPrice;
	int buildingPrice;
	int totalPrice;
	int owner;

}city;
typedef struct player {
	int location;
	int money;

}player;

int boad_size = 20;
city boad[40]= {
{"타이베이",0,0,0,0,0,0},{"열쇠",0,0,0,0,0,0},{"베이징",0,0,0,0,0,0},{"마닐라",0,0,0,0,0,0},{"제주",0,0,0,0,0,0},{"싱가포르",0,0,0,0,0,0},{"열쇠",0,0,0,0,0,0},{"카이로",0,0,0,0,0,0},{"이스탄불",0,0,0,0,0,0},{"무인도",0,0,0,0,0,0},
{"아테네",0,0,0,0,0,0},{"열쇠",0,0,0,0,0,0},{"코펜하겐",0,0,0,0,0,0},{"스톡홀름",0,0,0,0,0,0},{"콩코드",0,0,0,0,0,0},{"베른",0,0,0,0,0,0},{"열쇠",0,0,0,0,0,0},{"베를린",0,0,0,0,0,0},{"오타와",0,0,0,0,0,0},{"복지기금",0,0,0,0,0,0}
,{"부에노스아이레스",0,0,0,0,0,0},{"열쇠",0,0,0,0,0,0},{"상파울로",0,0,0,0,0,0},{"시드니",0,0,0,0,0,0},{"부산",0,0,0,0,0,0},{"하와이",0,0,0,0,0,0},{"리스본",0,0,0,0,0,0},{"퀸엘리자베스",0,0,0,0,0,0},{"마드리드",0,0,0,0,0,0},{"우주여행",0,0,0,0,0,0},
{"도쿄",0,0,0,0,0,0},{"콜롬비아",0,0,0,0,0,0},{"파리",0,0,0,0,0,0},{"로마",0,0,0,0,0,0},{"뉴욕",0,0,0,0,0,0},{"복지기금",0,0,0,0,0,0},{"서울",0,0,0,0,0,0},
};
int Total_player;

void slash();
void title();
diceResult dice();
void changeOwner(city *city, int owner);
void changeMoney(player *player, int delta);
void changePrice(city* city, int structure);
void turn(player* player);
void move(player* player, diceResult dice);
void reset();
int main() {
	
	title();

	player player1 = {0,1000};

	while (1) {

		turn(&player1);
	}

	
}

void slash() {
	for (int i = 0; i < boad_size;i++) printf("/");
	printf("\n");

}

void title() {
	slash();
	printf("\n브루마블 게임\n");
	printf("\n플레이어 수 입력\n");
	slash();
}
diceResult dice() {
	srand(time(0));
	diceResult new;
	new.dice1 = rand() % 6 + 1;
	new.dice2 = rand() % 6 + 1;
	return new;
}
void changeOwner(city* city, int owner)
{
	city->owner = owner;
}
void changeMoney(player* player, int delta)
{
	player->money += delta;

}
void changePrice(city* city, int structure)
{
	switch (structure){
	case 1:
		city->totalPrice += city->landPrice;
		break;
	case 2:
		city->totalPrice += city->motelPrice;
		break;
	case 3:
		city->totalPrice += city->hotelPrice;
		break;
	case 4:
		city->totalPrice += city->buildingPrice;
		break;
	}
}
void turn(player *player)
{
	diceResult new;
	printf("주사위를 던집니다\n");
	getchar();
	new = dice();
	move(player, new);
	printf("%s에 도착했습니다\n", boad[player->location].name);
}
void move(player *player,diceResult dice) {
	int count = dice.dice1 + dice.dice2;
	printf("%d가 나왔습니다\n",count);
	player->location = (player->location + count) % boad_size;
}
void reset() {


}