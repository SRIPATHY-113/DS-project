#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_ITEMS 100 
// Structure to store item details 
typedef struct { 
    int id; 
    char name[50]; 
    float price; 
    int quantity; 
} Item; 
 
// Structure for shopping cart node (linked list) 
typedef struct CartNode { 
    Item item; 
    struct CartNode* next; 
} CartNode; 
 
CartNode* cartHead = NULL; 
 
// Function prototypes 
void addItemToCart(int id, const char* name, float price, int quantity); 
void removeItemFromCart(int id); 
void viewCart(); 
void calculateTotal(); 
CartNode* findItemInCart(int id); 
 
int main() { 
    int choice, id, quantity; 
    float price; 
    char name[50]; 
    printf("=== Online Shopping Cart ===\n"); 
    while (1) { 
        printf("\n1. Add Item to Cart\n"); 
        printf("2. Remove Item from Cart\n"); 
        printf("3. View Cart\n"); 
        printf("4. Calculate Total\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter Item ID: "); 
                scanf("%d", &id); 
                printf("Enter Item Name: "); 
                scanf(" %[^\n]s", name); // To handle spaces in the item name 
                printf("Enter Item Price: "); 
                scanf("%f", &price); 
                printf("Enter Quantity: "); 
                scanf("%d", &quantity); 
                addItemToCart(id, name, price, quantity); 
                break; 
            case 2: 
                printf("Enter Item ID to Remove: "); 
                scanf("%d", &id); 
                removeItemFromCart(id); 
                break; 
            case 3: 
                viewCart(); 
                break; 
            case 4: 
                calculateTotal(); 
                break; 
            case 5: 
                printf("Thank you for shopping! Goodbye.\n"); 
                return 0; 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
} 
 
// Add an item to the cart 
void addItemToCart(int id, const char* name, float price, int quantity) { 
    if (findItemInCart(id)) { 
        printf("Item with ID %d is already in the cart.\n", id); 
        return; 
    } 
 
    CartNode* newNode = (CartNode*)malloc(sizeof(CartNode)); 
    newNode->item.id = id; 
    strcpy(newNode->item.name, name); 
    newNode->item.price = price; 
    newNode->item.quantity = quantity; 
    newNode->next = cartHead; 
    cartHead = newNode; 
 
    printf("Item added to cart successfully.\n"); 
    } 
 
// Remove an item from the cart 
void removeItemFromCart(int id) { 
    CartNode* current = cartHead; 
    CartNode* previous = NULL; 
 
    while (current != NULL && current->item.id != id) { 
        previous = current; 
        current = current->next; 
    } 
 
    if (current == NULL) { 
        printf("Item with ID %d not found in the cart.\n", id); 
        return; 
    } 
 
    if (previous == NULL) { 
        cartHead = current->next; 
    } else { 
        previous->next = current->next; 
    } 
 
    free(current); 
    printf("Item removed from cart successfully.\n"); 
} 
 
// View all items in the cart 
void viewCart() { 
    if (cartHead == NULL) { 
        printf("Your cart is empty.\n"); 
        return; 
    } 
 
    CartNode* current = cartHead; 
    printf("\n=== Your Cart ===\n"); 
    printf("ID\tName\t\tPrice\tQuantity\n"); 
    printf("--------------------------------------------\n"); 
 
    while (current != NULL) { 
        printf("%d\t%s\t\t%.2f\t%d\n", current->item.id, current->item.name, 
               current->item.price, current->item.quantity); 
        current = current->next; 
    } 
} 
 
// Calculate the total cost of items in the cart 
void calculateTotal() { 
    if (cartHead == NULL) { printf("Your cart is empty.\n"); 
        return; 
    } 
 
    float total = 0; 
    CartNode* current = cartHead; 
 
    while (current != NULL) { 
        total += current->item.price * current->item.quantity; 
        current = current->next; 
    } 
 
    printf("Total Cost: $%.2f\n", total); 
} 
 
// Find an item in the cart by ID 
CartNode* findItemInCart(int id) { 
    CartNode* current = cartHead; 
    while (current != NULL) { 
        if (current->item.id == id) { 
            return current; 
        } 
        current = current->next; 
    } 
    return NULL; 
}