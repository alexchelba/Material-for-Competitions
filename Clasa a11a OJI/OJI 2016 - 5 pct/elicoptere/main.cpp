#include <fstream>
#include<cmath>
using namespace std;
ifstream f("elicoptere.in");
ofstream g("elicoptere.out");
struct triunghi
{
    int x1,y1;
    int x2,y2;
    int x3,y3;
};
triunghi tri[110];
int p,n,k,v[110][110],nr,nr1;
void verif()
{
        for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int minn=2000000000,s;
                if(tri[i].x1==tri[j].x1) {s=tri[i].y1-tri[j].y1; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].x1==tri[j].x2) {s=tri[i].y1-tri[j].y2; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].x1==tri[j].x3) {s=tri[i].y1-tri[j].y3; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].x2==tri[j].x1) {s=tri[i].y2-tri[j].y1; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].x2==tri[j].x2) {s=tri[i].y2-tri[j].y2; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].x2==tri[j].x3) {s=tri[i].y2-tri[j].y3; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].x3==tri[j].x1) {s=tri[i].y3-tri[j].y1; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].x3==tri[j].x2) {s=tri[i].y3-tri[j].y2; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].x3==tri[j].x3) {s=tri[i].y3-tri[j].y3; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y1==tri[j].y1) {s=tri[i].x1-tri[j].x1; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y1==tri[j].y2) {s=tri[i].x1-tri[j].x2; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y1==tri[j].y3) {s=tri[i].x1-tri[j].x3; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y2==tri[j].y1) {s=tri[i].x2-tri[j].x1; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y2==tri[j].y2) {s=tri[i].x2-tri[j].x2; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y2==tri[j].y3) {s=tri[i].x2-tri[j].x3; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y3==tri[j].y1) {s=tri[i].x3-tri[j].x1; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y3==tri[j].y2) {s=tri[i].x3-tri[j].x2; if(abs(s)<=minn) minn=abs(s);}
                if(tri[i].y3==tri[j].y3) {s=tri[i].x3-tri[j].x3; if(abs(s)<=minn) minn=abs(s);}
            if(minn<=k) {nr++; v[j][i]=minn;}
        }
}
int main()
{
    f>>p;
    f>>n>>k;
    for(int i=1;i<=n;i++)
    {
        f>>tri[i].x1>>tri[i].y1;
        f>>tri[i].x2>>tri[i].y2;
        f>>tri[i].x3>>tri[i].y3;
    }
    verif();
    if(p==1)
    {
        g<<nr<<'\n';
    }
    else
    if(p==2)
    {
        for(int i=1;i<=n;i++)
        {
            int nr2=0;
            for(int j=1;j<=n;j++)
                if(v[i][j]) nr2++;
            if(nr2) nr1=nr1+nr2-1;
        }
        g<<nr+nr1<<'\n';
    }
    return 0;
}
