# Graph 

----------

[TOC]

Graph写于2016/10/21 09:04:24 

## Graph

### Floyd-Warshall

```C++
for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(e[i][j]>e[i][k]+e[k][j])
				e[i][j]=e[i][k]+e[k][j];
```
----------
### Dijkstra

```C++
for(i=1;i<=n-1;i++)
{
	min=inf;
	for(j=1;j<=n;j++)
	{
		if(book[j]==0&&dis[j]<min)
		{
			min=dis[j];
			u=j;
		}
	}
	book[u]=1;
	for(v=1;v<=n;v++)
	{
		if(e[u][v]<inf)
		{
			if(dis[v]>dis[u]+e[u][v])
				dis[v]>dis[u]+e[u][v];
		}
	}	
}
```
----------
### Bellman-Ford


```C++
for(k=1;k<=n-1;k++)
	for(i=1;i<=m;i++)
		if(dis[v[i]]>dis[u[i]]+w[i])
			dis[v[i]]=dis[u[i]]+w[i];
```
----------
### Bellman-Ford的队列优化

```C++
head=tail=1;
que[tail++]=1;
book[1]=1;
while(head<tail)
{
	k=first[que[head]];
	while(k!=-1)
	{
		if(dis[v[k]]>dis[u[k]]+w[k])
		{
			dis[v[k]]=dis[u[k]]+w[k];
			if(book[v[k]]==0)
			{
				que[tail]=v[k];
				tail++;
				book[v[k]]=1;
			}
		}
		k=next[k];
		book[que[head]]=0;
		head++;
	}
}
```
### Compare
| Floyed |  Dijkstra  | Bellman-Ford | 队列优化的Bellman-Ford |           |
|:------:|:----------:|:------------:|:-----------------:|:---------:|
|  空间复杂度 |  O($N^3$)  |     O(M)     |        O(M)       |    O(M)   |
|  时间复杂度 |    0(N)    | O((M+N)logN) |       O(NM)       | 最坏也是O(NM) |
|  适用情况  | 稠密图和顶点关系密切 |  稠密图和顶点关系密切  |     稀疏图和边关系密切     | 稀疏图和边关系密切 |
|   负权   |   可以解决负权   |    不能解决负权    |       可以解决负权      |   可以解决负权  |
