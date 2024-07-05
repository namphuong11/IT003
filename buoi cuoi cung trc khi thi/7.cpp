#include <bits/stdc++.h>
using namespace std;
#define NULLKEY -365

int bangbam[11];

int hambam(int k)
{
    return k%11;
}

void insert(int k)
{
 int i = hambam(k);
 if (bangbam[i] == NULLKEY)
 {
     bangbam[i]=k;
 }
 else
 {
     int z =1;
     while (bangbam[i]!=NULLKEY)
     {
         i = i+z*z;
         z++;
         if (i>=11)
         {
             i -= 11;
         }
     }
     bangbam[i]=k;
 }
}


void display()
{
    printf("\nBANG BAM CUA BAN:\n");
    printf("\n\t\tVi tri\t\t\tKhoa\n");
    for(int i=0;i<11;i++)
        if (bangbam[i]!=NULLKEY)
            printf("\n\t\t%d\t\t\t%d",i,bangbam[i]);
        else
            printf("\n\t\t%d\t\t\tNULL",i);
}


int main() {
    for (int i = 0; i < 11; i++)
        bangbam[i] = NULLKEY;

    insert(7);
    insert(20);
    insert(16);
    insert(24);
    insert(12);
    insert(40);
    insert(15);

    display();


    return 0;
}


