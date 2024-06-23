#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend-bst.h"
#include "memory.h"

void print_name(struct record *);
void print_number(struct record *);

// comparison function for records
int compare(char key[3], struct record *);

// data
struct record *data = NULL; // Initially NULL.

/***********************
Address Book by binary search tree
**************************/

void init()
{
  init_pool();
}

void search(char name[3])
{
  struct record *r; // Pointer to record being compared.
                    // data or left/right field of a node.
  int result;
  r = data;

  while (r != NULL)
  {
    if ((result = compare(name, r)) < 0)
      r = r->left;
    else if (result == 0)
    {
      print_name(r);
      printf(" : ");
      print_number(r);
      printf(" was found.\n");
      return;
    }
    else // case >0
      r = r->right;
  }
  printf("Couldn't find the name.\n");
}

// Function to add a record to the BST
void add(char *name, char *number) {
  struct record *r= new_node();
    
  if (r == NULL) {
    printf("Can't add.  The pool is empty!\n");
    return;
  }
    
  strncpy(r->name, name, 3);
  strncpy(r->number, number, 4);
  r->left = NULL;
  r->right = NULL;

  if (data == NULL) {
    data = r;
  } else {
    struct record *cur = data;
    struct record *parent = NULL;

    while (cur != NULL) {
      parent = cur;

      int cmp = compare(name, cur);
      if (cmp <= 0) {
        cur = cur->left;
      }
      else {
        cur = cur->right;  
      }
    }

    int cmp = compare(name, parent);
    if (cmp <= 0) {
      parent->left = r;
    } else {
      parent->right = r;
    }
  }
  printf("The name was successfully added!\n");
}

void delete(char name[3]) {
  struct record *cur = data;
  struct record *parent = NULL;
  struct record *successor = NULL;
  struct record *successorParent = NULL;

  // Find the node to delete and its parent
  while (cur != NULL) {
    int cmp = compare(name, cur);

    if (cmp == 0) {
      break; // Found the node to delete
    } else {
      parent = cur;
      if (cmp < 0) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
  }
    
  if (cur == NULL) {
    printf("Couldn't find the name.\n");
    return;
  }

    // Check if the node to delete has two children
  if (cur->left != NULL && cur->right != NULL) {
    successor = cur->right;
    successorParent = cur;

    while (successor->left != NULL) {
      successorParent = successor;
      successor = successor->left;
    }

    // Copy data from the successor to the cur(rent) node
    strncpy(cur->name, successor->name, 3);
    strncpy(cur->number, successor->number, 4);

    // Update cur(rent) and parent to point to the successor
    cur = successor;
    parent = successorParent;
  }

  // the node to delete has zero or one child
  struct record *child = (cur->left != NULL) ? cur->left : cur->right;

  if (parent == NULL) {
    // Delete the root node
    data = child;
  } else if (parent->left == cur) {
    parent->left = child;
  } else {
    parent->right = child;
  }

  free_node(cur);
  printf("The name was deleted.\n");
}

/* Just a wrapper of strncmp().
Regard strncmp(a,b) as a-b.
Negative value if key is less than r.
​0​ if key and r are equal.
Positive value if key is greater than r. */
int compare(char key[3], struct record *r)
{
  return strncmp(key, r->name, 3);
}

void print_data(char *s, int n)
{
  int i;
  for (i = 0; i < n; i++)
    putchar(s[i]);
}

void print_name(struct record *r)
{
  print_data(r->name, 3);
}

void print_number(struct record *r)
{
  print_data(r->number, 4);
}

void print_inorder(struct record *t)
{
  if (t != NULL)
  {
    print_inorder(t->left);
    print_name(t);
    printf(" : ");
    print_number(t);
    printf("\n");
    print_inorder(t->right);
  }
}

void print_list()
{
  print_inorder(data);
}

// returns the height of the BST.
int height(struct record *t)
{
  if (t == NULL)
  {
    return -1;
  }
  else
  {
    int left_height = height(t->left);
    int right_height = height(t->right);
    return (left_height > right_height) ? (left_height + 1) : (right_height + 1); //2024 midterm blank
  }
}

void print_height()
{
  printf("The Address Book BST's height is %d.\n", height(data));
}


//2024 midterm OUTPUT!!! (출력결과)화면 채우는 문제 나옴. 입력 순서, list_order() 했을 때 쓰여지는 값이 어떻게 화면에 출력되는지,,,
