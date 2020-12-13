#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : �ý��� UMASK ���� 022 ���� �ƴ��� ���� */

void U_57() {
	FILE* fp;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "UMASK=022";
	int ret;

	system("grep -r 'UMASK=022' /etc/profile > output57.txt");
	if ((fp = fopen("output57.txt", "w")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(arr, sizeof(arr), fp);
	ret = strcmp(arr, setting);
	if (ret == 10)
		printf("[U-57] UMASK ���� ����(��) : ��ȣ\n");
	else
		printf("[U-57] UMASK ���� ����(��) : ���\n");

	system("rm -f output57.txt");
}
