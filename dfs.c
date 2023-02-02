#include <stdio.h>
int G[20][20], n, i, j, visited[20];
void dfs(int);
void main()
{
    int v;
    int count = 0;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);

    printf("\n Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);
    dfs(1);
    printf("\n");
}
void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d\t", v);
    for (i = 0; i <= n; i++)
        if (G[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
}