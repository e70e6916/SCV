#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���� ���� : NFS ���� ��Ȱ��ȭ 
				NFS ���� ������ Ȱ��ȭ�Ǹ� ���, ��Ȱ��ȭ�� ��ȣ*/

void U_24() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2"; /*( grep�� system call�����ؼ� 2�� default )*/
	int ret1;

	system("ps -ef | egrep \"nfs|statd|lockd\" | wc -l > output24.txt");

	if ((fp = fopen("output24.txt", "r")) == NULL) {
		printf("[U-24] NFS ���� ��Ȱ��ȭ(��) : ���� ����\n");
		return;
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-24] NFS ���� ��Ȱ��ȭ(��) : ��ȣ\n");
	else
		printf("[U-24] NFS ���� ��Ȱ��ȭ(��) : ��ȣ\n");

	system("rm -f output24.txt");
}

