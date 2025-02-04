#include<bits/stdc++.h>
using namespace std;
void merge(long  long int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long int leftArr[n1], rightArr[n2];
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(long long int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int fun(long long int x[],int n,int c,long long int t){
    long long int sum1=0,sum2=x[0];
    int count=1;
    for(int i=0;i<n;i++){
        sum1=x[i];
        if(sum1 - sum2 >=t){
            sum2=x[i];
            count++;
        }
    }
    if(count >= c) return 1;
    return 0;
}
long long int find(long long int l,long long int r,long long int x[],int n,int c){
    if(r-l ==1){
        return l;
    }
    long long int m=(l+r)/2;
    if(fun(x,n,c,m)==1){
        return find(m,r,x,n,c);
    }
    else{
        return find(l,m,x,n,c);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        long long int x[n];
        for(int i=0;i<n;i++)cin >> x[i];
        mergeSort(x,0,n-1);
        long long int sum1=x[0],sum2=x[0];
        cout << find(0,1000000000000000000,x,n,c) << "\n";
    }
}