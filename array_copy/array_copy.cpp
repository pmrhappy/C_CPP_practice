#include <iostream>
#include <stdlib.h>

using namespace std;;

void getArrayCopy(int* arr){
	
	int *ori_array;
	ori_array[0]=1;
	ori_array[1]=2;
	ori_array[2]=3;
	ori_array[3]=4;
	*arr=&ori_array[0];
	
}

int main(void){
	
	int *array;
	getArrayCopy(array);
	for(int i=0;i<5;i++)
		cout << array[i] << "\n";
	
}