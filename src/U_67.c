#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : SNMP ���� ���� or �񱸵� ����
				SNMP ���� �� ���� ��ȣ, ���� ��� */

void U_67() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2"; /*( grep�� system call�����ؼ� 2�� default )*/
	int ret1;

	system("ps -ef | grep snmp | wc -l > output67.txt");

	if ((fp = fopen("output67.txt", "r")) == NULL) {
		printf("[U-67] SNMP ���� ���� ����(��) : ���� ����\n");
		return;
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-67] SNMP ���� ���� ����(��) : ��ȣ\n");
	else
		printf("[U-67] SNMP ���� ���� ����(��) : ���\n");

	system("rm -f output67.txt");
}
