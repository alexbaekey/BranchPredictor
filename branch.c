// Alexander Baekey
// CDA 5106
// Machine Problem 2


//libs
#include<stdlib.h> 
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>

//global counters & flags

//old un-needed
int *countArr;

int B, M2, M1, N, K;

int count;

int *bimodPT;
int bisize;

int *PT;
int gsize;
int *gbh;
int binsum = 0;
bool taken = false;

int *chooser;
int hybsize;

//Evaluation Metrics
int mispredictions=0;
int predictions=0;
int CPI;
int speedup;

//functions
void smith(int branchPC, char outcome);
void bimodal(int branchPC, char outcome, int M2);
void gshare(int branchPC, char outcome, int M1, int N);
void hybrid(int branchPC, char outcome, int K, int M1, int N, int M2);
int binArr2num(int *gbh, int N);

void smith(int branchPC, char outcome){

     predictions++;
     int mid = (int)pow(2,(float)B)/2.;
     int max = (int)pow(2,(float)B);
     if(count < (int)mid){
          //predicted not taken
          if(outcome == 't'){
               mispredictions++;
               //updatecounter
               if(count<(max-1)){
                    count++;
               }
          }
    
          if(outcome == 'n'){
               if(count>0){
                    count--;
               }
          }
     }
     else if(count >= (int)mid){
          //predicted taken
          if(outcome == 'n'){
               mispredictions++;
               //updatecounter
               if(count>0){
                    count = count - 1;
               }
          }
          if(outcome == 't'){
               //updatecounter
               if(count<(max-1)){
                    count = count + 1;
               }
          }
     }
}


void bimodal(int branchPC, char outcome, int M2){

     predictions++;
     //use bits M+1 to 2 of PC
     int cur = (((1<<(M2))-1) & (branchPC>>(2)));
     int mid = 4;
     int max = 8;
     if(bimodPT[cur]<mid){
          //predicted not taken
          if(outcome == 't'){
               mispredictions++;
               //updatecounter
               if(bimodPT[cur]<(max-1)){
                    bimodPT[cur] = bimodPT[cur] + 1;
               }
          }
          if(outcome == 'n'){
               if(bimodPT[cur]>0){
                    bimodPT[cur] = bimodPT[cur] - 1;
               }
          }
     }
     else if(bimodPT[cur]>=mid){
          //predicted taken
          if(outcome == 'n'){
               mispredictions++;
               //updatecounter
               if(bimodPT[cur]>0){
                    bimodPT[cur] = bimodPT[cur] - 1;
               }
          }
          if(outcome == 't'){
               //updatecounter
               if(bimodPT[cur]<(max-1)){
                    bimodPT[cur] = bimodPT[cur] + 1;
               }
          }
     }
}

void gshare(int branchPC, char outcome, int M1, int N){
     
     predictions++;
     //use bits M+1 to 2 of PC
     int test = binArr2num(gbh, N);
     int cur = (test ^ (((1<<(M1))-1) & (branchPC>>(2))));
     //printf("cur %d\n", cur);
     int mid = 4;
     int max = 8;
     if(PT[cur]<mid){
          //predicted not taken
          if(outcome == 't'){
               mispredictions++;
               //updatecounter
               if(PT[cur]<(max-1)){
                    PT[cur] = PT[cur] + 1;
               }
               taken = true;
          }
          if(outcome == 'n'){
               if(PT[cur]>0){
                    PT[cur] = PT[cur] - 1;
               }
               taken = false;
          }
     }
     else if(PT[cur]>=mid){
          //predicted taken
          if(outcome == 'n'){
               mispredictions++;
               //updatecounter
               if(PT[cur]>0){
                    PT[cur] = PT[cur] - 1;
               }
               taken = false;
          }
          if(outcome == 't'){
               //updatecounter
               if(PT[cur]<(max-1)){
                    PT[cur] = PT[cur] + 1;
               }
               taken = true;
          }
     }

//for testing
/*     printf("\nbefore\n");*/
/*     for(int i=0;i<N;i++){*/
/*          printf("gbh of %d: %d\n", i, gbh[i]);*/
/*     }*/

/*     //update global hist*/
     //1st shift bits right one
     //have to do this descending, otherwise new values spill over
     for(int i=(N-1);i>=0;i--){
          gbh[i+1]=gbh[i];
     }
/*     //place result value in MSB*/
     //gbh[0] is MSB
     if(taken==true){
          gbh[0]=1;
     }
     else if(taken==false){
          gbh[0]=0;
     }

//for testing
/*     printf("after\n");*/
/*     for(int i=0;i<N;i++){*/
/*          printf("gbh of %d: %d\n", i, gbh[i]);*/
/*     }*/

}

int binArr2num(int *gbh, int N){
     binsum=0;
     int m=(N-1);
     for(int i=0;i<N;i++){
          binsum = binsum + (pow(2,m)*gbh[i]);
          m--;
     }
     return binsum;
}

