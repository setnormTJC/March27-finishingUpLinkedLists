// FInishing up linked lists - March 27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include"SinglyLinkedList.h"
#include <forward_list> //std library's implementation of a SINGLY-linked list

auto getMasksOfCoteDIvoire()
{
	SinglyLinkedList masksOfCoteDIvoire("Mblo"); //beauty and calmness
	masksOfCoteDIvoire.insertAtFront("Deangle"); //initiation and harvest
	masksOfCoteDIvoire.insertAtFront("Wanyugo");//protection 

	//whoops - forgot a mask - insert after Deangle
	auto locationOfDeangle = masksOfCoteDIvoire.find("Deangle");

	masksOfCoteDIvoire.insertAfter(locationOfDeangle, "Goli"); //funerals

	return masksOfCoteDIvoire;

}

auto getOtherMasks()
{
	SinglyLinkedList otherMasks("The one from phantom of the opera");
	otherMasks.insertAtFront("Some mask from Persona 5");

	return otherMasks;
}


int main()
{
	auto masksOfCoteDIvoire = getMasksOfCoteDIvoire();
	std::cout << "Some masks from Cote d'Ivoire\n";
	masksOfCoteDIvoire.printList();


	std::cout << "Some \"other\" masks:\n";
	auto otherMasks = getOtherMasks();
	otherMasks.printList();

	//Merge the two: 
	masksOfCoteDIvoire.merge(otherMasks); 
	masksOfCoteDIvoire.printList();

	//std::forward_list<int> nums; 
	//nums.
}
