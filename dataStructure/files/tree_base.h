#ifndef __TREE_BASE_H__
#define __TREE_BASE_H__

#include "ds_globalVars.h"

typedef struct tree_n*	Tree_node_pointer;
typedef struct tree_n {
	Tree_node_pointer *branches;//节点数组
	void*	ele_addr;//存放元素地址 
	c8 (*EDIT_Data_node)(struct tree_n*,void*);
	Tree_node_pointer (*GET_BRANCH_node)(struct tree_n*,u32_ds);
	c8 (*ADD_node)(struct tree_n*,u32_ds,struct tree_n*);
	void (*FREE_node)(struct tree_n*);
	void (*PRINT_node)(struct tree_n*);
	u32_ds	branch_num;
	c8 ifinitial;
}Tree_node;

typedef struct trees {
	Tree_node *head;//头节点
	char	*name;
	c8 (*EDIT_Data_node)(Tree_node*,void*);
	c8 (*ADD_node)(struct trees*,Tree_node*,u32_ds,Tree_node*);
	c8 (*SET_head)(struct trees*,Tree_node*);
	u32_ds (*COUNT)(struct trees*);
	Tree_node* (*GET_BRANCH_node)(Tree_node*,u32_ds);
	void (*PRINT)(struct trees*);
	c8 (*FREE)(struct trees*);
	u32_ds	count;
	c8		ifinitial;
}Tree;

c8 InitTree(Tree *tree);
c8 CreateTree(Tree **tree);
c8 InitNode(Tree_node *node,u32_ds branch_num);
c8 CreateNode(Tree_node **node,u32_ds branch_num);
c8 put_in_data_node(Tree_node *node,void *ele);
c8 add_node(Tree_node *node,u32_ds ind,Tree_node *node_ele);
c8 add_node_tree(Tree *tree,Tree_node *node,u32_ds ind,Tree_node *node_ele);
u32_ds count_tree(Tree *tree);
Tree_node* get_branch_node(Tree_node *node,u32_ds ind);
void free_node(Tree_node *node);
c8 free_tree(Tree *tree);
void print_node_main(Tree_node *node);
void print_treeNode(Tree_node *node);
void print_tree_main(Tree *tree);
void print_tree(Tree *tree);
c8 set_head_tree(Tree *tree,Tree_node *head); 

static c8 DFSnode(Tree_node *node);
#endif

