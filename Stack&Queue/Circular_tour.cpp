// Suppose there is a circle. 
// There are N petrol pumps on that circle. 
// You will be given two sets of data.

// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.

// Find a starting point where the truck can start to get through the 
// complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.


#include <bits/stdc++.h>
using namespace std; 

class petrolPump 
{
    public:
    int petrol; 
    int distance; 
}; 

int printTour(petrolPump arr[], int n) 
{ 
    int start =0;
    int end =1;

    int pet = arr[start].petrol - arr[start].distance;

    while(end != start || pet<0)
    {
        while(pet<0 && start!=end)
        {
            pet = pet - (arr[start].petrol - arr[start].distance);
            start = (start+1)%n;

            if(start == 0)
            return -1;
        }

        pet += arr[end].petrol - arr[end].distance;
        end = (end+1)%n;
    }
    return start;
} 

int main() 
{ 
    petrolPump arr[] = {{4, 6}, {6, 5},{7, 3}, {4, 5}}; 

    int n = sizeof(arr)/sizeof(arr[0]); 
    int start = printTour(arr, n); 

    (start == -1)? cout<<"No solution": cout<<"Start = "<<start; 

    return 0; 
} 