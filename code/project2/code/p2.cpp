#include<iostream>
#include<cstdlib>
#include"p2.h"
#include"recursive.h"

using namespace std;

list_t reverse_helper(list_t list,list_t help);
list_t append_helper(list_t first, list_t second, list_t help);
list_t filter_odd_helper(list_t list, list_t help);
list_t filter_even_helper(list_t list, list_t help);
list_t filter_helper(list_t list, bool (*fn)(int), list_t help);
list_t insert_list_helper(list_t first, list_t second, unsigned int n, list_t help, int t);
list_t chop_helper(list_t list, unsigned int n, list_t help, int t);




int size(list_t list)
{
	int empty;
	empty=list_isEmpty(list);
	if (empty==1)
	{
		return 0;
	}
	else 
	{
		return 1+size(list_rest(list));
	}


}
/* 
// EFFECTS: Returns the number of elements in "list".
//          Returns zero if "list" is empty.
*/ 



int sum(list_t list)
{
	int empty;
	empty=list_isEmpty(list);
	if (empty==1)
	{
		return 0;
	}
	else
	{
		return list_first(list)+sum(list_rest(list));

	}
}

// EFFECTS: Returns the sum of each element in "list".
//          Returns zero if "list" is empty.

int product(list_t list)
{
	int empty;
	empty=list_isEmpty(list);
	if (empty==1)
	{
		return 1;
	}
	else
	{
		return list_first(list)*product(list_rest(list));

	}

}
/* 
// EFFECTS: Returns the product of each element in "list".
//          Returns one if "list" is empty.
*/

int accumulate(list_t list, int (*fn)(int, int), int base)
{
	int empty=list_isEmpty(list);
	if (empty==1)
	{
		return base;
	}
	else
	{
		return fn(list_first(list),accumulate(list_rest(list),fn,base));
	}
}
/*
// REQUIRES: "fn" must be associative.
//
// EFFECTS: Returns "base" if "list" is empty.
//          Returns fn(list_first(list), 
//                      accumulate(list_rest(list), fn, base) otherwise.
//
// For example, if you have the following function:
//
//           int add(int x, int y);
//
// Then the following invocation returns the sum of all elements:
//
//           accumulate(list, add, 0);
*/ 


list_t reverse(list_t list)
{
	list_t help;
	help=list_make();

	return reverse_helper(list,help);




}


list_t reverse_helper(list_t list,list_t help)
{
	int empty=list_isEmpty(list);
	if (empty==1)
	{
		return help;
	}
	else
	{
		help=list_make(list_first(list),help);
		return reverse_helper(list_rest(list),help);
	}


}
/*
// EFFECTS: Returns the reverse of "list".
//
// For example: the reverse of ( 3 2 1 ) is ( 1 2 3 )
*/


list_t append(list_t first, list_t second)
{
	list_t first_rev, second_rev, help;
	first_rev=reverse(first);
	second_rev=reverse(second);
	help=list_make();
	help=append_helper(first_rev, second_rev, help);
	return help;

}



list_t append_helper(list_t first, list_t second, list_t help)
{
	int first_empty=list_isEmpty(first);
	int second_empty=list_isEmpty(second);

	if (second_empty==1&&first_empty==1)
	{
		return help;
	}
	else if (first_empty==0&&second_empty==1)
	{
		return append_helper(list_rest(first),second, list_make(list_first(first),help));
	}
	else if (second_empty==0)
	{
		return append_helper(first,list_rest(second), list_make(list_first(second),help));
	}






}


/*
// EFFECTS: Returns the list (first second).
//
// For example: append(( 2 4 6 ), ( 1 3 )) gives
// the list ( 2 4 6 1 3 ).
*/ 


list_t filter_odd(list_t list)
{
	list_t help, list_rev;
	help=list_make();
	list_rev=reverse(list);
	return filter_odd_helper(list_rev, help);

}



