#include "header.h"
using namespace std;

void createall(user &u, post &p, noti &n) {
    createuser(u);
    createpost(p);
    createnoti(n);
}


void login (user &u, bool &keluar,bool &masuk, address &on, int &salah) {
    /* Nama : eri sadewo (1301140022)
    */
    char keypress;
    users in;
    cout << "+------------------------------------------------------------------------------+";
    gotoxy(0,1);cout << "|";cout << endl << "|";cout << endl << "|";cout << endl << "|";
    cout << endl << "|";cout << endl << "|";cout << endl << "|";cout << endl << "|";
    cout << endl << "|";cout << endl << "|";cout << endl << "|";cout << endl << "|";
    cout << endl << "|";cout << endl << "|";cout << endl << "|";cout << endl << "|";
    cout << endl << "|";cout << endl << "|";cout << endl << "|";cout << endl << "|";
    cout << endl << "|";cout << endl << "|";cout << endl << "|";
    gotoxy(79,1); cout << "|";gotoxy(79,2); cout << "|";gotoxy(79,3); cout << "|";
    gotoxy(79,4); cout << "|";gotoxy(79,5); cout << "|";gotoxy(79,6); cout << "|";
    gotoxy(79,7); cout << "|";gotoxy(79,8); cout << "|";gotoxy(79,9); cout << "|";
    gotoxy(79,10); cout << "|";gotoxy(79,11); cout << "|";gotoxy(79,12); cout << "|";
    gotoxy(79,13); cout << "|";gotoxy(79,14); cout << "|";gotoxy(79,15); cout << "|";
    gotoxy(79,16); cout << "|";gotoxy(79,17); cout << "|";gotoxy(79,18); cout << "|";
    gotoxy(79,19); cout << "|";gotoxy(79,20); cout << "|";gotoxy(79,21); cout << "|";
    gotoxy(79,22); cout << "|";
    gotoxy(21,5); cout << " _____       _ _     _____ _ _       ";
    gotoxy(21,6); cout << "|     |___ _| |_|___|  |  |_| |_ ___ ";
    gotoxy(21,7); cout << "| | | | -_| . | | .'|    -| |  _| .'|";
    gotoxy(21,8); cout << "|_|_|_|___|___|_|__,|__|__|_|_| |__,|";
    gotoxy(21,9); cout << "Sign[U]p      [S]ignIn        [C]lose";
    gotoxy(0,23); cout << "+------------------------------------------------------------------------------+";
    gotoxy(1,1);
    keypress=getch();
    while ((keypress!='C')and(keypress!='c')and(keypress!='S')and(keypress!='s')and(keypress!='U')and(keypress!='u')) {
        gotoxy(32,11); cout << "Invalid Command!"; getch(); gotoxy(32,11); cout << "                ";
        keypress=getch();
    }
    if (keypress=='c'||keypress=='C')
        keluar=true;
    else if (keypress=='s'||keypress=='S') {
        gotoxy(28,11);cout << "+----------------------+";
        gotoxy(28,12);cout << "|UserID :              |";
        gotoxy(28,13);cout << "|Pass   :              |";
        gotoxy(28,14);cout << "+----------------------+";
        gotoxy(38,12);cin >> in.iduser;
        gotoxy(38,13); in.pass=getpass("",true);
        address p=firstu(u);
        if (p!=NULL) {
            while (p!=NULL){
                if ((infou(p).iduser==in.iduser)and(infou(p).pass==in.pass)) {
                    masuk=true;
                    on=p;
                }
                p = nextu(p);
            }
        }
        if (masuk==false) {
            gotoxy(29,15); cout << "Invalid User/Password!";
            salah++;
            if (salah>3) {
                bool hintp = false;
                p = firstu(u);
                address q;
                if (p!=NULL) {
                    while (p!=NULL){
                        if (infou(p).iduser==in.iduser) {
                            hintp=true;
                            q=p;
                        }
                        p = nextu(p);
                    }
                }
                if (hintp) {
                    gotoxy(29,16); cout << "Hint : " << infou(q).hint;
                }
                else {
                    gotoxy(29,16); cout << "Hint : Unregisted ID";
                }
            }
            getch();
        }
    }
    else {
        address p = firstu(u);
        bool duplicat=false;
        gotoxy(25,11);cout << "+---------------------------+";
        gotoxy(25,12);cout << "|UserID :                   |";
        gotoxy(25,13);cout << "|Pass   :                   |";
        gotoxy(25,14);cout << "|Name   :                   |";
        gotoxy(25,15);cout << "|Address:                   |";
        gotoxy(25,16);cout << "|Hint   :                   |";
        gotoxy(25,17);cout << "+---------------------------+";
        gotoxy(35,12);cin >> in.iduser;
        do {
        if (duplicat) {
            gotoxy(27,19); cout << "UserID was already in use"; getch(); gotoxy(27,19); cout << "                         ";
            gotoxy(25,12); cout << "|UserID :                   |";gotoxy(35,12);cin >> in.iduser;
            duplicat=false;
        }
        if (p!=NULL) {
            while (p!=NULL){
                if (infou(p).iduser==in.iduser) {
                    duplicat=true;
                }
                p = nextu(p);
            }
        }
        }while(duplicat);
        gotoxy(35,13);in.pass=getpass("",true);
        gotoxy(35,14);cin >> in.nama;
        gotoxy(35,15);cin >> in.alamat;
        gotoxy(35,16);cin >> in.hint;
        in.favorite=NULL;
        p=alokasiu(in);
        insertfirstu(u,p);
        on=p;
        masuk=true;
    }
}


