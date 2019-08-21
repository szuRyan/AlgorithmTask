#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100 
int head  ,rear ,num = 0;
typedef struct node{

    int x , y ;//坐标
    struct node * next ;

} node_t;
node_t  b[N],way[N] ;//队列b，和记录路的座标的结构体数组
void go_map();
void cover() ;
void init();
void print();
node_t * pop();
int a[N][N];//构造地图
int  main(){
    while(1){
    memset(a , 0 , sizeof(a));
    int i , j ;
    for( i =1 ; i< 6 ; i ++){
        for( j = 1 ; j < 6; j++) {
                if(scanf("%d",&a[i][j]) == EOF){//传入地图
//数据，注意这儿是从a[1][1]开始存的，后面将地图边缘用1围起来
                return 0;
            }
        }
    }
    cover();
    init();//初始化队列
    go_map();
    print();
    }
    return 0;
}
void print(){

    int i;
    for(i = num-1 ; i >= 0 ; i--){//打印最短路径
        printf("(%d, %d)\n",way[i].x,way[i].y);
    }
}
void cover(){//将整个地图外围用1围起来，方便搜索

    int i , j ;

    for( i = 0 ; i< 7 ; i++){
        for( j = 0 ;j < 7 ; j++){
            if( i == 0 || i == 6 || j == 0 || j == 6){
                a[i][j] = 1;
            }
        }
    }
}
void init(){//初始化队列
    head = 0;
    rear = 0;
}
node_t * pop(){//弹出队列成员
    node_t * p ;
    p = &b[head];
    head ++;
    return p ;
}
void record(int x ,int y ,node_t * next){//将走过的点信息加入队列，next为指向
//上一个节点数据的指针

    b[rear].x = x;
    b[rear].y = y;
    b[rear].next =next ;
    rear ++;
}
void go_map(){//遍历地图
    node_t * temp ;
    record(1,1,NULL);
    while(1){

        if(head >=rear )return ;//当队头和队尾相等时，退出
        temp = pop();

        if( temp -> x == 5 && temp->y == 5){//当走到终点时，用way 数
//组又保存返回到起点的路径

            while(temp != NULL){//将第一个数据的next 指针指向空，
            //作为返回起点的终止条件。
                way[num].x = temp->x-1;
                way[num].y =temp->y-1 ;
                num ++ ;
                temp = temp->next;
            }
            return ;
        }
        if(a[temp->x][temp->y - 1]!= 1)//遍历四个方向，只要满足条件，
        //就加入队列
        {

            record(temp->x , temp->y -1 ,temp);
            a[temp->x][temp->y - 1] = 1 ;

        }
        if(a[temp->x][temp->y + 1]!=1){

            record(temp->x ,temp->y + 1 ,temp);
            a[temp->x][temp->y + 1] = 1;
        }
        if(a[temp->x-1][temp->y]!= 1){

            record(temp->x- 1 ,temp->y , temp);
            a[temp->x - 1][temp->y] = 1;
        }
        if(a[temp->x + 1][temp->y]!= 1){
            record(temp->x + 1 ,temp->y ,temp);
            a[temp->x + 1][temp->y] = 1;
        }
    }
}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
void search(int x, int y);
int columns[N];//记录第n列的状态，存在棋子且遍历过状态为1，否则为0
int num , fang_an ,area;//棋子数，方案数，行列数
char qipan[N][N];//设置字符串数组
int main(){

    int j,i ;
    while((scanf("%d%d",&area,&num))!=EOF){
            while('\n'!=getchar());//输入完缓冲区会有换行符，后面
            //要输入字符所以得清理缓冲区，本人惯用吃换行手段
        if(area == -1 && num==-1 )break;
        memset(qipan, 0 , sizeof(qipan)); 

        for(i = 0; i < area ;i++  ){//输入字符串
                scanf("%s",qipan[i]);
                while('\n'!=getchar());
        }

        fang_an = 0;//将可行反案设置为0

        memset(columns,0,sizeof(columns));//将记录行数的数组元素初始化0

        search(0 ,0);//从坐标为(0,0)处开始走
        printf("%d\n",fang_an); 
    }

}
void search(int x ,int y){ 
    int i,j;

    if(y == num ){//棋子数等于列数时，使方案递增，并退出当前层递归

        fang_an++ ;
        return ;
    }
    for( i = x ; i< area ; i++){

        for( j = 0 ;j< area ; j++){

            if((!columns[j]) && qipan[i][j] == '#'){//判断当前
//列是否已存在遍历过的棋子,并判断当前坐标中是否放的是棋子

                columns[j] = 1;//若是的话，将当前列的状态改为1

                search(x+1,y+1);

                columns[j] = 0; //既然要退出了本层递归，就将本
//层行的状态改为初始状态
            }   

        }
    }
    return ; 
}


