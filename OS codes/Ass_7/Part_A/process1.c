#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int f1,f2;
char str[256];
char buf[100],str1[100];
f1 = mkfifo("fifo1",0666);
printf("mkfifo: %d",f1);
printf("Enter a String: \n");
fgets(str1,100,stdin);
//scanf(ā%sā,&str1);
//strcat(str1,ā\0ā³);
f1=open("fifo1",O_RDWR);
write(f1,str1,100);

f2=open("fifo2",O_RDWR);
read(f2,buf,100);

printf("\n%s \n",buf);
close(f1);
close(f2);
return 0;
}


