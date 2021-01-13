#include<iostream>
#include<graphics.h>
#include<algorithm>

using namespace std;

int counter;

void swap(int *xp, int*yp);

int partition (int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

void selectionSort(int arr[], int n);

void insertionSort(int arr[], int n);

void bubbleSort(int arr[], int n);

int main() {

    do {

        int gd = DETECT , gm;
        initgraph(&gd, &gm,"C:\Program Files (x86)\CodeBlocks\MinGW\include\winbgim");

        int arr[60];
        counter = 0;
        cleardevice();
        int i=0;
        while(counter<60){
            setfillstyle(1,15);
            arr[counter]=rand()%500;
            bar(i,500,i+5,500-arr[counter++]);
            i+=10;
        }
        cout << "Random data values: \n";
        for(int k=0; k<60; k++){
            cout<< arr[k] << " ";
        }
        cout << endl << endl;

        cout<<"Select Sorting Algorithm"<<endl<<"1 Bubble Sort"<<endl<<"2 Insertion Sort"<<endl<<"3 Selection Sort"<<endl<<"4 Quick Sort"<<endl;
        int choose;
        cin>>choose;
        system("cls");

        switch(choose) {

            case 1:
                bubbleSort(arr,60);
                cout<<"Sorted data is: \n";
                    for(int k=0;k<60;k++){
                    cout<< arr[k] <<" ";
                }
                cout<<endl<<endl;
                break;

            case 2:
                insertionSort(arr,60);
                cout<<"Sorted Data is: \n";
                for(int k=0;k<60;k++) {
                    cout<< arr[k] << " ";
                }
                cout<< endl << endl;
                break;

            case 3:
                selectionSort(arr,60);
                cout<<"Sorted Data is: \n";
                for(int k=0;k<60;k++) {
                    cout<< arr[k] << " ";
                }
                cout<< endl << endl;
                break;

            case 4:
                quickSort(arr,0,60);
                cout<<"Sorted Data is: \n";
                for(int k=0;k<60;k++) {
                    cout<< arr[k] << " ";
                }
                cout<< endl << endl;
                break;

            default:
                cout<<"Wrong Choice!!"<< endl;
                break;
        }

        cleardevice();
        counter = 0;
        for(int i=0; counter<60; i+=10){
            setfillstyle(1,15);
            bar(i,500,i+5,500-arr[counter++]);
        }

        delay(200);
        cout<<"Press 1 to continue";
        int d;
        cin >> d;
        closegraph();
    } while(1);

    return 0;
}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

int partition (int arr[], int low, int high)
{

    int pivot = arr[high]; //pivot
    int i = (low -1); //Index of smaller element

    int temp1, temp2;

    for(int j=low; j<=high-1;j++)
    {
        if(arr[j]< pivot)
        {
            temp1 =i;
            temp2 = j;

            cleardevice();
            counter = 0;
            for(int i=0; counter<60; i+=10){
                if(counter == temp1 || counter == temp2 || counter == j){
                    setfillstyle(1,9);
                }
                else{
                    setfillstyle(1,5);
                }
                bar(i,500,i+5,500-arr[counter++]);
            }
            delay(20);

            i++;
            swap(&arr[i], &arr[j]);

            cleardevice();
            counter = 0;
            for(int i=0; counter<60; i+=10){
                    if(counter == temp1 || counter == temp2 || counter ==j){
                        setfillstyle(1,13);
                    }
                    else{
                        setfillstyle(1,5);
                    }
                    bar(i,500,i+5,500-arr[counter++]);
                }
                delay(20);
        }
        else{
            cleardevice();
            counter = 0;
            for(int i=0; counter<60; i+=10){
                if(counter == j){
                    setfillstyle(1,13);
                }
                else{
                    setfillstyle(1,5);
                }
                bar(i,500,i+5,500-arr[counter++]);
            }
            delay(40);
        }

    }

    temp1 = i+1;
    temp2 = high;

    delay(200);

    cleardevice();
    counter = 0;
    for(int i=0; counter<60; i+=10){
        if(counter == temp1 || counter == temp2){
            setfillstyle(1,7);
        }
        else{
            setfillstyle(1,5);
        }
        bar(i,500,i+5,500-arr[counter++]);
    }
    delay(200);

    swap(&arr[i+1], &arr[high]);

    cleardevice();
    counter = 0;
    for(int i=0; counter<60; i+=10) {
        if(counter ==temp1 || counter == temp2) {
            setfillstyle(1,14);
        }
        else{
            setfillstyle(1,5);
        }
        bar(i,500,i+5,500-arr[counter++]);
    }

    delay(200);
    return (i+1);
}




void bubbleSort(int arr[], int n){

    int i, j;
    for(i=0; i<n-1; i++){
        for(j =0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){

                int temp1 = j;
                int temp2 = j+1;

                cleardevice();
                counter = 0;

                for(int i=0; counter<60; i+=10){
                    if(counter == temp1){
                        setfillstyle(1,5);
                    }
                    else if(counter == temp2){
                        setfillstyle(1,10);
                    }
                    else{
                        setfillstyle(1,9);
                    }
                    bar(i,500,i+5,500-arr[counter++]);
                }
                delay(200);

                swap(arr[temp1],arr[temp2]);
            }
        }
    }

}



void insertionSort(int arr[], int n){

    int i, key, j;
    for(i=1;i<n; i++){

        key = arr[i];
        j = i -1;

        cleardevice();
        counter =0;
        for(int i=0;counter<60;i+=10){
            if(counter == i){
                setfillstyle(1,4);
            }
            else{
                setfillstyle(1,9);
            }
            bar(i,500,i+5,500-arr[counter++]);
        }
        delay(100);

        while(j >= 0 && arr[j] > key){

            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j + 1] = key;

    int temp1 = j+1;
    int temp2 = i;
    cleardevice();
    counter = 0;

    for(int i=0; counter<60 ; i+=10){
        if(counter == temp1){
            setfillstyle(1,4);
        }
        else if(counter == temp2){
            setfillstyle(1,2);
        }
        else{
            setfillstyle(1,9);
        }
        bar(i,500,i+5,500-arr[counter++]);
    }
    delay(100);
  }
}


void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for(i = 0; i<n-1;i++)
    {
        min_idx = i;
        for(j = i+1;j<n;j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        cleardevice();
        counter = 0;
        for(int k=0; counter<60; k+=10){
            if(counter == min_idx){
                setfillstyle(1,2);
            }
            else if (counter == i) {
                setfillstyle(1,2);
            }
            else{
                setfillstyle(1,15);
            }
            bar(k,500,k+5,500-arr[counter++]);

        }
        delay(100);

        swap(&arr[min_idx], &arr[i]);

    }
}


void quickSort(int arr[], int low, int high){

    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low,pi -1);

        quickSort(arr, pi+1, high);
    }
}








