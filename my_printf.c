#include <unistd.h>
#include <stdarg.h>

int my_putchar(char c)
{
    return write(1,&c,1);
    

}
int my_putstr(char*str)
{
    int i=0;
    if(str==NULL)
    {
        return write(1,"(null)",6);

    }
    while(str[i]!='\0')
    {
        my_putchar(str[i]);
        i++;
    }
    return i;

}
int my_putnbr(int n)
{
    char smvl[10];
    int i=0;
    int count_1=0;
    if(n == -2147483648)
    {
        count_1+=write(1,"-2147483648",11);
        return count_1;
    
    }
    if(n==0)
    {
        count_1+=my_putchar('0');
        return count_1;
    }
    if(n<0)
    {
        count_1+=my_putchar('-');
        n=-n;
    }
    while(n>0)
    {
        smvl[i]=n%10;
        n=n/10;
        i++;
    }
    i--;
    while(i>=0)
    {
        count_1+=my_putchar(smvl[i]+'0');
        i--;
    }
    return count_1;
    
}
int my_putnbr_base(unsigned long long n, char *base,int base_len)
{
    int count_2=0;
    char smvls[64];
    int i=0;
    if (n==0)
    {
        count_2+=my_putchar(base[0]);
    }
    while(n>0)
    {
        smvls[i]=n%base_len;
        n=n/base_len;
        i++;
    }
    i--;
    while(i>=0)
    {
        int qlq=smvls[i];
        count_2+=my_putchar(base[qlq]);
        i--;
    }
    return count_2;
}
int my_printf(char *restrict format,...)
{
    va_list args;
    int count=0;
    va_start(args,format);
    int i;
    for(i=0;format[i]!='\0';i++)
    {
        if(format[i]=='%' && format[i+1]!='\0')
        {
            i++;
            if(format[i]=='c')
            {
                count=count+my_putchar(va_arg(args,int));
            }
            else if(format[i]=='s')
            {
                char*s=va_arg(args,char*);
                count=count+my_putstr(s);
            }
            else if(format[i]=='d' || format[i]=='i')
            {
                count=count+my_putnbr(va_arg(args,int));
            }
            else if(format[i]=='%')
            {
                count=count+my_putchar('%');
            }
            else if(format[i]=='p')
            {
                void *p=va_arg(args,void*);
                if(p==NULL)
                {
                    count=count+my_putstr("0x0");

                }
                else{
                    unsigned long long ptr = (unsigned long long)p;
                    count+=my_putstr("0x");
                    count+=my_putnbr_base(ptr,"0123456789abcdef",16);


                }
                

            }
            else if(format[i]=='u')
            {
                count+=my_putnbr_base(va_arg(args,unsigned int),"0123456789",10);
            }
            else if(format[i]=='o')
            {
                count+=my_putnbr_base(va_arg(args,unsigned int),"01234567",8);

            }
            else if(format[i]=='x')
            {
                count+=my_putnbr_base(va_arg(args,unsigned int),"0123456789ABCDEF",16);
            }
            
            
        }
        else{
            count=count+my_putchar(format[i]);
        }
    }
    va_end(args);
    return count;
    

}
 