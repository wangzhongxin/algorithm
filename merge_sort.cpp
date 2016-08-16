#include <iostream>
using  std::cout;
using  std::endl;
int num_array1[10] ={1,5,7,9,21,45,47,50,55,60};
int num_array2[10] ={3,5,6,8,11,13,17,46,52,53};

void merge_sort(int len1, int len2, int* num1, int* num2 )
{
	int count =  len1+len2;
	int* temp= new int[count];
	int i = 0;
	int index1 = 0;
	int index2 = 0;
	while(1)
	{
			if(*num1 < *num2 )
			{
				temp[i++] = *num1++;
				index1++;
			}
			else
			{
				temp[i++] = *num2++;
				index2++;
			}
			if(index1 == len1)
			{
				for(;i<count;i++)
				temp[i] = *num2++;
			}
			if(index2 == len2)
			{
				for(;i<count;i++)
				temp[i] = *num1++;
			}
			if(i == count)
				break;
	}
	for(i = 0;i<count;i++)
			cout << temp[i] << endl;
	delete []temp;
}
int main()
{
	merge_sort(10,10,num_array1,num_array2);
	return 0;
}
 
