#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : FTP ���񽺰� Ȱ��ȭ �Ǿ��ִ��� ���� 
				�Ϲ� ftp���� , vsftpd or ProFtp���� Ȱ��ȭ�� ���, ��Ȱ��ȭ�� ��ȣ*/

void U_62() {
	FILE* fp1, * fp2;
	int n1, n2;
	char count1[BUF_SIZE], count2[BUF_SIZE];
	char checkarr[BUF_SIZE] = "2";  /*( grep�� system call�����ؼ� 2�� default )*/
	int ret1, ret2;

	system("ps -ef | grep ftp | wc -l > output62_1.txt");
	system("ps -ef | egrep \"vsftpd|proftp\" | wc -l > output62_2.txt");
	if ((fp1 = fopen("output62_1.txt", "r")) == NULL) {
		printf("[U-62] ftp ���� Ȯ��(��) : ���� ����\n");
		return;
	}
	if ((fp2 = fopen("output62_2.txt", "r")) == NULL) {
		printf("[U-62] ftp ���� Ȯ��(��) : ���� ����\n");
		return;
	}

	fgets(count1, sizeof(count1), fp1);
	fgets(count2, sizeof(count2), fp2);

	ret1 = strcmp(count1, checkarr);
	ret2 = strcmp(count2, checkarr);

	if (ret1 == 10 && ret2 == 10)
		printf("[U-62] ftp ���� Ȯ��(��) : ��ȣ\n");
	else
		printf("[U-62] ftp ���� Ȯ��(��) : ���\n");

	system("rm -f output62_1.txt");
	system("rm -f output62_2.txt");

}
