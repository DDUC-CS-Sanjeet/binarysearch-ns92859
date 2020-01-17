/*
  	By : Neeraj Sharma
   	Roll no. : 19HCS4037
   	Description : Binary search with and without recursion
*/
#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int flag=0;
	if(startIndex<=lastIndex)
	{
		int mid=(startIndex+lastIndex)/2;
		if(element>array[mid])
		{
			return binarySearchReacursive(array,mid+1,lastIndex,element);
		}
		else if(element<array[mid])
		{
			return binarySearchReacursive(array,startIndex,mid-1,element);
		}
		else if(element==array[mid])
		{
			startIndex=lastIndex+1;
			flag++;
		}
	}
	
	 if(flag==1)
	{
		return true;
	}
  	else
  	{
  		return false;
	}
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int counter=0;
	int first=startIndex;
	int last=lastIndex;
	int mid;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(element>array[mid])
		{
			first=mid+1;
		}
		else if(element<array[mid])
		{
			last=mid-1;
		}
		else
		{
			first=last+1;
			counter++;
		}
	}
	if(counter==1)
	{
		return true;
	}
	else
	{
		return false;
	}
  
}

int main()
{
	int elmnt1,start1,last1,target1;
	bool ansit;
	cout<<"                                        Welcome to Binary Search Iterative :)\n\n";
	cout<<"Enter how many elements you want in your array : ";
	cin>>elmnt1;
	int arr1[elmnt1];
	cout<<"Now enter the element of your array : ";
	for(int i=0;i<elmnt1;i++)
	{
		cin>>arr1[i];
	}
	cout<<"\nEnter the element which you want to search in your array : ";
	cin>>target1;
	cout<<"Your array before sorting is : ";
	for(int i=0;i<elmnt1;i++)
	{
		cout<<arr1[i]<<" ";
	}
	sort(arr1,arr1+elmnt1);
	cout<<"\nYour array after sorting is : ";
	for(int i=0;i<elmnt1;i++)
	{
		cout<<arr1[i]<<" ";
	}
	start1=0;
	last1=elmnt1-1;
	ansit=binarySearchIterative(arr1,start1,last1,target1);
	if(ansit==1)
	{
		cout<<"\n\nElement founded";
	}
	else
	{
		cout<<"\n\nElement not found";
	}
	cout<<"\n\n\n                                   Welcome to Binary Search Recursive :)\n\n";
	int start2,last2,elmnt2,target2;
	cout<<"Enter how many elements you want in your array : ";
	cin>>elmnt2;
	int arr2[elmnt2];
	cout<<"Now enter the element of your array : ";
	for(int i=0;i<elmnt2;i++)
	{
		cin>>arr2[i];
	}
	cout<<"\nNow,enter the element which you want to search in your array : ";
	cin>>target2;
	cout<<"\nYour array before sorting is : ";
	for(int i=0;i<elmnt2;i++)
	{
		cout<<arr2[i]<<" ";
	}
	sort(arr2,arr2+elmnt2);
	cout<<"\nYour array after sorting is : ";
	for(int i=0;i<elmnt2;i++)
	{
		cout<<arr2[i]<<" ";
	}
	start2=0;
	last2=elmnt2-1;
	int ansrec=binarySearchReacursive(arr2,start2,last2,target2);
	if(ansrec==1)
	{
		cout<<"\n\nElement founded";
	}
	else
	{
		cout<<"\n\nElement not found";
	}
  return 0;
}
