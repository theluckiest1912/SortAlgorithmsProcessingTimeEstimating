#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void Quicksort(int *a, int l, int r){
    int x = a[(l+r)/2]; //xac dinh gia tri truc x(phan tu chinh giua)
    int i = l; //khoi tao dau doc i
    int j = r; //khoi tao dau doc j
    while(i<=j){
        while(a[i]>x){
            i++; //cho i chay den khi gap gia tri >=x thi dung
        }
        while(a[j]<x){
            j--; //cho j chay den khi gap gia tri <=x thi dung
        }
        if(i<=j){
            swap(a[i], a[j]);

            i++;
            j--;
        }//hoan vi 2 phan tu tai i,j sau do tang i, giam j de bat dau cho vi tri moi

    }
    if(l<j) Quicksort(a,l,j);
    if(i<r) Quicksort(a,i,r);//tiep tuc cho i,j chay nen lap tu buoc 3 den buoc 5 cho den khi j vuot qua i thi dung
}

void SelectionSort(int *a, int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
}

void BubbleSort(int *a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

void Merge(int *a, int left, int mid, int right){
    int *temp = new int[right - left+1 ];
    int m = 0;
    int i = left;
    int j = mid+1;
    while(!(i>mid && j>right)){
        if((i<=mid && j<=right && a[i]<a[j]) || j>right){
            temp[m++] = a[i++];
        }
        else temp[m++] = a[j++];
    }
    for(int i=0;i<m;i++){
        a[left+i] = temp[i];
    }
    delete[] temp;
}

void MergeSort(int *a, int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,r);
        Merge(a,l,mid,r);
    }
}

void InsertionSort(int *a, int n){
    for(int i=1;i<n;i++){
        int x = a[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(x<a[j])  a[j+1] = a[j];
            else break;
        }
        a[j+1] = x;
    }
}

void BinaryInsertionSort(int *a, int n){
    for(int i=1;i<n;i++){
        int x = a[i];
        int l = 0;
        int r = i-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(x<a[mid]) r = mid - 1;
            else l = mid + 1;
        }
        for(int j=i-1;j>=l;j--){
            a[j+1] = a[j];
        }
        a[l] = x;
    }
}



int getInteger()
{
    int n;
    cout<<"Enter the array's size: ";
    do
    {
        cin>>n;
        if(n<100 || n>100000000) cout<<"Enter the array's size again\n";
    } while (n<100 || n>100000000);
    return n;

}

void generateArray(int *a, int n){
    int c = -10001;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i] = c + rand()%10001;
    }
}

void output(int *a, int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}

void copyArray(int a[], int b[], int n)
{
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }
}

void Menu(){
    cout << "\n-------MENU-------" << endl;
    cout << "1.QuickSort" << endl;
    cout << "2.SelectionSort" << endl;
    cout << "3.MergeSort" << endl;
    cout << "4.Insertion" << endl;
    cout << "5.BinaryInsertionSort" << endl;
    cout << "Choose an algorithm: " << endl;

}

int main()
{
   int n = getInteger();
   int* a = new int [n];
   generateArray(a,n);
   output(a,n);
   while(1)
   {
        int* b = new int [n];
        copyArray(a,b,n);
        Menu();
        int choose;
        cin>>choose;
        switch(choose)
        {
            case 1:
            {
                clock_t start = clock();
                Quicksort(b,0,n-1);
                clock_t end = clock();
                cout<<"Time: "<< end - start <<endl;
                break;
            }
            case 2:
            {
                clock_t start = clock();
                SelectionSort(b,n);
                clock_t end = clock();
                cout<<"Time: "<< end - start <<endl;
                break;
            }
            case 3:
            {
                clock_t start = clock();
                BubbleSort(b,n);
                clock_t end = clock();
                cout<<"Time: "<< end - start <<endl;
                break;
            }
            case 4:
            {
                clock_t start = clock();
                MergeSort(b,0,n-1);
                clock_t end = clock();
                cout<<"Time: "<< end - start <<endl;
                break;
            }
            case 5:
            {
                clock_t start = clock();
                BinaryInsertionSort(b,n);
                clock_t end = clock();
                cout<<"Time: "<< end - start <<endl;
                break;
            }
        }
        cout<<"Do you want to continue (Y/n)";
        char c;
        cin>>c;
        if(c=='n'||c=='N') {
            goto exit_loop;
            delete[] b;
        }

   }
   exit_loop: ;
   delete[] a;
   return 0;
}
