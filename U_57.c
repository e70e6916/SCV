#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : �ý��� UMASK ���� 022 �̻����� �ƴ��� ���� 
				UMASK ���� 022 �̻��̸� ��ȣ, �̸��̸� ��� */

void U_57() {
	FILE* fp;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "UMASK=022";
	int ret;

	system("grep -r 'UMASK=022' /etc/profile > output57.txt");
	if ((fp = fopen("output57.txt", "r")) == NULL) {
		printf("[U-57] UMASK ���� ����(��) : ���� ����\n");
		return;
	}
	fgets(arr, sizeof(arr), fp);
	ret = strcmp(arr, setting);
	if (ret > 0)
		printf("[U-57] UMASK ���� ����(��) : ��ȣ\n");
	else
		printf("[U-57] UMASK ���� ����(��) : ���\n");

	system("rm -f output57.txt");
}
