// Write a function “runCustomerSimulation” that takes following two inputs
// a) An integer ‘n’: total number of computers in a cafe and a string:
// b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. 
//The first occurrence indicates the arrival of a customer;
//the second indicates the departure of that same customer.

// A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times.
// Customers who leave without using a computer always depart before customers who are currently using the computers.
// There are at most 20 computers per cafe.

// For each set of input the function should output a number telling how many customers, 
// if any walked away without using a computer. Return 0 if all the customers were able to use a computer.

// runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0

// runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer

#include<bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int n, char* str)
{
    int hash[26] = {0};
    int res =0;
    int occ =0;

    for(int i=0; str[i]; i++)
    {
        int index = str[i] - 'A';
        if(hash[index] == 0)
        {
            hash[index] =1;
            if(occ<n)
            {
                occ++;
                hash[index]=2;
            }
            else res++;
        }
        else
        {
            if(hash[index] == 2)
                occ--;
            hash[index]=0;
        }
    }
    return res;
}

int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}