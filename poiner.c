#include<stdio.h>
void main()
{
    int count = 0;
    char str[50],*p=str;
    gets(str);
    while(*p){
        switch (*p)
        {
            case 'A':
                case 'a':
                    case 'E':
                        case 'e':
                            case 'I':
                                case 'i':
                                    case'O':
                                        case 'o':
                                            case 'U':
                                                case 'u':
                                                    count++;                                                    
                                                    break;
        
            default:
                break;
        }
        p++;
    }
    printf("%d\n",count);
    gets(str);
}