#include "header.h"
using namespace std;

void gotoxy(int x, int y){
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string getpass(const char *prompt, bool show_asterisk) {
  /* Nama : hafiz prahasta
     NIM  : 1301140057
  */
  const char BACKSPACE=8;
  const char RETURN=13;
  string password;
  unsigned char ch=0;
  cout <<prompt;
  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else if(ch==0 || ch==224) // handle escape sequences
         {
             getch(); // ignore non printable chars
             continue;
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

void createuser(user &u) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    firstu(u) = NULL;
    lastu(u) = NULL;
}

void createpost(post &p) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    firstp(p) = NULL;
    lastp(p) = NULL;
}

void createnoti(noti &n) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    firstn(n) = NULL;
    lastn(n) = NULL;
}

address alokasiu(users u) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    address p = new elmuser;
    infou(p) = u;
    nextu(p) = NULL;
    prevu(p) = NULL;
    firstf(p) =NULL;
    lastf(p) = NULL;
    return p;
}

address2 alokasif(address f) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    address2 p = new elmfolw;
    infof(p) = f;
    nextf(p) = NULL;
    prevf(p) = NULL;
    return p;
}

address3 alokasip(posts po) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    address3 p = new elmpost;
    infop(p) = po;
    nextp(p) = NULL;
    prevp(p) = NULL;
    return p;
}

address4 alokasin(notis n) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    address4 p = new elmnoti;
    infon(p) = n;
    nextn(p) = NULL;
    prevn(p) = NULL;
    return p;
}

void insertfirstu (user &u, address p) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (firstu(u)==NULL) {
        firstu(u) = p;
        lastu(u) = p;
    }
    else {
        nextu(p) = firstu(u);
        prevu(firstu(u)) = p;
        firstu(u) = p;
    }
}

void insertfirstf (user &u, address &q, address2 p) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (firstu(u)!=NULL) {
        if (firstf(q)==NULL) {
            firstf(q) = p;
            lastf(q) = p;
        }
        else {
            nextf(p) = firstf(q);
            prevf(firstf(q)) = p;
            firstf(q) = p;
        }
    }
}

void insertfirstp (post &po, address3 p) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (firstp(po)==NULL) {
        firstp(po) = p;
        lastp(po) = p;
    }
    else {
        nextp(p) = firstp(po);
        prevp(firstp(po)) = p;
        firstp(po) = p;
    }
}

void insertfirstn (noti &n, address4 p) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstn(n)==NULL) {
        firstn(n) = p;
        lastn(n) = p;
    }
    else {
        nextn(p) = firstn(n);
        prevn(firstn(n)) = p;
        firstn(n) = p;
    }
}

void deletefirstu(user &u, address &q) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstu(u)!=NULL) {
        address p = firstu(u);
        if (nextu(p)==NULL) {
            firstu(u) = NULL;
            lastu(u) = NULL;
        }
        else {
            firstu(u) = nextu(p);
            prevu(nextu(p)) = NULL;
            nextu(p) = NULL;
        }
        q=p;
    }
}

void deletefirstf(user &u, address &q) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstu(u)!=NULL) {
        if (firstf(q)!=NULL) {
            address2 p = firstf(q);
            if (nextf(p)==NULL) {
                firstf(q) = NULL;
                lastf(q) = NULL;
            }
            else {
                firstf(q) = nextf(p);
                prevf(nextf(p)) = NULL;
                nextf(p) = NULL;
            }
            delete p;
        }
    }
}

void deletefirstp(post &po, address3 &q) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstp(po)!=NULL) {
        address3 p = firstp(po);
        if (nextp(p)==NULL) {
            firstp(po) = NULL;
            lastp(po) = NULL;
        }
        else {
            firstp(po) = nextp(p);
            prevp(nextp(p)) = NULL;
            nextp(p) = NULL;
        }
        q=p;
    }
}

