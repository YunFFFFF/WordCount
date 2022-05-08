#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char fname[80];/*存贮文件名*/
    char parameter[2];/*查找控制参数*/ 
    FILE *rfp;
    long str_count, word_count;/*文件字符、单词计数器*/
    int ch;
    printf("请输入控制参数和文件名：\n");
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
    	printf("共有 %ld 个字符在文件 %s 中。\n",str_count,fname);
    }
    if(strcmp(parameter, "-w") == 0){
    	printf("共有 %ld 个单词在文件 %s 中。\n",word_count,fname);
	}
    
    return 0;
}
