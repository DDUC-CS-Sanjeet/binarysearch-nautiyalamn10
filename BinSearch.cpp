#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int mid;
	mid = (startIndex+lastIndex)/2;
	
	if(startIndex<=lastIndex){
		if(element<array[mid])
			return binarySearchReacursive(array,  startIndex,  lastIndex-1,  element);
		else if(element>array[mid])
   		 	return binarySearchReacursive( array,  startIndex+1,  lastIndex,  element);
    	else if(element==array[mid])
  			return true;
	}
	else if(startIndex>lastIndex){
			return false;
	}
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int mid;
	
	while(startIndex<=lastIndex)
	{
		
    	mid = (startIndex+lastIndex)/2;
		
	if(element<array[mid]){
	
		lastIndex = mid -1;
	}
	else if(element>array[mid]){
		startIndex=mid+1;
	}
	else if(element==array[mid]){
		return true;
		}
	}
	if(startIndex>lastIndex){
		return false;
	}
}

int main()
{
	int n,element;
	bool result=false,resultrec=false;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements in array = ";
	int array[n];
	for(int i=0;i<n;i++)
	cin>>array[i];
	sort(array,array+n);
	
	cout<<"Enter element you want to search in array = ";
	cin>>element;
    result = binarySearchIterative(array,0,n-1,element);
    if(result==true){
    	cout<<"Element "<<element<<" is found in array through iterative method"<<endl;
    	
	}
	else if(result==false)
	cout<<"Element " << element<<" not found in array "<<endl;
    resultrec=binarySearchReacursive( array, 0, n-1,  element);
    if(resultrec==true){
    	cout<<"Element "<<element<< " is found in array through recursive method";
	}
	else if(resultrec==false)
	cout<<"Element "<<element<< "not found in array";
  return 0;
}
