#pragma once
#include "cPerson.h"
#include <string>
#include <iostream>
#include <malloc.h>

template<typename T>
class DiyList
{


public:

	struct diylist
	{
		diylist *next;
		T myperson;
	};


	diylist* head = 0;
	diylist* slider;


	

	void push_back(T addperson)
	{

		if (head == NULL)
		{
			head = new diylist();
			head->myperson = addperson;
			head->next = NULL;
		}
		else
		{
			slider = head;
			while (slider->next != 0)
			{
				slider = slider->next;
			}
			slider->next = new diylist();
			slider = slider->next;
			slider->myperson = addperson;
			slider->next = NULL;
		}
		//std::cout << headnode->myperson.first;

	}


	diylist* begin(void)
	{
		return this->head;
	}


	diylist* iterator(void)
	{
		return this->slider;
	}


	diylist* end(void)
	{
		slider = head;
		while (slider->next != 0)
		{
			slider = slider->next;
		}
		slider = slider->next;
		return this->slider;
	}

	int size()
	{
		int size = 0;
		slider = head;
		for ( slider = head; slider->next != 0; slider = slider->next)
		
		{
			size++;
		}

		return size;
	}


	void printall(void)
	{
		int i = 0;
		slider = head;
		for (slider = head; slider->next != 0; slider = slider->next)
		{

			std::cout
				<< i + 1 << "  "
				<< "     ( " << slider->myperson.uniqueID << " )    "
				<< slider->myperson.first
				<< "       " << slider->myperson.last
				<< "    Age: "<< slider->myperson.age
				<< "       Health:" << slider->myperson.health
				<< "        Location ( " << slider->myperson.location.x << ", " << slider->myperson.location.y << ", " << slider->myperson.location.z << ")" << std::endl;

			i++;
		}
		std::cout
			<< i + 1 << "  "
			<< "     ( " << slider->myperson.uniqueID << " )    "
			<< slider->myperson.first
			<< "       " << slider->myperson.last
			<< "    Age: " << slider->myperson.age
			<< "       Health:" << slider->myperson.health
			<< "        Location ( " << slider->myperson.location.x << ", " << slider->myperson.location.y << ", " << slider->myperson.location.z << ")" << std::endl;
	}
};