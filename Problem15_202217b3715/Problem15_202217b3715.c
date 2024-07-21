#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Linked List node
struct node {
   char* key;  // key is string
   char* value; // value is also string
   struct node* next;
};
 
// Function to set node values
void setNode(struct node* node, char* key, char* value) {
   node->key = key;
   node->value = value;
   node->next = NULL;
}
 
// HashMap structure
struct hashMap {
   int numOfElements, capacity; // Current number of elements and capacity
   struct node** arr;           // Array of linked list base addresses
};
 
// Initialize the hash map
void initializeHashMap(struct hashMap* mp) {
   mp->capacity = 100; // Default capacity
   mp->numOfElements = 0;
   mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
   for (int i = 0; i < mp->capacity; i++) {
       mp->arr[i] = NULL;
   }
}
 
// Hash function to get bucket index
int hashFunction(struct hashMap* mp, char* key) {
   int sum = 0, factor = 31;
   for (int i = 0; i < strlen(key); i++) {
       sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
       factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
   }
   return sum;
}
 
// Insert key-value pair into the hash map
void insert(struct hashMap* mp, char* key, char* value) {
   int bucketIndex = hashFunction(mp, key);
   struct node* newNode = (struct node*)malloc(sizeof(struct node));
   setNode(newNode, key, value);
 
   // No collision
   if (mp->arr[bucketIndex] == NULL) {
       mp->arr[bucketIndex] = newNode;
   } else { // Collision
       newNode->next = mp->arr[bucketIndex];
       mp->arr[bucketIndex] = newNode;
   }
}
 
// Delete key from the hash map
void delete(struct hashMap* mp, char* key) {
   int bucketIndex = hashFunction(mp, key);
   struct node* prevNode = NULL;
   struct node* currNode = mp->arr[bucketIndex];
 
   while (currNode != NULL) {
       if (strcmp(key, currNode->key) == 0) {
           if (currNode == mp->arr[bucketIndex]) {
               mp->arr[bucketIndex] = currNode->next;
           } else {
               prevNode->next = currNode->next;
           }
           free(currNode);
           return;
       }
       prevNode = currNode;
       currNode = currNode->next;
   }
}
 
// Search for a key in the hash map
char* search(struct hashMap* mp, char* key) {
   int bucketIndex = hashFunction(mp, key);
   struct node* bucketHead = mp->arr[bucketIndex];
 
   while (bucketHead != NULL) {
       if (strcmp(bucketHead->key, key) == 0) {
           return bucketHead->value;
       }
       bucketHead = bucketHead->next;
   }
 
   return "Oops! No data found.\n";
}
 
// Driver code
int main() {
   struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
   initializeHashMap(mp);
 
   insert(mp, "Yogaholic", "Anjali");
   insert(mp, "pluto14", "Vartika");
   insert(mp, "elite_Programmer", "Manish");
   insert(mp, "GFG", "BITS");
   insert(mp, "decentBoy", "Mayank");
 
   printf("%s\n", search(mp, "elite_Programmer"));
   printf("%s\n", search(mp, "Yogaholic"));
   printf("%s\n", search(mp, "pluto14"));
   printf("%s\n", search(mp, "decentBoy"));
   printf("%s\n", search(mp, "GFG"));
   printf("%s\n", search(mp, "randomKey"));
 
   printf("\nAfter deletion:\n");
   delete(mp, "decentBoy");
   printf("%s\n", search(mp, "decentBoy"));
 
   return 0;
}
 
 
 
