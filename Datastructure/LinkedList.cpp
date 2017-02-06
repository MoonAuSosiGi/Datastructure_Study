#include "LinkedList.h"
#include<stdio.h>


///////////////////////////////////////////////////////////////
//
// SL Append Node 
// Single Linked List Append Node
//
void SL_AppendNode(NodeSL** headNode, NodeSL* newNode)
{
	// head가 null 일 경우 newNode가 head Node 가 된다
	if (*headNode == nullptr)
	{
		*headNode = newNode;
	}
	else
	{
		NodeSL* tailNode = SL_GetTailNode(*headNode);
		tailNode->nextNode = newNode;
	}
}

///////////////////////////////////////////////////////////////
//
// SL_InsertAfter
//
void SL_InsertAfter(NodeSL* current, NodeSL* newNode)
{
	if (current == nullptr)
	{
		printf("Select Node is NULL\n");
		return;
	}

	NodeSL* curNext = current->nextNode;
	current->nextNode = newNode;
	newNode->nextNode = curNext;
}

///////////////////////////////////////////////////////////////
//
// SL_InsertBefore
//
void SL_InsertBefore(NodeSL* head,NodeSL* current, NodeSL* newNode)
{
	if (current == nullptr)
	{
		printf("Select Node is NULL\n");
		return;
	}

	if (head == current)
	{
		SL_InsertAfter(head, newNode);
		return;
	}
	NodeSL* cur = head;

	while (cur->nextNode != current)
	{
		cur = cur->nextNode;
	}
	
	cur->nextNode = newNode;
	newNode->nextNode = current;
	
}

///////////////////////////////////////////////////////////////
//
// SL_CreateNode
// Node 생성
//
NodeSL* SL_CreateNode(int newData)
{
	NodeSL* node = new NodeSL();
	node->data = newData;

	return node;
}

///////////////////////////////////////////////////////////////
//
// SL_GetNodeAt (index 참조)
// 순차적으로 쫙 돌기 때문에 비효율적
//
NodeSL* SL_GetNodeAt(NodeSL* head, int index)
{
	NodeSL* curNode = head;
	int cnt = 0;

	if (index == 0)
		return curNode;

	while (cnt != index && curNode != nullptr)
	{
		cnt++;
		curNode = curNode->nextNode;
	}
	return curNode;
}

///////////////////////////////////////////////////////////////
//
// SL_GetTailNode
// head 를 던져주면 그곳의 가장 끝 노드를 반환
//
NodeSL* SL_GetTailNode(NodeSL* head)
{

	NodeSL* curNode = head;

	while (curNode->nextNode != nullptr)
		curNode = curNode->nextNode;

	return curNode;
}

///////////////////////////////////////////////////////////////
//
// SL_AllPrint
//
void SL_AllPrint(NodeSL* head)
{
	NodeSL* curNode = head;
	int index = 0;
	printf("SL_AllPrint -------------------\n");
	while (curNode != nullptr)
	{
		index++;
		printf(" [ %d ] --> ", curNode->data);
		if (index % 5 == 0)
			printf("\n");
		curNode = curNode->nextNode;
	}
}

///////////////////////////////////////////////////////////////
//
// SL_RemoveAll
//
void SL_RemoveAll(NodeSL** head)
{
	NodeSL* curNode = *head;
	NodeSL* tempNode = nullptr;

	while (curNode != nullptr)
	{
		tempNode = curNode;
		curNode = curNode->nextNode;

		delete tempNode;
	}
	*head = nullptr;
}
///////////////////////////////////////////////////////////////
//
// SL_RemoveAt
//
void SL_RemoveAt(NodeSL** head,int index)
{
	// index 가 0일 경우 head 를 지워야 한다.
	if (index == 0)
	{
		NodeSL* temp = *head;
		*head = ((*head)->nextNode);		
		delete temp;
		
		return;
	}
	
	NodeSL* curNode = *head;
	NodeSL* prevNode;
	int cnt = 0;

	while (curNode->nextNode != nullptr)
	{
		cnt++;
		prevNode = curNode;
		curNode = curNode->nextNode;

		if (cnt == index)
		{
			prevNode->nextNode = curNode->nextNode;
			delete curNode;	
			return;
		}
		
	}
}

