#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

// prototypes
int getDouble(double *pNumber);
void doubleTheData(double *d1,double *d2,double *d3,double *d4);
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage);
void fillArray(double values[], int numArray, double fillValue);


int main(void)
{
    double num1 = 0.0, num2 = 0.0, num3 = 0.0, num4 = 0.0;
    double *pnum1, *pnum2, *pnum3, *pnum4;
    pnum1 = &num1;
    pnum2 = &num2;
    pnum3 = &num3;
    pnum4 = &num4;

    printf("Enter 4 floating-point number, one number per input line\n");
    printf("Enter a number: ");
    if(!getDouble(pnum1)){
        return 1;
    }
    printf("Enter a number: ");
    if(!getDouble(pnum2)){
        return 1;
    }
    printf("Enter a number: ");
    if(!getDouble(pnum3)){
        return 1;
    }
    printf("Enter a number: ");
    if(!getDouble(pnum4)){
        return 1;
    }

    double average = 0;
    double sum = 0;
    doubleTheData(pnum1,pnum2,pnum3,pnum4);
    num1 = *pnum1;
    num2 = *pnum2;
    num3 = *pnum3;
    num4 = *pnum4;
    printf("After doubling the numbers the new values are: %lf %lf %lf %lf \n", *pnum1, *pnum2, *pnum3, *pnum4);


    double arr[7] = {};
    for(int i = 0; i < 7; i++){
        printf("Enter a number: ");
        if(!getDouble(&arr[i])){
            return 1;
        }
    }

    calculateArrayStats(arr, 7, &sum, &average);
    printf("The average and sum of the array elements: %lf, %lf \n", average, sum);

    //Call fillArray() to change all of the array element values to 40.
    fillArray(arr, 7, 40);

    for(int i = 0; i < 7; i++){
        printf("%lf", arr[i]);
        if(i !=6){
            printf(",");
        }

    }
    printf("\n");

    return 0;
}


/*
Function: getDouble()
Parameter: double *pNumber: pointer to a variable that is filled in by the user input, 
if valid Return Value: int: 1 if the user entered a valid floatingpoint number, 0 otherwise
Description: This function gets a floating-point number from the user. 
If the user enters a valid floating-point number, 
the value is put into the variable pointed to by the parameter and 1 is returned. 
If the user-entered value is not valid, 0 is returned. */
int getDouble(double *pNumber){
    /* the array is 121 bytes in size; we'll see in a later lecture how we can improve this code */
    char record[121] = {0}; /* record stores the string */
    double number = 0;
    /* NOTE to student: indent and brace this function consistent with your others */
    /* use fgets() to get a string from the keyboard */
    fgets(record, 121, stdin);
    /* extract the number from the string; sscanf() returns a number
     * corresponding with the number of items it found in the string */
    if (sscanf(record, "%lf", &number) != 1)
    {
        /* if the user did not enter a number recognizable by
         * the system, set number to 0 */
        return 0;
    }else{
        *pNumber = number;
    }
    return 1;
}


/*
Function: doubleTheData()
Parameters: double *d1, *d2, *d3, *d4: four pointers to floating-point numbers,
Description: This function takes pointers to four floating-point numbers passed 
as doubles and double them all.
Return value: none
*/
void doubleTheData(double *d1,double *d2,double *d3,double *d4){
    // double them all
    *d1 *= 2;
    *d2 *= 2;
    *d3 *= 2;
    *d4 *= 2;
}


/*
Function: calculateArrayStats()
Parameters: 
double values[]: floating-point numbers 
int numArray: number of array elements
double *pSum: pointer to a variable that is filled in by this function with the sum of all elements in the array
double *pAverage: pointer to a variable that is filled in by this function with the average of all elements in the array
Return Value: none
Description: This function takes an array of floating-point (double) numbers, 
given the number of elements in the array as a parameter, 
and calculates the average and sum of the numbers. Once calculated, 
the average gets put into the variable pointed to by the pAverage parameter 
and the sum gets put into the variable pointed to by the pSum parameter. */
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage){
    double sum = 0;
    for(int i = 0; i < numArray; i++){
        sum += values[i];
    }
    *pSum = sum;
    *pAverage = sum/numArray;
}



/*
Function: fillArray()
Parameters: 
double values[]: floating-point numbers
int numArray: number of array elements
double fillValue: value to put into array
elements Return Value: none
Description: This function takes an array of floating-point (double) numbers, 
given the number of elements in the array as a parameter, 
and puts the fillValue into each element of the array. */
void fillArray(double values[], int numArray, double fillValue){
    // puts the fillValue into each element of the array
    for(int i = 0; i < numArray; i++){
        values[i] = fillValue;
    }
}