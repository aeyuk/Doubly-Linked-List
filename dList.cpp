/* CATE YUK - CWID: 11817795
PROJECT 2
DOUBLY LINKED-LIST */
#include <cstddef>
#include <iostream>

using namespace std;

struct node {
    int key;
    char type;
    node *next;
    node *prev;
} ;

class dList {
    private:
        node* head;
        node* tail;

        node *split(node *head) {
            //Split doubly linked-list into two
            node *fast = head->next;
            node *slow = head;
            while (fast->next != NULL && fast->next->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            }
            node *temp = slow->next;
            slow->next = NULL;
            return temp;
        }

        node *merge(node *list1, node *list2) {
            //If first linked list is empty
            if (!list1)
                return list2;
            //If second linked list is empty
            if (!list2)
                return list1;

            //Compare keys and merge
            if (list1->key < list2->key) {
                list1->next = merge(list1->next, list2);
                list1->next->prev = list1;
                list1->prev = NULL;
                return list1;
            }
            else {
                list2->next = merge(list1, list2->next);
                list2->next->prev = list2;
                list2->prev = NULL;
                return list2;
            }
        }


        node *mergeSort(node *head) {
            //Empty list or list of 1 = Already sorted
            if (!head || !head->next)
                return head;

            node *list2 = split(head);

            //Recursion for left and right halves
            head = mergeSort(head);
            list2 = mergeSort(list2);

            //Merge the two sorted halves
            return merge(head, list2);
        }

    public:
        dList() { //Creates empty list
            head = NULL;
            tail = NULL;
        }

        dList(int *keyArray, char *typeArray, int length) {
        //Initializes list with key and type arrays
            for (int i = 0; i < length; i++) {
                if (i == 0) {
                    node *temp = new node();
                    temp->key = keyArray[i];
                    temp->type = typeArray[i];
                    temp->next = NULL;
                    temp->prev = NULL;
                    tail = temp;
                    head = temp;
                }
                else {
                    node *temp = new node();
                    temp->key = keyArray[i];
                    temp->type = typeArray[i];
                    temp->next = NULL;
                    temp->prev = tail;
                    temp->prev->next = temp;
                    tail = temp;
                }
            }
        }


        void addFront(int k, char t) {
            node *temp = new node(); //Create new node
            temp->key = k; //Insert data
            temp->type = t;
            temp->next = head;
            temp->prev = NULL;
            if (head == NULL) { //If list is empty
                temp->prev = NULL;
                temp->next = NULL;
                head = temp;
                tail = temp;
            }
            else if (head != NULL) //Adds node before head
                head->prev = temp;
            head = temp;
        }

        void addBack(int k, char t) {
            node *temp = new node(); //Create new node
            temp->key = k; //Insert data
            temp->type = t;
            temp->next = NULL;
            temp->prev = tail;
            if (head == NULL) { //If list is empty
                temp->prev = NULL;
                temp->next = NULL;
                head = temp;
                tail = temp;
            }
            else if (head != NULL)
                tail->next = temp; //Adds node after tail
            tail = temp;
        }

        node *search(int k) {
            //Traverse list
            for (node *cur = head; cur != NULL; cur = cur->next) {
                if (cur->key == k) return cur; //Finds node with matching key
            }
            return NULL;
        }

        void find(char t) {
            for (node *cur = head; cur != NULL; cur = cur->next) {
                if (cur->type == t) //Finds node with matching type
                    //Output
                    cout << cur->key << " " << cur->type << "  ";
            }
            cout << endl;

        }

        void moveFront(node* n) {
            if (head == n) return; //Node is already in front
            else if (tail == n) { //Node is the tail
                n->prev->next = NULL;
                tail = n->prev;
            }
            else { //Node is somewhere in the middle
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }
            //Make node the head
            head->prev = n;
            n->next = head;
            n->prev = NULL;
            head = n;
        }


        void moveBack(node* n) {
            if (n == tail) return; //Node is already in back
            else if (n == head) { //Node is the head
                n->next->prev = NULL;
                head = n->next;
            }
            else { //Node is somewhere in the middle
                n->next->prev = n->prev;
                n->prev->next = n->next;
            }
            //Make node the tail
            tail->next = n;
            n->prev = tail;
            tail = n;
            n->next = NULL;
        }



        void out(int k, char t = 'f') {
        //Output function
            int i = 0;
            node *cur;
            if (t == 'f') { //Prints forwards
                cur = head;
                while (i < k) {
                    cout << cur->key << " " << cur->type << "  ";
                    cur = cur->next;
                    i++;
                }
            }
            else if (t == 'b') { //Prints backwards
                cur = tail;
                while (i < k) {
                    cout << cur->key << " " << cur->type << "  ";
                    cur = cur->prev;
                    i++;
                }
            }
            cout << endl;
        }


        void sort() {
            head = mergeSort(head);
            //Update tail 
            for (node *cur = head; cur != NULL; cur = cur->next) {
                if (cur->next == NULL)
                    tail = cur;
            }
        }
};

