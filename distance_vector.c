#include <stdio.h>
#include <stdlib.h>
int findShortestPath(int G[6][6],int vertices,int edges,int edge[20][2],int source){
    int i,j,k,u,v,flag=1,parent[20],distance[20];
    for (i=0;i<vertices;i++){
        parent[i]=-1,distance[i]=999;
    }
    distance[source-1]=0;
    for(i=0;i<vertices;i++){
        for(k=0;k<edges;k++){
            u=edge[k][0],v=edge[k][1];
            if(distance[u]+G[u][v]<distance[v]){
                distance[v]=distance[u]+G[u][v];
                parent[v]=u;
            }
        }
    }
    for(k=0;k<edges;k++){
        u=edge[k][0],v=edge[k][1];
        if(distance[u]+G[u][v]<distance[v]){
            flag=0;
        }
    }
    printf("\ndistination\tcost\tpath\n");
    if(flag){
        for(i=0;i<vertices;i++){
            int nodes[10],b=9,next;
            nodes[b--]=i;
            next=parent[i];
            nodes[b--]=next;
            while(next!=-1){
                next=parent[next];
                nodes[b--]=next;
            }
            if(distance[i]==999){
                printf("\n%d\t\t%d\t",i,nodes[-1]);
            }
            else{
                printf("\n%d\t\t%d\t",i,distance[i]);
            }
            for(int h=10;h>0;h--){
                if(nodes[h]==-1){
                    for(int g=h+1;g<10;g++){
                        if(g==9){
                            printf("%d",nodes[g]);
                        }
                        else{
                            printf("%d-->",nodes[g]);
                        }
                    }
                    break;
                }
            }
        }
    }
    return flag;
}
int main(int argc,char **argv){
    int vertices=6,edge[20][2];
    int i,j,k=0;
    int graph[6][6]={{1,2,1,0,2,1},{1,6,5,4,3,2},{1,2,3,0,1,0},{0,2,0,1,0,2},{2,1,3,0,6,2},{0,0,1,0,2,2}};
    printf("\nthe adjacency matrix representation of graph\n");
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            printf("%d\t",graph[i][j]);
            if(graph[i][j]!=0){
                edge[k][0]=i,edge[k++][1]=j;
            }
        }
        printf("\n");
    }
    for(i=0;i<vertices;i++){
        printf("\n--------------------------\n\tsource vector %d\n",i);
        findShortestPath(graph,vertices,k,edge,i+1);
    }
    return(EXIT_SUCCESS);
}