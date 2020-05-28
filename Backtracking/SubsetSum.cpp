        // REFERENCES : GEEKSFORGEEKS and ABDUL BARI(YOUTUBE)

#include <iostream>
using namespace std;
void printTuple(int tuple[],int tsize)
{
    // print the tuple vector
    for(int i=0;i<tsize;i++)
    {
        cout << tuple[i] << " ";
    }
    cout << endl;
}
void subset(int arr[],int tuple_vector[],int size, int tsize, int itr, int totalSum, int k)
{
    if(totalSum == k)       // if sum(so far) is equal to given sum - it means we found a solution
    {
        printTuple(tuple_vector, tsize);        // print the tuple vector 
        /*
         after printing, remove the last element, and go on searching for next element
        */
        subset(arr,tuple_vector, size, tsize-1, itr+1, totalSum-arr[itr], k); 
        return;
    }   
    else
    {
        // generate all nodes along breadth
        for(int i=itr;i<size;i++)
        {
            tuple_vector[itr] = arr[i];     // include the cuurent nodes to tuple
            // consider next level nodes(along depth)
            subset(arr, tuple_vector, size, tsize+1, i+1, totalSum+arr[i], k);
        }
    }    
}
void subsetUtil(int arr[],int size,int k)
{
    int* tuple_vector = new int[size];      // variable size array that grows dynamically, to store the elements that constitue to the original sum
    subset(arr, tuple_vector,size,0,0,0,k);     // (array, tuple_vector, array_size, tuple_size(so far), index, sum(so far), given_sum)
    delete tuple_vector;
}
int main()
{
    int arr[] = {10, 7, 5, 18, 12, 20, 15};     // given set
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 35;         // sum that is required
    subsetUtil(arr,size,k);    
    return 0;
}