void hybrid(int branchPC, char outcome, int K, int M1, int N, int M2){

     bimodal(branchPC, outcome, M2);   
     
;
}

// main execution

void main(int argc, char *argv[]){

     char outcome;
     int branchPC;
     FILE* fp;

     char *trace;
     char *predictor;

     //read in type of branch predictor, loop through file
     predictor = argv[1];
     if(strcmp("smith", predictor) == 0){
          B = strtol(argv[2], NULL, 10);
          trace = argv[3];
          //initialize counter array of size 2^10
          //TODO JUST CAUSE IDK WHAT SIZE TO MAKE THIS ARRAY
          //countArr = (int *)malloc(sizeof(int)*1024);
          int x = (int)(pow(2,(float)B)/2.);
          count = x;
/*          old way assuming BHT (indexed table)*/
/*          for(int i=0; i<1024; i++){*/
/*               countArr[i] = x;*/
/*          }*/
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x %c\n", &branchPC, &outcome);
               smith(branchPC, outcome); 
          }  
          fclose(fp);
          printf("COMMAND\n");
          printf("./sim %s %d %s\n", predictor, B, trace);
          printf("OUTPUT\n");
     }
     else if(strcmp("bimodal", predictor) == 0){
          M2 = strtol(argv[2], NULL, 10);
          trace = argv[3];
          bisize = (int)(pow(2,(float)M2));
          bimodPT = (int *)malloc(sizeof(int)*bisize);
          for(int i=0; i<bisize; i++){
               bimodPT[i] = 4;
          }
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x %c\n", &branchPC, &outcome);
               bimodal(branchPC, outcome, M2);   
          }  
          fclose(fp);
          printf("COMMAND\n");
          printf("./sim %s %d %s\n", predictor, M2, trace);
          printf("OUTPUT\n");
     }
     else if(strcmp("gshare", predictor) == 0){
          M1 = strtol(argv[2], NULL, 10);
          N = strtol(argv[3], NULL, 10);
          trace = argv[4];
          gbh = (int *)malloc(sizeof(int)*N);
          gsize = (int)(pow(2,(float)M1));
          PT = (int *)malloc(sizeof(int)*gsize);
          for(int i=0;i<N;i++){
               gbh[i]=0;
          }
          for(int i=0; i<gsize; i++){
               PT[i] = 4;
          }
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x %c\n", &branchPC, &outcome);
               gshare(branchPC, outcome, M1, N);   
          }  
          fclose(fp);
          printf("COMMAND\n");
          printf("./sim %s %d %d %s\n", predictor, M1, N, trace);
          printf("OUTPUT\n");
     }
     else if(strcmp("hybrid", predictor) == 0){
          K = strtol(argv[2], NULL, 10);
          M1 = strtol(argv[3], NULL, 10);
          N = strtol(argv[4], NULL, 10);
          M2 = strtol(argv[5], NULL, 10);
          trace = argv[6];
          bisize = (int)(pow(2,(float)M2));
          bimodPT = (int *)malloc(sizeof(int)*bisize);
          for(int i=0; i<bisize; i++){
               bimodPT[i] = 4;
          }
          gbh = (int *)malloc(sizeof(int)*N);
          gsize = (int)(pow(2,(float)M1));
          PT = (int *)malloc(sizeof(int)*gsize);
          for(int i=0;i<N;i++){
               gbh[i]=0;
          }
          for(int i=0; i<gsize; i++){
               PT[i] = 4;
          }
          int hybsize = pow(2,K);
          chooser = (int *)malloc(sizeof(int)*(hybsize));
          for(int i=0;i<hybsize;i++){
               chooser[i]=1;
          }
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x %c\n", &branchPC, &outcome);
               hybrid(branchPC, outcome, K, M1, N, M2);   
          }  
          fclose(fp);
          
     }
     else
          printf("%s is not a valid predictor type\n", predictor);
        

     //RESULTS
     printf("number of predictions: %d\n", predictions);
     printf("number of mispredictions: %d\n", mispredictions);
     printf("misprediction rate: %.2f%%\n", (100*(double)mispredictions/(double)predictions));

     if(strcmp("bimodal", predictor) == 0){
          printf("FINAL BIMODAL CONTENTS\n");
          for(int i=0;i<bisize;i++){
               printf("%d %d\n",i, bimodPT[i]);
          }
     }

     if(strcmp("gshare", predictor) == 0){
          printf("FINAL GSHARE CONTENTS\n");
          for(int i=0;i<gsize;i++){
               printf("%d %d\n",i, PT[i]);
          }
     }


/*//not sure if necessary*/
/*     //firstline?*/
/*     fscanf(fp, "%c", &bom1);*/
/*     printf("bom1 %c\n", bom1);*/
/*     fscanf(fp, "%c", &bom2);*/
/*     printf("bom2 %c\n", bom2);*/
/*     fscanf(fp, "%c", &bom3);*/
/*     printf("bom 3 %c\n", bom3);*/

}