list_t filter_odd_helper(list_t list, list_t help)
{
	int empty=list_isEmpty(list);
	if (empty==1)
	{
		return help;
	}
	else
	{
		if (list_first(list)%2==0)
		{
			return filter_odd_helper(list_rest(list),help);
		}
		else
		{
			return filter_odd_helper(list_rest(list),list_make(list_first(list),help));
		}

	}



}
/*
// EFFECTS: Returns a new list containing only the elements of the
//          original "list" which are odd in value, 
//          in the order in which they appeared in list.
//
// For example, if you applied filter_odd to the list ( 3 4 1 5 6 )
// you would get the list ( 3 1 5 ).
*/ 



list_t filter_even(list_t list)
{
	list_t help, list_rev;
	help=list_make();
	list_rev=reverse(list);
	return filter_even_helper(list_rev, help);

}



list_t filter_even_helper(list_t list, list_t help)
{
	int empty=list_isEmpty(list);
	if (empty==1)
	{
		return help;
	}
	else
	{
		if (list_first(list)%2==1)
		{
			return filter_even_helper(list_rest(list),help);
		}
		else
		{
			return filter_even_helper(list_rest(list),list_make(list_first(list),help));
		}

	}



}
/*
// EFFECTS: Returns a new list containing only the elements of the
//          original "list" which are even in value, 
//          in the order in which they appeared in list.
*/

list_t filter(list_t list, bool (*fn)(int))
{
	list_t help, list_rev;
	help=list_make();
	list_rev=reverse(list);
	return filter_helper(list_rev, fn, help);
}

list_t filter_helper(list_t list, bool (*fn)(int), list_t help)
{
	int empty=list_isEmpty(list);
	if (empty==1)
	{
		return help;
	}
	else
	{
		if (fn(list_first(list))==0)
		{
			return filter_helper(list_rest(list), fn, help);
		}
		else
		{
			return filter_helper(list_rest(list), fn, list_make(list_first(list),help));
		}
	}

}
/*
// EFFECTS: Returns a list containing precisely the elements of "list"
//          for which the predicate fn() evaluates to true, in the
//          order in which they appeared in list.
//
// For example, if predicate bool odd(int a) returns true if a is odd,
// then the function filter(list, odd) has the same behavior as the
// function filter_odd(list).
*/

list_t insert_list(list_t first, list_t second, unsigned int n)
{
	int length=size(first);
	int n_rev=length-n;
	list_t first_rev=reverse(first);
	list_t second_rev=reverse(second);
	list_t help=list_make();
	return insert_list_helper(first_rev, second_rev, n_rev, help, 1);


}

list_t insert_list_helper(list_t first, list_t second, unsigned int n, list_t help, int t)
{
	int empty_second=list_isEmpty(second);
	int empty_first=list_isEmpty(first);
	if (t<=n)
	{
		return insert_list_helper(list_rest(first),second, n, list_make(list_first(first),help),t+1);
	}
	else if (empty_second==0&&t>n)
	{
		return insert_list_helper(first, list_rest(second),n,list_make(list_first(second),help),t);
	}
	else if (empty_second==1&&empty_first==0&&t>n)
	{
		return insert_list_helper(list_rest(first),second, n, list_make(list_first(first),help),t);
	}
	else if (empty_first==1&&empty_second==1)
	{
		return help;
	}

}
/*
// REQUIRES: n <= the number of elements in "first".
//
// EFFECTS: Returns a list comprising the first n elements of
//          "first", followed by all elements of "second",
//           followed by any remaining elements of "first".
//
//     For example: insert (( 1 2 3 ), ( 4 5 6 ), 2)
//            is  ( 1 2 4 5 6 3 ).
*/

list_t chop(list_t list, unsigned int n)
{
	list_t list_inv;
	list_inv=reverse(list);
	list_t help=list_make();
	return chop_helper(list_inv, n, help,1);
}

list_t chop_helper(list_t list, unsigned int n, list_t help, int t)
{
	int empty;
	empty=list_isEmpty(list);
	if (t<=n)
	{
		return chop_helper(list_rest(list),n, help, t+1);
	}
	else if (empty==0)
	{
		return chop_helper(list_rest(list), n, list_make(list_first(list),help), t);
	}
	else if (empty==1)
	{
		return help;

	}

}

/*
// REQUIRES: "list" has at least n elements.
//
// EFFECTS: Returns the list equal to "list" without its last n
//          elements.
*/


