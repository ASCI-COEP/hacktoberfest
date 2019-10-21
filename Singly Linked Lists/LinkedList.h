#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
using namespace std;

template <typename V>
class SingleLinkedList;

template <typename type>
class Node{
    type data;
    Node * next;
    public:
        Node() : next(0), data(0) {}
        Node(type d) : next(0), data(d) {}
        Node(const type &d) : next(0), data(d) {}
        Node(const Node &n) : next(0), data(n.data) {}
        type getData() const{
            return data;
        }
        template <typename U>
            friend class SingleLinkedList;
        template <typename U>
            friend ostream & operator<<(ostream &, const SingleLinkedList<U> &);
};

template <typename T>
class SingleLinkedList {
    Node<T> * head;
    static int sharedmemory;
    //COPY HELPER
    void copyas(const SingleLinkedList & L){
        //CANNOT CHANGE THE DATA POINTED TO BY THIS POINTER (CONST)
        //BUT CAN CHANGE THE POINTER VALUE
        const Node<T> * it = L.head;
        Node<T> * tail = 0;
        while(it){
            Node<T> *temp = new Node<T>(*it);
            if(!head){
                head = tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            it = it->next;
        }
        return;
    }

    public:
    SingleLinkedList(): head(0) {}
    SingleLinkedList(const SingleLinkedList & L) : head(0) {
        copyas(L);
    }

    //CLEAR LL
    void clear() {
        while(head){
            Node<T> * temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~SingleLinkedList() {
        clear();
        //(*this).clear();
        //this->clear;
    }

    // ++ OPERATOR OVERLOADING
    // PRE INCREMENT OPERATOR
    SingleLinkedList & operator++(){
        Node<T> * it = head;
        while(it){
            it->data++;
            it = it->next;
        }
        return *this;
    }
    
    // ++(INT DUMMY) OPERATOR OVERLOADING
    // POST INCREMENT OPERATOR
    SingleLinkedList  operator++(int dummy){
        SingleLinkedList temp = *this;
        ++(*this);
        return temp;
    }
    
    // = OPERATOR OVERLOADING
    SingleLinkedList & operator=(const SingleLinkedList & L){
        clear();
        copyas(L);
        return *this;
    }

    // += OPERATOR OVERLOADING
    SingleLinkedList & operator+=(const T & el){
        insertAtTheEnd(el);
        return *this;
    }

    // +=(CONST SINGLELINKEDLIST &L) OPERATOR OVERLOADING
    SingleLinkedList & operator+=(const SingleLinkedList & L){
        SingleLinkedList temp(L);
        if(!head){
            head = temp.head;
        } else {    
            Node<T> * it = head;
            while(it->next){
                it = it->next;
            }
            it->next = temp.head;
        }
        temp.head = 0;
        return *this;
    }

    // +(CONST SINGLELINKEDLIST &L) OPERATOR OVERLOADING
    SingleLinkedList operator+(const SingleLinkedList & L){
        SingleLinkedList ans = *this;
        SingleLinkedList ansright = L;
        if(!ans.head){
            return ansright;
        }
        Node<T> * temp = ans.head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = ansright.head;
        ansright.head = 0;
        return ans;
    }
    
    //FIND ELEMENT AT POS K
    Node<T> & findElementAtPosK(T &k){
        Node<T> *temp = head;
        k--;
        while(k--)
            temp = temp->next;

        return temp;
    }
   
    // Find Kth Node From End | K < length of LL
    Node<T> & findKthNodeFromEnd(T &k) {
        Node<T> *it1 = head;
        Node<T> *it2 = head;
        while(k--)
            it2 = it2->next;

        while(it2) {
            it1 = it1->next;
            it2 = it2->next;            
        }
        return *it1;
    }    
    /*
     // This solution is also true
    Node<T> & findKthNodeFromEnd(T &k) {
       int len = 1;
       Node<T> *temp = head; 
       while(temp){
           len++;
           temp = temp->next;
       }
       return findElementAtPosK(len-k+1);
    }
    */
    //INSERT AT THE HEAD
    void insertAtTheHead(const T & d){
        Node<T> * temp = new Node<T>(d);
        temp->next = head;
        head = temp;
        return;
    }
    
    //DELETE FROM HEAD
    void deleteFromHead(){
        if(!head) return;
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        return;
    }

    //INSERT AT THE END
    void insertAtTheEnd(const T&);

    //DELETE FROM END
    void deleteAtTail(){
        if(!head) return;
        Node<T> * temp = head;
        if(temp->next == NULL){
            delete temp; 
            return;
        }
        while(temp->next->next){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        return;
    }

    //INSERT AT POS K | STARTING INDEX IS 0
    void insertAtPosK(const T &d, T &k){
        if( k < 0 ){
            cout << "Negative positions are not permitted" << endl;
            return;
        }

        Node<T> *temp = new Node<T>(d);
        if ( k == 0 ){
            temp->next = head;
            head = temp; 
            return;
        }
        Node<T> *it = head;
        k--;
        while(k--){
            it = it->next;
            if(it == NULL){
                cout << "Position is beyond Linked List Length" << endl;
                return;
            }
        }
        temp->next = it->next;
        it->next = temp;
        return;
    }

    //DELETE AT POS K | STARTING INDEX IS 0
    void deleteAtPosK(T &k){
        if(k == 0) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T> * it = head;
        k--;
        while(k--){
            if(it == NULL){
                cout << "Position does not exist in Linked List" << endl;
                return;
            }
            it = it->next;
        }
        Node<T> *temp = it->next;
        it->next = temp->next;
        delete temp;
        return;
    }

    //DELETE AT POS K FROM END
    Node<T> & deleteAtPosKFromEnd(int n){
        if(!head)
            return *this;
        
        Node<T> *it1 = head;
        Node<T> *it2 = head;
        while(n--) {
            it2 = it2->next;
            if(it2 == NULL && n==0){
                Node<T> * temp = head;
                head = head->next;
                delete temp;
                return *this;
            }
            if(it2 == NULL) {
                return *this;
            }
        }

        while(it2->next != NULL) {
            it1 = it1->next;
            it2 = it2->next;
        }
        Node<T> * temp = it1->next;
        it1->next = temp->next;
        delete temp;
        return *this;
    }

    //FIND MIDDLE
    Node<T> *findMiddle() const {
        if(!head)
            return NULL;
        Node<T> *it1 = head;
        Node<T> *it2 = head;
        while(it2 != NULL && it2->next !=NULL) {
            it1 = it1->next;
            it2 = it2->next->next;
        }
        return it1;
    }

    //PRINT REVERSE LINKKEDLIST
    void printReverse() const {
        printReverseHelper(head);
    }

    //PRINT REVERSE HELPER
    private:
    static void printReverseHelper(const Node<T> * head){
        if(!head) return;
        printReverseHelper(head->next);
        cout << head->data << "-->";
        return;
    }
    
    //PRINT LINKEDLIST
    public:
    void printList() const{
        Node<T> *it = head;
        while(it){
            cout<<it->data<<"-->";
            it = it->next;
        }
        cout<<"NULL"<<endl;
        return;        
    }
    
    //MERGE TWO SORTED LINKED LIST
    SingleLinkedList merge(SingleLinkedList &L){
        if(!head)
            return L.head;
        if(!L.head)
            return head;

        Node<T> *it1 = head;
        Node<T> *it2 = L.head;
        SingleLinkedList Ltemp;

        while(it1 && it2){
            if(it1->data < it2->data){
                Ltemp.insertAtTheEnd(it1->data);
                it1 = it1->next;
            } else {
                Ltemp.insertAtTheEnd(it2->data);
                it2 = it2->next;
            }
        }

        while(it1){
            Ltemp.insertAtTheEnd(it1->data);
            it1 = it1->next;
        }

        while(it2){
            Ltemp.insertAtTheEnd(it2->data);
            it2 = it2->next;
        }

        return Ltemp;
    }

    //MERGE K SORTED LISTS
    /* struct ListNode{
     *  int val;
     *  ListNode * next;
     *  ListNode(int x): val(x), next(NULL){}
     * };
     */
    Node<T> * mergeKLists(vector<ListNode*>& lists){
        if(lists.size() < 1)
            return NULL;

        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.front());
            lists.erase(lists.front());
        }
        return lists.front();
    }

    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2){
        if(!l1)
            return l2;

        if(!l2)
            return l1;

        ListNode * ans = NULL;
        ListNode * prev = NULL;
        while(l1 && l2){
            if(l1->val < l2->val){
                if(!ans)
                    ans = prev = new ListNode(l1->val);

                else{
                    prev->next = new ListNode(l1->val);
                    prev = prev->next;
                }
                l1 = l1->next;
            }
            else{
                if(!ans)
                    ans = prev = new ListNode(l2->val);
                else{
                    prev->next = new ListNode(l2->val);
                    prev = prev->next;
                }
                l2 = l2->next;
            }
        }

        while(l1)}{
            prev->next = new ListNode(l1->val);
            prev = prev->next;
            l1 = l1->next;
        }

        while(l2){
            prev->next = new ListNode(l2->val);
            prev = prev->next;
            l2 = l2->next;
        }
        return ans;
    }

