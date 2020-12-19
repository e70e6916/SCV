#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : automountd 서비스 데몬의 실행 여부 점검 
            automountd 서비스 활성화시 취약, 비활성화시 양호 */

int U_26() {
   FILE* fp;
   int n1;
   char count1[BUF_SIZE];
   char setting[BUF_SIZE] = "2"; /*( grep과 system call에의해서 2가 default )*/
   int ret1;

   system("ps -ef | grep automount | wc -l > output26.txt");

   if ((fp = fopen("output26.txt", "r")) == NULL) {
      printf("[U-26] automountd 제거(상) : 점검 오류 (파일 탐색 불가) \n");
      system("rm -f output26.txt");
      return 0;
   }
   fgets(count1, sizeof(count1), fp);
   ret1 = strcmp(count1, setting);
   system("rm -f output26.txt");
   if (ret1 == 10){
      printf("[U-26] automountd 제거(상) : 양호\n");
      return 1;
   }
   else{
      printf("[U-26] automountd 제거(상) : 취약\n");
      return 2;
   }

}
