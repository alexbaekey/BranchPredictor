// Alexander Baekey
// CDA 5106
// Machine Problem 2


//libs
#include<stdlib.h> 
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>

//counter
int *countArr;
bool taken=false;
int mispredictions=0;
int predictions=0;
int B, M2, M1, N, K;

int count;

int *bimodPT;
//Evaluation Metrics
int CPI;
int speedup;

int bimodsize;

// hazards?
     // data
     // structural
     // control

//functions
void smith(int branchPC, char outcome);
void predict(int branchPC, char outcome);
void bimodal(int branchPC, char outcome, int M2, int bisize);



void predict(int branchPC, char outcome){
/*     printf("Wow you did it good job\n");*/
/*     printf("size of array: %ld\n", sizeof(countArr));*/
/*     printf("size of array: %ld\n", sizeof(countArr[0]));*/
     for(int i=0;i<1024;i++){
          printf("count %d\n",countArr[i]);
     }
}

void smith(int branchPC, char outcome){

/*     for(int j=0;j<1024;j++){*/
/*          printf("countArr %d, %d\n", j, countArr[j]);*/
/*     }*/
     predictions++;
/*     printf("branchPC: %d\n", branchPC);*/
/*     printf("outcome: %c\n", outcome);*/
     int cur = branchPC % 1024;
/*     printf("value of cur: %d\n", cur);*/
/*     printf("count array: %d\n", countArr[0]);*/
/*     printf("counternum %d\n", countArr[cur]);*/
     int mid = (int)(pow(2,(float)B)/2.);
     int max = (int)(pow(2,(float)B));
     //TODO CHECK THESE CONDITIONS
     if(countArr[cur]<mid){
          //predicted not taken
          if(outcome == 't'){
               mispredictions++;
               //updatecounter
               if(countArr[cur]<(max-1)){
                    countArr[cur] = countArr[cur] + 1;
               }
          }
          if(outcome == 'n'){
               if(countArr[cur]>0){
                    countArr[cur] = countArr[cur] - 1;
               }
          }
     }
     if(countArr[cur]>=mid){
          //predicted taken
          if(outcome == 'n'){
               mispredictions++;
               //updatecounter
               if(countArr[cur]>0){
                    countArr[cur] = countArr[cur] - 1;
               }
          }
          if(outcome == 't'){
               //updatecounter
               if(countArr[cur]<(max-1)){
                    countArr[cur] = countArr[cur] + 1;
               }
          }
     }
}



void smith2(int branchPC, char outcome){

/*     for(int j=0;j<1024;j++){*/
/*          printf("countArr %d, %d\n", j, countArr[j]);*/
/*     }*/
     predictions++;
/*     printf("branchPC: %d\n", branchPC);*/
/*     printf("outcome: %c\n", outcome);*/
/*     printf("value of cur: %d\n", cur);*/
/*     printf("count array: %d\n", countArr[0]);*/
/*     printf("counternum %d\n", countArr[cur]);*/
     int mid = (int)pow(2,(float)B)/2.;
     int max = (int)pow(2,(float)B);
     printf("count: %i\n", count);
/*     //TODO CHECK THESE CONDITIONS*/
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


void bimodal(int branchPC, char outcome, int M2, int bisize){

     predictions++;
     //use bits M+1 to 2 of PC
     int cur = (((1<<(M2))-1) & (branchPC>>(2)));
     int mid = 4;
     int max = 8;
     printf("cur: %d\n", cur);
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
     if(bimodPT[cur]>=mid){
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
               smith2(branchPC, outcome); 
          }  
          fclose(fp);
     }
     else if(strcmp("bimodal", predictor) == 0){
          M2 = strtol(argv[2], NULL, 10);
          trace = argv[3];
          int bisize = (int)(pow(2,(float)M2));
          bimodsize = bisize;
          bimodPT = (int *)malloc(sizeof(int)*bisize);
          for(int i=0; i<bisize; i++){
               bimodPT[i] = 4;
          }
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x\n %c", &branchPC, &outcome);
               bimodal(branchPC, outcome, M2, bisize);   
          }  
          fclose(fp);
     }
     else if(strcmp("gshare", predictor) == 0){
          M1 = strtol(argv[2], NULL, 10);
          N = strtol(argv[3], NULL, 10);
          trace = argv[4];
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x\n %c", &branchPC, &outcome);
               predict(branchPC, outcome);   
          }  
          fclose(fp);
     }
     else if(strcmp("hybrid", predictor) == 0){
          K = strtol(argv[2], NULL, 10);
          M1 = strtol(argv[3], NULL, 10);
          N = strtol(argv[4], NULL, 10);
          M2 = strtol(argv[5], NULL, 10);
          trace = argv[6];
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x\n %c", &branchPC, &outcome);
               predict(branchPC, outcome);   
          }  
          fclose(fp);
     }
     else
          printf("%s is not a valid predictor type\n", predictor);
        

     //RESULTS
     printf("Number of predictions: %d\n", predictions);
     printf("Number of mispredictions: %d\n", mispredictions);

     if(strcmp("bimodal", predictor) == 0){
          for(int i=0;i<bimodsize;i++){
               printf("%d %d\n",i, bimodPT[i]);
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


