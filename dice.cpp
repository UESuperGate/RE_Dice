#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define target 3664449
#define ind 0x3f

unsigned char flag1[]={0x59,0x2C,0x5E,0x58,0x3B,0x46,0x70,0x4A,0x1F,0xB,0x2E,0x2F,0x17,0x1F,0x8,0x28,0x73,0x60,0x6C,0xC,0x5C,0x4D,0x5A,0x8,0x60,0xF,0x79,0x60,0x4D,0xC,0x49,0xC,0x4D,0x33,0xE,0x51,0x27,0x42};
unsigned char flag2[38];

void UI(){
	printf("Play the game?\n");
	printf("1. Yes, I want to challenge!\n");
	printf("2. No, I am just a loser...\n");
	printf("Input your choice:\n");
}

int f(int a){
	if(a&1)return a*100+10100000;
	if(a<=10000)return a+2;
	return ((a<<5)+(a^1));
}

void put_flag(int a){
	for(int i=0;i<38;i++)flag2[i]=flag1[i]^(ind+((a&(1u<<i))>>i));
	printf("You must cheat in the game! flag: %s\n",flag2);
	exit(0);
}

int main(){
	printf("Guess the number of the dice, and you can get the score!\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	int score=0,choice,guess;
	srand(time(NULL));
	while(1){
		UI();
		scanf("%d",&choice);
		if(choice==2){
			printf("Loser!\n");
			return 0;
		}
		printf("Try to guess the number on the top of the dice:");
		scanf("%d",&guess);
		if(guess>6||guess<1){
			printf("Are you kidding?\n");
			return 0;
		}
		if(guess==rand()%6+1){
			score++;
			printf("Nice!\n");
		}
		else printf("Sorry...\n");
		printf("Now you have got %d points. Cheer up!\n",score);
		if(f(score)==target)put_flag(score);
		printf("=================================================\n");
	}
}
