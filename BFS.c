#include <stdio.h>
int G[20][20], q[20], visited[20], n, i, j, f = 0, r = -1, reach[20];
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (G[v][i] && !visited[i])
            q[++r] = i;
    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}
void main()
{
    int v;
    int count = 0;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    printf("\n Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);
    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    int option;
    printf("enter 1 for dfs or 2 for bfs\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
    {
        dfs(1);
        printf("\n");
        for (i = 1; i <= n; i++)
        {
            if (reach[i])
                count++;
        }
        if (count == n)
            printf("\n Graph is connected");
        else
            printf("\n Graph is not connected");
    }
    break;

    case 2:
    {

        bfs(v);
        printf("\n The node which are reachable are:\n");
        for (i = 1; i <= n; i++)
        {

            if (visited[i])
            {

                printf("%d\t", i);
            }
            else
            {

                printf("\n Bfs is not possible");
            }
        }
        break;
    }
    }
}
void dfs(int v)
{
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++)
        if (G[v][i] && !reach[i])
        {
            printf("\n %d->%d", v, i);
            dfs(i);
        }
}