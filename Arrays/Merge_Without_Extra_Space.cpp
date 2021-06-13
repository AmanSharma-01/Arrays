 #include<bits/stdc++.h>
// using namespace std;

// void merge(int a[],int n,int b[], int m) {
//     int s = n+m;
//     int c[10];//size of third list must be equal to the sum of the both lists.

//     int i=0,j=0,k=0;

//     while(i<n && j<m)
//     {
//         if(a[i]<b[j]) c[k++] = a[i++];
//         if(a[i]>b[j]) c[k++] = b[j++];
//     }

//     for(;i<n;i++)
//         c[k++] = a[i++];
//     for(;j<m;j++)
//         c[k++] = b[j++];

//         //for loop for printing the final array.
//         for(int q =0;q<10;q++)
//         {
//             cout<<c[q]<<"  ";
//         }
// }

// int main()
// {
//     int a[5]={1,3,5,7,9};
//     int x=5;
//     int b[5]={2,4,6,8,10};
//     int y=5;

//     merge(a,x,b,y);

// }

using namespace std;

int main() {
	//code
	int t;cin>>t;
	
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    
	    int arr1[x];
	    int arr2[y];
	    
	    for(int i=0; i<x; i++){
	        cin>>arr1[i];
	    }
	    for(int i=0; i<y; i++){
	        cin>>arr2[i];
	    }
	    
	    int i=x-1;
	    int j=0;
	    
	    for(;i>=0 && j<y; i--,j++){
	        
	        if(arr1[i]>=arr2[j]){
	            swap(arr1[i],arr2[j]);
	        }
	        else{
	            break;
	        }
	    }
	    
	    sort(arr1,arr1+x);
	    sort(arr2,arr2+y);
	    
	    for(int i=0; i<x; i++){
	        cout<<arr1[i]<<" ";
	    }
	    for(int i=0; i<y; i++){
	        cout<<arr2[i]<<" ";
	    }
	    
	    cout<<"\n";
	}
	return 0;
}