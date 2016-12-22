

//�禡�d���]Function template�^�S�١u�q�Ψ禡�v�]Generic function�^�A���i�H�A�Ω󤣦P��ƫ��A���ѼƦC�A����@���e�ۦP���禡�A�H�W������w�ƧǪk���ҡA���F�ѼƦC��ƫ��A���P���~�A���ƧǪ��{���X �X�G�ۦP�A��b�S���n���F��ƫ��A�����P�ӭ��м��g�ۦP���{���X�C 

//�إߨ禡�d������k���@�O�ϥ�"template"����r�A�èϥ�class�ӫŧi���N�Ϊ���ƫ��A�ŧi�r�A�ϥΤU���o�ӵ{���@�ӥܽd�G 

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