#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define nill NULL
#define infou(p) (p)->infou
#define nextu(p) (p)->nextu
#define prevu(p) (p)->prevu
#define firstu(l) ((l).firstu)
#define lastu(l) ((l).lastu)
#define infop(p) (p)->infop
#define nextp(p) (p)->nextp
#define prevp(p) (p)->prevp
#define firstp(l) ((l).firstp)
#define lastp(l) ((l).lastp)
#define infon(p) (p)->infon
#define nextn(p) (p)->nextn
#define prevn(p) (p)->prevn
#define firstn(l) ((l).firstn)
#define lastn(l) ((l).lastn)
#define infof(p) (p)->infof
#define nextf(p) (p)->nextf
#define prevf(p) (p)->prevf
#define firstf(l) (l)->firstf
#define lastf(l) (l)->lastf

using namespace std;
    /* Nama : hafiz prahasta

       NIM  : 1301140057
    */
typedef struct elmuser *address;
typedef struct elmfolw *address2;
typedef struct elmpost *address3;
typedef struct elmnoti *address4;


struct users {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    string iduser, pass, nama, alamat, hint;
    address3 favorite;
};
struct elmuser {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    users infou;
    address2 firstf,lastf;
    address nextu,prevu;
};
struct elmfolw {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    address infof;
    address2 nextf, prevf;
};
struct user{
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    address firstu,lastu;
};


struct posts {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    int idpost;
    address iduserp;
    string posting;
    int status;
};
struct elmpost {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    posts infop;
    address3 nextp, prevp;
};
struct post {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    address3 firstp, lastp;
};


struct notis {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    address idusern0;
    address idusern1;
    address3 idpostn;
    int cond;
};
struct elmnoti {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    notis infon;
    address4 nextn, prevn;
};
struct noti {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */

    address4 firstn, lastn;
};


void gotoxy(int x, int y);
string getpass(const char *prompt, bool show_asterisk=true);
void createuser(user &u);
void createpost(post &p);
void createnoti(noti &n);
address alokasiu(users u);
address2 alokasif(address f);
address3 alokasip(posts po);
address4 alokasin(notis n);
void insertfirstu (user &u, address p);
void insertfirstf (user &u, address &q, address2 p);
void insertfirstp (post &po, address3 p);
void insertfirstn (noti &n, address4 p);
void deletefirstu(user &u);
void deletefirstf(user &u, address &q);
void deletefirstp(post &po);
void deletefirstn(noti &n);
void deletelastu(user &u);
void deletelastf(user &u, address &q);
void deletelastp(post &po);
void deletelastn(noti &n);
void deleteitu(user &u, address &p);
void deleteitf(user &u, address &q, address2 &p);
void deleteitp(post &po, address3 &p);
void deleteitn(noti &n, address4 &p);
void deleteu (user &u, address &p);
void deletef (user &u, address &q, address2 &p);
void deletep (post &po, address3 &p);
void deleten (noti &n, address4 &p);

void createall(user &u, post &p, noti &n);
void login (user &u, bool &keluar, bool &masuk, address &on, int &salah);
void tampilawal(user u, post po, noti n, address on);
void editaccount(user &u, post &po, noti &n, address &on, bool &masuk);
void editpost(post &po, user &u, noti &n, address on);
void posit (post &po, address on, int &id);
void searchuser(user &u, address &on, noti &n);
void searchpost(user &u, post &po, address &on, noti &n);
void deletenoti(noti &n, address on);

#endif // HEADER_H_INCLUDED
