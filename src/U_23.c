#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* ���˱��� : Dos ���ݿ� ����� ���� ��Ȱ��ȭ
				/etc/xinetd.d/ dir ������ echo,discard, daytiem, chargen ���Ͽ���
				disable = yes�� �����Ǿ������� ��ȣ, �׷��������� ���  */

void U_23() {
	FILE* fp1, * fp2;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	char setting2[BUF_SIZE] = "2";
	int count = 0;
	int ret;
	system("ls -alL /etc/xinetd.d/* 2> /dev/null| wc -l > output23_0.txt");
	if ((fp1 = fopen("output23_0.txt", "r")) == NULL) {
		printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���� ����\n");
		return;
	}
	fgets(arr, sizeof(arr), fp1);
	ret = strcmp(arr, "0");
	// output23_0�� ����� 0�̸� xinetd.d�� ��ġ���� ������, ���˿���  
	if (ret == 10) {
		printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���� ����\n"); // xinetd.d ��ġ �ʿ� ( sudo apt-get install xinetd.d ) 
		system("rm -f output23_0.txt");
		return;
	}
	else {
		//echo 
		system("cat -T /etc/xinetd.d/echo > output23_1.txt");
		system("grep -r \'disable^I^I= yes\' output23_1.txt | wc -l > output23_1_2.txt");
		// ����� 2�̸� yes�� �����Ǿ��ִ°�  = > ��ȣ 2�� �ƴϸ� yes�� �����Ǿ����� �ʴ°�, ���
		if ((fp2 = fopen("output23_1_2.txt", "r")) == NULL) {
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���� ����\n");
			return;
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting2);
		if (ret == 10)
			count++;
		else {
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���\n");
			return;
		}

		system("rm -f output23_1.txt");
		system("rm -f output23_1_2.txt");

		//discard
		system("cat -T /etc/xinetd.d/discard > output23_1.txt");
		system("grep -r \'disable^I^I= yes\' output23_1.txt | wc -l > output23_1_2.txt");
		// ����� 2�̸� yes�� �����Ǿ��ִ°�  = > ��ȣ 2�� �ƴϸ� yes�� �����Ǿ����� �ʴ°�, ���
		if ((fp2 = fopen("output23_1_2.txt", "r")) == NULL) {
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���� ����\n");
			return;
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting2);
		if (ret == 10)
			count++;
		else {
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���\n");
			return;
		}

		system("rm -f output23_1.txt");
		system("rm -f output23_1_2.txt");

		//daytime
		system("cat -T /etc/xinetd.d/daytime > output23_1.txt");
		system("grep -r \'disable^I^I= yes\' output23_1.txt | wc -l > output23_1_2.txt");
		// ����� 2�̸� yes�� �����Ǿ��ִ°�  = > ��ȣ 2�� �ƴϸ� yes�� �����Ǿ����� �ʴ°�, ���
		if ((fp2 = fopen("output23_1_2.txt", "r")) == NULL) {
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���� ����\n");
			return;
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting2);
		if (ret == 10)
			count++;
		else {
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���\n");
			return;
		}

		system("rm -f output23_1.txt");
		system("rm -f output23_1_2.txt");

		//chargen
		system("cat -T /etc/xinetd.d/chargen > output23_1.txt");
		system("grep -r \'disable^I^I= yes\' output23_1.txt | wc -l > output23_1_2.txt");
		// ����� 2�̸� yes�� �����Ǿ��ִ°�  = > ��ȣ 2�� �ƴϸ� yes�� �����Ǿ����� �ʴ°�, ���
		if ((fp2 = fopen("output23_1_2.txt", "r")) == NULL) {
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���� ����\n");
			return;
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting2);
		if (ret == 10)
			count++;
		else {
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���\n");
			return;
		}

		system("rm -f output23_0.txt");
		system("rm -f output23_1.txt");
		system("rm -f output23_1_2.txt");

		if (count == 4)
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ��ȣ\n");
		else
			printf("[U-23] DoS ���ݿ� ����� ���� ��Ȱ��ȭ(��) : ���\n");
	}
}
