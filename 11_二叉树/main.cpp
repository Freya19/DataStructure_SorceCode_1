#include <iostream>
#include "¶þ²æÊ÷.h"

using namespace std;

int main()
{
	BinaryTree<char> tree;
	TreeNode<char> ¼Ó,¼õ,³Ë,³ý,a,b,c,d,e;

	¼Ó.data = '+';
	¼õ.data = '-';
	³Ë.data = '*';
	³ý.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';

	tree.root = &¼Ó;
	¼Ó.leftChild = &¼õ;
	¼Ó.rightChild = &e;
	¼õ.leftChild = &³Ë;
	¼õ.rightChild = &d;
	³Ë.leftChild = &³ý;
	³Ë.rightChild = &c;
	³ý.leftChild = &a;
	³ý.rightChild = &b;

	cout << "ÖÐÐò±éÀú: ";
	tree.InOrder();//ÖÐÐò±éÀú
	cout << endl;

	cout << "Ç°Ðò±éÀú: ";
	tree.PreOrder();
	cout << endl;

	cout << "ºóÐò±éÀú: ";
	tree.PostOrder();
	cout << endl;

	cout << "²ãÐò±éÀú: ";
	tree.LevelOrder();
	cout << endl;
	return 0;
}