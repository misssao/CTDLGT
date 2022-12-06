#include <stdio.h>
#include <conio.h>
#include <math.h>

struct Node
{
	int data;
	Node *left;
	Node *right;
};

struct Tree
{
	Node *root;
};

Node* createNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void showNode(Node *p)
{
	printf("%4d", p->data);
}

void initTree(Tree &t)
{
	t.root = NULL;
}

int insertNode(Node *&root, Node *p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;
	}
	if (root->data == p->data)
		return 0;
	if (p->data < root->data)
		insertNode(root->left, p);
	else
		insertNode(root->right, p);
	return 1;
}

void nhapDulLieuTuFile(FILE *&fileIn, Node *&root)
{
	while (!feof(fileIn))
	{
		int n;
		fscanf(fileIn, "%d", &n);
		Node *p = createNode(n);
		insertNode(root, p);
	}
}

int tinhTongCacSoCoGiaTriLonHonX(Node *root, int x)
{
	if (!root)
	return 0;
	int sumL = tinhTongCacSoCoGiaTriLonHonX(root->left, x);
	int sumR = tinhTongCacSoCoGiaTriLonHonX(root->right, x);
	if (root->data > x)
	{
		return root->data + sumL + sumR;
	}
	return sumL + sumR;
}

void RNL(Node *root)
{
	if (root == NULL)
		return;
	RNL(root->right);
	showNode(root);
	RNL(root->left);
}

void xuatCacPTChanGiamDan(Node *root)
{
	if (root == NULL)
		return;
	xuatCacPTChanGiamDan(root->right);
	if (root->data % 2 == 0)
		showNode(root);
	xuatCacPTChanGiamDan(root->left);
}

bool checkHangDVLa4(int n)
{
	return n % 10 == 4;
}

Node* timNodeTheMang(Node* &p)
{
	Node *f = p;
	Node *q = p->right;
	while (q->left != NULL)
	{
		f = q;
		q = q->left;
	}
	p->data = q->data;
	if (f == p)
		f->right = q->right;
	else
		f->left = q->right;
	return q;
}

int xoaNode(Node *&root, int x)
{
	if (root == NULL)
		return 0;
	if (x > root->data)
		return xoaNode(root->right, x);
	else if (x < root->data)
		return xoaNode(root->left, x);
	else
	{
		Node *p = root;
		if (root->left == NULL)
		{
			root = root->right;
			delete p;
		}
		else if (root->right == NULL)
		{
			root = root->left;
			delete p;
		}
		else
		{
			Node *q = timNodeTheMang(p);
			delete q;
		}
		return 1;
	}
}

void xoaNodeCoDataCoHangDVLa4(Node *&root, Node *p)
{
	if (p == NULL)
		return;
	xoaNodeCoDataCoHangDVLa4(root, p->left);
	xoaNodeCoDataCoHangDVLa4(root, p->right);
	if (checkHangDVLa4(p->data) == true)
		xoaNode(root, p->data);
}

int timPhanTuCoKCToiXNhoNhat(Node *root, int x)
{
	if (root == NULL)
		return -1;
	int min = root->data;
	int mindis = abs(x - min);
	while (root != NULL)
	{
		if (root->data == x)
			return x;
		if (abs(x - root->data) < mindis)
		{
			min = root->data;
			mindis = abs(x - min);
		}
		if (x > root->data)
			root = root->right;
		else
			root = root->left;
	}
	return min;
}

int tinhChieuCaoCuaCay(Node *root)
{
	if (!root)
		return 0;
	int hl = tinhChieuCaoCuaCay(root->left);
	int hr = tinhChieuCaoCuaCay(root->right);
	if (hl > hr)
		return 1 + hl;
	else
		return 1 + hr;
}

void xuatCacNutOMucK(Node *root, int k)
{
	if (!root)
		return;
	if (k == 0)
		printf("%4d", root->data);
	k--;
	xuatCacNutOMucK(root->left, k);
	xuatCacNutOMucK(root->right, k);
}

int Cau6(Node *root, int k, int x)
{
	if (!root)
		return 0;
	if (k == 0 && root->data < x)
		return 1;
	k--;
	int l = Cau6(root->left, k, x);
	int r = Cau6(root->right, k, x);
	return l + r;
}

int Cau8(Node *root)
{
	if (!root)
		return 0;
	int l = Cau8(root->left);
	int r = Cau8(root->right);
	if (!root->left && !root->right)
		return root->data + l + r;
	return l + r;
}

int demNodeLa(Node *root)
{
	if (!root)
		return 0;
	int l = demNodeLa(root->left);
	int r = demNodeLa(root->right);
	if (!root->left && !root->right)
		return 1 + l + r;
	return l + r;
}


