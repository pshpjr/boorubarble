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
	int class;//1: 도시, 2: 관광지, 3: 열쇠, 4: 무인도, 5: 콩코드, 6:엘리자베스 , 7: 콜롬비아호 8: 복지기금 수령, 9 복지기금 기부, 우주여행 10
}city;
typedef struct player {
	int location;
	int money;

}player;

int boad_size = 20;
city boad[40]= {//도시명, 땅값, 모텔, 호텔, 빌딩 건축비, 총 금액, 지주, 범주; 통행료는 건축비*2로 통일
{"타이베이",5,1,9,25,0,0,1},{"열쇠",0,0,0,0,0,0,3},{"베이징",8,2,18,45,0,0,1},{"마닐라",8,2,18,25,0,0,1},{"제주",20,0,0,0,30,0,2},{"싱가포르",10,3,27,55,0,0,1},{"열쇠",-1,0,0,0,0,0,3},{"카이로",10,3,27,55,0,0,1},{"이스탄불",12,4,30,60,0,0,1},{"무인도",-2,0,0,0,0,0,4},
{"아테네",14,5,45,75,0,0,1},{"열쇠",0,0,0,0,0,0,3},{"코펜하겐",16,6,50,90,0,0,1},{"스톡홀름",6,6,50,90,0,0,1},{"콩코드",20,0,0,30,0,5},{"취리히",18,7,50,95,0,0,1},{"열쇠",0,0,0,0,0,3},{"베를린",18,7,50,95,0,0,1},{"몬트리올",20,8,55,100,0,0,1},{"복지기금",0,0,0,0,0,0,8}
,{"부에노스아이레스",22,9,70,105,0,0,2},{"열쇠",0,0,0,0,0,0,3},{"상파울로",24,10,75,110,0,0,1},{"시드니",24,10,75,110,0,0,1},{"부산",50,0,0,0,60,0,2},{"하와이",26,11,80,115,0,0,1},{"리스본",26,11,80,115,0,0,1},{"퀸엘리자베스",30,0,0,0,25,0,7},{"마드리드",28,12,85,120,0,0,1},{"우주여행",0,0,0,0,0,10},
{"도쿄",30,13,90,127,0,0,1},{"콜롬비아",45,0,0,0,20,0,7},{"파리",32,15,100,900,0,0,1},{"로마",32,15,100,900,0,0,1},{"열쇠",0,0,0,0,0,0,3},{"런던",35,17,110,150,0,0,1},{"뉴욕",35,17,110,150,0,0,1},{"복지기금",0,0,0,0,0,0,9},{"서울",0,0,0,0,0,0,2},
};
int Total_player;

void slash();
void title();
diceResult dice();
void changeOwner(city *city, int owner);
void changeMoney(player *player, int delta);
void changeTotalPrice(city* city, int price);

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
void changeTotalPrice(city* city, int price)
{
	city->totalPrice += price;

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