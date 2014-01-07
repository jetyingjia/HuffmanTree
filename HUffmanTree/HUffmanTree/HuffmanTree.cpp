#include "HuffmanTree.h"

void main()
{
	int weight[]={2,3,5,58,8,5,9};
	std::cout<<"Construct HuffmanTree"<<std::endl;
	HuffmanTree<int> Huffman(weight,7);

	std::cout<<"inOrder HuffmanTree is: ";
	Huffman.inOrder(Huffman.getRoot());
	system("pause");



}