void tampilawal(user u, post po, noti n, address on) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    address2 q = firstf(on);
    address3 r = firstp(po);
    address4 s = firstn(n);
    int i=5;
    gotoxy(0,0);cout << "[P]ost    [E]ditPost   Edit[A]ccount    Search[U]ser   [S]earchPost    Log [O]ut";
    gotoxy(0,2);cout << "                           +-----------------+               +-----------------+";
    gotoxy(0,3);cout << "hello " << infou(on).nama << "!";
    gotoxy(24,3);cout<< "  /             Post |              /     Notification |";
    gotoxy(0,4);cout << "+------------------------+-------------------+ +-----------+-------------------+";
    gotoxy(0,5);cout << "                                               |                               |";
    gotoxy(0,6);cout << "                                               |                               |";
    gotoxy(0,7);cout << "                                               +-------------------------------+";
    gotoxy(0,8);cout << "                                               |                               |";
    gotoxy(0,9);cout << "                                               |                               |";
    gotoxy(0,10);cout << "                                               +-------------------------------+";
    gotoxy(0,11);cout << "                                               |                               |";
    gotoxy(0,12);cout << "                                               |                               |";
    gotoxy(0,13);cout << "                                               +-------------------------------+";
    gotoxy(0,14);cout << "                                                [D]eleteNotification            ";
    gotoxy(0,15);cout << "                                               +------------------------+------+";
    gotoxy(0,16);cout << "                                               |Following               |      |";
    gotoxy(0,17);cout << "                                               +------------------------+------+";
    if (firstf(on)!=NULL) {
        int jumf = 0;
        while (q!=NULL) {
            jumf++;
            q=nextf(q);
        }
        gotoxy(75,16); cout << jumf;
    }
    else {
        gotoxy(75,16); cout << 0;
    }

    if (firstn(n)!=NULL) {
        int jumn = 1;
        while (s!=NULL) {
            if (infon(s).idusern0==on) {
                if (infon(s).cond==0) {
                    if (jumn==1) {
                        gotoxy(48,5); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,6); cout << "Make your post his/her favorite";
                    }
                    else if (jumn==2) {
                        gotoxy(48,8); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,9); cout << "Make your post his/her favorite";
                    }
                    else if (jumn==3) {
                        gotoxy(48,11); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,12); cout << "Make your post his/her favorite";
                    }
                    jumn++;
                }
                else if (infon(s).cond==1) {
                    if (jumn==1) {
                        gotoxy(48,5); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,6); cout << "Love your post";
                    }
                    else if (jumn==2) {
                        gotoxy(48,8); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,9); cout << "Love your post";
                    }
                    else if (jumn==3) {
                        gotoxy(48,11); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,12); cout << "Love your post";
                    }
                    jumn++;
                }
                else if (infon(s).cond==2) {
                    if (jumn==1) {
                        gotoxy(48,5); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,6); cout << "Hate your post";
                    }
                    else if (jumn==2) {
                        gotoxy(48,8); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,9); cout << "Hate your post";
                    }
                    else if (jumn==3) {
                        gotoxy(48,11); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,12); cout << "Hate your post";
                    }
                    jumn++;
                }
                else if (infon(s).cond==3) {
                    if (jumn==1) {
                        gotoxy(48,5); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,6); cout << "Follow you";
                    }
                    else if (jumn==2) {
                        gotoxy(48,8); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,9); cout << "Follow you";
                    }
                    else if (jumn==3) {
                        gotoxy(48,11); cout << infou(infon(s).idusern1).nama;
                        gotoxy(48,12); cout << "Follow you";
                    }
                    jumn++;
                }
            }
            s = nextn(s);
        }
    }
    q=firstf(on);
    r=firstp(po);
    if (firstp(po)!=NULL) {
        int jump=0;
        if (infou(on).favorite!=NULL) {
            gotoxy(0,i);cout << "|                                            |";
            gotoxy(1,i);cout << infop(infou(on).favorite).idpost << "F* @" << infou(infop(infou(on).favorite).iduserp).nama;
            gotoxy(0,i+1);cout << "|                                            |";
            gotoxy(1,i+1);
            int panjang = (infop(infou(on).favorite).posting).length();
            if (panjang>44) {
                for (int j=0;j<44;j++) {
                    cout << infop(infou(on).favorite).posting[j];
                }
                gotoxy(0,i+2);cout << "|                                            |";
                gotoxy(1,i+2);
                for (int j=44;j<panjang;j++) {
                    cout << infop(infou(on).favorite).posting[j];
                }
            }
            else {
                for (int j=0;j<panjang;j++) {
                    cout << infop(infou(on).favorite).posting[j];
                }
                gotoxy(0,i+2);cout << "|                                            |";
            }
            gotoxy(0,i+3);cout << "|                            |love:  |hate:  |";
            gotoxy(36,i+3);cout << infop(infou(on).favorite).status/10;
            gotoxy(44,i+3);cout << infop(infou(on).favorite).status%10;
            gotoxy(0,i+4);cout << "+----------------------------+-------+-------+";
            i=i+5;
            jump++;
        }
        r=firstp(po);
        while (r!=NULL) {
            if (firstf(on)!=NULL) {
                q=firstf(on);
                while (q!=NULL) {
                    if ((infop(r).iduserp==on)or(infop(r).iduserp==infof(q))) {
                        gotoxy(0,i);cout << "|                                            |";
                        gotoxy(1,i);cout << infop(r).idpost << " @" << infou(infop(r).iduserp).nama;
                        gotoxy(0,i+1);cout << "|                                            |";
                        gotoxy(1,i+1);
                        int panjang = (infop(r).posting).length();
                        if (panjang>44) {
                            for (int j=0;j<44;j++) {
                                cout << infop(r).posting[j];
                            }
                            gotoxy(0,i+2);cout << "|                                            |";
                            gotoxy(1,i+2);
                            for (int j=44;j<panjang;j++) {
                                cout << infop(r).posting[j];
                            }
                        }
                        else {
                            for (int j=0;j<panjang;j++) {
                                cout << infop(r).posting[j];
                            }
                            gotoxy(0,i+2);cout << "|                                            |";
                        }
                        gotoxy(0,i+3);cout << "|                            |love:  |hate:  |";
                        gotoxy(36,i+3);cout << infop(r).status/10;
                        gotoxy(44,i+3);cout << infop(r).status%10;
                        gotoxy(0,i+4);cout << "+----------------------------+-------+-------+";
                        i=i+5;
                        jump++;
                        break;
                    }
                    q=nextf(q);
                }
            }
            else {
                if (infop(r).iduserp==on) {
                    gotoxy(0,i);cout << "|                                            |";
                    gotoxy(1,i);cout << infop(r).idpost << " @" << infou(infop(r).iduserp).nama;
                    gotoxy(0,i+1);cout << "|                                            |";
                    gotoxy(1,i+1);
                    int panjang = (infop(r).posting).length();
                    if (panjang>44) {
                        for (int j=0;j<44;j++) {
                            cout << infop(r).posting[j];
                        }
                        gotoxy(0,i+2);cout << "|                                            |";
                        gotoxy(1,i+2);
                        for (int j=44;j<panjang;j++) {
                            cout << infop(r).posting[j];
                        }
                    }
                    else {
                        for (int j=0;j<panjang;j++) {
                            cout << infop(r).posting[j];
                        }
                        gotoxy(0,i+2);cout << "|                                            |";
                    }
                    gotoxy(0,i+3);cout << "|                            |love:  |hate:  |";
                    gotoxy(36,i+3);cout << infop(r).status/10;
                    gotoxy(44,i+3);cout << infop(r).status%10;
                    gotoxy(0,i+4);cout << "+----------------------------+-------+-------+";
                    i=i+5;
                    jump++;
                }
            }
            r=nextp(r);
        }
        if (jump==0) {
            gotoxy(0,i);  cout << "|                                            |";
            gotoxy(0,i+1);cout << "|                                            |";
            gotoxy(0,i+2);cout << "|                                            |";
            gotoxy(0,i+3);cout << "|                            |love:  |hate:  |";
            gotoxy(0,i+4);cout << "+----------------------------+-------+-------+";
        }
    }
    else {
        gotoxy(0,i);  cout << "|                                            |";
        gotoxy(0,i+1);cout << "|                                            |";
        gotoxy(0,i+2);cout << "|                                            |";
        gotoxy(0,i+3);cout << "|                            |love:  |hate:  |";
        gotoxy(0,i+4);cout << "+----------------------------+-------+-------+";
    }
    gotoxy(0,0);
}

