#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : NFS Access control */

void U_25() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret1;

	system("ls -l /etc | grep exportss | wc -l > output25.txt");

	if ((fp = fopen("output25.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-25] NFS 접근 통제(상) : 양호\n");
	else
		printf("[U-25] NFS 접근 통제(상) : 취약\n");

	system("rm -f output25.txt");
}
