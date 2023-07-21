#include<bits/stdc++.h>
using namespace std;


class Time
{
    private:
    long seconds = 0;
    public:
    friend istream& operator >> (istream&,Time&);
    friend ostream& operator << (ostream&,Time);
    Time& operator ++ ();
    Time operator++(int);
    Time operator+(const Time& a);
};



istream& operator >> (istream& in,Time& a)
{
    long hour=0,min=0,sec=0;
    cout<<"nhap lan luot gio phut giay : ";
    in>>hour>>min>>sec;
    a.seconds=hour*3600+min*60+sec;
    return in;
}

ostream& operator << (ostream& out,Time a)
{
    out<<a.seconds/3600<<"h"<<(a.seconds%3600)/60<<"m"<<a.seconds%60<<"s";
    out<<endl;
    return out;
}


Time& Time::operator++()
{
    this->seconds++;
    return *this;
}

Time Time::operator + (const Time& a)
{
    Time temp;
    temp.seconds=this->seconds+a.seconds;
    return temp;
}


Time Time::operator++(int a)
{
    Time temp=*this;
    ++*this;
    return temp;
}


int main()
{
    Time x;
    cin>>x;
    cout<<x;
    ++x;
    cout<<"x sau khi tang len 1 don vi thoi gian( giay ) la: "<<x;
    Time y;
    cin>>y;
    cout<<x+y;
    return 0;
}