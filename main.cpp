// Onur KOSELER 330209 2. OGRETÝM

#include <iostream>
#include <fstream>
using namespace std;
class Akademisyen{
public:

    void setsicil_no(string sic);
    void setad(string a);
    void setsoyad(string s);
    void setabd(string anab);
    void seteposta(string ep);
    void settelefon(string tel);
    void setunvan(string un);
    void yazdir(){
        cout<<"sicilno:"<<sicil_no<<endl;
        cout<<"ad:"<<ad<<endl;
        cout<<"soyad:"<<soyad<<endl;
        cout<<"anabilimdali:"<<abd<<endl;
        cout<<"eposta:"<<eposta<<endl;
        cout<<"telefon:"<<telefon<<endl;
        cout<<"unvan:"<<unvan<<endl;
        cout<<endl;


    }

    string getsicil_no();
    string getad();
    string getsoyad();
    string getabd();
    string geteposta();
    string gettelefon();
    string getunvan();


private:
    string sicil_no;
    string ad;
    string soyad;
    string abd;
    string eposta;
    string telefon;
    string unvan;

};
void Akademisyen::setsicil_no(string sic)
{
     sicil_no =sic;
}
void Akademisyen ::setad(string a)
{
    ad = a;
}
void Akademisyen::setsoyad(string s)
{
    soyad = s;
}
void Akademisyen::setabd(string anab)
{
    abd = anab;
}
void Akademisyen ::seteposta(string ep)
{
    eposta = ep;
}
void Akademisyen::settelefon(string tel)
{
    telefon = tel;
}
void Akademisyen::setunvan(string un)
{
    unvan = un;
}
string Akademisyen::getsicil_no()
{
    return sicil_no;
}
string Akademisyen::getad()
{
    return ad;
}
string Akademisyen::getsoyad()
{
    return soyad;

}
string Akademisyen::getabd()
{
    return abd;
}
string Akademisyen::geteposta()
{
    return eposta;
}
string Akademisyen::gettelefon()
{
    return telefon;
}
string Akademisyen::getunvan()
{
    return unvan;
}
class Ogrenci{
public:

    void setnumara(string no);
    void setad(string a);
    void setsoyad(string s);
    void setbolum(string b);
    void setkayit_yili(string ky);
    void seteposta(string ep);
    void settelefon(string tel);
    void yazdir(){
        cout<<"no:"<<numara<<endl;
        cout<<"ad:"<<ad<<endl;
        cout<<"soyad:"<<soyad<<endl;
        cout<<"bolum:"<<bolum<<endl;
        cout<<"eposta:"<<eposta<<endl;
        cout<<"telefon:"<<telefon<<endl;
        cout<<"kayit yili:"<<kayit_yili<<endl;
    }
    string getnumara();
    string getad();
    string getsoyad();
    string getbolum();
    string getkayit_yili();
    string geteposta();
    string gettelefon();
private:
    string numara;
    string ad;
    string soyad;
    string bolum;
    string kayit_yili;
    string eposta;
    string telefon;
};
void Ogrenci::setnumara(string no)
{
    numara = no;
}
void Ogrenci::setad(string a)
{
    ad = a;
}
void Ogrenci ::setsoyad(string s)
{
    soyad = s;
}
void Ogrenci::setbolum(string b)
{
    bolum = b;
}
void Ogrenci::setkayit_yili(string ky)
{
    kayit_yili = ky;
}
void Ogrenci ::seteposta(string ep)
{
    eposta = ep;
}
void Ogrenci ::settelefon(string tel)
{
    telefon = tel;
}
string Ogrenci::getnumara()
{
    return numara;
}
string Ogrenci ::getad()
{
    return ad;
}
string Ogrenci ::getsoyad()
{
    return soyad;
}
string Ogrenci ::getbolum()
{
    return bolum;
}
string Ogrenci::getkayit_yili()
{
    return kayit_yili;
}
string Ogrenci::geteposta()
{
    return eposta;
}
string Ogrenci::gettelefon()
{
    return telefon;
}
class Zaman{
public:

