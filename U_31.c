#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : NIS ���� ��Ȱ��ȭ ( ���� ���ʿ����� ���� ������ �ϴ� ������� �߰� ������..  */

void U_31() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";
	int ret1;

	system("ps -ef | grep yp | wc -l > output31.txt");

	if ((fp = fopen("output31.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-31] NIS ���� ��Ȱ��ȭ(��) : ��ȣ\n");
	else
		printf("[U-31] NIS ���� ��Ȱ��ȭ(��) : ���\n");

	system("rm -f output31.txt");
}
