#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : SNMP ���� ���� or �񱸵� ���� */

void U_65() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";
	int ret1;

	system("ps -ef | grep snmp | wc -l > output65.txt");

	if ((fp = fopen("output65.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-65] SNMP ���� ���� ����(��) : ��ȣ\n");
	else
		printf("[U-65] SNMP ���� ���� ����(��) : ���\n");

	system("rm -f output65.txt");
}