    void settarih(string tar);
    void setbassaat(string bs);
    void setbitsaat(string fs);
    string gettarih();
    string getbassaat();
    string getbitsaat();
    void yazdir(){
        cout<<"tarih:"<<tarih<<endl;
        cout<<"baslangic saati:"<<bassaat<<endl;
        cout<<"bitis saati:"<<bitsaat<<endl;
    }


private:
    string tarih;
    string bassaat;
    string bitsaat;
};

void Zaman::settarih(string tar)
{
    tarih = tar;
}
void Zaman::setbassaat(string bs)
{
    bassaat = bs;
}
void Zaman::setbitsaat(string fs)
{
    bitsaat = fs;
}
string Zaman::gettarih()
{
    return tarih;
}
string Zaman::getbassaat()
{
    return bassaat;
}
string Zaman::getbitsaat()
{
    return bitsaat;
}
//base class
class Randevu:public Ogrenci,public Akademisyen,public Zaman{
    public:

        void randevuyazdir(){
            string an,on,tr,bn;
            string dosyain = "c.txt";
            ifstream dosya;
            dosya.open("c.txt");
            while(!dosya.eof())
            {
                dosya >> an;
                dosya >> on;
                dosya >> tr;
                dosya >> bn;
            }
            if((an == getsicil_no() && tr == gettarih()&&bn == getbassaat())||(on == getnumara()&&tr == gettarih()&&bn == getbassaat()))
                cout<<"cakisma var, randevu verilemez....."<<endl;
            else
            {
                std::ofstream dosya2;
                dosya2.open("c.txt",std :: ios::app);
                dosya2 <<endl;
                dosya2 <<getnumara()<<" ";
                dosya2 <<getsicil_no()<<" ";

                dosya2 <<gettarih()<<" ";
                dosya2 <<getbassaat()<<" ";
                dosya2 <<getbitsaat();
                //dosya2 << endl;
                dosya2.close();}




        /*c0out<<"sicil_no:"<<getsicil_no()<<endl;
        cout<<"ogrenci no:"<<getnumara()<<endl;
        cout<<"tarih:"<<gettarih()<<endl;
        cout<<"baslangic saati:"<<getbassaat()<<endl;
        cout<<"bitis saati:"<<getbitsaat()<<endl;*/
        }
        void ogrenciekle(){
            string on,ad,so,bo,ky,epo,tele,no;
            cout<<"eklemek istediginiz ogrenci numarasini giriniz."<<endl;
            cin>>on;
            string dosyain = "b.txt";
            ifstream dosya;
            dosya.open("b.txt");
            while(!dosya.eof())
            {
                dosya>>no;
                dosya>>ad;
                dosya>>so;
                dosya>>bo;
                dosya>>ky;
                dosya>>epo;
                dosya>>tele;
                if(no==on)
                    break;
       // dosya1>>un;
            }
            if(no == on)
            {
                cout<<"bu numarada ogrenci vardir, lütfen kontrol ediniz. "<<endl;
            }
            else
            {
                string a,s,b,k,e,t;
                cout<<"eklenmek istenen ogrencinin adini giriniz."<<endl;
                cin>>a;
                cout<<"eklenmek istenen ogrencinin soyadini giriniz."<<endl;
                cin>>s;
                cout<<"eklenmek istenen ogrencinin bolumunu giriniz."<<endl;
                cin>>b;
                cout<<"eklenmek istenen ogrencinin kayit yilini giriniz."<<endl;
                cin>>k;
                cout<<"eklenmek istenen ogrencinin epostasini giriniz."<<endl;
                cin>>e;
                cout<<"eklenmek istenen ogrencinin telefonunu giriniz."<<endl;
                cin>>t;




                std::ofstream dosya2;
                dosya2.open("b.txt", std :: ios::app);
                dosya2 << endl;


                dosya2 <<on<<" ";
                dosya2 <<a<<" ";
                dosya2 <<s<<" ";
                dosya2 <<b<<" ";
                dosya2 <<k<<" ";
                dosya2 <<e<<" ";
                dosya2 <<t;
                //dosya2 << endl;

                dosya2.close();


            }
        }
        void akademisyenekle()
        {
                string on,ad,so,bo,un,epo,tele,sic;
                cout<<"eklemek istediginiz akademisyenin numarasini giriniz."<<endl;
                cin>>on;
                string dosyain = "a.txt";
                ifstream dosya;
                dosya.open("a.txt");
                while(!dosya.eof())
            {
                    dosya>>sic;
                    dosya>>ad;
                    dosya>>so;
                    dosya>>bo;
                    dosya>>epo;
                    dosya>>tele;
                    dosya>>un;
                    if(sic==on)
                        break;
       // dosya1>>un;
            }
            if(sic == on)
            {
                cout<<"bu numarada akademisyen vardir, lutfen kontrol ediniz. "<<endl;
            }
            else
            {
                string a,s,b,u,e,t;
                cout<<"eklenmek istenen akademisyenin adini giriniz."<<endl;
                cin>>a;
                cout<<"eklenmek istenen akademisyenin soyadini giriniz."<<endl;
                cin>>s;
                cout<<"eklenmek istenen akademisyenin anabilimdalini giriniz."<<endl;
                cin>>b;
                cout<<"eklenmek istenen akademisyenin epostasini giriniz."<<endl;
                cin>>e;
                cout<<"eklenmek istenen akademisyenin telefonunu giriniz."<<endl;
                cin>>t;
                cout<<"eklenmek istenen akademisyenin unvanini giriniz."<<endl;
                cin>>u;




                std::ofstream dosya2;
                dosya2.open("a.txt", std :: ios::app);
                dosya2 << endl;


                dosya2 <<on<<" ";
                dosya2 <<a<<" ";
                dosya2 <<s<<" ";
                dosya2 <<b<<" ";
                dosya2 <<e<<" ";
                dosya2 <<t<<" ";
                dosya2 <<u;
                //dosya2 << endl;

                dosya2.close();


            }
        }
        void akademisyenlistele()
        {
            string ad,so,bo,un,epo,tele,sic;
            string dosyain = "a.txt";
                ifstream dosya;
                dosya.open("a.txt");
                while(!dosya.eof())
            {
                    dosya>>sic;
                    dosya>>ad;
                    dosya>>so;
                    dosya>>bo;
                    dosya>>epo;
                    dosya>>tele;
                    dosya>>un;
                    cout<<sic<<" "<<ad<<" "<<so<<" "<<bo<<" "<<epo<<" "<<tele<<" "<<un<<endl;

       // dosya1>>un;
            }
        }
        void ogrencilistele()
        {   string ad,so,bo,ky,epo,tele,no;
            string dosyain = "b.txt";
            ifstream dosya;
            dosya.open("b.txt");
            while(!dosya.eof())
            {
                dosya>>no;
                dosya>>ad;
                dosya>>so;
                dosya>>bo;
                dosya>>ky;
                dosya>>epo;
                dosya>>tele;
                cout<<no<<" "<<ad<<" "<<so<<" "<<bo<<" "<<ky<<" "<<epo<<" "<<tele<<endl;
       // dosya1>>un;
            }
        }
        void randevulistele()
        {
            string tar,bass,bits,sic,no;
            string dosyain = "c.txt";
            ifstream dosya;
            dosya.open("c.txt");
            while(!dosya.eof())
            {
                dosya>>no;
                dosya>>sic;
                dosya>>tar;
                dosya>>bass;
                dosya>>bits;
                cout<<no<<" "<<sic<<" "<<tar<<" "<<bass<<" "<<bits<<endl;
       // dosya1>>un;
            }
        }
        void ogrencisil()
        {
            string on;
            cout<<"silmek istediginiz ogrenci numarasini giriniz."<<endl;
            cin>>on;
            //string dosyain = "b.txt";
            std::ifstream dosya;
            dosya.open("b.txt");

            while(!dosya.eof())
            {
                string ad,so,bo,ky,epo,tele,no;
                dosya>>no;
                dosya>>ad;
                dosya>>so;
                dosya>>bo;
                dosya>>ky;
                dosya>>epo;
                dosya>>tele;
                std::ofstream dosya2;
                dosya2.open("d.txt", std :: ios::app);
                dosya2 << endl;
                if(no == on)
                {
                     no="";
                     ad="";
                     so ="";
                     bo="";
                     ky="";
                     epo="";
                     tele="";

                        dosya2 <<no<<" ";
                        dosya2 <<ad<<" ";
                        dosya2 <<so<<" ";
                        dosya2 <<bo<<" ";
                        dosya2 <<ky<<" ";
                        dosya2 <<epo<<" ";
                        dosya2 <<tele;
                        dosya2.close();
                }
               else{
                        dosya2 <<no<<" ";
                        dosya2 <<ad<<" ";
                        dosya2 <<so<<" ";
                        dosya2 <<bo<<" ";
                        dosya2 <<ky<<" ";
                        dosya2 <<epo<<" ";
                        dosya2 <<tele;
                        dosya2.close();
                }
            }

            string ad,so,bo,ky,epo,tele,no;
            //cout<<"silmek istediginiz ogrenci numarasini giriniz."<<endl;
            //cin>>on;
            string dosyain = "d.txt";
            ifstream dosya3;
            dosya3.open("d.txt");
            std::ofstream dosya4;
            dosya4.open("b.txt",std :: ios::trunc);

                while(!dosya3.eof())
                    {
                    dosya3>>no;
                    dosya3>>ad;
                    dosya3>>so;
                    dosya3>>bo;
                    dosya3>>ky;
                    dosya3>>epo;
                    dosya3>>tele;


                    std::ofstream dosya4;
                    //dosya4.open("b.txt",std :: ios::trunc);
                    dosya4.open("b.txt",std::ios::app);

                //dosya2 << endl;


                    dosya4 <<no<<" ";
                    dosya4 <<ad<<" ";
                    dosya4 <<so<<" ";
                    dosya4 <<bo<<" ";
                    dosya4 <<ky<<" ";
                    dosya4 <<epo<<" ";
                    dosya4 <<tele;
                    dosya4 << endl;
                    dosya4.close();

                }
                std::ofstream dosya5;
                dosya5.open("d.txt",std :: ios::trunc);
                dosya5.close();
            }
            void akademisyensil()
            {
            string on;
            cout<<"silmek istediginiz akademisyen sicil numarasini giriniz."<<endl;
            cin>>on;
            //string dosyain = "b.txt";
            std::ifstream dosya;
            dosya.open("a.txt");

            while(!dosya.eof())
            {
                string ad,so,bo,un,epo,tele,sic;
                dosya>>sic;
                dosya>>ad;
                dosya>>so;
                dosya>>bo;
                dosya>>epo;
                dosya>>tele;
                dosya>>un;
                std::ofstream dosya2;
                dosya2.open("d.txt", std :: ios::app);
                dosya2 << endl;
                if(sic == on)
                {
                     sic="";
                     ad="";
                     so ="";
                     bo="";
                     epo="";
                     tele="";
                     un="";

                        dosya2 <<sic<<" ";
                        dosya2 <<ad<<" ";
                        dosya2 <<so<<" ";
                        dosya2 <<bo<<" ";
                        dosya2 <<epo<<" ";
                        dosya2 <<tele<<" ";
                        dosya2 <<un;
                        dosya2.close();
                }
               else{
                         dosya2 <<sic<<" ";
                        dosya2 <<ad<<" ";
                        dosya2 <<so<<" ";
                        dosya2 <<bo<<" ";
                        dosya2 <<epo<<" ";
                        dosya2 <<tele<<" ";
                        dosya2 <<un;
                        dosya2.close();
                }
            }

            string ad,so,bo,un,epo,tele,sic;
            //cout<<"silmek istediginiz ogrenci numarasini giriniz."<<endl;
            //cin>>on;
            string dosyain = "d.txt";
            ifstream dosya3;
            dosya3.open("d.txt");
            std::ofstream dosya4;
            dosya4.open("a.txt",std :: ios::trunc);

                while(!dosya3.eof())
                    {
                    dosya3>>sic;
                    dosya3>>ad;
                    dosya3>>so;
                    dosya3>>bo;

                    dosya3>>epo;
                    dosya3>>tele;
                    dosya3>>un;


                    std::ofstream dosya4;
                    //dosya4.open("b.txt",std :: ios::trunc);
                    dosya4.open("a.txt",std::ios::app);

                //dosya2 << endl;


                    dosya4 <<sic<<" ";
                    dosya4 <<ad<<" ";
                    dosya4 <<so<<" ";
                    dosya4 <<bo<<" ";

                    dosya4 <<epo<<" ";
                    dosya4 <<tele<<" ";
                    dosya4 <<un;
                    dosya4 << endl;
                    dosya4.close();

                }
                std::ofstream dosya5;
                dosya5.open("d.txt",std :: ios::trunc);
                dosya5.close();
            }
            void randevusil()
            {
                string on,ono;
                cout<<"silmek istediginiz akademisyen sicil numarasini giriniz."<<endl;
                cin>>on;
                cout<<"silmek istediginiz ogrenci numarasini giriniz."<<endl;
                cin>>ono;
                std::ifstream dosya;
                dosya.open("c.txt");

            while(!dosya.eof()){

                string tar,bass,bits,sic,no;
                dosya>>no;
                dosya>>sic;
                dosya>>tar;
                dosya>>bass;
                dosya>>bits;
                std::ofstream dosya2;
                dosya2.open("d.txt", std :: ios::app);
                dosya2 << endl;
                if(sic == on && no == ono )
                {
                     no="";
                     sic="";
                     tar ="";
                     bass="";
                     bits="";


                        dosya2 <<no<<" ";
                        dosya2 <<sic<<" ";
                        dosya2 <<tar<<" ";
                        dosya2 <<bass<<" ";
                        dosya2 <<bits;
                        dosya2.close();
                }
               else{
                         dosya2 <<no<<" ";
                        dosya2 <<sic<<" ";
                        dosya2 <<tar<<" ";
                        dosya2 <<bass<<" ";
                        dosya2 <<bits;
                        dosya2.close();
                }
            }

            string tar,bass,bits,sic,no;
            //cout<<"silmek istediginiz ogrenci numarasini giriniz."<<endl;
            //cin>>on;
            string dosyain = "d.txt";
            ifstream dosya3;
            dosya3.open("d.txt");
            std::ofstream dosya4;
            dosya4.open("c.txt",std :: ios::trunc);

                while(!dosya3.eof())
                    {
                    dosya3>>no;
                    dosya3>>sic;
                    dosya3>>tar;
                    dosya3>>bass;

                    dosya3>>bits;


                    std::ofstream dosya4;
                    //dosya4.open("b.txt",std :: ios::trunc);
                    dosya4.open("c.txt",std::ios::app);

                //dosya2 << endl;


                    dosya4 <<no<<" ";
                    dosya4 <<sic<<" ";
                    dosya4 <<tar<<" ";
                    dosya4 <<bass<<" ";

                    dosya4 <<bits;
                    dosya4 << endl;
                    dosya4.close();

                }
                std::ofstream dosya5;
                dosya5.open("d.txt",std :: ios::trunc);
                dosya5.close();
            }
            void akademisyenguncelle()
            {
                string on;
            cout<<"degistirmek istediginiz akademisyen sicil numarasini giriniz."<<endl;
            cin>>on;
            string ad1,so1,anab,epos,telef,unv,yenino;
            cout<<"degistirmek istediginiz akademisyen yeni sicil numarasini giriniz."<<endl;
            cin>>yenino;
            cout<<"degistirmek istediginiz akademisyen adini  giriniz."<<endl;
            cin>> ad1;
            cout<<"degistirmek istediginiz akademisyen soyadini  giriniz."<<endl;
            cin>> so1;
            cout<<"degistirmek istediginiz akademisyen anabilimdalini   giriniz."<<endl;
            cin>> anab;
            cout<<"degistirmek istediginiz akademisyen epostasini  giriniz."<<endl;
            cin>> epos;
            cout<<"degistirmek istediginiz akademisyenin telefon numarasini giriniz."<<endl;
            cin>> telef;
            cout<<"degistirmek istediginiz akademisyenin unvanini giriniz."<<endl;
            cin>> unv;
            //string dosyain = "b.txt";
            std::ifstream dosya;
            dosya.open("a.txt");

            while(!dosya.eof())
            {
                string ad,so,bo,un,epo,tele,sic;
                dosya>>sic;
                dosya>>ad;
                dosya>>so;
                dosya>>bo;
                dosya>>epo;
                dosya>>tele;
                dosya>>un;
                std::ofstream dosya2;
                dosya2.open("d.txt", std :: ios::app);
                dosya2 << endl;
                if(sic == on)
                {
                     sic = yenino;
                     ad=ad1;
                     so =so1;
                     bo=anab;
                     epo=epos;
                     tele=telef;
                     un=unv;

                        dosya2 <<sic<<" ";
                        dosya2 <<ad<<" ";
                        dosya2 <<so<<" ";
                        dosya2 <<bo<<" ";
                        dosya2 <<epo<<" ";
                        dosya2 <<tele<<" ";
                        dosya2 <<un;
                        dosya2.close();
                }
               else{
                         dosya2 <<sic<<" ";
                        dosya2 <<ad<<" ";
                        dosya2 <<so<<" ";
                        dosya2 <<bo<<" ";
                        dosya2 <<epo<<" ";
                        dosya2 <<tele<<" ";
                        dosya2 <<un;
                        dosya2.close();
                }
            }

            string ad,so,bo,un,epo,tele,sic;
            //cout<<"silmek istediginiz ogrenci numarasini giriniz."<<endl;
            //cin>>on;
            string dosyain = "d.txt";
            ifstream dosya3;
            dosya3.open("d.txt");
            std::ofstream dosya4;
            dosya4.open("a.txt",std :: ios::trunc);

                while(!dosya3.eof())
                    {
                    dosya3>>sic;
                    dosya3>>ad;
                    dosya3>>so;
                    dosya3>>bo;

                    dosya3>>epo;
                    dosya3>>tele;
                    dosya3>>un;


                    std::ofstream dosya4;
                    //dosya4.open("b.txt",std :: ios::trunc);
                    dosya4.open("a.txt",std::ios::app);

                //dosya2 << endl;


                    dosya4 <<sic<<" ";
                    dosya4 <<ad<<" ";
                    dosya4 <<so<<" ";
                    dosya4 <<bo<<" ";

                    dosya4 <<epo<<" ";
                    dosya4 <<tele<<" ";
                    dosya4 <<un;
                    dosya4 << endl;
                    dosya4.close();

                }
                std::ofstream dosya5;
                dosya5.open("d.txt",std :: ios::trunc);
                dosya5.close();
            }
            void ogrenciguncelle()
            {
                string on;
            cout<<"degistirmek istediginiz ogrenci  numarasini giriniz."<<endl;
            cin>>on;
            string ad1,so1,anab,epos,telef,unv,yenino,ky1;
            cout<<"degistirmek istediginiz ogrencinin yeni  numarasini giriniz."<<endl;
            cin>>yenino;
            cout<<"degistirmek istediginiz ogrenci adini  giriniz."<<endl;
            cin>> ad1;
            cout<<"degistirmek istediginiz ogrenci soyadini  giriniz."<<endl;
            cin>> so1;
            cout<<"degistirmek istediginiz ogrenci bolumunu   giriniz."<<endl;
            cin>> anab;
            cout<<"degistirmek istediginiz ogrenci kayit yilini   giriniz."<<endl;
            cin>> ky1;
            cout<<"degistirmek istediginiz ogrenci epostasini  giriniz."<<endl;
            cin>> epos;
            cout<<"degistirmek istediginiz ogrencinin telefon numarasini giriniz."<<endl;
            cin>> telef;
            //string dosyain = "b.txt";
            std::ifstream dosya;
            dosya.open("b.txt");

            while(!dosya.eof())
            {
                string ad,so,bo,ky,epo,tele,no;
                dosya>>no;
                dosya>>ad;
                dosya>>so;
                dosya>>bo;
                dosya>>ky;
                dosya>>epo;
                dosya>>tele;
                std::ofstream dosya2;
                dosya2.open("d.txt", std :: ios::app);
                dosya2 << endl;
                if(no == on)
                {
                     no = yenino;
                     ad=ad1;
                     so =so1;
                     bo=anab;
                     ky = ky1;
                     epo=epos;
                     tele=telef;

                        dosya2 <<no<<" ";
                        dosya2 <<ad<<" ";
                        dosya2 <<so<<" ";
                        dosya2 <<bo<<" ";
                        dosya2<< ky<<" ";
                        dosya2 <<epo<<" ";
                        dosya2 <<tele;
                        dosya2.close();
                }
               else{
                        dosya2 <<no<<" ";
                        dosya2 <<ad<<" ";
                        dosya2 <<so<<" ";
                        dosya2 <<bo<<" ";
                        dosya2<< ky<<" ";
                        dosya2 <<epo<<" ";
                        dosya2 <<tele;
                        dosya2.close();
                }
            }

            string ad,so,bo,un,epo,tele,sic,no,ky;
            //cout<<"silmek istediginiz ogrenci numarasini giriniz."<<endl;
            //cin>>on;
            string dosyain = "d.txt";
            ifstream dosya3;
            dosya3.open("d.txt");
            std::ofstream dosya4;
            dosya4.open("b.txt",std :: ios::trunc);

                while(!dosya3.eof())
                    {
                    dosya3>>no;
                    dosya3>>ad;
                    dosya3>>so;
                    dosya3>>bo;
                    dosya3>>ky;
                    dosya3>>epo;
                    dosya3>>tele;


                    std::ofstream dosya4;
                    //dosya4.open("b.txt",std :: ios::trunc);
                    dosya4.open("b.txt",std::ios::app);

                //dosya2 << endl;


                    dosya4 <<no<<" ";
                    dosya4 <<ad<<" ";
                    dosya4 <<so<<" ";
                    dosya4 <<bo<<" ";
                    dosya4 <<ky<<" ";
                    dosya4 <<epo<<" ";
                    dosya4 <<tele;
                    dosya4 << endl;
                    dosya4.close();

                }
                std::ofstream dosya5;
                dosya5.open("d.txt",std :: ios::trunc);
                dosya5.close();
            }
            void randevuguncelle()
            {
                string on,ono;
                cout<<"guncellemek istediginiz akademisyen sicil numarasini giriniz."<<endl;
                cin>>on;
                cout<<"guncellemek istediginiz ogrenci numarasini giriniz."<<endl;
                cin>>ono;

                string ano1,ono1,ttar,basss,bitss;
                cout<<"lutfen yeni ogrenci nosunu girin"<<endl;
                cin>>ono1;
                cout<<"lutfen yeni akademisyen sicil nosunu girin"<<endl;
                cin>>ano1;
                cout<<"lutfen yeni randevu tarihi girin."<<endl;
                cin>>ttar;
                cout<<"lutfen yeni randevu baslangic saati girin"<<endl;
                cin>>basss;
                cout<<"lutfen yeni randevu bitis saati girin"<<endl;
                cin>>bitss;

                std::ifstream dosya;
                dosya.open("c.txt");

            while(!dosya.eof()){

                string tar,bass,bits,sic,no;
                dosya>>no;
                dosya>>sic;
                dosya>>tar;
                dosya>>bass;
                dosya>>bits;
                std::ofstream dosya2;
                dosya2.open("d.txt", std :: ios::app);
                dosya2 << endl;
                if(sic == on && no == ono )
                {
                     no=ono1;
                     sic=ano1;
                     tar =ttar;
                     bass=basss;
                     bits=bitss;


                        dosya2 <<no<<" ";
                        dosya2 <<sic<<" ";
                        dosya2 <<tar<<" ";
                        dosya2 <<bass<<" ";
                        dosya2 <<bits;
                        dosya2.close();
                }
               else{
                         dosya2 <<no<<" ";
                        dosya2 <<sic<<" ";
                        dosya2 <<tar<<" ";
                        dosya2 <<bass<<" ";
                        dosya2 <<bits;
                        dosya2.close();
                }
            }

            string tar,bass,bits,sic,no;
            //cout<<"silmek istediginiz ogrenci numarasini giriniz."<<endl;
            //cin>>on;
            string dosyain = "d.txt";
            ifstream dosya3;
            dosya3.open("d.txt");
            std::ofstream dosya4;
            dosya4.open("c.txt",std :: ios::trunc);

                while(!dosya3.eof())
                    {
                    dosya3>>no;
                    dosya3>>sic;
                    dosya3>>tar;
                    dosya3>>bass;

                    dosya3>>bits;


                    std::ofstream dosya4;
                    //dosya4.open("b.txt",std :: ios::trunc);
                    dosya4.open("c.txt",std::ios::app);

                //dosya2 << endl;


                    dosya4 <<no<<" ";
                    dosya4 <<sic<<" ";
                    dosya4 <<tar<<" ";
                    dosya4 <<bass<<" ";

                    dosya4 <<bits;
                    dosya4 << endl;
                    dosya4.close();

                }
                std::ofstream dosya5;
                dosya5.open("d.txt",std :: ios::trunc);
                dosya5.close();
            }



