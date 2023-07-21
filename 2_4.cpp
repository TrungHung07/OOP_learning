#include<bits/stdc++.h>
using namespace std;

class Date
{
    friend istream& operator >> (istream&,Date&);
    friend ostream& operator << (ostream&,Date);
    private:
    int day;
    int month;
    int year;
    public:
    Date();
    Date(int nam,int ngay_thang);
    Date(int nam,int thang,int ngay);
    Date operator ++ (int);
    friend bool operator < (Date,Date);
};


Date::Date()
{
    this->day=0;
    this->month=0;
    this->year=0;
}

Date::Date(int nam,int ngay_thang)
{
    this->day=ngay_thang;
    this->month=ngay_thang;
    this->year=nam;
}


Date::Date(int nam,int thang,int ngay)
{
    this->day=ngay;
    this->month=thang;
    this->year=nam;
}



istream& operator>>(istream& in,Date& a)
{
    cout<<"nhap lan luot ngay thang nam : "<<endl;
    in>>a.day>>a.month>>a.year;
    return in;
}

ostream& operator<<(ostream& out,Date a)
{
    out<<a.day<<"/"<<a.month<<"/"<<a.year<<endl;
    return out;
}

bool IsNhuan(int nam)
{
    return ((nam%4==0 and nam%100!=0) or nam%400==0);
}


Date Date::operator++(int)
{
    Date temp=*this;
    int ngaytrongthang[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    ++day;
    if(IsNhuan(year))ngaytrongthang[2]=29;
    if(day>ngaytrongthang[month])
    {
        ++month;
        if(month>12)
        {
            ++year;
            month=1;
        }
        day=1;
    }
    return temp;
}


bool operator < (Date a,Date b)
{
    if(a.day<b.day)return true;
    if(a.month<b.month)return true;
    if(a.year<b.year)return true;
    return false;
}


int main()
{
    Date ng1;//ng1 sẽ có giá tị là ngày 1 tháng 1 năm 1
    Date ng2(2017,1);//ng2 sẽ có giá tị là ngày 1 tháng 1 năm 2017
    Date ng3(2017,1,7);//ng3 sẽ có giá tị là ngày 7 tháng 1 năm 2017
    cin>>ng1;
    ng1++;
    cout<<ng1;
    if(ng1<ng2)cout<<"ngay 1 truoc ngay 2"<<endl;
    else cout<<"ngay 1 khong truoc ngay 2"<<endl;
    return 0;
}