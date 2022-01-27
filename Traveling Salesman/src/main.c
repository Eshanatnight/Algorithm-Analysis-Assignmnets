#include <stdio.h>
// used custom macro rather than the one
// in limits header for possible overflow
#define INF 999999

// Number of nodes
const int n = 7;

//memorization table
int dp[128][7];

//adjecency list made global for ease of use
int dist[10][10] =
                    {
                        { 0,  3,  5, INF, INF, INF,   3 },
                        { 3,  0,  3,   7, INF, INF,  11 },
                        { 5,  3,  0, INF, INF, INF, INF },
                        { 0,  7,  3,   0,   3,   9,  11 },
                        { 0,  0,  0,   3,   0,   3, INF },
                        { 0,  0,  0,   9,   3,   0,   3 },
                        { 3, 11, 11, INF, INF,   3,   0 }
                    };

// bit mask if all cities are visited
const int VISITED_ALL = (1 << n) -1;

// min comparator fuction cpp has it c does not
// so i implemented my own
int min(int a, int b)
{
    return (a < b) ? a : b;
}

//function that solves TSP takes a bitmask and a position
int travelingSalesmanProblem(int mask, int pos)
{
    if(mask ==  VISITED_ALL)
        return dist[pos][0];

    //Lookup case
    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    for(int city = 0; city < n; city++)
    {
        if((mask&(1<<city)) == 0)
        {
            int newAns = dist[pos][city] + travelingSalesmanProblem(mask|(1<<city), city);
            ans = min(ans, newAns);
        }
    }

    // returns true and sets up the lookup table
    return dp[mask][pos] = ans;
}


int main()
{
    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;

    printf("Minimum Weight Path Costs: %d", travelingSalesmanProblem(1, 0));
    return 0;
}