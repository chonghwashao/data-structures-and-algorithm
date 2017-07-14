#ifndef _TREE_H
#define _TREE_H

#ifndef NULL
#define NULL 0
#endif // !NULL

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

struct TreeNode
{
	ElementType element;
	SearchTree left;
	SearchTree right;
};

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType e, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif // !_TREE_H