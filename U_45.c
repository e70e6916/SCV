#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : NIS ���񽺰� Ȱ��ȭ �Ǿ��ִ��� �Ǿ����� �ʴ��� ���� */

void U_45() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";
	int ret1;

	system("ps -ef | egrep \"ypserv|ypbind|ypxfrd|rpc.yppasswdd|rpc.ypupdated\" | wc -l > output45.txt");

	if ((fp = fopen("output45.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}

	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);

	if (ret1 == 10)
		printf("[U-45] NIS, NIS+ ����(��) : ��ȣ\n");
	else
		printf("[U-45] NIS, NIS+ ����(��) : ���\n");

	system("rm -f output45.txt");

}
