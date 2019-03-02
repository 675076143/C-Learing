#include <stdio.h>

int in(char s[], char str[])
{
    int i=0,j=0,k;
    while(s[i]!='\0'&&str[j]!='\0'){
        i=0;
        k=j;//1
        //printf("%d\n",j);
        while(s[i]!='\0'&&str[k]!='\0'&&s[i]==str[k])//2    如果字符相同,字符串s和str向后遍历
        {
            printf("find char s[]:%c\n",s[i]);                          
            i++;
            k++;
            if(s[i]=='\0'|| str[k]=='\0')//当任意字符串遍历到末位时，跳出
            {
                break;//3                
            }            
        }
        j++;
    }

    if(s[i]=='\0')//当字符串s遍历到末位时，代表s中的字符包含在str中
        return 1;
    else
        return 0;
}
void main()
{
    printf("result:%d\n",in("mny","you are nmy friend"));
    getchar();
}