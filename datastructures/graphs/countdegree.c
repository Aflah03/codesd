#include<stdio.h>
#define MAX_NUM_OF_NODES 8
void printNodesDegree(int graph[MAX_NUM_OF_NODES][MAX_NUM_OF_NODES],int nodes,char VERTEX[8][20]){
    for(int i=0;i<nodes;i++){
        int degree=0;
        for(int j=0;j<nodes;j++){
            if(graph[i][j]==1){
                degree++;
            }
        }
        printf("the degree of  %s:  %d\n",VERTEX[i],degree);
    }
}
int main(){
    int nodes, edges;
    char VERTEX[8][20]={{"Aflah"},
                        {"DIlshan"},
                        {"Adil"},
                        {"Akbar"},
                        {"Abel"},
                        {"Rizwan"},
                        {"Hashim"},
                        {"Nisham"},
                        };
    int graph[MAX_NUM_OF_NODES][MAX_NUM_OF_NODES]={{0,1,1,1,0,0,0,0},
                                                   {1,0,0,0,1,1,0,0},
                                                   {1,0,0,0,0,0,1,0},
                                                   {1,0,0,0,0,0,0,1},
                                                   {0,1,0,0,0,0,0,1},
                                                   {0,1,0,0,0,0,0,1},
                                                   {0,0,1,0,0,0,0,1},
                                                   {0,0,0,1,1,1,1,0}
                                                   };

    
    for(int i=0;i<MAX_NUM_OF_NODES;i++){
        for(int j=0;j<MAX_NUM_OF_NODES;j++){
                printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    printNodesDegree(graph,8,VERTEX);

}