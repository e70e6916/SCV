#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : /dev�� �������� �ʴ� device ���� ���� */

void U_27() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret1;

	system("find /dev -type f -exec ls -l {} \\; | wc -l > output27.txt");

	if ((fp = fopen("output27.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-27] /dev�� �������� �ʴ� device ���� ����(��) : ��ȣ\n");
	else
		printf("[U-27] /dev�� �������� �ʴ� device ���� ����(��) : ���\n");

	system("rm -f output27.txt");
}
