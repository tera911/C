//
//  main.c
//  bignumeral
//
//  Created by tera on 13/05/11.
//  Copyright (c) 2013年 tera. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char* encodeLittleEndian(char* data,const char* source){
    char* pdata = data;
    data = strcpy(data, source);
   // printf("%p\n",data);
    
    //ソースを最後までまわす
    while(*source != '\0'){
        source++;
    }
    
    //data変数にソースを最後から入れる
    while(*data != '\0'){
        source--;
        *data = *source;
        data++;
    }
   // printf("%s",pdata);
    return pdata;
   
}

char* addArrayNum(char* num1,char* num2){
    char num[128];
    char* nump = num;
    char* tmp = num;
    int add = 0;
    
    while(*num1 != '\0' || *num2 != '\0'){
        int l,r,sum;
        l = *num1 - '0';
        r = *num2 - '0';
        
        
       // printf("l = %d  r = %d\n",l,r);
        //ポインター進める
        num1++;
        num2++;
        
        
        //数字か判定
        if((l >= 0 || l <= 9)&&( r >= 0 || r <= 9)){
            //数字なら加算
            sum = l + r + add;
            if((sum - 10) > 0){//10以上だから次の桁に＋１
                sum = sum - 10;
                add = 1;
                
            }else{
                add = 0;
            }
            *tmp = sum + '0';
            //printf("sum %d\n",sum);
            
        }else{
            return NULL;
        }
        tmp++;
    }
    
    return nump;
}

int main(int argc, const char * argv[])
{
    char a[128] = "2222444455556666";
    char b[128] = "4444333388881111";
    char tmp[128];
    char result[128];
    char tmp1[128];
    char tmp2[128];
    
    char* tmpp = tmp;
    tmpp = addArrayNum(encodeLittleEndian(tmp1, a), encodeLittleEndian(tmp2, b));
    
    
    printf("a = %s\nb = %s　を加算します。\n結果は %s\n",a,b,encodeLittleEndian(result,tmpp));
  // printf("%s\n",tmpp);

    
    return 0;
}

