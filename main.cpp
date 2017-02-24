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
void MinFind(int a[], int size, int min, int index);
void MinRec(int a[], int size, int min, int index, int current);
int ArraySum(int *a, int size);
bool isPalla(int *x, int length);
bool isPallaRec(int *x, int length);
bool isPosPall(int *a, int larr, int lpall,int &x);

int main() {
    srand(time(NULL));
    int p1a=6;
    int p1b=4;
    //order1(&p1b,&p1a);
    //order2(p1b,p1a);
    new int;
    //ArrayFill();
    int a[]={3,5,7,3,7,9,9};
    int 
}
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

void ArrayFill(int a[],int size){
    a[size];
    for(int i =0; i<size; i++){
        a[i]=rand()%100;
    }
    return;
    
}

void ArrayPrint(int a[], int size){
    for(int i =0; i<size;i++){
        cout<<a[i]<<", ";
    }
    cout<<endl;
}
void Swap(int &x, int &y){
    int *tmp;
    tmp=x;
    x=y;
    y=tmp;
}
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

void MinRec(int a[], int size, int min, int index, int current){
    if(current>=(size-1)){
        cout<<"The smallest value in this array is "<<min<<" which can be found at index "<<index<<endl;
        return; 
    }
    if(a[index]>a[current]){
        min=a[current];
        index=current;                
    }
    MinRec(a,size,min,index,current+1);
}

void Sort(){
    int min;
    int minind;
    int sortedlength=-1;
    while(){
    FindMin(a[],int size,min, minind);
    Swap(minind,sortedlength);
    sortedlength++;
    }
}

int ArraySum(int *a, int size){
    int sum;
    for(int i =0; i<size;i++){
        sum=sum+a[i];
    }
    return sum;
}

//bool isPalla(int *a,int length){
//    int b[length/2];
//    int c[length/2];
//    for(int i=0;i<length/2;i++){
//        b[i]=a[i];
//        c[i]=a[length-i];
//    }
//    if(b==c){
//        return true;
//    }
//    else{
//        return false;
//    } 
//}
bool isPalla(int &a, int window){
    if(even){
        
    }
    if(odd){
}

bool isPallaRec(int *a,int length){
    if(a[0]!=a[length]){
        return false;
    }
    if(length==0){
        return true;
    }
    isPallaRec(&a[1], length-2);
    
}

bool isPosPall(int *a, int larr, int lpall,int &x){
    bool pall=false;
    for(int i=0; i<(larr-lpall);i++){
        if(isPalla(&a[i],lpall ==1)){
            x=a[i];           
            pall=true;
        }
    }
    return pall;
    
}

bool isFinPalla(int *a, int larr,int &x, int &y){
    if(larr<=3){
        return;
    }
    for(int i=larr;i>1;i--){
        for(int j= 0; j<larr-length;j++){
            isPalla(a[i],larr);
        }
    }
    
    
}
