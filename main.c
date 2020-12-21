//
//  main.c
//  read_a_text_file
//
//  Created by Vincent Tsang on 22/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buff_size 255//一行最多有255个字符

FILE *open_file(){
    static FILE *fp;
    fp=fopen("log.txt","r");
    if(fp==NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    printf("已打开文件\n");
    return fp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char *text,*temp;//temp储存每次读到的行，text储存整个完整的文本
    int i=0,n=buff_size*2;
    text=calloc(n,sizeof(char));
    FILE *fp_tmp=open_file();//输入流fp_tmp用于统计文件行数
    temp=calloc(buff_size,sizeof(char));
    for(i = 0; fgets(temp,buff_size,fp_tmp)!=NULL; i++);
    free(temp);
    printf("文本行数: %d\n",i);
    fclose(fp_tmp);
    
    FILE *fp=open_file();
    temp = calloc(buff_size, sizeof(char));
    text = calloc(buff_size*i, sizeof(char));
    while(fgets(temp,buff_size,fp)!=NULL){
        strcat(text,temp);//将temp中的文本追加到text中
        free(temp);//释放temp的内存
        temp = calloc(buff_size, sizeof(char));//重新分配内存并填充为0
    }
    free(temp);
    
    printf("%s\n",text);
    fclose(fp);
    return 0;
}
