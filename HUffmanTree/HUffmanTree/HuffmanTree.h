#ifndef _HuffmanTree_hpp_
#define _HuffmanTree_hpp_
#include <iostream>
#include "minHeap.h"

template<typename T> class HuffmanTree;

template<typename T>
class HuffmanTreeNode{
	friend class HuffmanTree<T>;
private:
	T info;
	HuffmanTreeNode<T>* parent;
	HuffmanTreeNode<T>* left;
	HuffmanTreeNode<T>* right;
public:
	HuffmanTreeNode() {};
	HuffmanTreeNode<T> *leftChild(){
		return left;
	};
	HuffmanTreeNode<T> *rightChild(){
		return right;
	};
	bool operator > (HuffmanTreeNode<T> &HN) {return info > HN.info;}; // ע��Ҫ���������
	bool operator < (HuffmanTreeNode<T> &HN) {return info < HN.info;}; 
	bool operator == (HuffmanTreeNode<T> &HN) {return info == HN.info;};
};

template<typename T>
class HuffmanTree {
private:
	HuffmanTreeNode<T>* root;
	
	//��ht1��ht2Ϊ����Huffman�����ϲ���һ����parentΪ���Ķ�����
	void mergeTree(HuffmanTreeNode<T>&ht1,HuffmanTreeNode<T>&ht2,HuffmanTreeNode<T>* parent);
	void deleteTree(HuffmanTreeNode<T>*root);     //ɾ��Huffman����������
public:
	//����Huffman����weight�Ǵ洢Ȩֵ�����飬n�����鳤��
	HuffmanTree(T weight[],int n);
	//��������
	virtual ~HuffmanTree(){
		deleteTree(root);
	};
	//��������
	void inOrder(HuffmanTreeNode<T> *root);
	HuffmanTreeNode<T>* getRoot(){
		return root;
	};

};

template<typename T>
HuffmanTree<T>::HuffmanTree(T weight[],int n){
	minHeap< HuffmanTreeNode<T> >heap(n);
	/*heap.buildHeap();*/
	HuffmanTreeNode<T>*parent, firstChild,secondChild;
	HuffmanTreeNode<T>* nodeList=new HuffmanTreeNode<T> [n];
	for(int i=0;i<n;i++) {
		nodeList[i].info=weight[i];
		nodeList[i].parent=nodeList[i].left=nodeList[i].right=NULL;
		heap.insert(nodeList[i]);
	}

	for(int i=0;i<n-1;i++) {
		parent=new HuffmanTreeNode<T>;
		firstChild=heap.removeMin();
		secondChild=heap.removeMin();
		mergeTree(firstChild,secondChild,parent);
		heap.insert(*parent);
		root=parent;
	}
	delete []nodeList;
}

template<typename T>
void HuffmanTree<T>::deleteTree(HuffmanTreeNode<T> *root){
	if(root){
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
}

template <typename T>
void HuffmanTree<T>::inOrder(HuffmanTreeNode<T> *root){
	if(root) {
		inOrder(root->left);
		std::cout<<root->info<<" ";
		inOrder(root->right);
	}
}

template <typename T>
void HuffmanTree<T>::mergeTree(HuffmanTreeNode<T>&ht1,HuffmanTreeNode<T>&ht2,HuffmanTreeNode<T>* parent){
	HuffmanTreeNode<T> *l=new HuffmanTreeNode<T>();
	HuffmanTreeNode<T> *r=new HuffmanTreeNode<T>();
	*l=ht1;
	*r=ht2;

	parent->parent=NULL;
	parent->left=l;
	parent->right=r;
	parent->info=ht1.info+ht2.info;
	ht1.parent=ht2.parent=parent;
}

#endif