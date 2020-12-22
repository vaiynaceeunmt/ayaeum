//
//  main.c
//  read_a_text_file
//
//  Created by Vincent Tsang on 22/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 255//一行最多有255个字符
#define FILE_DEST "log.txt" //文件位置

FILE *open_file(){
    FILE *fp;
    fp=fopen(FILE_DEST,"r");
    if(fp==NULL)
    {
        printf("文件不存在或无权限打开\n");
        exit(0);
    }
    printf("已打开文件\n");
    return fp;//返回指向文件流的指针
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char *text,*temp;//temp储存每次读到的行，text储存整个完整的文本
    int i;

    FILE *fp_tmp = open_file();//输入流fp_tmp用于统计文件行数
    temp = calloc(BUFF_SIZE,sizeof(char));
    for(i = 0; fgets(temp,BUFF_SIZE,fp_tmp)!=NULL; i++);//统计行数
    free(temp);
    printf("文本行数: %d\n",i);
    fclose(fp_tmp);
    
    FILE *fp=open_file();
    temp = calloc(BUFF_SIZE, sizeof(char));
    text = calloc(BUFF_SIZE * i, sizeof(char));//i为行数，text的大小相当于最长行大小乘i
    while(fgets(temp,BUFF_SIZE,fp)!=NULL){
        strcat(text,temp);//将temp中的文本追加到text中
        
        //以下这两部相当于清空了temp，但由于fgets执行时也会清空，所以可有可无
        free(temp);//释放temp的内存
        temp = calloc(BUFF_SIZE, sizeof(char));//重新分配内存并填充为0
    }
    free(temp);//temp用完了，释放内存
    
    printf("%s\n",text);//输出text
    free(text);//text用完了，释放内存
    
    fclose(fp);//关闭文件流
    
    return 0;
}
