#include <stdio.h>
#include <pthread.h>
#include "main.h"

void *average(void *parameters){

    params *p_ptr = (params *) parameters;
    float sum  = 0.0;
    for(int i = 0; i <= p_ptr->numvalues; i++){
        sum = sum + p_ptr->values[i];
    }
    o_avg = sum/ (float) p_ptr->numvalues;
    pthread_exit(0);
}
int main(void){

    int values [100000]; //Make a large buffer of integers the user can enter
    int i = 0; //Counter of current buffer position
    int ret = 1; //return value from fscanf
    pthread_t threads[1];

    printf("Enter an integer or enter any other key when finished: ");
    ret = fscanf(stdin,"%d", &values[i]);
    do{
        printf("Value %d is: %d\n",i,values[i]);
        i++;
        printf("Enter an integer or enter any other key when finished: ");
        ret = fscanf(stdin,"%d",&values[i]);
    }while (ret != 0);

    //Initialize parameters that can be passed to the thread functions
    params p = {values, i};

    //Create 3 threads to do calculations
    pthread_create(&threads[0], NULL, average, &p);

    //Convert this statement to wait for all three threads to complete
    pthread_join(threads[0],NULL);

    //Modify to print the min, max, and average of the user inputs
    printf("The average was: %.2f\n",o_avg);

    return 0;
}

