#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : ftp ���� shell ���� ���� 
				ftp ���������� /bin/false �ο��Ǿ����� ��ȣ, ���������� ��� */

void U_63() {
	FILE* fp1, * fp2;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret;
	system("grep -r 'ftp' /etc/passwd | wc -l > output63_1.txt");
	if ((fp1 = fopen("output63_1.txt", "r")) == NULL) {
		printf("[U-63] ftp ���� shell ����(��) : ���� ����\n");
		return;
	}
	fgets(arr, sizeof(arr), fp1);
	ret = strcmp(arr, setting);
	// output63_1�� ����� 0�̸� ftp���� �۵����� �ʴ°� -> ��ȣ print�� ���� 
	if (ret == 10) {
		printf("[U-63] ftp ���� shell ����(��) : ��ȣ\n");
		system("rm -f output63_1.txt");
	}
	else {
		system("grep -r 'ftp:x:500:100:Anonymous FTP USER:/var/ftp:/bin/false' /etc/passwd | wc -l > output63_2.txt");
		// ����� 0�̸� false ������ �ʴ� -> ���  .. 1�̸� �ݴ��, ��ȣ
		if ((fp2 = fopen("output63_2.txt", "r")) == NULL) {
			printf("[U-63] ftp ���� shell ����(��) : ���� ����\n");
			return;
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting);
		if (ret == 10)
			printf("[U-63] ftp ���� shell ����(��) : ���\n");
		else
			printf("[U-63] ftp ���� shell ����(��) : ��ȣ\n");

		system("rm -f output63_2.txt");
	}
}
