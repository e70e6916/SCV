#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : NIS ���� ��Ȱ��ȭ
    ( ���� ���ʿ����� ���� �ϴ� Ȱ��ȭ�Ǹ� ���, ������ ��ȣ�� ������ )  */

void U_56() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2"; /*( grep�� system call�����ؼ� 2�� default )*/
	int ret1;

	system("ps -ef | grep yp | wc -l > output56.txt");

	if ((fp = fopen("output56.txt", "r")) == NULL) {
		printf("[U-56] NIS ���� ��Ȱ��ȭ(��) : ���� ����\n");
		return;
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-56] NIS ���� ��Ȱ��ȭ(��) : ��ȣ\n");
	else
		printf("[U-56] NIS ���� ��Ȱ��ȭ(��) : ���\n");

	system("rm -f output56.txt");
}
