#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "synergy.h"
void SetSynergyNum(int* trait, int* SynergyNum) {

	//���ŵ� �ó���
	if (trait[1] >= 3 && trait[1] < 6)
		SynergyNum[1] = 3;
	else if (trait[1] >= 6 && trait[1] < 9)
		SynergyNum[1] = 6;
	else if (trait[1] == 9)
		SynergyNum[1] = 9;

	//�������� �ó���
	if (trait[2] >= 3 && trait[2] < 6)
		SynergyNum[2] = 3;
	else if (trait[2] >= 6 && trait[2] < 9)
		SynergyNum[2] = 6;
	else if (trait[2] == 9)
		SynergyNum[2] = 9;

	//���� �ó���
	if (trait[3] == 1)
		SynergyNum[3] = 1;
	else if (trait[3] > 1 && trait[3] < 4)
		SynergyNum[3] = 0;
	else if (trait[3] == 4)
		SynergyNum[3] = 4;

	//�޺� �ó���
	if (trait[4] >= 3 && trait[4] < 5)
		SynergyNum[4] = 3;
	else if (trait[4] == 5)
		SynergyNum[4] = 5;

	//���屺 �ó���
	if (trait[5] >= 3 && trait[5] < 6)
		SynergyNum[5] = 3;
	else if (trait[5] >= 6 && trait[5] < 9)
		SynergyNum[5] = 6;
	else if (trait[5] == 9)
		SynergyNum[5] = 9;

	//���� �ó���
	if (trait[6] == 1)
		SynergyNum[6] = 1;

	//������ �ó���
	if (trait[7] >= 2 && trait[7] < 4)
		SynergyNum[7] = 2;
	else if (trait[7] >= 4 && trait[7] < 6)
		SynergyNum[7] = 4;
	else if (trait[7] == 6)
		SynergyNum[7] = 6;

	//�ż� �ó���
	if (trait[8] >= 2 && trait[8] < 4)
		SynergyNum[8] = 2;
	else if (trait[8] >= 4 && trait[8] < 6)
		SynergyNum[8] = 4;
	else if (trait[8] >= 6 && trait[8] < 8)
		SynergyNum[8] = 6;
	else if (trait[8] == 8)
		SynergyNum[8] = 8;

	//��ȥ �ó���
	if (trait[9] >= 2 && trait[9] < 4)
		SynergyNum[9] = 2;
	else if (trait[9] == 4)
		SynergyNum[9] = 4;

	//��θӸ� �ó���
	if (trait[10] == 1)
		SynergyNum[10] = 1;

	//�߹��� �ó���
	if (trait[11] == 1)
		SynergyNum[11] = 1;

	//��� �ó���
	if (trait[12] >= 3 && trait[12] < 6)
		SynergyNum[12] = 3;
	else if (trait[12] == 6)
		SynergyNum[12] = 6;

	//Ȳȥ �ó���
	if (trait[13] >= 2 && trait[13] < 4)
		SynergyNum[13] = 2;
	else if (trait[13] >= 4 && trait[13] < 6)
		SynergyNum[13] = 4;
	else if (trait[13] == 6)
		SynergyNum[13] = 6;

	//������ �ó���
	if (trait[14] >= 2 && trait[14] < 4)
		SynergyNum[14] = 2;
	else if (trait[14] >= 4 && trait[14] < 6)
		SynergyNum[14] = 4;
	else if (trait[14] >= 6 && trait[14] < 8)
		SynergyNum[14] = 6;
	else if (trait[14] == 8)
		SynergyNum[14] = 8;

	//�Ͱ� �ó���
	if (trait[15] >= 2 && trait[15] < 4)
		SynergyNum[15] = 2;
	else if (trait[15] >= 4 && trait[15] < 6)
		SynergyNum[15] = 4;
	else if (trait[15] == 6)
		SynergyNum[15] = 6;

	//�׸��� �ó���
	if (trait[16] == 2)
		SynergyNum[16] = 2;
	else if (trait[16] == 3)
		SynergyNum[16] = 3;
	else if (trait[16] == 4)
		SynergyNum[16] = 4;

	//����� �ó���
	if (trait[17] >= 2 && trait[17] < 4)
		SynergyNum[17] = 2;
	else if (trait[17] >= 4 && trait[17] < 6)
		SynergyNum[17] = 4;
	else if (trait[17] == 6)
		SynergyNum[17] = 6;

	//��ɲ� �ó���
	if (trait[18] == 2)
		SynergyNum[18] = 2;
	else if (trait[18] == 3)
		SynergyNum[18] = 3;
	else if (trait[18] == 4)
		SynergyNum[18] = 4;
	else if (trait[18] == 5)
		SynergyNum[18] = 5;

	//������ �ó���
	if (trait[19] >= 2 && trait[19] < 4)
		SynergyNum[19] = 2;
	else if (trait[19] >= 4 && trait[19] < 6)
		SynergyNum[19] = 4;
	else if (trait[19] >= 6 && trait[19] < 8)
		SynergyNum[19] = 6;
	else if (trait[19] == 8)
		SynergyNum[19] = 8;

	//�ź���� �ó���
	if (trait[20] >= 2 && trait[20] < 4)
		SynergyNum[20] = 2;
	else if (trait[20] >= 4 && trait[20] < 6)
		SynergyNum[20] = 4;
	else if (trait[20] == 6)
		SynergyNum[20] = 6;

	//�ο�� �ó���
	if (trait[21] >= 2 && trait[21] < 4)
		SynergyNum[21] = 2;
	else if (trait[21] >= 4 && trait[21] < 6)
		SynergyNum[21] = 4;
	else if (trait[21] >= 6 && trait[21] < 8)
		SynergyNum[21] = 6;
	else if (trait[21] == 8)
		SynergyNum[21] = 8;

	//�ϻ��� �ó���
	if (trait[22] >= 2 && trait[22] < 4)
		SynergyNum[22] = 2;
	else if (trait[22] >= 4 && trait[22] < 6)
		SynergyNum[22] = 4;
	else if (trait[22] == 6)
		SynergyNum[22] = 6;

	//����� �ó���
	if (trait[23] >= 3 && trait[23] < 6)
		SynergyNum[23] = 3;
	else if (trait[23] >= 6 && trait[23] < 9)
		SynergyNum[23] = 6;
	else if (trait[23] == 9)
		SynergyNum[23] = 9;

	//������ �ó���
	if (trait[24] == 2)
		SynergyNum[24] = 2;
	else if (trait[24] == 3)
		SynergyNum[24] = 3;
	else if (trait[24] == 4)
		SynergyNum[24] = 4;

	//��Ȥ���� �ó���
	if (trait[25] == 2)
		SynergyNum[25] = 2;
	else if (trait[25] > 2 && trait[25] <= 4)
		SynergyNum[25] = 4;

	//Ȳ�� �ó���
	if (trait[26] == 1)
		SynergyNum[26] = 1;

	//�ó��� ����
	for (int i = 1; i < 27; i++) {
		if (SynergyNum[i] > 0) {
			SynergyNum[0] = 0;
			break;
		}
		else
			SynergyNum[0] = 1;
	}
}
int ChampionSynergy(int * signal, int* trait, char* champ) {

	if (!strcmp(champ, "Garen")) {
		trait[5]++; trait[19]++; signal[5]++; signal[19]++;
	} else if (!strcmp(champ, "Nami")) {
		trait[7]++; trait[23]++; signal[7]++; signal[23]++;
	} else if (!strcmp(champ, "Nunu")) {
		trait[2]++;	trait[21]++; signal[2]++; signal[21]++;
	} else if (!strcmp(champ, "Nidalee")) {
		trait[5]++; trait[17]++; signal[5]++; signal[17]++;
	} else if (!strcmp(champ, "Diana")) {
		trait[4]++; trait[22]++; signal[4]++; signal[22]++;
	} else if (!strcmp(champ, "Lux")) {
		trait[8]++; trait[25]++; signal[8]++; signal[25]++;
	} else if (!strcmp(champ, "Lulu")) {
		trait[2]++; trait[23]++; signal[2]++; signal[23]++;
	} else if (!strcmp(champ, "LeeSin")) {
		trait[8]++; trait[14]++; signal[8]++; signal[14]++;
	} else if (!strcmp(champ, "Riven")) {
		trait[13]++; trait[15]++; signal[13]++;  signal[15]++;
	} else if (!strcmp(champ, "Lissandra")) {
		trait[4]++; trait[25]++; signal[4]++; signal[25]++;
	} else if (!strcmp(champ, "Lillia")) {
		trait[13]++; trait[23]++; signal[13]++; signal[23]++;
	} else if (!strcmp(champ, "Maokai")) {
		trait[2]++; trait[21]++; signal[2]++; signal[21]++;
	} else if (!strcmp(champ, "Morgana")) {
		trait[7]++; trait[25]++; signal[7]++; signal[25]++;
	} else if (!strcmp(champ, "Vi")) {
		trait[5]++; trait[21]++; signal[5]++; signal[21]++;
	} else if (!strcmp(champ, "Veigar")) {
		trait[2]++; trait[23]++; signal[2]++; signal[23]++;
	} else if (!strcmp(champ, "Vayne")) {
		trait[13]++; trait[17]++; signal[13]++; signal[17]++;
	} else if (!strcmp(champ, "Sylas")) {
		trait[4]++;	trait[21]++; signal[4]++; signal[21]++;
	} else if (!strcmp(champ, "Seguani")) {
		trait[12]++; trait[19]++; signal[12]++; signal[19]++;
	} else if (!strcmp(champ, "Sett")) {
		trait[10]++; trait[21]++; signal[10]++; signal[21]++;
	} else if (!strcmp(champ, "Shen")) {
		trait[3]++;	trait[20]++; trait[24]++; signal[3]++; signal[20]++; signal[24]++;
	} else if (!strcmp(champ, "XinZhao")) {
		trait[5]++; trait[14]++; signal[5]++; signal[14]++;
	} else if (!strcmp(champ, "Thresh")) {
		trait[13]++; trait[19]++; signal[13]++; signal[19]++;
	} else if (!strcmp(champ, "Ahri")) {
		trait[9]++;	trait[23]++; signal[9]++; signal[23]++;
	} else if (!strcmp(champ, "Azir")) {
		trait[5]++; trait[15]++; trait[26]++; signal[5]++; signal[15]++; signal[26]++;
	} else if (!strcmp(champ, "Akali")) {
		trait[3]++;	trait[22]++; signal[3]++; signal[22]++;
	} else if (!strcmp(champ, "Aatrox")) {
		trait[1]++; trait[19]++; signal[1]++; signal[19]++;
	} else if (!strcmp(champ, "Aphelios")) {
		trait[4]++;	trait[18]++; signal[4]++; signal[18]++;
	} else if (!strcmp(champ, "Annie")) {
		trait[12]++; trait[23]++; signal[12]++; signal[23]++;
	} else if (!strcmp(champ, "Ashe")) {
		trait[2]++; trait[18]++; signal[2]++; signal[18]++;
	} else if (!strcmp(champ, "Yasuo")) {
		trait[11]++; trait[14]++; signal[11]++; signal[14]++;
	} else if (!strcmp(champ, "Elise")) {
		trait[1]++; trait[15]++; signal[1]++; signal[15]++;
	} else if (!strcmp(champ, "Wukong")) {
		trait[8]++; trait[19]++; signal[8]++; signal[19]++;
	} else if (!strcmp(champ, "Yone")) {
		trait[11]++; trait[24]++; signal[11]++; signal[24]++;
	} else if (!strcmp(champ, "Warwick")) {
		trait[8]++;	trait[18]++; trait[21]++; signal[8]++; signal[18]++; signal[21]++;
	} else if (!strcmp(champ, "Yuumi")) {
		trait[9]++;	trait[20]++; signal[9]++; signal[20]++;
	} else if (!strcmp(champ, "Irelia")) {
		trait[7]++;	trait[8]++;	trait[24]++; signal[7]++; signal[8]++; signal[24]++;
	} else if (!strcmp(champ, "Evelynn")) {
		trait[1]++;	trait[16]++; signal[1]++; signal[16]++;
	} else if (!strcmp(champ, "Ezreal")) {
		trait[2]++;	trait[25]++; signal[2]++; signal[25]++;
	} else if (!strcmp(champ, "JarvanIV")) {
		trait[5]++; trait[15]++; signal[5]++; signal[15]++;
	} else if (!strcmp(champ, "Janna")) {
		trait[7]++;	trait[20]++; signal[7]++;  signal[20]++;
	} else if (!strcmp(champ, "Jax")) {
		trait[8]++;	trait[14]++; signal[8]++; signal[14]++;
	} else if (!strcmp(champ, "Zed")) {
		trait[3]++; trait[16]++; signal[3]++; signal[16]++;
	} else if (!strcmp(champ, "Jhin")) {
		trait[1]++; trait[17]++; signal[1]++; signal[17]++;
	} else if (!strcmp(champ, "Zilean")) {
		trait[1]++; trait[20]++; signal[1]++; signal[20]++;
	} else if (!strcmp(champ, "Jinx")) {
		trait[12]++; trait[17]++; signal[12]++; signal[17]++;
	} else if (!strcmp(champ, "Cassiopeia")) {
		trait[13]++; trait[20]++; signal[13]++; signal[20]++;
	} else if (!strcmp(champ, "Katarina")) {
		trait[5]++; trait[12]++; trait[22]++; signal[5]++; signal[12]++; signal[22]++;
	} else if (!strcmp(champ, "Kalista")) {
		trait[1]++; trait[14]++; signal[1]++; signal[14]++;
	} else if (!strcmp(champ, "Kennen")) {
		trait[3]++; trait[15]++; signal[3]++; signal[15]++;
	} else if (!strcmp(champ, "Kayn")) {
		trait[6]++; trait[16]++; signal[6]++; signal[16]++;
	} else if (!strcmp(champ, "Kindred")) {
		trait[9]++; trait[18]++; signal[9]++; signal[18]++;
	} else if (!strcmp(champ, "Talon")) {
		trait[7]++; trait[22]++; signal[7]++; signal[22]++;
	} else if (!strcmp(champ, "Tahmkench")) {
		trait[12]++; trait[21]++; signal[12]++;  signal[21]++;
	} else if (!strcmp(champ, "TwistedFate")) {
		trait[1]++;	trait[23]++; signal[1]++; signal[23]++;
	} else if (!strcmp(champ, "Teemo")) {
		trait[9]++; trait[17]++; signal[9]++; signal[17]++;
	} else if (!strcmp(champ, "Pyke")) {
		trait[1]++;	trait[22]++; signal[1]++; signal[22]++;
	} else if (!strcmp(champ, "Fiora")) {
		trait[7]++; trait[14]++; signal[7]++;		signal[14]++;
	} else if (!strcmp(champ, "Hecarim")) {
		trait[2]++; trait[19]++; signal[2]++; signal[19]++;
	} else {
		printf("è�Ǿ� ���� �߸� �Է��߽��ϴ� \n");
		return -1;
	}

	return 1;
}