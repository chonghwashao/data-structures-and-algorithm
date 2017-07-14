#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType e, SearchTree T)
{
	if (T != NULL )
	{
		if (e > T->element)
			return Find(e, T->right);
		else if (e < T->element)
			return Find(e, T->right);
		else
			return T;
	}

	return NULL;
}

Position FindMin(SearchTree T)
{
	//if (T == NULL)
	//	return NULL;

	//if (T->left != NULL)
	//{
	//	return FindMin(T->left);
	//}

	//return T;

	/* non-recursive implementation */
	if (T == NULL)
		return NULL;

	while (T->left != NULL)
	{
		T = T->left;
	}

	return T;
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;

	if (T->right != NULL)
	{
		return FindMax(T->right);
	}
	else
		return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)malloc(sizeof(TreeNode));
		if (T == NULL)
		{
		}
		else
		{
			T->element = X;
			T->left = T->right = NULL;
		}
	}

	if (X < T->element)
	{
		T->left = Insert(X, T->left);
	}
	else if (X > T->element)
	{
		T->right = Insert(X, T->right);
	}
		
	return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
	{
		printf("Element not found!");
	}
	else
	{
		if (X < T->element)
		{
			T->left = Delete(X, T->left);
		}
		else if (X > T->element)
		{
			T->right = Delete(X, T->right);
		}
		else if(T->left && T->right)// Found element to delete // two children
		{
			/*replace with the smallest in right subtree*/
			TmpCell = FindMin(T->right);
			T->element = TmpCell->element;
			T->right = Delete(T->element, T->right);
		}
		else 
		{
			TmpCell = T;
			if (T->left == NULL)
			{
				T = T->right;
			}
			else if (T->right == NULL)
			{
				T = T->left;
			}

			free(TmpCell);
		}
	}

	return T;
}