///////////////////////////////////////////////////////////////
//
// SL_GetSize
//
int SL_GetSize(NodeSL* head)
{
	NodeSL* curNode = head;

	int cnt = 0;

	while (curNode != nullptr)
	{
		curNode = curNode->nextNode;
		cnt++;
	}

	return cnt;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//
// DL_AppendNode 
// Double Linked List Append Node
//
void DL_AppendNode(NodeDL** headNode, NodeDL* newNode)
{
	if (*headNode == nullptr)
	{
		*headNode = newNode;
	}
	else
	{
		NodeDL* tail = DL_GetTailNode(*headNode);
		tail->nextNode = newNode;
		newNode->prevNode = tail;
	}
}

///////////////////////////////////////////////////////////////
//
// DL_InsertAfter
//
void DL_InsertAfter(NodeDL* current, NodeDL* newNode)
{
	if (current == nullptr)
	{
		printf("Select Node is NULL\n");
		return;
	}
	// current <-> newNode <-> curNext
	NodeDL* curNext = current->nextNode;

	current->nextNode = newNode; // current -> newNode
	newNode->prevNode = current; // current <- newNode
	newNode->nextNode = curNext; // newNode -> curNext
	curNext->prevNode = newNode; // newNode <- curNext
}

///////////////////////////////////////////////////////////////
//
// DL_InsertBefore
//
void DL_InsertBefore(NodeDL* current, NodeDL* newNode)
{
	if (current == nullptr)
	{
		printf("Select Node is NULL\n");
		return;
	}
	// curPrev <-> newNode <-> current
	NodeDL* curPrev = current->prevNode;

	current->prevNode = newNode; // newNode <- current
	newNode->nextNode = current; // newNode -> current
	newNode->prevNode = curPrev; // curPrev <- newNode
	curPrev->nextNode = newNode; // curPrev -> newNode
}

////////////////////////////////////////////////////////////////
//
// DL_CreateNode
//
NodeDL* DL_CreateNode(int newData)
{
	NodeDL* newNode = new NodeDL();
	newNode->data = newData;
	newNode->prevNode = nullptr;
	newNode->nextNode = nullptr;
	
	return newNode;
}

////////////////////////////////////////////////////////////////
//
// DL_GetNodeAt 
//
NodeDL* DL_GetNodeAt(NodeDL* head, int index)
{
	if (index < 0)
		return nullptr;
	int cnt = 0;
	NodeDL* curNode = head;

	while (cnt != index && curNode != nullptr)
	{
		curNode = curNode->nextNode;
		cnt++;
	}

	return curNode;
}

////////////////////////////////////////////////////////////////
//
// DL_GetTailnode
//
NodeDL* DL_GetTailNode(NodeDL* head)
{
	NodeDL* curNode = head;

	while (curNode->nextNode != nullptr)
		curNode = curNode->nextNode;

	return curNode;
}

////////////////////////////////////////////////////////////////
//
// DL_AllPrint
//
void DL_AllPrint(NodeDL* head)
{
	NodeDL* curNode = head;
	int cnt = 0;

	printf("DL_AllPrint----------------------------------\n");

	while (curNode->nextNode != nullptr)
	{
		cnt++;
		printf("<-- [ %d ] -->", curNode->data);

		if (cnt % 5 == 0)
			printf("\n");
		curNode = curNode->nextNode;
	}
}

////////////////////////////////////////////////////////////////
//
// DL_RemoveAll
//
void DL_RemoveAll(NodeDL** head)
{
	NodeDL* curNode = *head;
	NodeDL* temp = nullptr;

	while (curNode != nullptr)
	{
		temp = curNode;
		curNode = curNode->nextNode;

		delete temp;
	}
	*head = nullptr;
}

////////////////////////////////////////////////////////////////
// 
// DL_RemoveAt 
//
void DL_RemoveAt(NodeDL** head, int index)
{
	// index 가 0이면 head
	if (index == 0)
	{
		NodeDL* temp = *head;
		*head = (*head)->nextNode;
		delete temp;
		return;
	}
	
	NodeDL* curNode = *head;
	NodeDL* prevNode = nullptr;
	int cnt = 0;

	while (curNode->nextNode != nullptr)
	{
		cnt++;
		prevNode = curNode;
		curNode = curNode->nextNode;

		if (cnt == index)
		{
			prevNode->nextNode = curNode->nextNode;
			(curNode->nextNode)->prevNode = prevNode;

			delete curNode;
			return;
		}

	}

}

///////////////////////////////////////////////////////////////
//
// DL_GetSize
//
int DL_GetSize(NodeDL* head)
{
	NodeDL* curNode = head;

	int cnt = 0;

	while (curNode != nullptr)
	{
		curNode = curNode->nextNode;
		cnt++;
	}
	return cnt;
}