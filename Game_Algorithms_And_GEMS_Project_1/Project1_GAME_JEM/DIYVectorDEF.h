#pragma once
#include<stddef.h>
template <class T>
class diyVector
{
public:
	int cap = 50;
	//int incr = 100;
	struct ar
	{
		int emp;
		T value;
		
	};
	ar *arr = new ar[cap];
	bool init = 0;
	
	int size()
	{
		int size=0;
		for (int i = 0; arr[i].emp != 1; i++)
		{
			size++;
		}
		return size;
	}
	
	void push_back(T var)
	{
		if (init == 0)
		{
			for (int i = 0; i < cap; i++)
			{
				arr[i].emp = 1;
				arr[i].value = T{};
			}
			init = 1;
		}
		


		int i;
		for (i = 0; i < cap; i++)
		{
			if (arr[i].emp == 1)
				break;
		}

		if (i == cap - 1)
		{
			ar* temp = new ar[cap + 500];
			for (int i = 0; i < cap; i++)
			{
				temp[i] = arr[i];
			}
			for (int i = cap; i < cap + 500; i++)
			{
				temp[i].emp = 1;
				temp[i].value = T{};
			}
			delete[] arr;
			arr = temp;
			arr[cap-1].value = var;
			arr[cap - 1].emp = 0;
			cap += 100;
			
		}
		else
		{
			arr[i].value = var;
			arr[i].emp = 0;
		}
	}

	void printall(void)
	{
		for (int i = 0; i < cap; i++)
		{
			std::cout << arr[i].value;
		}
	}


};