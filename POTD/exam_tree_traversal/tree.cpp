#ifndef TREE_CPP
#define TREE_CPP

#include "tree.h"

template <class T>
Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
	// TODO: your code here

	while(curr_!=NULL) {
		stack_.push(curr_);
		curr_=curr_->right_;
	}

	if(!stack_.empty()) curr_ = stack_.top();
	else curr_ = NULL;



	while ( !stack_.empty()  && (stack_.top()->data_)==NULL){
		curr_=stack_.top();
		stack_.pop();

		if(curr_!=NULL) {
			curr_=curr_->left_;
			while(curr_!=NULL){
				stack_.push(curr_);
				curr_=curr_->right_;
		 }
	 }

	if(!stack_.empty()) curr_=stack_.top();
	else curr_=NULL;

}
//if(stack_.empty()) curr_=NULL;


}

template <class T>
typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
	// TODO: your code here


	if(!stack_.empty()){
	curr_=stack_.top();
	stack_.pop();

	 if(curr_!=NULL) {
		  curr_=curr_->left_;
		  while(curr_!=NULL){
				stack_.push(curr_);
				curr_=curr_->right_;
		 }
	 }

	if(!stack_.empty()) curr_=stack_.top();
	else curr_=NULL;

	}
	else curr_=NULL;




		while ( !stack_.empty()  && (stack_.top()->data_)==NULL){
			curr_=stack_.top();
			stack_.pop();

			if(curr_!=NULL) {
	 		  curr_=curr_->left_;
	 		  while(curr_!=NULL){
	 				stack_.push(curr_);
	 				curr_=curr_->right_;
	 		 }
	 	 }

	 	if(!stack_.empty()) curr_=stack_.top();
	 	else curr_=NULL;

	}


	//if(stack_.empty()) curr_=NULL;






	return *this;
}

template <class T>
T Tree<T>::Iterator::operator*() const {
	// TODO: your code here
	if (!stack_.empty()){
	return curr_->data_;
}

	return T(); // remove this line
}



/*******************
 ** PROVIDED CODE **
 *******************/
template <class T>
bool Tree<T>::Iterator::operator!=(const Tree<T>::Iterator &other) {
	return !(curr_ == other.curr_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::begin() {
	return Iterator(root_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::end() {
	return Iterator(NULL);
}

#endif
