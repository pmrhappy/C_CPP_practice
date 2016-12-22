

//函式範本（Function template）又稱「通用函式」（Generic function），它可以適用於不同資料型態的參數列，但實作內容相同的函式，以上面的氣泡排序法為例，除了參數列資料型態不同之外，其實排序的程式碼 幾乎相同，實在沒必要為了資料型態的不同而重覆撰寫相同的程式碼。 

//建立函式範本的方法之一是使用"template"關鍵字，並使用class來宣告取代用的資料型態宣告字，使用下面這個程式作個示範： 

#include <iostream> 
using namespace std; 

template <class X> 
void bubbleSort(X[], int); 

int main() { 
    int iarr[] = {5, 3, 11, 6, 8, 9, 20, 11}; 
    float farr[] = {5.1, 3.4, 11.3, 6.6, 8.9, 9.11, 20.2, 11.4}; 

    bubbleSort(iarr, 8); 
    for(int i = 0; i < 8; i++) 
        cout << " " << iarr[i]; 
    cout << endl; 

    bubbleSort(farr, 8); 
    for(int i = 0; i < 8; i++) 
        cout << " " << farr[i]; 
    cout << endl; 
 
    return 0; 
} 

template <class X> 
void bubbleSort(X number[], int length) { 
    int i, j, k, flag = 1; 
    X tmp; 

    for(i = 0; i < length-1 && flag == 1; i++) { 
        flag = 0; 
        for(j = 0; j < length-i-1; j++) { 
            if(number[j+1] < number[j]) { 
                tmp = number[j]; 
                number[j] = number[j+1]; 
                number[j+1] = tmp; 
                flag = 1; 
            } 
        } 
    } 
}