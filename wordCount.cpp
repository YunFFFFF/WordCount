#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char fname[80];/*�����ļ���*/
    char parameter[2];/*���ҿ��Ʋ���*/ 
    FILE *rfp;
    long str_count, word_count;/*�ļ��ַ������ʼ�����*/
    int ch;
    printf("��������Ʋ������ļ�����\n");
    scanf("%s %s",&parameter,&fname);
    if((rfp=fopen(fname,"r"))==NULL){
        printf("Can't open file %s.\n",fname);
        exit(1);
    }
    str_count = 0;
    word_count = 1;
    while((ch=fgetc(rfp))!=EOF){
        str_count++;
        if(ch==44){
        	word_count++; 
		}
    }
    fclose(rfp);
    if(strcmp(parameter, "-c") == 0){
    	printf("���� %ld ���ַ����ļ� %s �С�\n",str_count,fname);
    }
    if(strcmp(parameter, "-w") == 0){
    	printf("���� %ld ���������ļ� %s �С�\n",word_count,fname);
	}
    
    return 0;
}
