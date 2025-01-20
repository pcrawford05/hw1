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
  if(head_ == nullptr){
    head_ = tail_ = new Item();
    head_->val[head_->last++] = val;
  } else if(tail_->last == ARRSIZE){
    tail_->next = new Item();
    Item* temp = tail_;
    tail_ = tail_->next;
    tail_->prev = temp;
    tail_->val[tail_->last++] = val;
  } else {
    tail_->val[tail_->last++] = val;
  }
  size_++;
}

void ULListStr::pop_back() {
  if(head_ == nullptr)
    return;
  if(tail_->first == tail_->last - 1){
    Item* temp = tail_;
    if(tail_ == head_)
      tail_ = head_ = nullptr;
    else{
      tail_ = tail_->prev;
      if(head_ == tail_)
        head_->next = nullptr;
    }
    delete temp;
  } else {
    tail_->val[--tail_->last] = "";
  }
  size_--;
}
  
void ULListStr::push_front(const std::string& val) {
  if(head_ == nullptr){
    head_ = tail_ = new Item();
    head_->val[head_->last++] = val;
  } else if(head_->first == 0){
    head_->prev = new Item();
    Item* temp = head_;
    head_ = head_->prev;
    head_->next = temp;
    head_->val[ARRSIZE - 1] = val;
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
  } else {
    head_->val[--(head_->first)] = val;
  }
  size_++;
}

void ULListStr::pop_front() {
  if(head_ == nullptr)
    return;
  if(head_->first == head_->last - 1){
    Item* temp = head_;
    if(tail_ == head_)
      tail_ = head_ = nullptr;
    else{
      head_ = head_->next;
      if(head_ == tail_)
        tail_->prev = nullptr;
    }
    delete temp;
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
  if(loc < 0 || loc >= size_ || head_ == nullptr)
    return nullptr;
  Item* t = head_;
  while(true){
    if(t->last - t->first <= loc){
      loc -= t->last - t->first;
      t = t->next;
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
