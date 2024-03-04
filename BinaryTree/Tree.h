#pragma once

template <class T>
class TreeNode {
private:
	T value;
	TreeNode<T>* right = nullptr;
	TreeNode<T>* left = nullptr;
public:
	TreeNode(const T& value) {
		this->value = value;
	}
	TreeNode<T>* getLeft() const {
		return left;
	}
	TreeNode<T>* getRight() const {
		return right;
	}
	void setLeft(TreeNode<T>* node) {
		left = node;
	}
	void setRight(TreeNode<T>* node) {
		right = node;
	}
	const T& getValue() const {
		return value;
	}
	void setValue(const T& value) {
		this->value = value;
	}
	~TreeNode() {
		delete right;
		delete left;
	}
};

template <class T>
class Tree {
private:
	TreeNode<T>* root;
public:
	Tree() {
		root = nullptr;
	}
	void setRoot(TreeNode<T>* node) {
		root = node;
	}
	TreeNode<T>* getRoot() {
		return root;
	}
	void printPreorder(TreeNode<T>* parent) {
		if (parent == nullptr) {
			return;
		}
		std::cout << parent->getValue() << std::endl;
		printPreorder(parent->getLeft());
		printPreorder(parent->getRight());
	} 
	void printPreorder() {
		printPreorder(root);
	}
	void printInorder(TreeNode<T>* parent) {
		if (parent == nullptr) {
			return;
		}
		printInorder(parent->getLeft());
		std::cout << parent->getValue() << std::endl;
		printInorder(parent->getRight());
	}
	void printInorder() {
		printInorder(root);
	}
	void printPostorder(TreeNode<T>* parent) {
		if (parent == nullptr) {
			return;
		}
		printPostorder(parent->getLeft());
		printPostorder(parent->getRight());
		std::cout << parent->getValue() << std::endl;
	}
	void printPostorder() {
		printPostorder(root);
	}
	~Tree() {
		delete root;
	}
};