void editaccount(user &u, post &po, noti &n, address &on, bool &masuk) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    gotoxy(0,0);cout << "                        [E]ditAccount       [D]eleteAccount                     ";
    char comm = getch();
    if (comm=='e'||comm=='E') {
        gotoxy(23,10);cout << "                               ";
        gotoxy(23,11);cout << " +---------------------------+ ";
        gotoxy(23,12);cout << " |UserID :                   | ";
        gotoxy(23,13);cout << " |Pass   :                   | ";
        gotoxy(23,14);cout << " |Name   :                   | ";
        gotoxy(23,15);cout << " |Address:                   | ";
        gotoxy(23,16);cout << " |Hint   :                   | ";
        gotoxy(23,17);cout << " +---------------------------+ ";
        gotoxy(23,18);cout << "                               ";
        gotoxy(35,12);cout << infou(on).iduser;
        gotoxy(35,13);infou(on).pass=getpass("",true);
        gotoxy(35,14);cin >> infou(on).nama;
        gotoxy(35,15);cin >> infou(on).alamat;
        gotoxy(35,16);cin >> infou(on).hint;
    }
    else if (comm=='d'||comm=='D') {
        gotoxy(0,0);cout << "                               Are you sure (y/n)                               ";
        comm=getch();
        if (comm=='y'||comm=='Y') {
            address2 fd;
            if (firstn(n)!=NULL) {
                address4 nd = firstn(n);
                cout<<"4";
                while (nd!=NULL) {
                    if ((infon(nd).idusern0==on)or(infon(nd).idusern1==on)) {
                        address4 prec=nd;
                        nd=nextn(nd);
                        deleten(n,prec);
                    }
                    else
                        nd=nextn(nd);
                }
                cout<<"4";
            }
            if (firstf(on)!=NULL) {
                fd=firstf(on);
                cout<<"1";
                while (fd!=NULL) {
                    if (fd==firstf(on)) {
                        address2 prec=fd;
                        fd=nextf(fd);
                        deletef(u,on,prec);
                    }
                    else if (fd==lastf(on)) {
                        deletef(u,on,fd);
                    }
                    else{
                        fd=nextf(fd);
                        deletef(u,on,prevf(fd));
                    }
                }
                cout<<"1";
            }
            if (firstu(u)!=NULL) {
                address ud = firstu(u);
                cout << "5";
                while (ud!=NULL) {
                    if (infou(ud).favorite==NULL) {
                        ud=nextu(ud);
                    }
                    else if (infop(infou(ud).favorite).iduserp==on) {
                        address prec=ud;
                        ud=nextu(ud);
                        infou(prec).favorite=NULL;
                        }
                    else
                        ud=nextu(ud);
                }cout << "5";
            }
            if (firstu(u)!=NULL) {
                address ud = firstu(u);
                cout<<"2";
                address2 fd;
                while (ud!=NULL) {
                        cout<<"x";
                    if (firstf(ud)!=NULL) {
                        fd=firstf(ud);
                        while (fd!=NULL) {
                            cout<<"y";
                            if (infof(fd)==on) {
                                if (fd==firstf(ud)) {
                                    deletef(u,ud,fd);
                                    break;
                                }
                                else if (fd==lastf(ud)) {
                                    deletef(u,ud,fd);
                                    break;
                                }
                                else
                                    deletef(u,ud,fd);
                            }
                            fd=nextf(fd);
                        }
                    }
                    ud=nextu(ud);
                }cout<<"2";
            }
            deleteu(u,on);
            if (firstp(po)!=NULL) {
                address3 pd = firstp(po);
                cout<<"3";
                while (pd!=NULL) {
                    if (infop(pd).iduserp==on) {
                        address3 prec=pd;
                        pd=nextp(pd);
                        deletep(po,prec);
                        delete pd;
                    }
                    else
                        pd=nextp(pd);
                }
                cout<<"3";
            }
            delete on;
            masuk=false;
        }
    }
}


