#include <algorithm>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "StandardVector.h"
#include "StandardList.h"
#include "StandardMap.h"
#include "DIYVector.h"
#include "DIYList.h"
#include "DIYMap.h"


int main(int argc, char* argv[])
{
	sPerfData performance;
	
	StandardVector* stlvecperson = new StandardVector();
	StandardList* stllistperson = new StandardList();
	StandardMap* stlmap = new StandardMap();

	DIYVector* diyvecperson = new DIYVector();
	DIYList* diylist = new DIYList();
	DIYMAP* diymap = new DIYMAP();

	std::vector<sPerson> output;




//
/////////////////////************STL-VECTOR**********//////////////////
//
	//stlvecperson->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	//stlvecperson->GetPerformanceFromLastCall(performance);
	//std::cout << "                                            Assignment ------ 1 : STL-VECTOR " << std::endl;
	//std::cout << "******************************************* Load Data Successfully *******************************************\n" << std::endl;
	//

	//// GENERATE RANDOM PEOPLE
	//stlvecperson->GenerateRandomPeople(1000);
	//stlvecperson->GetPerformanceFromLastCall(performance);
	//
	////FIND ONLY ONE PERSON
	//sPerson OnePeople;
	//OnePeople.first = "";
	//OnePeople.last = "VOTTA";

	//std::cout << "\nRESULT FOR FIND ONLY ONE PERSON:" << std::endl;
	//stlvecperson->FindPeopleByName(output, OnePeople, 5);
	//stlvecperson->GetPerformanceFromLastCall(performance);

	////FIND MULTIPLE PEOPLE
	//std::vector<sPerson> vecPeopleToFind;
	//sPerson x1,x2,x3,x4;

	//x1.first = "";
	//x1.last = "ADLEY";
	//vecPeopleToFind.push_back(x1);

	//x2.first = "";
	//x2.last = "BURDICK";
	//vecPeopleToFind.push_back(x2);

	//x3.first = "RHEE";
	//x3.last = "";
	//vecPeopleToFind.push_back(x3);

	//x4.first = "ART";
	//x4.last = "";
	//vecPeopleToFind.push_back(x4);
	//
	//std::cout << "\nRESULT FOR FIND MULTIPLE PEOPLE: " << std::endl;
	//stlvecperson->FindPeopleByName(output, vecPeopleToFind, 10);
	//stlvecperson->GetPerformanceFromLastCall(performance);
	//
	////FIND PERSON BY ID
	//sPerson myperson;
	//std::cout << "\nRESULT FOR FIND PERSON BY ID: " << std::endl;
	//stlvecperson->FindPersonByID(myperson, 301);
	//stlvecperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION AND RADIUS
	//sPoint s1;
	//s1.x = 33.0f;
	//s1.y = 34.0f;
	//s1.z = 185.0f;
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION AND RADIUS: " << std::endl;
	//stlvecperson->FindPeople(output, s1, 5000.0f, 30);
	//stlvecperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY HEALTH RANGE: " << std::endl;
	//stlvecperson->FindPeople(output, 15.0f, 50.0f, 10);
	//stlvecperson->GetPerformanceFromLastCall(performance);
	//
	////FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE:" << std::endl;
	//stlvecperson->FindPeople(output, s1, 40.0f, 10.0f, 90.0f, 10);
	//stlvecperson->GetPerformanceFromLastCall(performance);
	//
	////SORTING PEOPLE
	//std::cout << "\nRESULT FOR SORTING PEOPLE:" << std::endl;
	//stlvecperson->SortPeople(output, stlvecperson->ASC_BY_ID);
	//stlvecperson->GetPerformanceFromLastCall(performance);
	//
	//stlvecperson->getContainerType();
	//stlvecperson->GetPerformanceFromLastCall(performance);




















//
/////////////////////************STL-LIST**********//////////////////
//
	//stllistperson->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	//stllistperson->GetPerformanceFromLastCall(performance);
	//
	//std::cout << "                                            Assignment ------ 1 : STL-LIST " << std::endl;
	//std::cout << "******************************************* Load Data Successfully *******************************************\n" << std::endl;

	//stllistperson->GenerateRandomPeople(1000);
	//stllistperson->GetPerformanceFromLastCall(performance);

	////FIND ONLY ONE PERSON
	//sPerson OnePeople;
	//OnePeople.first = "AMANDA";
	//OnePeople.last = "TAPIA";
	//
	//std::cout << "\nRESULT FOR FIND ONLY ONE PERSON:" << std::endl;
	//stllistperson->FindPeopleByName(output, OnePeople, 5);
	//stllistperson->GetPerformanceFromLastCall(performance);

	////FIND MULTIPLE PEOPLE
	//std::vector<sPerson> vecPeopleToFind;
	//sPerson x1, x2, x3, x4;

	//x1.first = "NITA";
	//x1.last = "";
	//vecPeopleToFind.push_back(x1);

	//x2.first = "";
	//x2.last = "MOTT";
	//vecPeopleToFind.push_back(x2);

	//x3.first = "DAISY";
	//x3.last = "SNEED";
	//vecPeopleToFind.push_back(x3);

	//x4.first = "";
	//x4.last = "GEE";
	//vecPeopleToFind.push_back(x4);

	//std::cout << "\nRESULT FOR FIND MULTIPLE PEOPLE: " << std::endl;
	//stllistperson->FindPeopleByName(output, vecPeopleToFind, 3);
	//stllistperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY ID
	//sPerson myperson;
	//std::cout << "\nRESULT FOR FIND PERSON BY ID: " << std::endl;
	//stllistperson->FindPersonByID(myperson, 301);
	//stllistperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION AND RADIUS
	//sPoint s1;
	//s1.x = 33.0f;
	//s1.y = 34.0f;
	//s1.z = 185.0f;
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION AND RADIUS: " << std::endl;
	//stllistperson->FindPeople(output, s1, 5000.0f, 30);
	//stllistperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY HEALTH RANGE: " << std::endl;
	//stllistperson->FindPeople(output, 15.0f, 50.0f, 10);
	//stllistperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE:" << std::endl;
	//stllistperson->FindPeople(output, s1, 500.0f, 10.0f, 90.0f, 5);
	//stllistperson->GetPerformanceFromLastCall(performance);

	////SORTING PEOPLE
	//std::cout << "\nRESULT FOR SORTING PEOPLE:" << std::endl;
	//stllistperson->SortPeople(output, stllistperson->DESC_FIRST_THEN_LAST);
	//stllistperson->GetPerformanceFromLastCall(performance);

	//stllistperson->getContainerType();
	//stllistperson->GetPerformanceFromLastCall(performance);















//
///////////////////************STL-MAP**********//////////////////
//
	//stlmap->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	//stlmap->GetPerformanceFromLastCall(performance);

	//std::cout << "                                            Assignment ------ 1 : STL-MAP " << std::endl;
	//std::cout << "******************************************* Load Data Successfully *******************************************\n" << std::endl;

	//// GENERATE RANDOM PEOPLE
	//stlmap->GenerateRandomPeople(1000);
	//stlmap->GetPerformanceFromLastCall(performance);

	////FIND ONLY ONE PERSON
	//sPerson OnePeople;
	//OnePeople.first = "BOB";
	//OnePeople.last = "";

	//std::cout << "\nRESULT FOR FIND ONLY ONE PERSON:\n" << std::endl;
	//stlmap->FindPeopleByName(output, OnePeople, 5);
	//stlmap->GetPerformanceFromLastCall(performance);

	////FIND MULTIPLE PEOPLE
	//std::vector<sPerson> vecPeopleToFind;
	//sPerson x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;

	//x1.first = "";
	//x1.last = "LEAL";
	//vecPeopleToFind.push_back(x1);

	//x2.first = "";
	//x2.last = "ROMO";
	//vecPeopleToFind.push_back(x2);

	//x3.first = "";
	//x3.last = "GEE";
	//vecPeopleToFind.push_back(x3);

	//x4.first = "";
	//x4.last = "BAEZ";
	//vecPeopleToFind.push_back(x4);

	//x5.first = "MONTY";
	//x5.last = "";
	//vecPeopleToFind.push_back(x5);

	//x6.first = "JEFF";
	//x6.last = "";
	//vecPeopleToFind.push_back(x6);

	//x7.first = "";
	//x7.last = "DILL";
	//vecPeopleToFind.push_back(x7);

	//x8.first = "TONY";
	//x8.last = "";
	//vecPeopleToFind.push_back(x8);

	//x9.first = "STAN";
	//x9.last = "";
	//vecPeopleToFind.push_back(x9);

	//x10.first = "CHANCE";
	//x10.last = "";
	//vecPeopleToFind.push_back(x10);

	//x11.first = "";
	//x11.last = "LENTZ";
	//vecPeopleToFind.push_back(x11);

	//x12.first = "VICTOR";
	//x12.last = "";
	//vecPeopleToFind.push_back(x12);

	//std::cout << "\nRESULT FOR FIND MULTIPLE PEOPLE:\n " << std::endl;
	//stlmap->FindPeopleByName(output, vecPeopleToFind, 12);
	//stlmap->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY ID
	//sPerson myperson;
	//std::cout << "\nRESULT FOR FIND PERSON BY ID:\n " << std::endl;
	//stlmap->FindPersonByID(myperson, 8);
	//stlmap->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION AND RADIUS
	//sPoint s1;
	//s1.x = 33.0f;
	//s1.y = 34.0f;
	//s1.z = 185.0f;
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION AND RADIUS:\n " << std::endl;
	//stlmap->FindPeople(output, s1, 5000.0f, 5);
	//stlmap->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY HEALTH RANGE:\n " << std::endl;
	//stlmap->FindPeople(output, 15.0f, 50.0f, 20);
	//stlmap->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE:\n" << std::endl;
	//stlmap->FindPeople(output, s1, 4000.0f, 10.0f, 50.0f, 10);
	//stlmap->GetPerformanceFromLastCall(performance);

	////SORTING PEOPLE
	//std::cout << "\nRESULT FOR SORTING PEOPLE:" << std::endl;
	//stlmap->SortPeople(output, stlmap->DESC_FIRST_THEN_LAST);
	//stlmap->GetPerformanceFromLastCall(performance);

	//stlmap->getContainerType();
	//stlmap->GetPerformanceFromLastCall(performance);













//
///////////////////************DIY-VECTOR**********//////////////////
//
	//diyvecperson->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	//diyvecperson->GetPerformanceFromLastCall(performance);

	//std::cout << "                                            Assignment ------ 1 : DIY-VECTOR " << std::endl;
	//std::cout << "******************************************* Load Data Successfully *******************************************\n" << std::endl;

	//// GENERATE RANDOM PEOPLE
	//diyvecperson->GenerateRandomPeople(1000);
	//diyvecperson->GetPerformanceFromLastCall(performance);

	////FIND ONLY ONE PERSON
	//sPerson OnePeople;
	//OnePeople.first = "ROYAL";
	//OnePeople.last = "";

	//std::cout << "\nRESULT FOR FIND ONLY ONE PERSON:" << std::endl;
	//diyvecperson->FindPeopleByName(output, OnePeople, 5);
	//diyvecperson->GetPerformanceFromLastCall(performance);

	////FIND MULTIPLE PEOPLE
	//std::vector<sPerson> vecPeopleToFind;
	//sPerson x1, x2, x3, x4;

	//x1.first = "ELVA";
	//x1.last = "";
	//vecPeopleToFind.push_back(x1);

	//x2.first = "";
	//x2.last = "VOTTA";
	//vecPeopleToFind.push_back(x2);

	//x3.first = "ROYAL";
	//x3.last = "";
	//vecPeopleToFind.push_back(x3);

	//x4.first = "";
	//x4.last = "EATMON";
	//vecPeopleToFind.push_back(x4);

	//std::cout << "\nRESULT FOR FIND MULTIPLE PEOPLE: " << std::endl;
	//diyvecperson->FindPeopleByName(output, vecPeopleToFind, 3);
	//diyvecperson->GetPerformanceFromLastCall(performance);
	//

	////FIND PERSON BY ID
	//sPerson myperson;
	//std::cout << "\nRESULT FOR FIND PERSON BY ID: " << std::endl;
	//diyvecperson->FindPersonByID(myperson, 6);
	//diyvecperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION AND RADIUS
	//sPoint s1;
	//s1.x = 33.0f;
	//s1.y = 34.0f;
	//s1.z = 185.0f;
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION AND RADIUS: " << std::endl;
	//diyvecperson->FindPeople(output, s1, 5000.0f, 5);
	//diyvecperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY HEALTH RANGE: " << std::endl;
	//diyvecperson->FindPeople(output, 1.0, 8.0f, 3.0f);
	//diyvecperson->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE:" << std::endl;
	//diyvecperson->FindPeople(output, s1, 4000.0f, 1.0f, 100.0f, 20);
	//diyvecperson->GetPerformanceFromLastCall(performance);

	////SORTING PEOPLE
	//std::cout << "\nRESULT FOR SORTING PEOPLE:" << std::endl;
	//diyvecperson->SortPeople(output, diyvecperson->DESC_BY_ID);
	//diyvecperson->GetPerformanceFromLastCall(performance);

	//diyvecperson->getContainerType();
	//diyvecperson->GetPerformanceFromLastCall(performance);










//
///////////////////************DIY-LIST**********//////////////////
//
	//std::vector<sPerson> people;
	//std::vector<sPerson> peopletofind;
	//diylist->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	//diylist->GetPerformanceFromLastCall(performance);

	//std::cout << "                                            Assignment ------ 1 : DIY-LIST " << std::endl;
	//std::cout << "******************************************* Load Data Successfully *******************************************\n" << std::endl;

	//	
	//diylist->GenerateRandomPeople(1000);
	//diylist->GetPerformanceFromLastCall(performance);

	////FIND ONLY ONE PERSON
	//sPerson OnePeople;
	//OnePeople.first = "SONNY";
	//OnePeople.last = "";

	//std::cout << "\nRESULT FOR FIND ONLY ONE PERSON:" << std::endl;
	//diylist->FindPeopleByName(output, OnePeople, 5);
	//diylist->GetPerformanceFromLastCall(performance);

	////FIND MULTIPLE PEOPLE
	//sPerson x1, x2, x3, x4;
	//x1.first = "SONNY";
	//x1.last = "";
	//peopletofind.push_back(x1);

	//x2.first = "";
	//x2.last = "BONA";
	//peopletofind.push_back(x2);

	//x3.first = "DAISY";
	//x3.last = "SNEED";
	//peopletofind.push_back(x3);

	//x4.first = "";
	//x4.last = "CHIU";
	//peopletofind.push_back(x4);

	//std::cout << "\nRESULT FOR FIND MULTIPLE PEOPLE: " << std::endl;
	//diylist->FindPeopleByName(output, peopletofind, 4);
	//diylist->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY ID
	//sPerson myperson;
	//std::cout << "\nRESULT FOR FIND PERSON BY ID: " << std::endl;
	//diylist->FindPersonByID(myperson, 10);
	//diylist->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION AND RADIUS
	//sPerson s1;
	//s1.location.x = 23.0f;
	//s1.location.y = 24.0f;
	//s1.location.z = 25.0f;

	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION AND RADIUS: " << std::endl;
	//diylist->FindPeople(output, s1.location, 5000.0f, 10);
	//diylist->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY HEALTH RANGE: " << std::endl;
	//diylist->FindPeople(output, 15.0f, 50.0f, 5);
	//diylist->GetPerformanceFromLastCall(performance);

	////FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE
	//std::cout << "\nRESULT FOR FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE:" << std::endl;
	//diylist->FindPeople(output, s1.location, 5000.f, 10.0f, 90.0f, 5);
	//diylist->GetPerformanceFromLastCall(performance);

	////SORTING PEOPLE
	//std::cout << "\nRESULT FOR SORTING PEOPLE:" << std::endl;
	//diylist->SortPeople(output, diylist->ASC_BY_ID);
	//diylist->GetPerformanceFromLastCall(performance);

	//diylist->getContainerType();
	//diylist->GetPerformanceFromLastCall(performance);








/////////////////************DIY-MAP**********//////////////////
//
	diymap->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	diymap->GetPerformanceFromLastCall(performance);

	std::cout << "                                            Assignment ------ 1 : DIY-MAP " << std::endl;
	std::cout << "******************************************* Load Data Successfully *************************************************\n" << std::endl;

	// GENERATE RANDOM PEOPLE
	diymap->GenerateRandomPeople(1000);
	diymap->GetPerformanceFromLastCall(performance);

	//FIND ONLY ONE PERSON
	sPerson OnePeople;
	OnePeople.first = "NINFA";
	OnePeople.last = "";

	std::cout << "\nRESULT FOR FIND ONLY ONE PERSON:\n" << std::endl;
//	diymap->FindPeopleByName(diymap->vecPeople, OnePeople, 5);
	diymap->GetPerformanceFromLastCall(performance);

	//FIND MULTIPLE PEOPLE
	std::vector<sPerson> vecPeopleToFind;
	sPerson x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;

	x1.first = "";
	x1.last = "VAL";
	vecPeopleToFind.push_back(x1);

	x2.first = "";
	x2.last = "BONA";
	vecPeopleToFind.push_back(x2);

	x3.first = "";
	x3.last = "CHIU";
	vecPeopleToFind.push_back(x3);

	x4.first = "";
	x4.last = "BAEZ";
	vecPeopleToFind.push_back(x4);

	x5.first = "NINFA";
	x5.last = "";
	vecPeopleToFind.push_back(x5);

	x6.first = "CRAIG";
	x6.last = "";
	vecPeopleToFind.push_back(x6);

	x7.first = "";
	x7.last = "GRANT";
	vecPeopleToFind.push_back(x7);

	x8.first = "TONY";
	x8.last = "";
	vecPeopleToFind.push_back(x8);

	x9.first = "STAN";
	x9.last = "";
	vecPeopleToFind.push_back(x9);

	x10.first = "CHANCE";
	x10.last = "";
	vecPeopleToFind.push_back(x10);

	x11.first = "";
	x11.last = "LENTZ";
	vecPeopleToFind.push_back(x11);

	x12.first = "VICTOR";
	x12.last = "";
	vecPeopleToFind.push_back(x12);

	std::cout << "\nRESULT FOR FIND MULTIPLE PEOPLE:\n " << std::endl;
	diymap->FindPeopleByName(output, vecPeopleToFind, 10);
	diymap->GetPerformanceFromLastCall(performance);


	//FIND PERSON BY IDs
	sPerson myperson;
	std::cout << "\nRESULT FOR FIND PERSON BY ID:\n " << std::endl;
	diymap->FindPersonByID(myperson, 8);
	diymap->GetPerformanceFromLastCall(performance);

	//FIND PERSON BY LOCATION AND RADIUS
	sPoint s1;
	s1.x = 33.0f;
	s1.y = 34.0f;
	s1.z = 185.0f;
	std::cout << "\nRESULT FOR FIND PERSON BY LOCATION AND RADIUS:\n " << std::endl;
	diymap->FindPeople(output, s1, 5000.0f, 5);
	diymap->GetPerformanceFromLastCall(performance);

	//FIND PERSON BY HEALTH RANGE
	std::cout << "\nRESULT FOR FIND PERSON BY HEALTH RANGE:\n " << std::endl;
	diymap->FindPeople(output, 15.0f, 50.0f, 20);
	diymap->GetPerformanceFromLastCall(performance);

	//FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE
	std::cout << "\nRESULT FOR FIND PERSON BY LOCATION,RADIUS AND HEALTH RANGE:\n" << std::endl;
	diymap->FindPeople(output, s1, 4000.0f, 10.0f, 50.0f, 10);
	diymap->GetPerformanceFromLastCall(performance);

	//SORTING PEOPLE
	std::cout << "\nRESULT FOR SORTING PEOPLE:" << std::endl;
	diymap->SortPeople(output, diymap->ASC_BY_HEALTH);
	diymap->GetPerformanceFromLastCall(performance);

	diymap->getContainerType();
	diymap->GetPerformanceFromLastCall(performance);




	Sleep(1000000);
	return 0;
}

