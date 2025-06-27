#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main()
{

char a;
int op1;
int op2;

cout<<"\nEnter the operator: ";
cin>>a;
cout<<"\nEnter the operand: ";
cin>>op1;
cout<<"\nEnter the operand 2: ";
cin>>op2;

int fd[2];
pipe(fd);
int opp1[2];
pipe(opp1);
int opp2[2];
pipe(opp2);
int res[2];
pipe(res);

write(opp1[1],&op1,sizeof(int));
write(opp2[1],&op2,sizeof(int));
write(fd[1],&a,sizeof(char));
int pid=fork();

if(pid>1)
{
cout<<"\nIn Parent Process\n";
wait(NULL);
int final=0;
read(res[0],&final,sizeof(int));
cout<<"\nThe final answer is: ";
cout<<final;



}
else
{
cout<<"\nIn Child Process\n";
char b;
int one;
int two;
read(opp1[0],&one,sizeof(int));
read(opp2[0],&two,sizeof(int));
read(fd[0],&b,sizeof(char));
int ans=0;

if(b=='+')
{
ans=one+two;
}
else if(b=='-')
{
ans=one-two;
}
else if(b=='*')
{
ans=one*two;
}
else if(b=='/')
{
ans=one/two;
}

write(res[1],&ans,sizeof(int));








}







}

