#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : world writable ���� ����  */

void U_15() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret1;

	system("find /dev -type f -exec ls -l {} \\; | wc -l > output15.txt");

	if ((fp = fopen("output15.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-15] world writable ���� ����(��) : ��ȣ\n");
	else
		printf("[U-15] world writable ���� ����(��) : ���\n");

	system("rm -f output15.txt");
}