int tree_sum(tree_t tree)
{
	int empty=tree_isEmpty(tree);
	if (empty==1)
	{
		return 0;
	}
	else
	{
		return tree_elt(tree)+tree_sum(tree_left(tree))+tree_sum(tree_right(tree));
	}
}
/*
// EFFECTS: Returns the sum of all elements in "tree". 
//          Returns zero if "tree" is empty.
*/


bool tree_search(tree_t tree, int key)
{
	int empty=tree_isEmpty(tree);
	if (empty==1)
	{
		return 0;
	}
	else
	{
		if (tree_elt(tree)==key)
		{
			return 1;
		}
		else
		{
			return (tree_search(tree_left(tree),key)||tree_search(tree_right(tree),key));
		}
	}
}
/*
// EFFECTS: Returns true if and only if there exists any element in
//          "tree" whose value is "key".
*/

int depth(tree_t tree)
{
	int empty=tree_isEmpty(tree);
	if (empty==1)
	{
		return 0;
	}
	else
	{
		if (depth(tree_left(tree))>depth(tree_right(tree)))
		{
			return depth(tree_left(tree))+1;
		}
		else
		{
			return depth(tree_right(tree))+1;
		}
	}
}
/*
// EFFECTS: Returns the depth of "tree", which equals the number of
//          layers of nodes in the tree.
//          Returns zero is "tree" is empty.
//
// For example, the tree
// 
//                           4
//                         /   \
//                        /      \
//                       2        5
//                      / \      / \
//                         3        8
//                        / \      / \
//                       6   7
//                      / \ / \
//
// has depth 4.
// The element 4 is on the first layer.
// The elements 2 and 5 are on the second layer.
// The elements 3 and 8 are on the third layer.
// The elements 6 and 7 are on the fourth layer.
//
*/

int tree_min(tree_t tree)
{
	int empty_left=tree_isEmpty(tree_left(tree));
	int empty_right=tree_isEmpty(tree_right(tree));
	if (empty_left==1&&empty_right==1)
	{
		return tree_elt(tree);
	}
	else if (empty_left==0&&empty_right==1)
	{
		int left_min=tree_min(tree_left(tree));
		if (left_min<=tree_elt(tree))
		{
			return left_min;
		}
		else 
		{
			return tree_elt(tree);
		}
	}
	else if (empty_right==0&&empty_left==1)
	{
		int right_min=tree_min(tree_right(tree));
		if (right_min<=tree_elt(tree))
		{
			return right_min;
		}
		else
		{
			return tree_elt(tree);
		}
	}
	else if (empty_left==0&&empty_right==0)
	{
		int left_min=tree_min(tree_left(tree));
		int right_min=tree_min(tree_right(tree));
		int elt=tree_elt(tree);
		int help;
		if (left_min<right_min)
		{
			help=left_min;
		}
		else
		{
			help=right_min;
		}
		if (help<elt)
		{
			return help;
		}
		else
		{
			return elt;
		}
	}


}
/*
// REQUIRES: "tree" is non-empty.
// EFFECTS: Returns the smallest element in "tree".
*/

list_t traversal(tree_t tree)
{
	int empty=tree_isEmpty(tree);
	if (empty==1)
	{
		return list_make();
	}
	else
	{
		list_t list_left=traversal(tree_left(tree));
		list_t list_right=traversal(tree_right(tree));
		list_t list_elt=list_make(tree_elt(tree),list_make());
		list_t list_help=append(list_left, list_elt);
		return append(list_help, list_right);
	}
}
/* 
// EFFECTS: Returns the elements of "tree" in a list using an
//          in-order traversal. An in-order traversal prints 
//          the "left most" element first, then the second-left-most, 
//          and so on, until the right-most element is printed.
//
//          For any root element, all the elements of its left subtree
//          are considered as on the left of that root element and
//          all the elements of its right subtree are considered as
//          on the right of that root element.
//
// For example, the tree:
// 
//                           4
//                         /   \
//                        /      \
//                       2        5
//                      / \      / \
//                         3 
//                        / \
//
// would return the list
//
//       ( 2 3 4 5 )
// 
// An empty tree would print as:
// 
//       ( )
//
*/

