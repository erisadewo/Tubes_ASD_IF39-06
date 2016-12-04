#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    user u;
    post po;
    noti n;
    int salah=0;
    int id=0;
    char command;
    address on=NULL;
    bool keluar=false;
    bool masuk=false;
    createall(u,po,n);
    while (keluar==false) {
        system("cls");
        login(u,keluar,masuk,on,salah);
        while (masuk) {
            /* Nama : hafiz prahasta
               NIM  : 1301140057
            */
            system("cls");
            salah=0;
            tampilawal(u,po,n,on);
            command=getch();
            if (command=='o'||command=='O') {
                masuk=false;
            }
            else if (command=='a'||command=='A') {
                editaccount(u,po,n,on,masuk);
            }
            else if (command=='e'||command=='E') {
                editpost(po,u,n,on);
            }
            else if (command=='p'||command=='P') {
                posit(po,on,id);
            }
            else if (command=='u'||command=='U') {
                searchuser(u,on,n);
            }
            else if (command=='s'||command=='S') {
                searchpost(u,po,on,n);
            }
            else if (command=='d'||command=='D') {
                deletenoti(n,on);
            }
        }
    }
    gotoxy(0,25);
    return 0;
}
