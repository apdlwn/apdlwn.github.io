#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double f(double a, double x){
    return pow(a, x);
}
void calculatefitness(double fitness[], double genedata[], double randoma[]){
    for(int i=0; i<100; i++){
        for(int j=0; j<12; j++){
            int a=randoma[i]/1000;
            fitness[i]+=((f(a, j)-genedata[j])*(f(a, j)-genedata[j]));
        }
        fitness[i]=12/fitness[i];
    }
}
int roulettewheeltable(double wheeltablesize[], double fitness[]){
    double fitnesssum=0;

    for(int i=0; i<100; i++){
        fitnesssum+=fitness[i];
    }
    for(int i=0; i<100; i++){
        wheeltablesize[i]=(fitness[i]/fitnesssum)*100;
    }
}
void selection(){
    for(int i=0; i<100; i++){
        double rand_roulette=rand()%100;
    }
}
int main(){
    srand(time(NULL));
    double randoma[100];
    for(int i=0; i<100; i++){
        randoma[i]=rand()%15000;
        printf("[%d] : %f\n", i+1, randoma[i]/10000);
    }
    double genedata[]={1.0, 2.0,4.0,4.0,9.0,11.0,16.0,28.0,49.0,77.0,173.0,313.0};
    double fitness[100]={0};
}