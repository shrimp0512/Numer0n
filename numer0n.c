#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//構造体
struct user
{
    int num;
    int array[3];
}player;

void shuffle(int array[], unsigned int size) {
    unsigned int i, j;
    int tmp;

    /* シャッフル範囲の末尾を設定 */
    i = size - 1;

    while (i > 0) {
        /* シャッフル範囲（0〜i）からランダムに１つデータを選択 */
        j = rand() % i;

        /* ランダムに決めたデータとシャッフル範囲の末尾のデータを交換 */
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;

        /* シャッフル範囲を狭める */
        i--;
    } 
}

int hantei(int enemy[3],int *flag);
int usr(void);
int main(void){
    int i;
    int array[10];
    int seikai[3];
 
    /* 種を初期化 */
    srand((unsigned int)time(NULL));

    /* 乱数の範囲は1〜100 */
    for (i = 0; i < 10; i++) {
        array[i] = i;
    }

    /* arrayの中身をシャッフル */
    shuffle(array, sizeof(array) / sizeof(array[0]));
    
    for (i = 0; i < 3; i++) {
        /* 重複なしの乱数を生成（取得）*/
        seikai[i] = array[i];
        //printf("%d\n",seikai[i]);
    }

    int apple = 0;
    do{
        usr();
        hantei(seikai,&apple);

    }while(apple != 1);
        printf("正解です！");

    return 0;
}

    int usr(){
        //プレイヤーが数字を入力
        int i;
        for(i = 0;i < 3;i++){
            printf("一文字づつ違う数字を3回入力してください\n");
            printf("%d回目:",i + 1);
            scanf("%d",&player.num);
            player.array[i] = player.num;
        }
         
        printf("%d%d%d\n",player.array[0],player.array[1],player.array[2]);
        }

    int hantei(int enemy[3],int *flag){

    //結果を格納する変数
        int Hit;
        int Blow;
        int j = 0;
        int i;

        Hit = 0;
        Blow = 0;

        //判定
        if((enemy[0] == player.array[0]) && (enemy[1] == player.array[1]) && (enemy[2] == player.array[2])){
            *flag = 1;
            Hit = 3;
        }else{
            //printf("test");
            for(i = 0;i < 3; i++){
                if((i == 0) && (enemy[i] == player.array[j])){
                    Hit = Hit + 1;
                }else if((i != 0) && (enemy[i] == player.array[j])){
                    Blow = Blow + 1;
                }else if((i == 1) && (enemy[i] == player.array[j+1])){
                    Hit = Hit + 1;
                }else if((i != 1) && (enemy[i] == player.array[j+1])){
                    Blow = Blow + 1;
                }else if((i == 2) && (enemy[i] == player.array[j+2])){
                    Hit = Hit + 1;
                }else if((i != 2) && (enemy[i] == player.array[j+2])){
                    Blow = Blow + 1;
                }else{
                    Hit = Hit + 0;
                    Blow = Blow + 0;
                }
            }
            *flag = 0;
        }
            printf("Hit:%d\n",Hit);
            printf("Blow:%d\n",Blow);
    }