/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() {
  // @TODO: graded in MP3.1
     head_ = NULL;
     tail_ = NULL;
     length_=0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1

  return List<T>::ListIterator(tail_->next);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */






template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode* temp;
  temp=head_;
  while(temp!=NULL){
    ListNode* next=temp->next;
    delete temp;
    temp=NULL;
    temp=next;
  }
  head_=NULL;
  tail_=NULL;
  length_=0;

}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);


  if (head_== NULL) {
    head_=newNode;
    tail_=newNode;
    head_->prev=NULL;
    head_->next=NULL;
    tail_->prev=NULL;
    tail_->next=NULL;
  }
  else{
    head_->prev=newNode;
    newNode -> next = head_;
    newNode -> prev = NULL;
    head_=newNode;
  }


  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);


  if (head_== NULL) {
    head_=newNode;
    tail_=newNode;
    head_->prev=NULL;
    head_->next=NULL;
    tail_->prev=NULL;
    tail_->next=NULL;
  }
  else{
    tail_ -> next = newNode;
    newNode->prev=tail_;
    newNode -> next = NULL;
    tail_=newNode;
  }


  length_++;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode* temp=start;

   for (int i=0; i<splitPoint;i++){
     temp=temp->next;
     if(temp==NULL) return NULL;
     }



     if(temp->prev!=NULL){
       temp->prev->next = NULL;
   	  temp->prev = NULL;

     }

     return temp;
}
/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
if(head_==NULL || tail_==NULL) return;
ListNode* temp=head_->next;
ListNode* skip=temp;
while(temp!=NULL && temp!=tail_){
  if(temp->next!=NULL){
    temp->next->prev=temp->prev;
    skip=temp->next;
    temp->prev->next=temp->next;
  }

  tail_->next=temp;
  temp->next=NULL;
  temp->prev=tail_;
  tail_=temp;
  temp=skip->next;
}



}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  ListNode* temp=NULL;
  ListNode* current=startPoint;
  ListNode* before=startPoint->prev;
  ListNode* after=endPoint->next;
  while(current!=after){
    temp=current->prev;
    current->prev=current->next;
    current->next=temp;
    current=current->prev;
  }
  if(temp!=NULL){
    temp=endPoint;
    endPoint=startPoint;
    startPoint=temp;
  }
  endPoint->next=after;
  if (after!=NULL) after->prev=endPoint;
  startPoint->prev=before;
  if (before!=NULL) before->next=startPoint;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  if(head_==NULL || tail_==NULL || n<=0) return;
  ListNode* startPoint=head_;
  ListNode* endPoint=head_;
  if(n>=size()) {
    reverse();
    return;
  }
  for(int i=1;i<n;i++){
     if (endPoint->next!=NULL) endPoint=endPoint->next;
  }
  reverse(head_,endPoint);
  while(endPoint->next!=NULL){
    startPoint=endPoint->next;
    for(int i=1;i<=n;i++){
       if (endPoint->next!=NULL) endPoint=endPoint->next;
    }
    reverse(startPoint,endPoint);

   }

 }



  /// @todo Graded in MP3.2



/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  ListNode* f=first->next;
  ListNode* s=second->next;
  ListNode* r=NULL;
  ListNode* result=NULL;

  if(first->data<second->data){
    result=first;
    result->prev=NULL;
    result->next=NULL;
    r=result;
    first=f;
  }
  else{
    result=second;
    result->prev=NULL;
    result->next=NULL;
    r=result;
    second=s;

  }
  while(first!=NULL || second!=NULL){
    if(first!=NULL && second!=NULL){
      if(first->data<second->data){
        first->prev=r;
        r->next=first;
        first=first->next;
        r=r->next;
      }
      else{
        second->prev=r;
        r->next=second;
        second=second->next;
        r=r->next;

      }
    }
    else if (first!=NULL){
      if(first==r) first=first->next;
      if(first==NULL) break;
      first->prev=r;
      r->next=first;
      first=first->next;
      r=r->next;

    }
    else{
      if(second==r) second=second->next;
      if(second==NULL) break;
      second->prev=r;
      r->next=second;
      second=second->next;
      r=r->next;


    }
  }
  return result;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
if(chainLength==1 || chainLength==0) return start;
int len1=chainLength/2;
int len2=chainLength-len1;
ListNode* middle=split(start,len1);
return merge(mergesort(start,len1),mergesort(middle,len2));
}