void editpost(post &po, user &u, noti &n, address on) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    gotoxy(0,0);cout << "                         [E]ditPost         [D]eletePost                        ";
    char comm = getch();
    int id;
    address3 p = firstp(po);
    address3 ketemu = NULL;
    if (comm=='e'||comm=='E') {
        gotoxy(0,0);cout << "Id Post :                                                  ";
        gotoxy(10,0);cin >> id;
        if (firstp(po)!=NULL) {
            while (p!=NULL) {
                if ((infop(p).idpost==id)and(infop(p).iduserp==on)) {
                    ketemu=p;
                }
                p=nextp(p);
            }
            if (ketemu!=NULL) {
                system("cls");
                gotoxy(0,0); cout << "                                                             +-----------------+";
                gotoxy(0,1); cout << "                                                            /             Post |";
                gotoxy(0,2); cout << "+----------------------------------------------------------+-------------------+";
                gotoxy(0,3); cout << "|                                                                              |";
                gotoxy(0,4); cout << "|                                                                              |";
                gotoxy(0,5); cout << "|                                                                              |";
                gotoxy(0,6); cout << "|                                                              |love:  |hate:  |";
                gotoxy(0,7); cout << "+--------------------------------------------------------------+-------+-------+";
                gotoxy(0,8); cout << "                                                                                ";
                gotoxy(0,8); cout << "                                                                                ";
                gotoxy(70,6);cout << infop(ketemu).status/10;
                gotoxy(78,6);cout << infop(ketemu).status%10;
                gotoxy(1,3); cout << infop(ketemu).idpost << " @" << infou(infop(ketemu).iduserp).nama;
                gotoxy(1,4);ws(cin);getline(cin,infop(ketemu).posting);
            }
            else {
                gotoxy(0,0);cout << "Data not found";
            }
        }
        else {
            gotoxy(0,0);cout << "Data not found";
        }
    }
    else if (comm=='d'||comm=='D') {
        gotoxy(0,0);cout << "Id Post :                                                  ";
        gotoxy(10,0);cin >> id;
        if (firstp(po)!=NULL) {
            while (p!=NULL) {
                if ((infop(p).idpost==id)and(infop(p).iduserp==on)) {
                    ketemu=p;
                }
                p=nextp(p);
            }
            if (ketemu!=NULL) {
                gotoxy(0,0);cout << "                               Are you sure (y/n)                               ";
                comm=getch();
                if (comm=='y'||comm=='Y') {
                    deletep(po,ketemu);
                    if (firstu(u)!=NULL) {
                        address ud = firstu(u);
                        while (ud!=NULL) {
                            if (infou(ud).favorite==ketemu) {
                                infou(ud).favorite=NULL;
                            }
                            ud=nextu(ud);
                        }
                    }
                    if (firstn(n)!=NULL) {
                        address4 nd = firstn(n);
                        while (nd!=NULL) {
                            if ((infon(nd).idusern0==on)or(infon(nd).idusern1==on)) {
                                address4 prec=nd;
                                nd=nextn(nd);
                                deleten(n,prec);
                            }
                            else
                                nd=nextn(nd);
                        }
                    }
                    delete ketemu;
                }
            }
            else {
                gotoxy(0,0);cout << "Data not found";
            }
        }
        else {
            gotoxy(0,0);cout << "Data not found";
        }
    }
}


