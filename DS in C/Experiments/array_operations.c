#include <stdio.h>
#include <stdlib.h>
void traverse(int *a, int *n)
{
  int i;
  printf("Here's the array: ");
  for (i = 0; i < (*n); i++)
  {
    printf("%d ", a[i]);
  }
}

void insert(int *a, int *n)
{
  int i, loc, item;
  printf("Enter the location for insertion: ");
  scanf("%d", &loc);
  loc--;
  //Validation
  if (loc < 0 || loc > (*n))
  {
    printf("Error! Invalid location");
  }
  //Insertion of the item
  else
  {
    (*n)++;
    printf("Enter the element to be inserted : ");
    scanf("%d", &item);
    for (i = (*n) - 1; i >= loc; i--)
    {
      a[i + 1] = a[i];
    }
    a[loc] = item;

    printf("The new array is: ");
    for (i = 0; i < (*n); i++)
    {
      printf("%d ", a[i]);
    }
  }
}

void delposition(int *a, int *n)
{
  int i, item, loc;
  printf("Enter the location of the element to be deleted: ");
  scanf("%d", &loc);
  loc--;
  //Validation
  if (loc < 0 || loc > (*n) - 1)
  {
    printf("Invalid location");
  }
  else
  {
    item = a[loc];
    for (i = loc; i < (*n) - 1; i++)
    {
      a[i] = a[i + 1];
    }
    (*n)--;
    printf("Item deleted is: %d", item);
    printf("\nThe new array is: ");
    for (i = 0; i < (*n); i++)
    {
      printf("%d ", a[i]);
    }
  }
}

void delitem(int *a, int *n)
{
  int i, loc, item;
  printf("Enter the element to be deleted: ");
  scanf("%d", &item);
  for (i = 0; i < (*n); i++)
  {
    if (a[i] == item)
    {
      loc = i;
      break;
    }
  }
  if (i >= (*n))
    printf("Element doesn't exist. Deletion not possible");
  else
  {
    for (i = loc; i < (*n) - 1; i++)
    {
      a[i] = a[i + 1];
    }
    (*n)--;
    printf("Item deleted is: %d", item);
    printf("\nThe new array is: ");
    for (i = 0; i < (*n); i++)
    {
      printf("%d ", a[i]);
    }
  }
}

void bubblesort(int *a, int *n)
{
  int i = 0, j = 0, temp;
  for (i = 0; i < (*n); i++)
  {
    for (j = 0; j < (*n) - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  printf("After bubble sort: ");
  for (i = 0; i < (*n); i++)
    printf("%d ", a[i]);
}

void linearsearch(int *a, int *n)
{
  int i, item, loc;
  printf("Enter the element to be searched: ");
  scanf("%d", &item);
  for (i = 0; i < (*n); i++)
  {
    if (a[i] == item)
    {
      loc = i;
      break;
    }
  }
  if (i >= (*n))
    printf("Element does not exist in the array");
  else
    printf("Element found at position: %d ", loc + 1);
}

void binarysearch(int *a, int *n)
{
  int low = 0, high = (*n) - 1, mid, key;
  mid = (low + high) / 2;
  printf("Enter the element to be searched : ");
  scanf("%d", &key);
  while (low <= high)
  {
    if (a[mid] < key)
      low = mid + 1;
    else if (a[mid] == key)
    {
      printf("%d found at location %d", key, mid + 1);
      break;
    }
    else
      high = mid - 1;
    mid = (low + high) / 2;
  }
  if (low > high)
    printf("Not found! %d isn't present in the array", key);
}

int main(void)
{
  int a[100], n, ch, i = 0, item, loc;

  printf("\nEnter the no. of elements: ");
  scanf("%d", &n);

  printf("Enter elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  while (1)
  {
    printf("\n\n1.Insertion\n2.Deletion\n3.Traversal\n4.Sorting\n5.Searching\n6.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1: //INSERTION CASE
      insert(a, &n);
      break;

    case 2: //DELETION CASE
      printf("\n1. Location-wise Deletion\n2. Item-wise Deletion ");
      scanf("%d", &ch);
      if (ch == 1)
      {
        delposition(a, &n);
      }
      else
      {
        delitem(a, &n);
      }
      break;

    case 3: //TRAVERSAL CASE
      traverse(a, &n);
      break;

    case 4: //SORTING CASE
      bubblesort(a, &n);
      break;

    case 5: //SEARCH CASE
      printf("\n1.Linear Search\n2.Binary Search\n");
      scanf("%d", &ch);
      if (ch == 1)
      {
        linearsearch(a, &n);
        break;
      }
      else
      {
        binarysearch(a, &n);
        break;
      }
    case 6: //EXIT CASE
      exit(0);
      break;

    default:
      printf("\nError! Invalid\n");
    }
  }
}
