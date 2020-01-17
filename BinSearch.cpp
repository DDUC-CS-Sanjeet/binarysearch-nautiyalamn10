#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int mid;
	mid = (startIndex+lastIndex)/2;
	
	while(startIndex<=lastIndex){
		if(element<array[mid])
		return binarySearchReacursive(array,  startIndex,  lastIndex-1,  element);
	else if(element>array[mid])
    return binarySearchReacursive( array,  startIndex+1,  lastIndex,  element);
    else if(element==array[mid])
  return true;
  else	if(startIndex>lastIndex){
		return false;
	}

}
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int mid;
	mid = (startIndex+lastIndex)/2;
	
	while(startIndex<=lastIndex){
		if(element<array[mid]){
	
		lastIndex = mid -1;
		mid = (startIndex+lastIndex)/2;
	}
	else if(element>array[mid]){
		startIndex=mid+1;
		mid = (startIndex+lastIndex)/2;
	}
	else if(element=array[mid]){
		//cout<<x<<" is found at "<<mid<<" this index ";
		return true;
		}
	else if(startIndex>lastIndex){
		return false;
	}
	
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
	
	cout<<"Enter element you want to search in array = ";
	cin>>element;
    result = binarySearchIterative(array,0,n-1,element);
    if(result==true){
    	cout<<"Element found in array ";
    	
	}
	else if(result==false)
	cout<<"not found in array "<<endl;
    resultrec=binarySearchReacursive( array, 0, n-1,  element);
    if(resultrec==true){
    	cout<<"Element is found";
	}
	else if(resultrec==false)
	cout<<"not found";
  return 0;
}