    private:

};
int main()
{
    int a,b;
    a = 2;
    while(a != b ){
    int secenek;
    Randevu r1;

    cout<<"asagidaki seceneklerinizi okuyunuz."<<endl;
    cout<<"1) Ogrenci Ekle:"<<endl;
    cout<<"2) Akademisyen Ekle:"<<endl;
    cout<<"3) Randevu Ekle:"<<endl;
    cout<<"4) Akademisyen Listele:"<<endl;
    cout<<"5) Ogrenci Listele:"<<endl;
    cout<<"6) Randevu Listele:"<<endl;
    cout<<"7) Ogrenci Sil:"<<endl;
    cout<<"8) Akademisyen Sil:"<<endl;
    cout<<"9) Randevu Sil:"<<endl;
    cout<<"10) Ogrenci Guncelle:"<<endl;
    cout<<"11) Akademisyen Guncelle:"<<endl;
    cout<<"12) Randevu Guncelle:"<<endl;
    cout<<"lutfen seciminizi giriniz:"<<endl;
    cin>>secenek;
    if(secenek == 1)
    {
        r1.ogrenciekle();
        cout <<"devam etmek icin 1 sonlandýrmak için 2'ye basiniz."<<endl;
        cin>>b;

    }
    else if(secenek == 2)
    {
        r1.akademisyenekle();
        cout <<"devam etmek icin 1 sonlandýrmak için 2'ye basiniz."<<endl;
        cin>>b;
    }
    else if(secenek == 3)
    {
        cout<<"ogrenci no gir"<<endl;
        string girdinum;
        cin>>girdinum;
        cout<<"sicil no gir"<<endl;
        string girdinum1;
        cin>>girdinum1;
        cout<<"tarih gir:"<<endl;
        string gtar;
        cin>>gtar;
        cout<<"b.saat gir"<<endl;
        string bs;
        cin>>bs;
        cout<<"bitis saati gir"<<endl;
        string bis;
        cin>>bis;
        Akademisyen a1;
        string dosyain = "a.txt";
        ifstream dosya;
        dosya.open("a.txt");
        string sic,a,s,anab,ep,tel,un;
        string z;

        while(!dosya.eof())
    {
        dosya>>sic;
        dosya>>a;
        dosya>>s;
        dosya>>anab;
        dosya>>ep;
        dosya>>tel;
        dosya>>un;
        if(sic == girdinum1 )
            break;

    }
    string dosyaini = "b.txt";
    ifstream dosya1;
    dosya1.open("b.txt");
    string no,ad,so,bo,ky,epo,tele;
    Ogrenci o1;

    while(!dosya1.eof())
    {
        dosya1>>no;
        dosya1>>ad;
        dosya1>>so;
        dosya1>>bo;
        dosya1>>ky;
        dosya1>>epo;
        dosya1>>tele;
        if(no==girdinum)
         break;
       // dosya1>>un;
    }

    r1.setsicil_no(sic);
    r1.setnumara(no);
    r1.settarih(gtar);
    r1.setbassaat(bs);
    r1.setbitsaat(bis);
    //cout<<"sc.:"<<r1.sicil_no<<endl;
    //Randevu r2;
    r1.randevuyazdir();
    cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
    cin>>b;

    }
    else if(secenek == 4)
    {
        r1.akademisyenlistele();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;
    }
    else if(secenek == 5)
    {
        r1.ogrencilistele();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;
    }
    else if(secenek == 6)
    {
        r1.randevulistele();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;
    }
    else if(secenek == 7)
    {
        r1.ogrencisil();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;
    }
    else if(secenek == 8)
    {
        r1.akademisyensil();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;
    }
    else if(secenek ==9)
    {
        r1.randevusil();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;

    }
    else if(secenek ==10)
    {
        r1.ogrenciguncelle();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;
    }
    else if(secenek ==11)
    {
        r1.akademisyenguncelle();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;
    }
    else if(secenek == 12)
    {
        r1.randevuguncelle();
        cout <<"devam etmek icin 1 sonlandirmak icin 2'ye basiniz."<<endl;
        cin>>b;
    }

    else
        cout<<"hatali deger girdiniz lutfen dikkatli okuyunuz..."<<endl;
    }

    return 0;
    }




