/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:12:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/06 11:18:59 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "avltree.hpp"

namespace ft{

	template < typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{};

};


#endif

////////////////////////////ToDo
//* calculate the balance factor for each node of the tree
//* implement helpers :
	//! int height(void); √
		//? The height of a rooted tree is the number of edges between the tree's
		//? root and its furthest leaf. This means that a tree containing a single
		//? node has a height of 0.
	//! int size(){ return nbr_node; } √
	//! bool isEmpty(); √
	//! bool exist(node root, T value){} √
		//? Return true/false depending on whether a value exists in the tree.
//* insert non duplicate value to the avl-tree -left node or right node-
	//? allocate new nod √
		//? allocate value √
// * update _nbr_node value after each insertion +=1 
//* update height and bf
//* rebalance the tree if |bf| == 2
	//! leftLeft rotation
	//! rightright rotation
	//! leftright rotation  *update height and bf child node first then the parent node*
	//! rightLeft rotation  *update height and bf child node first then the parent node*
//* display the tree
	//? level order traversal
//* remove node..
//* 3 cases
	//! case1: the node is a leaf
	//! case2: the node have at most 1 child
	//! case3: the node have left and right child
		//? choose the successor and swap its value into the node
			// The successor is either the smallest value in the right subtree
			// or the largest value in the left subtree.
		//? remove the successor's node
		//? rebalance the tree
//* update nbr_node value after each insertion
// use min max functions instead (easy node removal)
//* update height and bf

////TODO > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >

//* implemetation of 3 types of traversal : preorder, inorder, postorder
//* replace node->data with pair
//* bidirectionnal iterator

