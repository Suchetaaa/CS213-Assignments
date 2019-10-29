
#include <iostream>

using namespace std;

class Node
{
public:
	int key;
	Node* left;
	Node* right;
public:

    Node()
    {
        left = NULL;
        right = NULL;
    }

	 Node(int Key)
	 {
	 	key = Key;
	 	left = NULL;
	 	right = NULL;
	 }
};

void insert(Node*& root, int key) {
  if (root == 0x0) 
  {
  	Node* temp = new Node;
  	temp->key = key;
  	temp->left = temp->right = NULL;
  	root = temp;
  	//cout << temp << endl;
  	// cout << (*root).key;
  	//cout << "yay";
  }
  else if (key < root->key)
    insert(root->left, key);
  else if (key >= root->key)
  {
  	//cout << "Greater" << endl;
  	insert(root->right, key);

  }
    
}

bool find_ancestors(Node*& root_node, int query, bool& check)
{
	//cout << (root_node->right)->key << endl;
	//cout << "Hey" << endl;
	if (root_node == 0x0)
	{
		//cout << "Root Node" << endl;
		check = 1;
		return false;
	}

	if (root_node->key == query)
	{
		//cout << "Found" << endl;
		return true;
	}

	//find_ancestors(root_node->right, query);
	if (find_ancestors(root_node->right, query, check) || find_ancestors(root_node->left, query, check))
	{
		cout << root_node->key << " ";
		check = 1;
		return true;
	}

	return false;
}

class binary_tree
{
public:
	Node* root;

	binary_tree()
	{
		root = NULL;
	}
};


int main()
{

	int num_nodes;
	cin >> num_nodes;

	binary_tree tree1;


	for (int i = 0; i < num_nodes; i++)
	{
		int value;
		cin >> value;
		insert(tree1.root, value);
	}

	int query; 
	cin >> query;

	bool check = 0;

	bool a = find_ancestors(tree1.root, query, check);

	if (!a) cout << "-1" << endl;
	if (!check) cout << "-1" << endl;
	

}