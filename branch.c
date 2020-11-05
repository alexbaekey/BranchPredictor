// Alexander Baekey
// CDA 5106
// Machine Problem 2


//libs
#include<stdlib.h> 
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>


//NOT SURE IF I NEED ANY OF THESE, DONT THINK
//Instruction Fetch
int IF;
int ID;
int EX;
int MEM;
int WB;

//target branch
int PC;

//Evaluation Metrics
int CPI;
int speedup;

// hazards?
     // data
     // structural
     // control




// main execution

void main(int argc, char *argv[]){

     //   User Input Attributes //

/*     printf("%d\n", argc);*/
/*     printf("%s\n", argv[0]);     */
/*     printf("%s\n", argv[1]);     */

     //read in type of branch predictor
     predictor = argv[0];
     if(predictor == "smith"){
          B = strtol(argv[1], NULL, 10);
          trace = argv[2];
     }
     else if(predictor == "bimodal"){
          M2 = strtol(argv[1], NULL, 10);
          trace = argv[2];
     }
     else if(predictor == "gshare"){
          M1 = strtol(argv[1], NULL, 10);
          N = strtol(argv[2], NULL, 10);
          trace = argv[3];
     }
     else if(predictor == "hybrid"){
          K = strtol(argv[1], NULL, 10);
          M1 = strtol(argv[2], NULL, 10);
          N = strtol(argv[3], NULL, 10);
          M2 = strtol(argv[4], NULL, 10);
          trace = argv[5];
     }
     else if(predictor != "smith" && predictor != "bimodal" && predictor != "gshare" && predictor != "hybrid"){
          printf("%s is not a valid predictor type", &predictor);
     }
        


     //   Read in trace file  //
     char outcome;
     int branchPC;
     FILE* fp;
     fp = fopen(trace, "r");
//not sure if necessary
/*     //firstline?*/
/*     fscanf(fp, "%c", &bom1);*/
/*/*     printf("bom1 %c\n", bom1);*/*/
/*     fscanf(fp, "%c", &bom2);*/
/*/*     printf("bom2 %c\n", bom2);*/*/
/*     fscanf(fp, "%c", &bom3);*/
/*/*     printf("bom 3 %c\n", bom3);*/*/
     while(!feof(fp)){   
          fscanf(fp, "%x\n %c", &branchPC, &outcome);
          predict(branchPC, outcome);)   
     }  
     fclose(fp);


}

void decompaddress1(char* temphexyaddr, int tagsize, int indexsize, int offsetsize){
     //need to adjust to new trace files

     //ex/
     /*302d28 n*/
     /*302d30 n*/
     /*305b0c t*/
     /*30093c t*/


     PC;
     
     
/*     hexyaddr = strtol(temphexyaddr,NULL,16);*/
/*     tag1 = hexyaddr >> (indexsize+offsetsize);*/
/*     index1 = hexyaddr << (tagsize);*/
/*     index1 = index1 >> (addr1tagsize+offsetsize);*/
/*     offset1 = hexyaddr << (tagsize+indexsize);*/
/*     offset1 = offset1 >> (tagsize+indexsize);*/

}

bimodal(){
     
}



void createArr()








//OUTPUT
printf("COMMAND")

     //   Read in trace file  //
     char action;
     char hextempaddr[9];
     FILE* fp;
     fp = fopen(trace, "r");
     //firstline?


