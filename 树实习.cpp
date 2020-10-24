#include<iostream>
#include<ostream>
#include<istream>
#include<fstream>
#include <vector>

using namespace std;
const char *txtaddr = "C:\\Users\\Platanus\\Desktop\\chnMainCities.txt";

typedef class TreeNode
{
	public:
	int id;
	float x, y;
	char name[50];
	TreeNode *left;
	TreeNode *right;
	void init()
	{
		this->left = nullptr;
		this->right = nullptr;
	}
}Btree;

void insertRightTree(TreeNode **curr, TreeNode *newone);//����������
void insertLeftTree(TreeNode **curr, TreeNode *newone);//����������
void loadfiletoTree(const char* addr, TreeNode** root);//���ļ�����������
void preorder(TreeNode * root);//ǰ���������ӡ
void inorder(TreeNode *root); //�������
void postorder(TreeNode *root);//�������



void insertLeftTree(TreeNode **curr,TreeNode *newone)
{
	if (*curr == nullptr || *curr == NULL)
	{
		(*curr) = newone;
		return;
	}
	if(newone->name[0]<(*curr)->name[0])
		insertLeftTree((&((*curr)->left)), newone);
	else 
		insertRightTree((&((*curr)->right)), newone);
}

void insertRightTree(TreeNode **curr, TreeNode *newone)
{
	if (*curr == nullptr || *curr == NULL)
	{
		(*curr) = newone;
		return;
	}
	if (newone->name[0] < (*curr)->name[0])
	{
		
		insertLeftTree((&((*curr)->left)), newone);
	}
	else
	{
		insertRightTree((&((*curr)->right)), newone);
	}
}

void loadfiletoTree(const char* addr,TreeNode** root)
{
	ifstream read(addr, ios::in);
	if (read.bad())
	{
		cout << "failed to load";
		exit(1);
	}
	while (!read.eof())
	{
		TreeNode *node = new TreeNode;
		node->init();
		read >> (node)->id >> (node)->x >> (node)->y >> (node)->name;
		if (*root == nullptr)
		{
			*root = node;
			(*root)->init();
		}
		else if (node->name[0] < (*root)->name[0])
			insertLeftTree(root, node);
		else
			insertRightTree(root, node);
	}
}

void preorder(TreeNode * root)
{
	if (root != nullptr)
	{
		cout << root->id << '(' << root->x << ',' << root->y << ')' << root->name << endl;
		preorder(root->left);
		preorder(root->right);
	}
}//ǰ��

void inorder(TreeNode *root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		cout << root->id << '(' << root->x << ',' << root->y << ')' << root->name << endl;
		inorder(root->right);
	}
}//����

void postorder(TreeNode *root)
{
	if (root != nullptr)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->id << '(' << root->x << ',' << root->y << ')' << root->name << endl;
	}
}//����

void sortedorder(TreeNode *root)
{
	vector <TreeNode> list;
	TreeNode * p = root;
	if (p != nullptr)
	{
		list.push_back(*root);
	}
}

int main()
{
	Btree *tree=nullptr;

	loadfiletoTree(txtaddr, &tree);
	
	cout << "****************ǰ��********************" << endl;
	preorder(tree);
	cout << "********************����****************"<<endl;
	inorder(tree);
	cout << "******************����******************" << endl;
	postorder(tree);
	
	system("pause");
	return 0;
}