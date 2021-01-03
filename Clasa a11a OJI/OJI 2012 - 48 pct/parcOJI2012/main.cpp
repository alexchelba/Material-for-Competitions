#include <bits/stdc++.h>
using namespace std;
FILE *f = fopen("parc.in", "r");
FILE *g = fopen("parc.out", "w");
float stx,sty,sfx,sfy,lat1,lat2,s1,s2;
float minx,miny,maxx,maxy;
int n,m,ko,kv;
int main()
{
    fscanf(f,"%d%d",&n,&m);
    fscanf(f,"%f%f%f%f",&stx,&sty,&sfx,&sfy);
    minx=sfx,miny=sfy,maxx=stx, maxy=sty;
    if(stx<sfx) {minx=stx; maxx=sfx;}
    if(sty<sfy) {miny=sty; maxy=sfy;}
    lat1=maxx-minx;
    lat2=maxy-miny;
    fscanf(f,"%d",&kv);
    for(int i=1;i<=kv;i++)
    {
        float stb,sfb;
        fscanf(f,"%f%f",&stb,&sfb);
        if(stb>sfb) swap(stb,sfb);
        if(minx>stb)
        {
            if(minx<sfb) s1+=sfb-minx;
        }
        else
        {
            if(maxx<sfb) s1+=maxx-stb;
            else s1+=sfb-stb;
        }
    }
    fscanf(f,"%d",&ko);
    for(int i=1;i<=ko;i++)
    {
        float stb,sfb;
        fscanf(f,"%f%f",&stb,&sfb);
        if(stb>sfb) swap(stb,sfb);
        if(miny>stb)
        {
            if(miny<sfb) s2+=sfb-miny;
        }
        else
        {
            if(maxy<sfb) s2+=maxy-stb;
            else s2+=sfb-stb;
        }
    }
    if (minx==maxx)
	{
	    fprintf(g,"%f\n",maxy-miny);
		return 0;
	}
	else
	if (miny==maxy)
	{
	    fprintf(g,"%d\n",maxx-minx);
		return 0;
	}
	else
    {
        float dif1=lat1-s1;
        float dif2=lat2-s2;
        float sd=sqrt((dif1*dif1)+(dif2*dif2));
        ///fprintf(g,"%d %d %f %f %f %f %d %d", n,m,stx,sfx,sty,sfy,kv,ko);
        fprintf(g,"%.6f",s2+s1+sd);
    }
    return 0;
}
