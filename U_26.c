#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : automountd ���� ������ ���� ���� ���� */

void U_26() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";
	int ret1;

	system("ps -ef | grep automount | wc -l > output26.txt");

	if ((fp = fopen("output26.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-26] automountd ����(��) : ��ȣ\n");
	else
		printf("[U-26] automountd ����(��) : ���\n");

	system("rm -f output26.txt");
}
