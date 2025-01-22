#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_; 
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  // Case 1: List is empty so we initialize head/tail with a new item
  if(head_ == nullptr){
    head_ = tail_ = new Item();
    head_->val[head_->last++] = val;
  // Case 2: Tail array is full at the back so we allocate a new item and adjust tail
  } else if(tail_->last == ARRSIZE){
    tail_->next = new Item();
    Item* temp = tail_;
    tail_ = tail_->next;
    tail_->prev = temp;
    tail_->val[tail_->last++] = val;
  // Case 3: Otherwise, there's space in an existing item so we add the item and change the value of last
  } else {
    tail_->val[tail_->last++] = val;
  }
  size_++;
}

void ULListStr::pop_back() {
  // Case 1: The list is empty so we do nothing
  if(head_ == nullptr)
    return;
  // Case 2: The tail array has one element, so we adjust tail and deallocate
  if(tail_->first == tail_->last - 1){
    Item* temp = tail_;
    if(tail_ == head_) // If there is only one item, then we need to set head/tail to nullptr
      tail_ = head_ = nullptr;
    else{
      tail_ = tail_->prev;
      if(head_ == tail_) // If there is only one item left, we set next to nullptr
        head_->next = nullptr;
    }
    delete temp;
  // Case 3: The tail array has >1 element, so we clear the last element and decrement last
  } else {
    tail_->val[--tail_->last] = "";
  }
  size_--;
}
  
void ULListStr::push_front(const std::string& val) {
  // Case 1: List is empty so we initialize head/tail with a new item
  if(head_ == nullptr){
    head_ = tail_ = new Item();
    head_->val[head_->last++] = val;
  // Case 2: Head array is full at front so we allocate a new item and adjust tail
  } else if(head_->first == 0){
    head_->prev = new Item();
    Item* temp = head_;
    head_ = head_->prev;
    head_->next = temp;
    head_->val[ARRSIZE - 1] = val;
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
  // Case 3: Otherwise, there's space in an existing item so we add the item and change the value of first
  } else {
    head_->val[--(head_->first)] = val;
  }
  size_++;
}

void ULListStr::pop_front() {
  // Case 1: The list is empty so we do nothing
  if(head_ == nullptr)
    return;
  // Case 2: The head array has one element, so we adjust head and deallocate
  if(head_->first == head_->last - 1){
    Item* temp = head_;
    if(tail_ == head_) // If there is only one item, then we need to set head/tail to nullptr
      tail_ = head_ = nullptr;
    else{
      head_ = head_->next;
      if(head_ == tail_) // If there is only one item left, we set next to nullptr
        tail_->prev = nullptr;
    }
    delete temp;
  // Case 3: The head array has >1 element, so we clear the front element and increment first
  } else {
    head_->val[head_->first++] = "";
  }
  size_--;
}
  
std::string const & ULListStr::back() const {
  if(head_ == nullptr)
    throw std::invalid_argument("Can't access because does not exist.");
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  if(head_ == nullptr)
    throw std::invalid_argument("Can't access because does not exist.");
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  //If invalid location or no list we return nullptr for get to throw exception
  if(loc < 0 || loc >= size_ || head_ == nullptr)
    return nullptr;
  
  // Traverse the list to find the appropriate Item then return the value
  Item* t = head_;
  while(true){
    // We essentially mod location to get to the correct item
    if(t->last - t->first <= loc){ 
      loc -= t->last - t->first;
      t = t->next;
    // If we are in the right array we return the address of the value
    } else {
      return &t->val[t->first + loc];
    }
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == nullptr){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == nullptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == nullptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != nullptr){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = nullptr;
  size_ = 0;
}
