#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void U_39()
{
	int result = 1;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/apache2/apache2.conf", "r")) == NULL) {
		printf("[U-39] Apache 링크 사용금지 : 점검 오류\n");
	}
	
	const int max = 9999;
	char line[max];
	char *pLine;
	char *p;
	while(!feof(fp))
	{
		pLine = fgets(line, max, fp);
		if(pLine)
		{
			if(strstr(pLine, "FollowSymLinks"))
			{
				if(strchr(pLine, '#'))
				{
					result = 1;
				}
				result = 0;
				break;
			}
		}
	}
	fclose(fp);

	if(result)
		printf("[U-39] Apache 링크 사용금지 : 양호\n");
	else
		printf("[U-39] Apache 링크 사용금지 : 취약\n");

}