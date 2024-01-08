// できるだけ小さな容量になるようにじゃんけんのプログラムを書いてみました
#include<stdio.h>
int main(){int a,b,r;scanf("%d %d",&a,&b);r=(a-b+3)%3;printf("%s\n",r<1?"even":r>1?"win":"lose");}
