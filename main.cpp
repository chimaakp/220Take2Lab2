/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chima Akparanta
 *
 * Created on February 17, 2017, 12:26 PM
 */

#include <cstdlib>
#include<iostream>
#include<stdlib.h>
#include<time.h>


using namespace std;

/*
 * 
 */
bool order1(int *x, int *y);
bool order2(int &x, int &y);
void ArrayFill(int a[], int size);
void ArrayPrint(int a[],int size);
void MinFind(int a[], int size, int &min, int &index);
void MinRec(int a[], int size, int &min, int &index, int current);
int ArraySum(int* x, int size);
int SmallestSeq(int a[],int length);
void SmallestSort(int a[], int size);
void Swap(int &x, int &y);
bool isPalla(int x[], int length);
bool isPallaRec(int *x, int length);
bool isPosPall(int *a, int larr, int lpall,int &x);

int main() {
    srand(time(NULL));
    int p1a=6;
    int p1b=4;
    //order1(&p1a,&p1b);
    //cout<<p1a;
    //order2(p1a,p1b);
    //cout<<p1a;
    int size=20;
    int a[size];
    ArrayFill(a,size);
    ArrayPrint(a,size);
    //cout<<a;
    //int min=0;
    //int mindex=0;
    //MinFind(a,size,min,mindex);
    //MinRec(a,size,min,mindex,1);//mindex &curind must be 0
    //cout<<"Min: "<<min<<" Mindex: "<<mindex<<endl;
    //ArraySum(&a[3],5);
    //SmallestSeq(a,size);
    //SmallestSort(a,size);
    //ArrayPrint(a,size);
    int b[]={2,6,3,3,7,7,3,3,6,2};
    int length=10;
    //cout<<isPallaRec(b,length);
    int palint=0;
    isPosPall(&b[0],length,2,palint);
    cout<<endl<<palint;
}
//Working
//Problem 1:This Function takes two values. If the values are in order
//True is returned. If they are not, false is returned and the values are 
//swapped so that they are now in order
//Call by Pointer
bool order1(int *x, int *y){
    if(*x>*y){//ensures first parameter is smaller
        int tmp = *x;
        *x=*y;
        *y=tmp;
        return false;
    }
    else{
        return true;
    } 
}
//Working
//Problem 2: This function is the same as problem 1 except it uses
//Call by Reference
bool order2(int &x, int &y){
    if(x>y){
        int tmp=x;
        x=y;
        y=tmp;
        return false;
    }
    else{
        return true;
    }
}
//Working
//Problem 3:This function takes an array of 20 ints and then
//fills it with values from 0 to 99
void ArrayFill(int a[],int size){
    a[size];
    for(int i =0; i<size; i++){
        a[i]=rand()%100;
    }
    return;    
}
//Working
//Problem 4:This function, takes an array and an int(size of array)
//and prints the values within the array seperated by commas.
//Once the array has been printed, endl is used to flush  buffer
void ArrayPrint(int a[], int size){
    for(int i =0; i<size-1;i++){
        cout<<a[i];
        cout<<", ";
    }
    cout<<a[size-1];

    cout<<endl;
}


//Working
//Problem 5: This function takes an array the size of the array
//and 2 int variables, and then finds the smallest value and its index using
//using call by reference
//smallest value and its index 
void MinFind(int a[], int size, int &min, int &index){
    min=a[0];
    for(int i=1;i<size;i++){
        if(a[i]<min){
            min=a[i];
            index=i;
        }        
    }
    cout<<"The smallest value in this array is "<<min<<" which can be found at index "<<index<<endl;
    return;    
}
//Working
//Problem 6: This function is the same as function 5, except it is recursive
//there is also a new variable curind(current index) which keeps track
//of where in the array we are at the moment
void MinRec(int a[], int size, int &min, int &index, int curind){
    if(curind>=(size-1)){
        cout<<"The smallest value in this array is "<<min<<" which can be found at index "<<index<<endl;
        return; 
    }
    if(a[index]>a[curind]){
        min=a[curind];
        index=curind;                
    }
    MinRec(a,size,min,index,curind+1);
}

//
//void Sort(){
//    int min;
//    int minind;
//    int sortedlength=-1;
//    while(){
//    FindMin(a[],int size,min, minind);
//    Swap(minind,sortedlength);
//    sortedlength++;
//    }
//}
//Working
//Problem 7a:This function takes an address of an array
//and its size and returns the sum of all values within
int ArraySum(int* a, int size){
    int sum=0;
    for(int i =0; i<size;i++){
        sum=sum+a[i];
    }
    //cout<<sum<<endl;
    return sum;
}
//Working
//Problem 7b: An array and its length are passed into this function
//a random number between 3 and 7 is generated. This number serves as the window
//The purpose is to find the the smallest sequence of numbers of size window within the array
//the index of the first value of the smallest sequence is returned
int SmallestSeq(int a[],int length){
    int x=rand()%5 +3;
    cout<<"X: "<<x<<endl;
    int minsum=10000;
    int index=0;
    for(int i=0; i<=length-x;i++){
        //cout<<i<<endl;
        ArraySum(&a[i],x);
        if(ArraySum(&a[i],x)<=minsum){
            minsum=ArraySum(&a[i],x);
            index=i;
        }
    }
    cout<<index<<endl;
    return index;
    
}
//Working
//Problem 8: This function takes 2 inputs, an array and its size
//The function sorts the array by placing the smallest value 
//at the begining and then changing the index
void SmallestSort(int a[], int size){
    if(size <=2){
        return;
    }
    int min=0;
    int mindex=0;
    MinFind(a,size,min, mindex);
    if(min<a[0]){
            a[mindex]=a[0];
            order2(a[0],min);
    }
    //ArrayPrint(a,size);
    int *newarr=&a[1];
    SmallestSort(newarr,size-1);
    
}
//Working
//Problem 9:This function takes the address of a value in an array
//and the size of the array. This function checks to see if the array is a paladrone
bool isPalla(int a[],int length){
    int b[length/2];
    int c[length/2];
    bool tf=false;
    for(int i=0;i<length/2;i++){
        if(a[i]==a[length-i-1]){
            tf=true;
        }
        else{
            tf=false;
            break;
        }
    }
    cout<<tf;
    return tf;
 
}
//Working
//Problem 10:This function is the same as problem 9
//except it is recursive
bool isPallaRec(int a[],int length){
    if(a[0]!=a[length-1]){
        return false;
    }
    if(length==0){
        return true;
    }
    isPallaRec(&a[1], length-2);
    
}
//Problem 11:This function takes the address of the first value 
//of an array, the size of the array, a window,
//and a third value which will hold the index of any paladrones within the 
//array.This function tries to find a paldrone of size window 
//within the array passed in and returns true if one is found
bool isPosPall(int *a, int larr, int lpall,int &x){
    bool pall=false;
    for(int i=0; i<(larr-lpall);i++){
        if(isPalla(&a[i],lpall)){
            x=a[i];           
            pall=true;
        }
    }
    return pall;
    
}
//
//bool isFinPalla(int *a, int larr,int &x, int &y){
//    if(larr<=3){
//        return;
//    }
//    for(int i=larr;i>1;i--){
//        for(int j= 0; j<larr-length;j++){
//            isPalla(a[i],larr);
//        }
//    }
//    
//    
//}
