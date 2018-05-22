#pragma once
#include "cPerson.h"
#include <string>
#include <iostream>
#include <malloc.h>

template<typename T2, typename T>
class DiyMap
{

public:

	struct diymap
	{
		diymap *gt;
		diymap *lt;
		int index;
		T myperson;
	};


	diymap* head=0;
	diymap* slider;
	diymap* nextnode;


	void push_back(int newindex, T addperson)
	{

		if (head == 0)
		{
			head = new diymap();
			head->myperson = addperson;
			head->index = newindex;
			head->lt = NULL;
			head->gt = NULL;
		}
		else
		{
			slider = head;
			int out = 0;
			while ( out!=1 )
			{
				if (newindex > slider->index )
				{
					if (slider->gt == 0)
					{
						out = 1;
					}
					else
					{
						slider = slider->gt;
					}
					
				}

				if(newindex < slider->index)
				{
					if (slider->lt == 0)
					{
						out = 1;
					}
					else
					{
						slider = slider->lt;
					}
				}
			}
			
			if (newindex > slider->index)
			{
				slider->gt = new diymap();
				slider = slider->gt;
				slider->myperson = addperson;
				slider->index = newindex;
				slider->lt = NULL;
				slider->gt = NULL;
			}
			else
			{
				slider->lt = new diymap();
				slider = slider->lt;
				slider->myperson = addperson;
				slider->index = newindex;
				slider->lt = NULL;
				slider->gt = NULL;
			}
			
		}
		//std::cout << headnode->myperson.first;

	}


	diymap* begin(void)
	{
		return this->head;
	}


	diymap* iterator(void)
	{
		return this->slider;
	}


	diymap* find(int findindex)
	{
		slider = head;
		int out = 0;
		while (out!=1)
		{
			if (findindex > slider->index )
			{
				if (slider->gt != 0)
				{
					slider = slider->gt;
				}
			}

			if (findindex < slider->index)
			{
				if (slider->lt != 0)
				{
					slider = slider->lt;
				}
			}

			if (findindex == slider->index)
			{
				return this->slider;
				out = 1;
			}
			
			
		}

	}

	int maxindex()
	{
		int size = 0;
		slider = head;
		while (1)
		{
			
			if (slider->gt == 0)
			{
				break;
			}
			else
			{
				slider = slider->gt;
			}

		}

		return slider->index;
	}

};