// ConstantNodeMultiIterationTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Node
{
public:
	int m_value = 0;
	Node* m_next = nullptr;
};

int NodeCount = 100000000;
int JumpCount = NodeCount / 10;
int NodeMultiIterationCount = 10;


Node* m_first;

void ConstantNodeMultiJump(int NodeMultiIterationCount, Node* iter)
{
	assert(0 <= NodeMultiIterationCount);
	assert(NodeMultiIterationCount <= 10);
	switch (NodeMultiIterationCount)
	{
	case 0:
		break;
	case 1: iter = iter->m_next; break;
	case 2: iter = iter->m_next->m_next; break;
	case 3: iter = iter->m_next->m_next->m_next; break;
	case 4: iter = iter->m_next->m_next->m_next->m_next; break;
	case 5: iter = iter->m_next->m_next->m_next->m_next->m_next; break;
	case 6: iter = iter->m_next->m_next->m_next->m_next->m_next->m_next; break;
	case 7: iter = iter->m_next->m_next->m_next->m_next->m_next->m_next->m_next; break;
	case 8: iter = iter->m_next->m_next->m_next->m_next->m_next->m_next->m_next->m_next; break;
	case 9: iter = iter->m_next->m_next->m_next->m_next->m_next->m_next->m_next->m_next->m_next; break;
	case 10: iter = iter->m_next->m_next->m_next->m_next->m_next->m_next->m_next->m_next->m_next->m_next; break;
	}
}

void NodeMultiJump(int NodeMultiIterationCount, Node* iter)
{
	for (int i = 0; i < NodeMultiIterationCount; i++)
		iter = iter->m_next;
}

int main()
{
	// init
	m_first = new Node;
	Node* last = m_first;
	for (int i = 0; i < NodeCount; i++)
	{
		last->m_next = new Node;
		last = last->m_next;
	}

	{
		// dynamic iter
		cout << "Dynamic iteration starts...\n";
		auto time0 = high_resolution_clock::now();

		Node* iter = m_first;
		for (int i = 0; i < JumpCount; i++)
		{
			NodeMultiJump(NodeMultiIterationCount, /*ref*/ iter);
		}
		auto time1 = high_resolution_clock::now();
		cout << "..took " << duration_cast<milliseconds>(time1 - time0).count() << "ms.\n";
	}

	{
		// const iter
		cout << "Constant iteration starts...\n";
		auto time0 = high_resolution_clock::now();

		Node* iter = m_first;
		
		for (int i = 0; i < JumpCount; i++)
		{
			ConstantNodeMultiJump(NodeMultiIterationCount, /*ref*/ iter);
		}

		auto time1 = high_resolution_clock::now();
		cout << "..took " << duration_cast<milliseconds>(time1 - time0).count() << "ms.\n";
	}

    return 0;
}

