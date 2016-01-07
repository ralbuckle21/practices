#include<cmath>   
#include<iostream>   
#include<cstdio>   
#include<cmath>   
#include<iostream>   
#include<cstdio>   
#include<algorithm>   
#include <vector>   
  
using namespace std;   
  
class Route   
{   
public:   
    Route(int firstTime_, int interval_, int frequence_)    
        : firstTime(firstTime_)   
        , interval(interval_)   
        , frequence(frequence_)   
    {   
    }   
    bool operator <(const Route &lhs) const  
    {   
        return frequence > lhs.frequence;   
    }   
    int firstTime;   
    int interval;   
    int frequence;   
};   
  
int visited[60] = { 0 };   
std::vector <Route> routes;   
  
//firstTime < interval, otherwise firstTime - interval earlier than firstTime (1)   
//firstTime + interval <= 59 =>  interval <= 59 - firstTime (2)   
//(1)(2)==> firstTime < interval <= 59 - firstTime => 2*firstTime < interval => firstTime <= 29 (3)   
//firstTime >= 0   
// => 0 <= firstTime <= 29, 1 <= interval <= 59    (4)   
// first + frequency * interval > 59  => frequency > (59 - first) / interval   
// first + (frequency - 1) * interval <= 59 => frequency <= (59 - first) / interval + 1   
// => frequency = (59 - first) / interval + 1 (4)   
void prepareRoutes()   
{   
    routes.reserve(900);   
    for (int firstTime = 0; firstTime <= 29; ++firstTime)   
    {   
        if (!visited[firstTime])   
            continue;   
        for (int interval = firstTime + 1; interval <= 59 - firstTime; ++interval)   
        {   
            bool suffice = true;   
            for (int k = firstTime + interval; k <= 59; k += interval)   
            {   
                if (!visited[k])   
                {   
                    suffice = false;   
                    break;   
                }   
            }   
            if (suffice)   
            {   
                int fre = 1 + (59 - firstTime) / interval;   
                routes.push_back(Route(firstTime, interval, fre));   
            }   
        }   
    }   
    sort(routes.begin(), routes.end());   
}//prepareRoutes   
  
int nMinRoutes = 17;   
  
bool isValidRoute(int firstTime, int interval)   
{   
    int t = firstTime;   
    for (; t <= 59; t += interval)   
    {   
        if (!visited[t])   
            return false;   
    }   
    return true;   
}   
  
//std::vector <Route> bestX;   
//std::vector <Route> currentX;   
  
//在搜索时，如果还有n个未被覆盖，用频率为f的线路来覆盖，至少需要n/f条，显然f>n的线路是不可能符合条件的   
void solve(int currentRouteNumber, int nCurrentRoutes, int nRemain)   
{   
    if (nRemain == 0)   
    {   
        if (nCurrentRoutes < nMinRoutes)   
        {   
            nMinRoutes = nCurrentRoutes;   
            //bestX = currentX;   
        }   
        //else   
        //{   
        //  currentX.clear();   
        //}   
        return;   
    }   
    while (currentRouteNumber < (int)routes.size() && routes[currentRouteNumber].frequence > nRemain)   
        ++currentRouteNumber;   
    for (;currentRouteNumber < (int)routes.size(); ++currentRouteNumber)   
    {   
        if (nCurrentRoutes + 1 + (nRemain - 1) / routes[currentRouteNumber].frequence >= nMinRoutes)   
            return;   
  
        if (isValidRoute(routes[currentRouteNumber].firstTime, routes[currentRouteNumber].interval))   
        {   
            //currentX.push_back(routes[currentRouteNumber]);   
  
            for (int i = routes[currentRouteNumber].firstTime; i <= 59; i += routes[currentRouteNumber].interval)   
            {   
                    --visited[i];   
                    --nRemain;   
            }   
            solve(currentRouteNumber, nCurrentRoutes + 1, nRemain);//线路不同的公交路线可能有相同的起始时间和间隔   
            for (int i = routes[currentRouteNumber].firstTime; i <= 59; i += routes[currentRouteNumber].interval)   
            {   
                ++visited[i];   
                ++nRemain;   
            }   
            //currentX.pop_back();   
        }   
    }   
}   
  
int main()   
{   
    int n;   
    scanf ("%d", &n);   
  
    int tmp;   
    for (int i = 0; i < n; ++i)   
    {   
        scanf("%d", &tmp);   
        visited[tmp]++;   
    }   
    prepareRoutes();   
    solve(0, 0, n);   
    printf("%d\n", nMinRoutes);  
    return 0;   
}
