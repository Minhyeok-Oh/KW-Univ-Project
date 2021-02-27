#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "synergy.h"
#define STRING_SIZE 512

int signal[27] = { 0, };
int SynergyNum[27] = { 0, };
const char * synergy[27] = { "����", "���ŵ�", "��������", "����", "�޺�", "���屺", "����","������","�ż�","��ȥ","��θӸ�","�߹���","���","Ȳȥ","������","�Ͱ�","�׸���","����","��ɲ�","������","�ź����","�ο��","�ϻ���","�����","������","��Ȥ����","Ȳ��" };
int trait[27] = { 0, };
struct recommend {
	char name[100];
	int SynNum[3];
};

struct recommend Recommend[58] = { 0, };


struct NODE {
	int firstSynergy;			// ù ��° �ó���
	int secondSynergy;			// �� ��° �ó���
	int thirdSynergy;			// �� ��° �ó���

	char name[100];		// è�Ǿ� �̸�
	struct NODE* next;	// ���� ���
};

int overlap(struct NODE* head, char* name) { // �ߺ��� è�� ��õ ��ܿ��� ����
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
	int count = 0; // ��õ è�Ǿ� ��� �迭�� ���� count


	while (recommend != NULL) {
		if (overlap(My, recommend->name) == 1) {
			recommend = recommend->next;
			continue;
		}

		int temp[27] = { 0, }; // ��õ�� ���� è�Ǿ� Ư�� �ӽ� �迭
		memmove(temp, trait, sizeof(int) * 27); // trait �� temp �� �ű�
		char* tmp = recommend->name;
		ChampionSynergy(signal, temp, tmp);
		
		int ChSynergy[27] = { 0, }; // ������Ʈ �� �ó���
		int cnt = 0; // �߰��ǰų� ��ȭ�Ǵ� �ó��� ������ ��� ���� �迭�� index ī��Ʈ
		
		SetSynergyNum(temp, ChSynergy);
		
		for (int i = 1; i <= 26; i++) { // �ó����� �ϳ��� �߰��� ���� �ִٸ� è�Ǿ� ��õ
			if (SynergyNum[i] != ChSynergy[i]) {
				strcpy(Recommend[count].name, recommend->name);				
				Recommend[count].SynNum[cnt] = i;
				cnt++;
			}
		}
				
		recommend = recommend->next;
		count++;
	}
	printf("��õ�ص帱 è�Ǿ� ����� ������ �����ϴ�.(����) [��ȣ. è�Ǿ� �� / �߰��ǰų� ��ȭ�Ǵ� �ó��� ��]\n");
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
	fopen_s(&myFile, "champion.txt", "r"); // ���� ����ü ������ �� champion.txt ������ �б� ���� ����

	char buffer[STRING_SIZE]; // ���Ϸκ��� ������ ���ڸ� �ӽ÷� ���� �� buffer

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
	printf("è�Ǿ��� ���� �Է����ּ��� : ");
	scanf_s("%d", &n, sizeof(n));
		
	printf("è�Ǿ� ���� �Է����ּ���. \n");
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
	struct NODE* AllChampionListHead = malloc(sizeof(struct NODE)); // ��� è�Ǿ� ����� ����� ���� Linked List�� Head
	struct NODE* UserChampionListHead = malloc(sizeof(struct NODE));// ������ è�Ǿ� ����� ����� ���� Linked List�� Head
	int LimitLoad = 0; // LOAD Ƚ�� ����
	int LimitChamp = 0; // MYCHAMPION Ƚ�� ����
	while (1) {
		
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("------------------------------------------ COMMAND LIST ------------------------------------------\n");
		printf("LOAD : �ؽ�Ʈ ���Ͽ� ����Ǿ� �ִ� ��� è�Ǿ��� �������� �о� ��ũ�� ����Ʈ�� �����Ѵ�.\n");
		printf("PRINTALL : ���� ���ӿ� �����ϴ� ��� è�Ǿ� ���� ������ ����Ѵ�.\n");
		printf("MYCHAMPION : User�� ���� ������ è�Ǿ� ������ �Է� �ް� ��ũ�� ����Ʈ�� �����Ѵ�.\n");
		printf("PRINTMY : User�� ������ �ִ� ��� è�Ǿ��� ������ ����Ѵ�.\n");
		printf("MYSYNERGY : User�� ������ �ִ� Synergy ������ ����Ѵ�.\n");
		printf("RECOMMEND : ���� ��Ȳ�� �´� ��õ è�Ǿ� ����� ����Ѵ�.\n");
		printf("EXIT : ���α׷��� �����Ѵ�.\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("�� ������ �����Ͽ� �����ϰ��� �ϴ� COMMAND�� �Է����ּ��� : ");

		scanf_s("%s", command,sizeof(command));

		int fileCon;								// ������ �������� ������ Ȯ���ϱ� ���� �ñ׳�
		
		if (!strcmp(command,"LOAD") && LimitLoad<1) {
			LoadChampionList(AllChampionListHead);
			LimitLoad++;
		}
		else if (!strcmp(command, "LOAD") && LimitLoad >= 1) {
			printf("LOAD�� �� ���� �����մϴ�.\n");
		}
		else if(!strcmp(command, "PRINTALL")) {
			PrintALLChampionList(AllChampionListHead);
		}
		else if (!strcmp(command, "MYCHAMPION") && LimitChamp < 1) {
			InputMyChampionList(UserChampionListHead);
			LimitChamp++;
		}
		else if (!strcmp(command, "MYCHAMPION")&&LimitChamp>=1) {
			printf("MYCHAMPION�� �� ���� �����մϴ�.\n");
		}
		else if (!strcmp(command, "PRINTMY")) {
			if (PrintMyChampionList(UserChampionListHead) == 0) {
				printf("�Է� �� è�Ǿ� ������ �����ϴ�.\n");
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
			printf("���α׷� ����\n");
			return 0;
		}
		else {
			printf("���ǵ��� ���� COMMAND �Դϴ�. ���α׷��� �ٽ� �������ּ���.\n");
			break;
		}
		
		
		getchar();											// �Է� ���� ����
	}

	free(AllChampionListHead);
	free(UserChampionListHead);
	return 0;
}