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

//Evaluation Metrics
int CPI;
int speedup;

// hazards?
     // data
     // structural
     // control

//functions
void smith(int branchPC, char outcome);
void predict(int branchPC, char outcome);




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
/*          printf("countArr %d, %d", j, countArr[j]);*/
/*     }*/
     predictions++;
     printf("branchPC: %d\n", branchPC);
     printf("outcome: %c\n", outcome);
     int cur = branchPC % 1024;
     printf("value of cur: %d\n", cur);
     printf("count array: %d\n", countArr[0]);
     printf("counternum %d\n", countArr[cur]);
     //TODO CHECK THESE CONDITIONS
     if(countArr[cur]<(int)(pow(2,B)/2)){
          taken = false;
/*          if(strcmp("T",outcome)==0){*/
/*               mispredictions++;*/
/*          }*/
     }

/*     if(countArr[cur]>=(int)(pow(2,B)/2)){*/
/*          taken = true;*/
/*          if(strcmp("N",outcome)==0){*/
/*               mispredictions++;*/
/*          }*/
/*     }*/

/*     //update counter*/
/*     if(taken==true){*/
/*          if(countArr[cur]<(int)(pow(2,B)))*/
/*               countArr[cur]++;*/
/*     }*/
/*     else{*/
/*          if(countArr[cur]>0)*/
/*     countArr[cur]--;*/
/*     }*/
}


// main execution

void main(int argc, char *argv[]){

     //   User Input Attributes //

/*     printf("%d\n", argc);*/
/*     printf("%s\n", argv[0]);     */
/*     printf("%s\n", argv[1]);     */

     //   Read in trace file  //
     char outcome;
     int branchPC;
     FILE* fp;

     char *trace;
     char *predictor;
     char *taken;
     

     //read in type of branch predictor, loop through file
     predictor = argv[1];
//while ( != 0)
     if(strcmp("smith", predictor) == 0){
          B = strtol(argv[2], NULL, 10);
          trace = argv[3];
          //initialize counter array of size 2^10
          //TODO JUST CAUSE IDK WHAT SIZE TO MAKE THIS ARRAY
          //
          countArr = (int *)malloc(sizeof(int)*1024);
          for(int i=0; i<1024; i++){
               //NOT SURE IF RIGHT START VALUE  ROUND DOWN? //TODO
               countArr[i] = 0;
          }
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x\n %c", &branchPC, &outcome);
               smith(branchPC, outcome); 
          }  
          fclose(fp);
     }
     else if(strcmp("bimodal", predictor) == 0){
          M2 = strtol(argv[2], NULL, 10);
          trace = argv[3];
          fp = fopen(trace, "r");
          while(!feof(fp)){   
               fscanf(fp, "%x\n %c", &branchPC, &outcome);
               predict(branchPC, outcome);   
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
        



/*//not sure if necessary*/
/*     //firstline?*/
/*     fscanf(fp, "%c", &bom1);*/
/*     printf("bom1 %c\n", bom1);*/
/*     fscanf(fp, "%c", &bom2);*/
/*     printf("bom2 %c\n", bom2);*/
/*     fscanf(fp, "%c", &bom3);*/
/*     printf("bom 3 %c\n", bom3);*/

}


