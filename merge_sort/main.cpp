#include <iostream>
#include<vector>
using namespace std;
void merge(vector<int>& left, vector<int>& right,vector<int>& array1){
    int leftSize =left.size();
    int rightSize = right.size();

    int r =0;
    int l =0;
    int i=0;

    while(l<leftSize && r < rightSize){
        if(left[l]<right[r]){
            array1[i] = left[l];
            i++;
            l++;
        }else{
        array1[i]=right[r];
        i++;
        r++;
        }

    }

    while(l<leftSize){
        array1[i] = left[l];
        i++;
        l++;
    }
     while(r<rightSize){
        array1[i] = right[r];
        i++;
        r++;
    }

}
void mergeSort(vector<int>& arrayx){
    int n = arrayx.size();
    if(n<=1) return;
    int center = n / 2;

    vector<int> leftArray(center);
    vector<int> rightArray(n-center);
    //crear arrays
   for(int i=0; i<n;i++){
        if(i<center){
            leftArray[i]=arrayx[i];
        }else{
            rightArray[i-center]=arrayx[i];
        }
    }
    //dividir
    mergeSort(leftArray);
    mergeSort(rightArray);
    merge(leftArray, rightArray, arrayx);

}

int main()
{
   vector<int> array1={12,3,7,9,14,6,11,2};
   mergeSort(array1);
   for(int num:array1){
    cout<<num<<",";
   }
}
