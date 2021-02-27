#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "synergy.h"
#define STRING_SIZE 512

int signal[27] = { 0, };
int SynergyNum[27] = { 0, };
const char * synergy[27] = { "없음", "광신도", "나무정령", "닌자", "달빛", "대장군", "번뇌","선지자","신성","영혼","우두머리","추방자","행운","황혼","결투가","귀감","그림자","명사수","사냥꾼","선봉대","신비술사","싸움꾼","암살자","요술사","조율자","현혹술사","황제" };
int trait[27] = { 0, };
struct recommend {
	char name[100];
	int SynNum[3];
};

struct recommend Recommend[58] = { 0, };


struct NODE {
	int firstSynergy;			// 첫 번째 시너지
	int secondSynergy;			// 두 번째 시너지
	int thirdSynergy;			// 세 번째 시너지

	char name[100];		// 챔피언 이름
	struct NODE* next;	// 다음 노드
};

int overlap(struct NODE* head, char* name) { // 중복된 챔프 추천 명단에서 제거
	struct NODE* temp = head->next;

	while (temp != NULL) {
		if (!strcmp(temp->name, name)) {
			return 1;
		}


		temp = temp->next;
	}
	return 0;
}

void recommendChampion(int* trait, int* SynergyNum, struct NODE* head,struct NODE * My) {
	for (int i = 0; i < 58; i++) {
		memset(Recommend[i].name, NULL, sizeof(char) * 100);
		Recommend[i].SynNum[0] = 0;
		Recommend[i].SynNum[1] = 0;
		Recommend[i].SynNum[2] = 0;
	}

	struct NODE* recommend = head->next;
	int count = 0; // 추천 챔피언 명단 배열을 위한 count


	while (recommend != NULL) {
		if (overlap(My, recommend->name) == 1) {
			recommend = recommend->next;
			continue;
		}

		int temp[27] = { 0, }; // 추천을 위한 챔피언 특성 임시 배열
		memmove(temp, trait, sizeof(int) * 27); // trait 를 temp 로 옮김
		char* tmp = recommend->name;
		ChampionSynergy(signal, temp, tmp);
		
		int ChSynergy[27] = { 0, }; // 업데이트 된 시너지
		int cnt = 0; // 추가되거나 강화되는 시너지 정보를 담기 위한 배열의 index 카운트
		
		SetSynergyNum(temp, ChSynergy);
		
		for (int i = 1; i <= 26; i++) { // 시너지가 하나라도 추가된 것이 있다면 챔피언 추천
			if (SynergyNum[i] != ChSynergy[i]) {
				strcpy(Recommend[count].name, recommend->name);				
				Recommend[count].SynNum[cnt] = i;
				cnt++;
			}
		}
				
		recommend = recommend->next;
		count++;
	}
	printf("추천해드릴 챔피언 명단은 다음과 같습니다.(설명) [번호. 챔피언 명 / 추가되거나 강화되는 시너지 명]\n");
	printf("=================================================================================\n");
	int num = 1;
	for(int j=0; j<58; j++){
		if (strlen(Recommend[j].name)==0) {
			continue;
		}
		printf("%d. %s : ", num, Recommend[j].name);
		for (int i = 0; i < 3; i++) {
			if (Recommend[j].SynNum[i] == 0) {
				break;
			}
			printf("%s, ", synergy[Recommend[j].SynNum[i]]);
		}
		printf("\n");
		num++;
	}
}

void LoadChampionList(struct NODE* head) {
	FILE* myFile;
	fopen_s(&myFile, "champion.txt", "r"); // 파일 구조체 포인터 및 champion.txt 파일을 읽기 모드로 열기

	char buffer[STRING_SIZE]; // 파일로부터 가져온 문자를 임시로 저장 할 buffer

	struct NODE* Curr = head;
	Curr->next = NULL;

	while (!feof(myFile)) {
		struct NODE* Champion = malloc(sizeof(struct NODE));

		fgets(buffer, sizeof(buffer), myFile);

		char* ptr = strtok(buffer, " \t");

		if (ptr != NULL)
			strcpy(Champion->name, ptr);

		ptr = strtok(NULL, " \t");
		if (ptr != NULL)
			Champion->firstSynergy = atoi(ptr);

		ptr = strtok(NULL, " \t");
		if (ptr != NULL)
			Champion->secondSynergy = atoi(ptr);

		ptr = strtok(NULL, " \t");
		if (ptr != NULL) {
			Champion->thirdSynergy = atoi(ptr);
		}
		else {
			Champion->thirdSynergy = 0;
		}
		Champion->next = NULL;
		Curr->next = Champion;
		Curr = Curr->next;

	}
	fclose(myFile);
}

void PrintALLChampionList(struct NODE* head) {
	struct NODE* print = head->next;
	while (print != NULL) {
		if (print->thirdSynergy != 0) {
			printf("%s ( %s, %s, %s )\n", print->name, synergy[print->firstSynergy], synergy[print->secondSynergy], synergy[print->thirdSynergy]);
		}
		else {
			printf("%s ( %s, %s )\n", print->name, synergy[print->firstSynergy], synergy[print->secondSynergy]);
		}
		print = print->next;

	}
}