    //GET LENGTH OF LINKEDLIST
    int getLength(){
        if(!head) return 0;
        Node<T> *temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    //REVERSE LINKED LIST
    void reverse(){
        Node<T> *prev = NULL;
        Node<T> *current = head;
        Node<T> *next;

        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void reverseRecursive(){
        reverseRecursiveHelper(head);
    }

    void reverseRecursiveHelper(Node<T> *head){
        // Empty List
        if(!head)
            return;

        // Suppose first={1,2,3,4}, rest={2,3,4}
        Node<T> *first = head;
        Node<T> *rest = first->next;

        // List has only one node
        if(!rest){
			// Fix head pointer | rest = {4}
			head = first;
            return;
		}

        // Reverse the rest list & put the first
        // element at the end
        reverseRecursiveHelper(rest);

        first->next->next = first;

        // Tricky Step
        // 1->2<-3<-4 ==> NULL<-1<-2<-3<-4
        first->next = NULL;

    }

    //REVERSE IN GROUPS OF K
    void reverseInGroupsOfK(const T &k) {
        head = reverseInGroupsOfKHelper(head, k);
    }
    
    private:
    Node<T> * reverseInGroupsOfKHelper(Node<T> *node,const T k) {
        Node<T> *prev = NULL;
        Node<T> *current = node;
        Node<T> *next = NULL;
        T group = k;

        while(current != NULL && group--) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        if(next != NULL) {
            node->next = reverseInGroupsOfKHelper(next, k);
        }

        return prev;
    }

    public:
    //REVERSE FROM HEAD TO Kth NODE
    void reverseTillK(const T &k) const{
        reverseTillKHelper(head, k);
    }
    
    private:
    //REVERSE TILL K HELPER
    void reverseTillKHelper(Node<T> *node, T k) {
        Node<T> *prev = NULL;
        Node<T> *current = node;
        Node<T> *next = NULL;
       while(current!=NULL && k>0) {
           next = current->next;
           current->next = prev;
           prev = current;
           current = next;
           k--;
       }
       head->next = current;
       head = prev;
    }

    public:
    //REVERSE FROM M TO N
    void reverseFromMtoN(const T &m,const T &n) {
        if(m == 1)
            reverseTillKHelper(head, n);
        else {
            Node<T> *temp = head;
            T it = m-2;
            while(it--)
               temp = temp->next;          
            reverseFromMtoNHelper(temp, n-m+1);
        }
    }
    private:
    //REVERSE FROM M TO N HELPER
    void reverseFromMtoNHelper(Node<T> *node, T m) {
        Node<T> *temp = node;
        Node<T> *prev = NULL;
        Node<T> *current = node->next;
        Node<T> *next = NULL;
        while(current!=NULL && m>0) {
           next = current->next;
           current->next = prev;
           prev = current;
           current = next;
           m--;
       }
       
       temp->next->next = current;
       temp->next = prev;
    }

    public:
    //DETECT LOOP IN LL
    bool detectLoop() {
        if(!head) return false;
        Node<T> *slow = head;
        Node<T> *fast = head->next;
        while(fast && fast->next){
            if(slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }

    // Find LOOP NODE
    Node<T> * findLoopNode(){
        Node<T> *slow = head;
        Node<T> *fast = head;
        while(slow != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return findLoopNodeHelper(slow, head);
        }
        return NULL; 
    }

    private:
    Node<T> * findLoopNodeHelper(Node<T> *slow, Node<T> *head){
        while(slow != head){
            slow = slow->next;
            head = head->next;
        }
        return slow;

    }

    //REMOVE LOOP
    public:
    void removeLoop(){
        Node<T> *loopNode = findLoopNode();

        if(loopNode == NULL)
            return;

        Node<T> *temp = loopNode->next;
        while(temp->next != loopNode)
            temp = temp->next;

        temp->next = NULL;
    }

    //COPY LIST WITH RANDOM POINTER
    /* Definition for singly-linked list with random ptr
     * struct RandomListNode{
     *  int label;
     *  RandomListNode *next, *random;
     *  RandomListNode(int x) : label(x), next(NULL), random(NULL){}
     * };
     */

    RandomListNode *copyRandomList(RandomListNode *head){
        if(!head)
            return head;

        map<RandomListNode*, RandomListNode*> mymap;

        RandomListNode * temp = head;

        while(temp){
            mymap.insert({temp, new RandomListNode(temp->label)});
            temp = temp->next;
        }

        temp = head;
        while(temp){
            mymap[temp]->next = mymap[temp->next];
            mymap[temp]->random = mymap[temp->random];
            temp = temp->next;
        }

        return mymap[head];
    }
    
    //ROTATE LINKED LIST
    /* This function rotates a linked list counter-clockwise and
     * updates the head. The function assumes that k is smaller
     * than size of linked list. It doesn't modify the list if
     * k is greater than or equal to size.
     */
    void rotate(Node<T> *head, int k){
        if(k==0)
            return;

        // Let k=4 and LL = 10->20->30->40->50->60
        Node<T> * current = head;

        // Get kthNode
        int count=1;
        while(count<k && current != NULL){
            current = current->next;
            count++;
        }// current == 40

        if(current == NULL)
            return;

        Node<T> *kthNode = current;

        // Take current to last Node
        while(current->next != NULL)
            current = current->next;
        //current == 60

        // Change next of last node to head
        current->next = head;

        // Change head to (k+1)th Node
        head = kthNode->next;

        // Change next of kthNode to NULL
        kthNode->next = NULL;
    }

    //FLATTEN LL
    /* 5 -> 10 -> 19  ( Sorted Horizontally )
     * |     |     |
     * \/    \/    \/
     * 7     20    22  ( Sorted Vertically Also )
     * |           |
     * \/          \/
     * 30          50
     * ans = 5->7->10->19->20->22->30->50 ( Sorted )
     */
    Node<T> *flatten(){
        // Base cases
        if(!head || !(head->right))
            return head;

        // Merge this list with the list on right side
        return mergeFlatten(head, flatten(head->right);
    }

    private:
    Node<T> * mergeFlatten(Node<T> *a, Node<T> *b){
        // If first list empty, return second
        if(!a)
            return b;

        // If second list empty, return first
        if(!b)
            return a;

        // Compare the data members of head nodes of
        // both lists and put the smaller one in result
        Node<T> *result;
        if(a->data < b->data){
            result = a;
            result->down = mergeFlatten(a->down, b);
        }
        else{
            result = b;
            result->down = mergeFlatten(a, b->down);
        }
        return result;
    }

    public:
    //GET INTERSECTION POINT OF TWO LINKED LIST
    /* 1
     *  \
     *   2   0
     *    \ /
     *     3
     *     |
     *     4
     *     |
     *     5
     * ANS = 3 ( Intersection Point )
     */
    T getIntersectionPointOfTwoLL(const SingleLinkedList &L){
        int c1 = this->getLength();
        int c2 = L.getLength();

        if(c1 > c2){
            int diff = c1-c2;
            return getIntersectionPointHelper(diff, head, L.head);
        }
        else{
            int diff = c2-c1;
            return getIntersectionPointHelper(diff, L.head, head);
        }
    }
    private:
    T getIntersectionPointHelper(int diff, Node<T> *a, Node<T> *b){
        Node<T> *t1 = a;
        Node<T> *t2 = b;
        while(diff--)
            t1 = t1->next;

        while(t1 && b){
            if(t1 == t2)
                return t1->data;
            t1 = t1->next;
            t2 = t2->next;
        }

        return -1;
    }

    public:
    //ADD TWO NUMBERS REPRESENTED BY LL ( SET 1 )
    /* first list : 7->5->9->4->6 | represents number 64957
     * second list: 8->4 | represents number 48
     * Output
     * Resultant list: 5->0->0->5->6 | 65005
     */
    SingleLinkedList addTwoLists(const SingleLinkedList &first,const SingleLinkedList &second){
        SingleLinkedList result;
        Node<T> *prev = NULL;
        int carry=0, sum;

        while(first || second){
            /* Calculate value of next digit in resultant list.
             * The next digit is sum of following things
             * (i)   Carry
             * (ii)  Next digit of first list ( if exists )
             * (iii) Next digit of second list( if exists )
             */
            sum = carry + ((first) ? first->data : 0) +
                             ((second) ? second->data : 0);

            // Update carry for next calculation
            carry = (sum>=10) ? 1 : 0;

            // Update sum if it is greater than 10
            sum = sum % 10;

            // Create new node with sum as data
            Node<T> *temp = new Node(sum);

            // If this is first node of result
            if(result.head == NULL)
                L.head = temp;
            // ELse connect it to the rest
            else
                prev->next = temp;

            // Set prev for next insertion
            prev = temp;

            if(first) first = first->next;
            if(second) second = second->next;
        }

        if(carry)
            prev->next = new Node(carry);

        return result;
    }

    //ADD TWO NUMBERS REPRESENTED BY LL (SET 2)
    /* First List: 5->6->3 | Represents Number 563
     * Second List:8->4->2 | Represents Number 842
     * Output
     * Resultant List:1->4->0->5 | 1405
     */

    /* 1.Calculate sizes of given two linked list
     * 2.If sizes are same, then calculate sum using recursion.
     *   Hold all nodes in recursion call stack till the
     *   rightmost node, calculate sum of rightmost nodes and
     *   forward carry to left side.
     * 3.If size is not same, then:
     *      a)Calculate diff of sizes. (diff)
     *      b)Move diff nodes ahead in the bigger LL.
     *        Now use step 2 to calculate sum of smaller list
     *        and right sub-list (of same size) of larger list.
     *        Also, store the carry of this sum.
     *      c)Calculate sum of the carry (calculated in prev step)
     *        with the remaining left sub-list of larger list.
     *        Nodes of this sum are added at the beginning of
     *        sum list obtained previous step.
     */
    SingleLinkedList addTwoLists2(const SingleLinkedList &first, const SingleLinkedList &second) {
        SingleLinkedList result;
        if(!first.head)
            return second;

        else if(!second.head)
            return first;

        int size1 = first.getLength();
        int size2 = second.getLength();

        int carry = 0;

        // Add same size lists
        if(size1 == size2)
            result.head = addSameSize(first, second, &carry);
            
        else{
            int diff = abs(size1-size2);

            //First List should always be larger than second list.
            //If not, swap pointers
            if(size1 < size2)
                swapPointer(&L1.head, &L2.head);

            //Move forward diff number of nodes in first list
            for(Node<T> *cur = L1.head; diff--; cur=cur->next);

            //Get addition of same size lists
            result.head = addSameSize(cur, L2.head, &carry);

            //Get addition of remaining first list and carry
            addCarryToRemaining(L1.head, cur, &carry, result);
        }

        //If some carry is still thre, add a new node to the front
        // of the result list
        if(carry)
            result.insertAtTheHead(carry);

        return result;
    }
    private:
    void swapPointer(Node<T> **a, Node<T> **b){
        Node<T> *temp = *a;
        *a = *b;
        *b = temp;
    }


    Node<T> *addSameSize(Node<T> *head1, Node<T> *head2, int *carry){
        if(!head1)
            return NULL;
        if(!head2)
            return NULL;

        int sum;

        Node<T> *ans = new Node();

        ans->next = addSameSize(head1->next, head2->next, carry);

        sum = head1->data + head2->data + *carry;
        *carry = sum/10;
        sum = sum%10;

        ans->data = sum;
        return ans;
    }

    void addCarryToRemaining(Node<T> *head1, Node<T> *cur, int *carry, SingleLinkedList &result){
        int sum;

        if(head1 != cur){
            addCarryToRemaining(head->next, cur, carry, result);

            sum = head1->data + *carry;
            *carry = sum/10;
            sum %= 10;

            result.insertAtTheHead(sum);
        }            
    }

    public:
    //CHECK IF LIST IS PALINDROME
    bool isPalindrome(){
        return isPalindromeHelper(&head, head);
    }

    private:
    bool isPalindromeHelper(Node<T> **left, Node<T> *right){
        // When at lastnode->next i.e. NULL ... return true
        // to backtrack
        if(!right)
            return true;

        // Recurse till last node
        bool isp = isPalindromeHelper(left, right->next);
        if(!isp)
            return false;

        // Check if data matches at first and last node
        // of sub-list
        bool isp_data = ( (*left)->data == right->data );

        *left = (*left)->next;

        return isp_data;
    }

    public:
    //SORT LINKED LIST OF 0s 1s 2s

    /* Count the number of 0s=a 1s=b and 2s=c
     * Fill first a nodes with 0.
     * Next b nodes with 1.
     * Next c nodes with 2.
     */

    /* !----- BY CHANGING LINKS -----!
     * Make 3 list of 0s 1s and 2s
     * Link all three lists
     */

    void sortList0s1s2s(){
        if(!head || !(head->next))
            return;

        // Pointers to 0,1,2 Dummy List
        // Created to avoid many NULL checks
        Node<T> *zeroD = new Node();
        Node<T> *oneD = new Node();
        Node<T> *twoD = new Node();

        Node<T> *zero = zeroD, *one = oneD, *two = twoD;
        Node<T> *cur = head;
        while(cur){
            if(cur->data == 0){
                zero->next = cur;
                zero = zero->next;
            }
            else if(cur->data == 1){
                one->next = cur;
                one = one->next;
            }
            else{
                two->next = cur;
                two = two->next;
            }
            cur = cur->next;
        }

        //Attach three lists
        zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
        one->next = twoD->next;
        two->next = NULL;

        //Update Head
        head = zeroD->next;

        //Delete dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;
    }
    
    //GIVEN POINTER TO THE GIVEN NODE, DELETE IT, W/O HEAD POINTER GIVEN
    void deleteNode(Node<T> *delNode){
        if(delNode->next == NULL)
            cout << "Can't delete last node with these constraints" << endl;

        else{
            delNode->data = delNode->next->data;
            Node<T> *temp = delNode->next;
            delNode->next = delNode->next->next;
            delete temp;
        }
    }

    //PARTITION LIST
    /*Given a linked list and a value x, 
     * partition it such that all nodes less than x 
     * come before nodes greater than or equal to x.
     * You should preserve the original relative order 
     * of the nodes in each of the two partitions.
     * For example,
     * Given 1->4->3->2->5->2 and x = 3,
     * return 1->2->2->4->3->5.
     *
     * Sol: Make 2 different list
     *      i) Containing Values  <  x
     *      ii)Containing Values  >= x
     *      Join the two list and return.
     */
    Node<T> *partition(Node<T> *head, int x){
        Node<T> node1(0), node2(0);
        Node<T> *p1 = &node1, *p2 = &node2;
        while(head){
            if(head->data < x)
                p1 = p1->next = head;
            else
                p2 = p2->next = head;
            head = head->next;
        }
        p2->next = NULL;
        p1->next = node2.next;
        return node1.next;
    }

    //GET SHARED MEMORY DATA
    int getDataForSharedMemory(){
        return sharedmemory;
    }

    //INCREMENT SHARED MEMORY DATA
    void incrementSharedMemory(){
        sharedmemory++;
    }

    //FRIEND FUNCTION DECLARATION
    friend void friendFunction();

    //FRIEND FUNCTIOND DECLARATION | OPERATOR OVERLOADING
    template<typename U>
    friend ostream & operator<<(ostream &, const SingleLinkedList<U> &);
};

//STATIC MEMBER INITIALIZATION
template<typename T>
int SingleLinkedList<T>::sharedmemory=10;

//OPERATOR OVERLOADING FUNCTION (FRIEND TO CLASS)
template<typename T>
ostream & operator<<(ostream & out, const SingleLinkedList<T> &L){
    const Node<T> * it = L.head;
    while(it){
        out<< it->data << "-->";
        it = it->next;
    }
    cout << "NULL" << endl;
    return out;
}

//FUNCTION (FRIEND TO CLASS)
void friendFunction(){
    //Do any work. 
    return;
}

//FUNCTION DEFINITION OF INSERTATTHEEND
template<typename T>
void SingleLinkedList<T>::insertAtTheEnd(const T &d){
    Node<T> * temp = new Node<T>(d);
    if(!head){
        head = temp;
        return;
    }
    Node<T> *it = head;
    while(it->next){
        it = it->next;
    }
    it->next = temp;
    return;
}

int & getValue() {
    static int x = 10;
    x++;
    return x;
}
#endif
