#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : NIS ���񽺰� Ȱ��ȭ �Ǿ��ִ��� �Ǿ����� �ʴ��� ���� 
				NIS ���� Ȱ��ȭ�� ���, ��Ȱ��ȭ�� ��ȣ*/

void U_28() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";  /*( grep�� system call�����ؼ� 2�� default )*/
	int ret1;

	system("ps -ef | egrep \"ypserv|ypbind|ypxfrd|rpc.yppasswdd|rpc.ypupdated\" | wc -l > output28.txt");

	if ((fp = fopen("output28.txt", "r")) == NULL) {
		printf("[U-28] NIS, NIS+ ����(��) : ���� ����\n");
		return;
	}

	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);

	if (ret1 == 10)
		printf("[U-28] NIS, NIS+ ����(��) : ��ȣ\n");
	else
		printf("[U-28] NIS, NIS+ ����(��) : ���\n");

	system("rm -f output28.txt");

}