void InputMyChampionList(struct NODE* head) {
	int n;
	char champ[100] = { '\0' };
	printf("챔피언의 수를 입력해주세요 : ");
	scanf_s("%d", &n, sizeof(n));
		
	printf("챔피언 명을 입력해주세요. \n");
	struct NODE* MyList = head;
	for (int i = 0; i < n; i++) {
		printf("%d. ", i + 1);
		scanf_s("%s", champ, sizeof(champ));
		
		if (ChampionSynergy(signal, trait, champ) == -1) {
			i--;
			continue;
		}
		
		struct NODE* IN = malloc(sizeof(struct NODE));
		IN->next = NULL;
		strcpy(IN->name, champ);
		for (int i = 1; i < 27; i++) {
			if (signal[i] != 0) {
				signal[i] = 0;
				IN->firstSynergy = i;
				break;
			}
		}

		for (int i = 1; i < 27; i++) {
			if (signal[i] != 0) {
				signal[i] = 0;
				IN->secondSynergy = i;
				break;
			}
		}
		IN->thirdSynergy = 0;
		for (int i = 1; i < 27; i++) {
			if (signal[i] != 0) {
				signal[i] = 0;
				IN->thirdSynergy = i;
				break;
			}
		}

		MyList->next = IN;
		MyList = MyList->next;
	}
}

int PrintMyChampionList(struct NODE* head) {
	if (head == NULL) {
		return 0;
	}
	
	struct NODE* print = head->next;

	

	while (print != NULL) {
		if (print->thirdSynergy != 0) {
			printf("%s ( %s, %s, %s )\n", print->name, synergy[print->firstSynergy], synergy[print->secondSynergy], synergy[print->thirdSynergy]);
		}
		else {
			printf("%s ( %s, %s )\n", print->name, synergy[print->firstSynergy], synergy[print->secondSynergy]);
		}
		print = print->next;

	}
	return 1;
}

int main(void) {
	
	for (int i = 0; i < 58; i++) {
		memset(Recommend[i].name, NULL, sizeof(char) * 100);
		Recommend[i].SynNum[0] = 0;
		Recommend[i].SynNum[1] = 0;
		Recommend[i].SynNum[2] = 0;
	}

	char command[100];
	struct NODE* AllChampionListHead = malloc(sizeof(struct NODE)); // 모든 챔피언 목록을 만들기 위한 Linked List의 Head
	struct NODE* UserChampionListHead = malloc(sizeof(struct NODE));// 유저의 챔피언 목록을 만들기 위한 Linked List의 Head
	int LimitLoad = 0; // LOAD 횟수 제한
	int LimitChamp = 0; // MYCHAMPION 횟수 제한
	while (1) {
		
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("------------------------------------------ COMMAND LIST ------------------------------------------\n");
		printf("LOAD : 텍스트 파일에 저장되어 있는 모든 챔피언의 정보들을 읽어 링크드 리스트를 구성한다.\n");
		printf("PRINTALL : 현재 게임에 존재하는 모든 챔피언에 대한 정보를 출력한다.\n");
		printf("MYCHAMPION : User로 부터 보유한 챔피언 정보를 입력 받고 링크드 리스트를 구성한다.\n");
		printf("PRINTMY : User가 가지고 있는 모든 챔피언의 정보를 출력한다.\n");
		printf("MYSYNERGY : User가 가지고 있는 Synergy 정보를 출력한다.\n");
		printf("RECOMMEND : 현재 상황에 맞는 추천 챔피언 명단을 출력한다.\n");
		printf("EXIT : 프로그램을 종료한다.\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("위 설명을 참고하여 실행하고자 하는 COMMAND를 입력해주세요 : ");

		scanf_s("%s", command,sizeof(command));

		int fileCon;								// 파일의 정상적인 닫힘을 확인하기 위한 시그널
		
		if (!strcmp(command,"LOAD") && LimitLoad<1) {
			LoadChampionList(AllChampionListHead);
			LimitLoad++;
		}
		else if (!strcmp(command, "LOAD") && LimitLoad >= 1) {
			printf("LOAD는 한 번만 가능합니다.\n");
		}
		else if(!strcmp(command, "PRINTALL")) {
			PrintALLChampionList(AllChampionListHead);
		}
		else if (!strcmp(command, "MYCHAMPION") && LimitChamp < 1) {
			InputMyChampionList(UserChampionListHead);
			LimitChamp++;
		}
		else if (!strcmp(command, "MYCHAMPION")&&LimitChamp>=1) {
			printf("MYCHAMPION은 한 번만 가능합니다.\n");
		}
		else if (!strcmp(command, "PRINTMY")) {
			if (PrintMyChampionList(UserChampionListHead) == 0) {
				printf("입력 된 챔피언 정보가 없습니다.\n");
				continue;
			}
		}
		else if (!strcmp(command, "MYSYNERGY")) {
			SetSynergyNum(trait, SynergyNum);
			for (int i = 1; i < 27; i++) {
				if (SynergyNum[i] != 0) {
					printf("%s : %d(%d)\n", synergy[i], SynergyNum[i],trait[i]);
				}
			}			
		}
		else if (!strcmp(command, "RECOMMEND")) {
			recommendChampion(trait, SynergyNum, AllChampionListHead, UserChampionListHead);
		}
		else if (!strcmp(command, "EXIT")) {
			printf("프로그램 종료\n");
			return 0;
		}
		else {
			printf("정의되지 않은 COMMAND 입니다. 프로그램을 다시 실행해주세요.\n");
			break;
		}
		
		
		getchar();											// 입력 버퍼 비우기
	}

	free(AllChampionListHead);
	free(UserChampionListHead);
	return 0;
}