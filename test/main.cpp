#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print(SearchTree T, int depth)
{
	if (T != NULL)
	{
		int i = depth;
		printf("|-");
		while (i-- > 0)
			printf("--");
		printf("%d\n", T->element);
		if (T->left != NULL)
			print(T->left, depth + 1);
		if (T->right != NULL)
			print(T->right, depth + 1);
	}
}

//int main(int argc, char * argv[])
//{
//	// create a empty tree
//	SearchTree t = (SearchTree)malloc(sizeof(TreeNode));
//	t->element = 10;
//	t->left = NULL;
//	t->right = NULL;
//	// MakeEmpty(t);
//	SearchTree _t = Find(0, t);
//	SearchTree pos = FindMin(t);
//	Insert(9, t);
//	Insert(6, t);
//	Insert(12, t);
//	Insert(8, t);
//	Insert(4, t);
//	Insert(11, t);
//	print(t, 0);
//
//	printf("================================================\n");
//	Delete(9, t);
//	print(t, 0);
//
//	//
//	/* strspn example */
//	int i;
//	char strtext[] = "129t4h";
//	char cset[] = "1234567890";
//
//	i = strspn(strtext, cset);
//	printf("The initial number has %d digits.\n", i);
//	return 0;
//}


// for the high-resolution timer

#include <windows.h>
#include "BTree.hpp"
 
int main(int argc, char* argv[])

{

// the main function is just some code to test the b-tree.  it inserts 100,000 elements,

// then searches for each of them, then deletes them in reverse order (also tested in

// forward order) and searches for all 100,000 elements after each deletion to ensure that

// all remaining elements remain accessible.

 

    __int64 frequency, start, end, total;

    QueryPerformanceFrequency( (LARGE_INTEGER *)&frequency );

 
    Node::m_failure.invalidate();

    Node::m_failure.m_key = "";

    Elem elem;

 
    RootTracker tracker;  // maintains a pointer to the current root of the b-tree

    Node* root_ptr = new Node(tracker);

    tracker.set_root (null_ptr, root_ptr);

   

    vector<string> search_vect;

    // prepare the key strings

    search_vect.resize (100000);

    int search_count = 0;

    for (int i=0; i<100000; i++) {

        strstream stm;

        stm << i;

        stm >> search_vect[search_count++];

    }

    string s;

    cout << "finished preparing key strings\n";

    QueryPerformanceCounter ( (LARGE_INTEGER *)&start);

    for (int i=0; i<100000; i++) 
	{
        elem.m_key = search_vect[i];
        elem.m_payload = search_vect[i]+" hi you";
        tracker.get_root()->tree_insert(elem);
    }

	cout << "finished inserting elements\n";
	{
		Node * l;
		Elem e, tmp;
		e.m_key = "1999";
		tmp = tracker.get_root()->search(e, l);
		tmp.dump();
	}

    Node * last;

    for (int i=0; i<100000; i++) {

        Elem desired;

        desired.m_key = search_vect[i];

        Elem& result = tracker.get_root()->search (desired, last);

    }

    cout << "finished searching for elements\n";

    for (int i=99999; i>=0; i--) {

        Elem target;

        target.m_key = search_vect[i];

        tracker.get_root()->delete_element (target);

        Node * last;

    }

 
    QueryPerformanceCounter ( (LARGE_INTEGER *)&end);

    total = (end-start)/(frequency/1000);

    cout << "total millisec for 100000 elements: " << (int)total << endl;

 
    cout << "after deletion" << endl;

    tracker.get_root()->dump();

    getchar();

    return 0;

}

 
 
 