void posit (post &po, address on, int &id) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    posts in;
    id++;
    in.idpost=id;
    in.iduserp=on;
    in.status=0;
    system("cls");
    gotoxy(0,0); cout << "                                                             +-----------------+";
    gotoxy(0,1); cout << "                                                            /             Post |";
    gotoxy(0,2); cout << "+----------------------------------------------------------+-------------------+";
    gotoxy(0,3); cout << "|                                                                              |";
    gotoxy(0,4); cout << "|                                                                              |";
    gotoxy(0,5); cout << "|                                                                              |";
    gotoxy(0,6); cout << "|                                                              |love:  |hate:  |";
    gotoxy(0,7); cout << "+--------------------------------------------------------------+-------+-------+";
    gotoxy(0,8); cout << "                                                                                ";
    gotoxy(0,8); cout << "                                                                                ";
    gotoxy(1,3); cout << in.idpost << " @" << infou(on).nama;
    gotoxy(1,4);ws(cin);getline(cin,in.posting);
    address3 p = alokasip(in);
    insertfirstp(po,p);
}

void searchuser(user &u, address &on, noti &n) {
    /* Nama : eri sadewo
       NIM  : 1301140022
    */
    notis in;
    string nama,id;
    address p=firstu(u);
    address ketemu=NULL;
    gotoxy(0,0);cout << "                       SearchBy[I]d        SearchBy[N]ame                       ";
    char comm = getch();
    if (comm=='i'||comm=='I') {
        gotoxy(0,0);cout << "User Id :                                                    ";
        gotoxy(10,0);cin >> id;
        if (firstu(u)!=NULL){
            while(p!=NULL) {
                if (id==infou(p).iduser) {
                    ketemu=p;
                }
                p=nextu(p);
            }
        }
    }
    else if (comm=='n'||comm=='N') {
        gotoxy(0,0);cout << "User Name :                                                    ";
        gotoxy(12,0);cin >> nama;
        if (firstu(u)!=NULL){
            while(p!=NULL) {
                if (nama==infou(p).nama) {
                    ketemu=p;
                }
                p=nextu(p);
            }
        }
    }
    if (ketemu==on) {
        ketemu=NULL;
    }
    if (((comm=='n')or(comm=='N')or(comm=='i')or(comm=='I'))and(ketemu!=NULL)) {
        gotoxy(23,9); cout << "                               ";
        gotoxy(23,10);cout << " +---------------------------+ ";
        gotoxy(23,11);cout << " |UserID :                   | ";
        gotoxy(23,12);cout << " |Name   :                   | ";
        gotoxy(23,13);cout << " |Address:                   | ";
        gotoxy(23,14);cout << " +---------------------------+ ";
        gotoxy(23,15);cout << "           [F]ollow            ";
        gotoxy(23,16);cout << "                               ";
        gotoxy(35,11);cout << infou(ketemu).iduser;
        gotoxy(35,12);cout << infou(ketemu).nama;
        gotoxy(35,13);cout << infou(ketemu).alamat;
        comm=getch();
        if (comm=='f'||comm=='F') {
            address2 follow=alokasif(ketemu);
            insertfirstf(u,on,follow);
            in.idusern1=on;
            in.idusern0=ketemu;
            in.idpostn=NULL;
            in.cond=3;
            address4 noc=alokasin(in);
            insertfirstn(n,noc);
        }
    }
    else if (((comm=='n')or(comm=='N')or(comm=='i')or(comm=='I'))and(ketemu==NULL)) {
        gotoxy(0,0); cout << "                       Data Not Found                                           ";
    }
}


