#include<bits/stdc++.h>
#define lol long long
#define inf 1000000000000000LL
using namespace std;
 
lol n, xmin, xmax, ymin, ymax;
pair<lol, lol> p[2001];
const double epsilon = 1e-8;
 
double dist(lol x, lol y) {
    
    double ans = 0.0;
    double dx, dy;
    for(int i = 0; i < n; i++) {
        dx = p[i].first - x + 0.0;
        dy = p[i].second - y + 0.0;
        
        ans += sqrt(dx*dx+dy*dy);
    }
    
    return ans;
}
 
double findy(lol x) {
    
   // printf("in findy..x = %d, ymin = %d, ymax = %d\n",x,ymin,ymax);
    double dl, dr;
    lol max = ymax, min = ymin;
    lol delta = max - min;
    delta = delta / 3;
    
    lol l = min + delta;
    lol r = max - delta;
    
    double dis = 1e18;
    
    while (r>=l) {
        
        if((r-l) <= 3) {
            double di;
                    
            for(lol i = l; i <= r; i++) {
                di = dist(x,i);
                        
                if(di < dis) {
                    dis = di;
                }
            }
            break;
        }
        
        //printf("in findy..l = %d, r = %d\n",l,r);
        dl = dist(x,l);
        dr = dist(x,r);
        
        if(abs(dl-dr)<epsilon)
            dis = std::min<double>(dis,dl);
            
        if(dl > dr) {
            min = l;
        }
        
        else if(dl < dr) {
            max = r;
        }
        
        else {
            min = l; max = r;
        }
        
        delta = max - min;
        delta = delta / 3;
        
        l = min + delta;
        r = max - delta;
    }
    
    return dis;
}
 
int main() {
    
    scanf("%lld",&n);
    while(n) {
        
        xmin = ymin = LONG_LONG_MAX;
        ymax = xmax = LONG_LONG_MIN;
        
        for(int i = 0; i < n; i++) {
            scanf("%lld%lld",&p[i].first,&p[i].second);
            
            if(p[i].first > xmax) xmax = p[i].first;
            if(p[i].first < xmin) xmin = p[i].first;
            
            if(p[i].second < ymin) ymin = p[i].second;
            if(p[i].second > ymax) ymax = p[i].second;
        }
        
        lol delta,l,r;
        double dl, dr, ans = 1e18;
        
        lol lo = xmin, hi = xmax;
        
        while(lo <= hi) {
            
            //printf("l=%d,r=%d\n",l,r);
            
            if((hi-lo) <= 3) {
                 
                double di;
                    
                for(lol i = lo; i <= hi; i++) {
                    di = findy(i);
                        
                    if(di < ans) ans = di;
                }
                
                break;
            }
            
            delta = hi-lo;
            delta = delta / 3;
            
            l = lo + delta;
            r = hi - delta;
        
            dl = findy(l);
            dr = findy(r);
            
            if(abs(dl-dr) < epsilon)
                ans = min(ans,min(dl,dr));
            //printf("found yl = %d, yr = %d\n",yl,yr);
            
            //dl = dist(l,yl);
            //dr = dist(r,yr);
            
            if(dl > dr) {
                lo = l;
            }
            
            else if(dl < dr) {
                hi = r;
            }
            
            else {
                lo = l; hi = r;
            }
            
            delta = hi - lo;
            delta = delta / 3;
            
            l = lo + delta;
            r = hi - delta;
        }
                    
        printf("%.6lf\n",ans);
        scanf("%lld",&n);
    }
    return 0;
}
