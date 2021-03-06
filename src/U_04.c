#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define LINE 512

int U_04()
{
	FILE *fp;
	DIR *dir_ptr;
	struct dirent *direntp;
	char buf[LINE];
	int shadow_check = FALSE;

	if( (dir_ptr = opendir("/etc")) == NULL ) {
		printf("[U-04] 패스워드 파일 보호 (상) : 점검 오류 (파일 탐색 불가)\n");
		return 0;
	}
	else {
		while( (direntp = readdir(dir_ptr)) != NULL )
			if( strcmp(direntp->d_name, "shadow") == 0 ) {
				shadow_check = TRUE;
				break;
			}
		closedir(dir_ptr);
	}

	if( (fp = fopen("/etc/passwd", "r")) == NULL ) {
                printf("[U-04] 패스워드 파일 보호 (상) : 점검 오류 (파일 탐색 불가)\n");
                return 0;
        }
	else {
		while( fgets(buf, sizeof(buf), fp) ) {
			int i = 0;
			while(buf[i] != ':')
				i++;
			if(buf[i+1] != 'x') {
				printf("[U-04] 패스워드 파일 보호 (상) : 취약\n");
				fclose(fp);
				return 2;
			}	
		}
	}
	if(shadow_check == TRUE)
	{ 
		printf("[U-04] 패스워드 파일 보호 (상) : 양호\n");
		return 1;
	}
	fclose(fp);
}
