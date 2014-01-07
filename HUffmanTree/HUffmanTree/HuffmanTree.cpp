#include "HuffmanTree.h"

void main()
{
	int weight[]={15,2,6,5,20,10,18};
	std::cout<<"Construct HuffmanTree"<<std::endl;
	HuffmanTree<int> Huffman(weight,7);

	std::cout<<"inOrder HuffmanTree is: ";
	Huffman.inOrder(Huffman.getRoot());
	system("pause");



}