bool tree_hasPathSum(tree_t tree, int sum)
{
	int empty_left=tree_isEmpty(tree_left(tree));
	int empty_right=tree_isEmpty(tree_right(tree));

	if (empty_left==1&&empty_right==1)
	{
		if (tree_elt(tree)==sum)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (empty_left==0&&empty_right==1)
	{
		return tree_hasPathSum(tree_left(tree),sum-tree_elt(tree));
	}
	else if (empty_left==1&&empty_right==0)
	{
		return tree_hasPathSum(tree_right(tree),sum-tree_elt(tree));
	}
	else
	{
		return (tree_hasPathSum(tree_left(tree),sum-tree_elt(tree))||tree_hasPathSum(tree_right(tree),sum-tree_elt(tree)));
	}
}
/* 
// EFFECTS: Returns true if and only if "tree" has at least one root-to-leaf
//          path such that adding all elements along the path equals "sum".
//          
// A root-to-leaf path is a sequence of elements in a tree starting
// with the root element and proceeding downward to a leaf (an element
// with no children).
//
// An empty tree has no root-to-leaf path.
//
// For example, the tree:
// 
//                           4
//                         /   \
//                        /     \
//                       1       5
//                      / \     / \
//                     3   6 
//                    / \ / \
//
// has three root-to-leaf paths: 4->1->3, 4->1->6 and 4->5.
// Given sum = 9, the path 4->5 has the sum 9, so the function
// should return true. If sum = 10, since no path has the sum 10,
// the function should return false.
// 
*/


bool covered_by(tree_t A, tree_t B)
{
	int A_empty=tree_isEmpty(A);
	int B_empty=tree_isEmpty(B);
	if (A_empty==1&&B_empty==0)
	{
		return 1;
	}
	else if (B_empty==1&&A_empty==1)
	{
		return 1;
	}
	else if (B_empty==1&&A_empty==0)
	{
		return 0;
	}
	else if (A_empty==0&&B_empty==0)
	{
		if (tree_elt(A)==tree_elt(B))
		{
			return (covered_by(tree_left(A),tree_left(B))&&covered_by(tree_right(A),tree_right(B)));
		}
		else
		{
			return 0;
		}
	}
}
/*
// EFFECTS: Returns true if tree A is covered by tree B.
*/  


bool contained_by(tree_t A, tree_t B)
{
	int A_empty=tree_isEmpty(A);
	int B_empty=tree_isEmpty(B);


	if(A_empty==1&&B_empty==0) 
	{
		return 1;
	}
	else if (B_empty==1&&A_empty==1)
	{
		return 1;
	}
	else if (B_empty==1&&A_empty==0)
	{
		return 0;
	}
	else if (A_empty==0&&B_empty==0)
	{
		if (covered_by(A,B)==1)
		{
			return 1;
		}
		else
		{
			return (contained_by(A,tree_left(B))||covered_by(A, tree_right(B)));
		}

	}



	
}
/*
// EFFECTS: Returns true if tree A is covered by tree B
//          or any complete subtree of B.
*/   


tree_t insert_tree(int elt, tree_t tree)
{
	int empty=tree_isEmpty(tree);

	if (empty==1)
	{
		return tree_make(elt,tree_make(),tree_make());
	}
	else
	{
		if (tree_elt(tree)>elt)
		{
			tree_t left;
			left=insert_tree(elt,tree_left(tree));
			return tree_make(tree_elt(tree),left, tree_right(tree));
		}
		else
		{
			tree_t right;
			right=insert_tree(elt,tree_right(tree));
			return tree_make(tree_elt(tree),tree_left(tree),right);
		}
	}
}
/* 
// REQUIRES: "tree" is a sorted binary tree.
//
// EFFECTS: Returns a new tree with elt inserted at a leaf such that 
//          the resulting tree is also a sorted binary tree.
//
// For example, inserting 1 into the tree:
//
//                           4
//                         /   \
//                        /      \
//                       2        5
//                      / \      / \
//                         3 
//                        / \
//
// would yield
//                           4
//                         /   \
//                        /      \
//                       2        5
//                      / \      / \
//                     1   3 
//                    / \ / \
// 
*/