void searchpost(user &u, post &po, address &on, noti &n) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    notis in;
    int idp;
    address3 p=firstp(po);
    address3 ketemu=NULL;
    gotoxy(0,0);cout << "Post Id :                                                                       ";
    gotoxy(10,0);cin >> idp;
    if (firstp(po)!=NULL){
        while(p!=NULL) {
            if (idp==infop(p).idpost) {
                ketemu=p;
            }
            p=nextp(p);
        }
    }
    if (ketemu!=NULL) {
        system("cls");
        gotoxy(0,0); cout << "                                                             +-----------------+";
        gotoxy(0,1); cout << "                                                            /             Post |";
        gotoxy(0,2); cout << "+----------------------------------------------------------+-------------------+";
        gotoxy(0,3); cout << "|                                                                              |";
        gotoxy(0,4); cout << "|                                                                              |";
        gotoxy(0,5); cout << "|                                                                              |";
        gotoxy(0,6); cout << "|                                                              |love:  |hate:  |";
        gotoxy(0,7); cout << "+--------------------------------------------------------------+-------+-------+";
        gotoxy(0,8); cout << "                        [L]ove   [H]ate   [F]avorite                            ";
        gotoxy(70,6);cout << infop(ketemu).status/10;
        gotoxy(78,6);cout << infop(ketemu).status%10;
        gotoxy(1,3); cout << infop(ketemu).idpost << " @" << infou(infop(ketemu).iduserp).nama;
        gotoxy(1,4); cout << infop(ketemu).posting;
        char comm=getch();
        if (comm=='l'||comm=='L') {
            infop(ketemu).status=infop(ketemu).status+10;
            in.idusern0=infop(ketemu).iduserp;
            in.idusern1=on;
            in.idpostn=ketemu;
            in.cond=1;
            address4 no = alokasin(in);
            insertfirstn(n,no);
        }
        else if (comm=='h'||comm=='H') {
            infop(ketemu).status=infop(ketemu).status+1;
            in.idusern0=infop(ketemu).iduserp;
            in.idusern1=on;
            in.idpostn=ketemu;
            in.cond=2;
            address4 no = alokasin(in);
            insertfirstn(n,no);
        }
        else if (comm=='f'||comm=='F') {
            infou(on).favorite=ketemu;
            in.idusern0=infop(ketemu).iduserp;
            in.idusern1=on;
            in.idpostn=ketemu;
            in.cond=0;
            address4 no = alokasin(in);
            insertfirstn(n,no);
        }
    }
}


void deletenoti(noti &n, address on) {
    /* Nama : hafiz prahasta
       NIM  : 1301140057
    */
    if (firstn(n)!=NULL) {
        address4 p=firstn(n);
        while (p!=NULL) {
            if (infon(p).idusern0==on) {
                deleten(n,p);
            }
            p=nextn(p);
        }
    }
}
