#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : Finger ���� ��Ȱ��ȭ
				Finger ���� Ȱ��ȭ�� ���, ��Ȱ��ȭ�� ��ȣ */

void U_19() {
	FILE* fp1, * fp2;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret;
	system("ls -alL /etc/xinetd.d/* 2> /dev/null| wc -l > output19_1.txt");
	if ((fp1 = fopen("output19_1.txt", "r")) == NULL) {
		printf("[U-19] Finger ���� ��Ȱ��ȭ(��) : ���� ����\n");
		return;
	}
	fgets(arr, sizeof(arr), fp1);
	ret = strcmp(arr, setting);
	// output19_1�� ����� 0�̸� xinetd.d�� ��ġ���� ������, ���˿���  
	if (ret == 10) {
		printf("[U-19] Finger ���� ��Ȱ��ȭ(��) : ���� ����\n"); // xinetd.d ��ġ �ʿ� ( sudo apt-get install xinetd.d ) 
		system("rm -f output19_1.txt");
		return;
	}
	else {
		system("ls -alL /etc/xinetd.d/* | egrep \"echo finger\" | wc -l > output19_2.txt");
		// ����� 0�̸� �۵����� �ƴѰ� = > ��ȣ 0�̾ƴϸ� �۵���, ���
		if ((fp2 = fopen("output19_2.txt", "r")) == NULL) {
			printf("[U-19] Finger ���� ��Ȱ��ȭ(��) : ���� ����\n");
			return;
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting);
		if (ret == 10)
			printf("[U-19] Finger ���� ��Ȱ��ȭ(��) : ��ȣ\n");
		else
			printf("[U-19] Finger ���� ��Ȱ��ȭ(��) : ���\n");

		system("rm -f output19_1.txt");
		system("rm -f output19_2.txt");
	}
}
