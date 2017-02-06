#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

// input var.
int mainmenuInput = 0;
int menuInput = 0;
bool isSL = false;


NodeSL* slhead = nullptr; // nullptr keyword < C++ 11 >
NodeDL* dlhead = nullptr; // nullptr keyword < C++ 11 >

/////////////////////////////////////////
// Main Menu ////////////////////////////
void MainMenuLoop();
void ShowMainMenu();

////////////////////////////////////////
// Linked List Menu ////////////////////
void Process();
void ShowMenu();
void MenuSelect();
void MenuInputData();
void MenuInsertIndexMenu(int select);
void MenuGetNodeAt();
void MenuAllPrint();
void MenuRemoveAll();
void MenuRemoveAt();
void MenuGetSize();


////////////////////////////////////////
// Main ////////////////////////////////
int main()
{
	MainMenuLoop();
	return 0;
}
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// Main Menu //////////////////////////////////////////////////
void MainMenuLoop()
{
	while (mainmenuInput != -1)
	{
		ShowMainMenu();

		switch (mainmenuInput)
		{
		case 1: isSL = true; break;
		case 2: isSL = false; break;
		case 3: return;
		}
		menuInput = 0;
		Process();
	}
}

void ShowMainMenu()
{
	printf("DataStructure Console ----------------------------- Linked List\n");
	printf("1. Single Linked List 2. Double Linked List 3. exit\n");
	printf("input : ");
	scanf_s("%d", &mainmenuInput);
	system("cls");
}

///////////////////////////////////////////////////////////////
//
// ProcessSL
//
void Process()
{
	while (menuInput != -1)
	{
		ShowMenu();
		MenuSelect();
	}
}


///////////////////////////////////////////////////////////////
//
// Single Linked List Menu
//
void ShowMenu()
{
	printf("Datastructure Console ---------------------------------------\n");
	printf("1. Input Data 2. GetNodeAt 3. AllPrint 4. RemoveAt 5. RemoveAll 6. GetSize 7. exit\n");
	printf("input : ");
}

///////////////////////////////////////////////////////////////
//
// MenuSelectSL
//
void MenuSelect()
{
	scanf_s("%d", &menuInput);

	switch (menuInput)
	{
	case 1:	MenuInputData();					break;
	case 2: MenuGetNodeAt();					break;
	case 3: MenuAllPrint();						break;
	case 4:	MenuRemoveAt();						break;
	case 5: MenuRemoveAll();					break;
	case 6: MenuGetSize();						break;
	case 7: MenuRemoveAll(); menuInput = -1;	break;
	default: system("cls");						break;
	}
}

///////////////////////////////////////////////////////////////
//
// MenuInputDataSL
//
void MenuInputData()
{
	printf("Input Data ---------------------------------------\n");
	printf("1. Append Node 2. Insert Before 3. Insert After (그 외의 입력은 나가기)\n");

	int input = 0;
	printf("input : ");
	scanf_s("%d", &input);


	if (input < 0 || input >= 4)
		return;

	
	
	MenuInsertIndexMenu(input);

	system("cls");
}

void MenuInsertIndexMenu(int select)
{
	int size = (isSL) ? SL_GetSize(slhead) : DL_GetSize(dlhead);
	int index = 0;
	int inputData = 0;
	

	if (select != 1)
	{
		if (isSL)
			SL_AllPrint(slhead);
		else
			DL_AllPrint(dlhead);
		printf("\n몇번째 노드에 삽입하시겠습니까?  현재 0번부터 ~ %d번까지 있습니다.  ", size-1);
		scanf_s("%d", &index);

	}
	printf("Input Data : ");
	scanf_s("%d", &inputData);

	if (isSL)
	{
		NodeSL*  newNode = SL_CreateNode(inputData);
		switch (select)
		{
		case 1: SL_AppendNode(&slhead, newNode); break;
		case 2: SL_InsertBefore(slhead, SL_GetNodeAt(slhead,index), newNode); break;
		case 3: SL_InsertAfter(SL_GetNodeAt(slhead, index), newNode); break;
		}
		SL_AllPrint(slhead);
	}
	else
	{
		NodeDL* newNode = DL_CreateNode(inputData);
		switch (select)
		{
		case 1: DL_AppendNode(&dlhead, newNode); break;
		case 2: DL_InsertBefore(DL_GetNodeAt(dlhead,index), newNode); break;
		case 3: DL_InsertAfter(DL_GetNodeAt(dlhead, index), newNode); break;
		}
		DL_AllPrint(dlhead);
	}
	printf("\n");
	getchar();
	getchar();
}

///////////////////////////////////////////////////////////////
//
// MenuGetNodeAtSL
//
void MenuGetNodeAt()
{
	while (true)
	{
		int input = 0;
		printf("Input index (나가려면 0보다 작은 수를 입력) ---> ");
		scanf_s("%d", &input);
		if (input >= 0)
		{
			if (isSL)
			{
				NodeSL* node = SL_GetNodeAt(slhead, input);

				if (node != nullptr)
					printf("Node[%d] = %d \n", input, node->data);
				else
					printf("%d 번째 Node는 존재하지 않습니다.\n", input);
			}
			else
			{
				NodeDL* node = DL_GetNodeAt(dlhead, input);

				if (node != nullptr)
					printf("Node[%d] = %d \n", input, node->data);
				else
					printf("%d 번째 Node는 존재하지 않습니다.\n", input);
			}
			
		}
		else
			break;
	}
	system("cls");

}

///////////////////////////////////////////////////////////////
//
// MenuAllPrintSL
//
void MenuAllPrint()
{
	if (isSL)
		SL_AllPrint(slhead);
	else
		DL_AllPrint(dlhead);
	printf("\nEnd----------------------------------------\n");
	getchar();
	getchar();
	system("cls");
}

///////////////////////////////////////////////////////////////
//
// MenuRemoveAll
//
void MenuRemoveAll()
{
	if (isSL)
		SL_RemoveAll(&slhead);
	else
		DL_RemoveAll(&dlhead);
	printf("Remove All Completed\n");
	getchar();
	getchar();
	system("cls");
}

///////////////////////////////////////////////////////////////
//
// MenuRemoveAt
//
void MenuRemoveAt()
{
	int input = 0;
	printf("RemoveAt (0보다 작으면 취소) : ");
	scanf_s("%d", &input);

	if (input >= 0)
	{
		if (isSL)
			SL_RemoveAt(&slhead, input);
		else
			DL_RemoveAt(&dlhead, input);
		system("cls");
	}
}

///////////////////////////////////////////////////////////////
//
// MenuGetSize
//
void MenuGetSize()
{
	int size = 0;

	if (isSL)
		size = SL_GetSize(slhead);
	else
		size = DL_GetSize(dlhead);

	printf("Size : %d\n", size);
	getchar();
	getchar();
	system("cls");
}