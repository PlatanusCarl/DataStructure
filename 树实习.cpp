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

void insertRightTree(TreeNode **curr, TreeNode *newone);//创建左子树
void insertLeftTree(TreeNode **curr, TreeNode *newone);//创建右子树
void loadfiletoTree(const char* addr, TreeNode** root);//读文件创建二叉树
void preorder(TreeNode * root);//前序遍历并打印
void inorder(TreeNode *root); //中序遍历
void postorder(TreeNode *root);//后序遍历



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
}//前序

void inorder(TreeNode *root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		cout << root->id << '(' << root->x << ',' << root->y << ')' << root->name << endl;
		inorder(root->right);
	}
}//中序

void postorder(TreeNode *root)
{
	if (root != nullptr)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->id << '(' << root->x << ',' << root->y << ')' << root->name << endl;
	}
}//后序

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
	
	cout << "****************前序********************" << endl;
	preorder(tree);
	cout << "********************中序****************"<<endl;
	inorder(tree);
	cout << "******************后序******************" << endl;
	postorder(tree);
	
	system("pause");
	return 0;
}