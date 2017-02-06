#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


////////////////////////////////////////////////////////////////
// SL  Single Linked List
typedef struct NODESL
{
	int data;
	NODESL* nextNode;
}NodeSL;

void SL_AppendNode(NodeSL** headNode, NodeSL* newNode);
void SL_InsertAfter(NodeSL* current, NodeSL* newNode);
void SL_InsertBefore(NodeSL* head,NodeSL* current, NodeSL* newNode);
NodeSL* SL_CreateNode(int newData);
NodeSL* SL_GetNodeAt(NodeSL* head, int index);
NodeSL* SL_GetTailNode(NodeSL* head);
void SL_AllPrint(NodeSL* head);
void SL_RemoveAll(NodeSL** head);
void SL_RemoveAt(NodeSL** head,int index);
int SL_GetSize(NodeSL* head);
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// DL Double Linked List
typedef struct NODEDL
{
	int data;
	NODEDL* nextNode;
	NODEDL* prevNode;
}NodeDL;

void DL_AppendNode(NodeDL** headNode, NodeDL* newNode);
void DL_InsertAfter(NodeDL* current, NodeDL* newNode);
void DL_InsertBefore(NodeDL* current, NodeDL* newNode);
NodeDL* DL_CreateNode(int newData);
NodeDL* DL_GetNodeAt(NodeDL* head, int index);
NodeDL* DL_GetTailNode(NodeDL* head);
void DL_AllPrint(NodeDL* head);
void DL_RemoveAll(NodeDL** head);
void DL_RemoveAt(NodeDL** head,int index);
int DL_GetSize(NodeDL* head);

#endif