void deletefirstn(noti &n) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstn(n)!=NULL) {
        address4 p = firstn(n);
        if (nextn(p)==NULL) {
            firstn(n) = NULL;
            lastn(n) = NULL;
        }
        else {
            firstn(n) = nextn(p);
            prevn(nextn(p)) = NULL;
            nextn(p) = NULL;
        }
        delete p;
    }
}

void deletelastu(user &u, address &q) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstu(u)!=NULL) {
        address p = firstu(u);
        if (nextu(p)==NULL) {
            firstu(u) = NULL;
            lastu(u) = NULL;
        }
        else {
            p = lastu(u);
            lastu(u) = prevu(p);
            nextu(prevu(p)) = NULL;
            prevu(p) = NULL;
        }
        q=p;
    }
}

void deletelastf(user &u, address &q) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (firstu(u)!=NULL) {
        if (firstf(q)!=NULL) {
            address2 p = firstf(q);
            if (nextf(p)==NULL) {
                firstf(q) = NULL;
                lastf(q) = NULL;
            }
            else {
                p = lastf(q);
                lastf(q) = prevf(p);
                nextf(prevf(p)) = NULL;
                prevf(p) = NULL;
            }
            delete p;
        }
    }
}

void deletelastp(post &po, address3 &q) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (firstp(po)!=NULL) {
        address3 p = firstp(po);
        if (nextp(p)==NULL) {
            firstp(po) = NULL;
            lastp(po) = NULL;
        }
        else {
            p = lastp(po);
            lastp(po) = prevp(p);
            nextp(prevp(p)) = NULL;
            prevp(p) = NULL;
        }
        q=p;
    }
}

void deletelastn(noti &n) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (firstn(n)!=NULL) {
        address4 p = firstn(n);
        if (nextn(p)==NULL) {
            firstn(n) = NULL;
            lastn(n) = NULL;
        }
        else {
            p = lastn(n);
            lastn(n) = prevn(p);
            nextn(prevn(p)) = NULL;
            prevn(p) = NULL;
        }
        delete p;
    }
}

void deleteitu(user &u, address &p) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (firstu(u)!=NULL) {
        nextu(prevu(p))=nextu(p);
        prevu(nextu(p))=prevu(p);
        nextu(p)=NULL;
        prevu(p)=NULL;
    }
}

void deleteitf(user &u, address &q, address2 &p) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstu(u)!=NULL) {
        if (firstf(q)!=NULL) {
            nextf(prevf(p))=nextf(p);
            prevf(nextf(p))=prevf(p);
            nextf(p)=NULL;
            prevf(p)=NULL;
            delete p;
        }
    }
}

void deleteitp(post &po, address3 &p) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstp(po)!=NULL) {
        nextp(prevp(p))=nextp(p);
        prevp(nextp(p))=prevp(p);
        nextp(p)=NULL;
        prevp(p)=NULL;
    }
}

void deleteitn(noti &n, address4 &p) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    if (firstn(n)!=NULL) {
        nextn(prevn(p))=nextn(p);
        prevn(nextn(p))=prevn(p);
        nextn(p)=NULL;
        prevn(p)=NULL;
        delete p;
    }
}

void deleteu (user &u, address &p) {
     /* Nama : hafiz prahasta
        NIM  : 1301140057
     */
    if (p==firstu(u))
        deletefirstu(u,p);
    else if (p==lastu(u))
        deletelastu(u,p);
    else
        deleteitu(u,p);
}

void deletef (user &u, address &q, address2 &p) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (p==firstf(q))
        deletefirstf(u,q);
    else if (p==lastf(q))
        deletelastf(u,q);
    else
        deleteitf(u,q,p);
}

void deletep (post &po, address3 &p) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (p==firstp(po))
        deletefirstp(po,p);
    else if (p==lastp(po))
        deletelastp(po,p);
    else
        deleteitp(po,p);
}

void deleten (noti &n, address4 &p) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (p==firstn(n))
        deletefirstn(n);
    else if (p==lastn(n))
        deletelastn(n);
    else
        deleteitn(n,p);
}
