#pragma once
#include <iostream>
using namespace std;
static int s;

class arrayimplement
{
public:
	arrayimplement(int array2[],int s)
	{
		this->s = s;
		for (int i = 0; i < s; i++)
		{
			this->array[i] = array2[i];
		}
	}
	void Display()
	{
		cout << "{";
		for (int i = 0; i < s; i++)
		{	
			cout << array[i];
			if (i < s  - 1)
			{
				cout << ",";
			}
		}
		cout << "}" << endl;;
	
	}
	void Insert(int index, int value)
	{
		this->s += 1;
		for (int i = s; i >= index; i--)
		{
			array[i] = array[i - 1];
		}
		array[index] = value;
	}
	int Delete_By_Value(int value)
	{
		bool flag = false;
		int i = 0;
		while ( i < s)
		{
			if (array[i] == value)
			{
				for (int j = i; j < s - 1; j++)
				{
					array[j] = array[j + 1];
				}
 				flag = true;
				break;
			}
			i++;
		}
		if (flag == true)
		{
			this->s -= 1;
			return i;
		}
		else
		{
			return -1;
		}
		
	}
	void Delete_By_Index(int index)
	{
		int i = index;
		while (i < s - 1)
		{
			array[i] = array[i + 1];
			i++;
		}
		this->s -= 1;
	}
	void Append(int value)
	{
		this->s += 1;
		array[s - 1] = value;

	}
	void Reverse()
	{
		int temp = 0;
		int t = s - 1;
		int i = 1;
		while (i < s)
		{
			for (int j = 0; j < t; j++)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			t -= 1;
			i++;
		}
	}
	int Search_By_Value(int value)
	{
		bool flag = false;
		int i = 0;
		while (i < s)
		{
			if (array[i] == value)
			{
				flag = true;
				break;
			}
			i++;
		}
		if (flag == true)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
private:
	int array[50];
	int s;
};