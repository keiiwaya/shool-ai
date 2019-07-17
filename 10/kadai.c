#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define try 50 //試行回数
#define maxWeight 744 //重さの上限
#define maxGen 200 //世代数
#define gen_locus 30 //遺伝子座
#define mutation_p 0.01 //突然変異の確率
#define gene_number 100 //世代の個体数
#define P 0.01 //突然変異の確率
#define elite 2
int count_vi(int);


int main(void){

  int rulet_row = 0;
  int sum_value = 0;
  double value_rate[gen_locus];
  double max_rate = 0.0;
  int select_rulet[2]; //選ばれたか確率を格納
  double rulet = 0;
  int separate;
  int child1[gene_number][gen_locus],child2[gene_number][gen_locus];
  int parent1[gen_locus], parent2[gen_locus];
  int genes[gene_number][gen_locus];
  int i,j,k,l,m,g,r,t;
  double num;
  int total_vi[gene_number];
  int total_weight[gene_number];
  int max_vi = 0;
  int data[gen_locus][2] = {
    {95,28},{89,95},{88,60},
    {84,9},{81,63},{76,43},
    {75,7},{58,13},{58,44},
    {58,83},{54,61},{53,37},
    {53,84},{52,72},{42,57},
    {40,74},{40,78},{39,79},
    {32,34},{30,48},{28,15},
    {26,45},{26,52},{25,64},
    {23,29},{23,64},{22,16},
    {21,5},{16,55},{12,74}
  };

  /*乱数生成*/
  srand((unsigned)time(NULL));
  for(l=0;l<gene_number;l++){
    for(m=0;m<gen_locus;m++){
      num = (double)rand()/RAND_MAX;
      if(num >= 0.5){
    	genes[l][m] = 1;
      }else{
    	genes[l][m] = 0;
      }
      //printf("%d", genes[l][m]);
    }
    //printf("\n");
  }
  printf("\n");


  /*世代数ループさせる*/
  for(k=0;k<maxGen;k++){
    //printf("%d世代目のループ\n", k+1);
    max_vi = 0;
    /*価値の合計を計算*/
    for(i=0;i<gene_number;i++){
      total_vi[i] = 0;
      total_weight[i] = 0;
      for(j=0;j<gen_locus;j++){
    	   total_weight[i] += genes[i][j] * data[j][1];
    	   total_vi[i] += genes[i][j] * data[j][0];
      }
      if(total_weight[i] > maxWeight){
    	   total_vi[i] = 0;
      }
      if(total_vi[i] > max_vi){
        max_vi = total_vi[i];
      }
      printf("%3dの評価値：%5d 重さ:%5d\n",i+1,  total_vi[i], total_weight[i]);
      //printf("%3d:%4d\n", i+1, total_vi[i]);
    }
    printf("%3d %4d\n", k+1, max_vi);

  /*エリート選択*/






  /*ルーレット選択*/
  for(i=0;i<gene_number;i++){ //data配列の価値の合計計算
    sum_value += data[i][0];
  }
  for(j=0;j<gen_locus;j++){ //価値の割合を計算
    value_rate[j] = data[j][0] / sum_value;
  }
  /*ruletの値に応じて場合分け*/
  for(r=0;r<2;r++){
    rulet = (double)rand()/RAND_MAX;
    for(g=gen_locus;g>0;g--){
      if(rulet <= value_rate[g]){
    	select_rulet[r] = g;
      }
      value_rate[g] += value_rate[g-1];
    }
  }

  /*交差*/
  //1~30までの乱数を生成
  //２つの配列にルーレット選択で選んだ２つを交差させたものを入れる
  srand((unsigned)time(NULL));
  separate = rand() % 30 + 1;

    for(t=0;t<gen_locus;t++){
      parent1[t] = genes[select_rulet[0]][t];
      parent2[t] = genes[select_rulet[1]][t];
    }

  for(i=0;i<separate;i++){
    child1[select_rulet[0]][i] = parent2[i];
    child2[select_rulet[1]][i] = parent1[i];
  }
  for(j=separate;j<gen_locus;j++){
    child1[select_rulet[0]][j] = parent1[j];
    child2[select_rulet[1]][j] = parent2[j];
  }
  if(k != 0){
    for(j=0;j<2;j++){
      rulet_row = select_rulet[j];
      for(i=0;i<gen_locus;i++){
        genes[rulet_row][i] = child1[rulet_row][i];
      }
    }
  }

  /*突然変異*/
  //確率Pでgenes[i][j]の遺伝子座を反転
  //乱数がP以下ならそのまま、それ以外は反転
  double muta = 0.0;
  srand((unsigned)time(NULL));
  for(i=0;i<gene_number;i++){
    for(j=0;j<gen_locus;j++){
      muta = (double)rand()/RAND_MAX;
      if(muta <= P && genes[i][j] == 0){
	genes[i][j] = 1;
      }else if(muta <= P && genes[i][j] == 1){
	genes[i][j] = 0;
      }
    }
  }
}



  return 0;
}
