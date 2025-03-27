#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList(const std::string& valueInitiallyAtHeadOfList)
{
	SinglyLinkedList::pHead = new RawPointerNode;

	SinglyLinkedList::pHead->data = valueInitiallyAtHeadOfList;

}

void SinglyLinkedList::insertAtFront(const std::string& valueToInsertAtFront)
{
	RawPointerNode* pNewNode = new RawPointerNode;
	pNewNode->data = valueToInsertAtFront;

	pNewNode->pNext = pHead;
	pHead = pNewNode;
}

void SinglyLinkedList::printList()
{
	RawPointerNode* pCurrent = pHead;

	while (pCurrent != nullptr) //this is "node-based" iteration 
	{
		//"visit" (print the contents of) the current node : 
		std::cout << pCurrent->data << "\n";

		pCurrent = pCurrent->pNext;
	}

}
void SinglyLinkedList::merge(const SinglyLinkedList& otherList)
{
	

	auto tempHead = this->pHead;

	while (tempHead->pNext != nullptr)
	{
		tempHead = tempHead->pNext;
	}

	tempHead->pNext = otherList.pHead;
}



void SinglyLinkedList::clear()
{
	/*similar to printList*/
	RawPointerNode* pCurrent = pHead;

	/*A WRONG way: */
	//while (pCurrent != nullptr) 
	//{
	//	//DE-allocate memory address of current node : 
	//	pCurrent = pCurrent->pNext;

	//	delete pCurrent; //NO! ->this will only delete one node
	//}

	//a fairly good way: 
	//while (pCurrent != nullptr)
	//{
	//	RawPointerNode* temp = pCurrent; 
	//	//step "forward"
	//	pCurrent = pCurrent->pNext; 
	//	//delete the previous
	//	delete temp;
	//}

	//the best? way? 
	while (pHead != nullptr)
	{
		RawPointerNode* temp = pHead;
		pHead = pHead->pNext;

		delete temp;
	}
}

RawPointerNode* SinglyLinkedList::find(const std::string& valueToFind)
{

	RawPointerNode* pCurrent = pHead;

	while (pCurrent->data != valueToFind)
	{
		pCurrent = pCurrent->pNext;
	}

	return pCurrent; //this is similar to returning -1 from binary search or sequential search 
}

void SinglyLinkedList::insertAfter(RawPointerNode* pPreviousNode, const std::string& valueToInsertAfterGivenNode)
{
	RawPointerNode* pNewNode = new RawPointerNode;
	pNewNode->data = valueToInsertAfterGivenNode;

	pNewNode->pNext = pPreviousNode->pNext;
	pPreviousNode->pNext = pNewNode;
}



SinglyLinkedList::~SinglyLinkedList()
{
	clear(); 
}




