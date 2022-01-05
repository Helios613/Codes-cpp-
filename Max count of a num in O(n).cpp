#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    int n = sizeof(a)/sizeof(a[0]);

    int k = n;

     for (int i = 0; i< n; i++)
        a[a[i]%k] += k;

    int max = a[0], result = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            result = i;
        }
    }

    cout<<result;

}
