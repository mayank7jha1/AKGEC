#include<bits/stdc++.h>
using namespace std;


template<typename T>
class TreeNode {

public:
	T val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T val) {
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};


TreeNode<int>*BuildTree() {

	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	}

	TreeNode<int>*n = new TreeNode<int>(x);
	n->left = BuildTree();
	n->right = BuildTree();
	return n;
}

//Level Order Traversal Just for Reference.
void BFS(TreeNode<int>*root) {
	queue<TreeNode<int>*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		TreeNode<int>*f = q.front();
		q.pop();

		if (f == NULL) {
			if (!q.empty()) {
				q.push(NULL);
			}
			cout << endl;
		} else {

			cout << f->val << " ";
			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}
		}
	}

	cout << "------------------------------" << endl;
}


void dfs(TreeNode<int>*root, int col, int level, multimap<pair<int, int>, int>&mmap) {

	if (root == NULL) {
		return;
	}

	mmap.insert({{col, level}, root->val});
	dfs(root->left, col - 1, level + 1, mmap);
	dfs(root->right, col + 1, level + 1, mmap);
}

vector<int>VerticalViewColumnLevelWiseSortedUsingMultimap(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	multimap<pair<int, int>, int>mmap;
	dfs(root, 0, 0, mmap);



	for (auto x : mmap) {
		ans.push_back(x.second);
	}

	return ans;

}


vector<int>TopViewColumnLevelWiseSortedUsingMultimap(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	multimap<pair<int, int>, int>mmap;
	dfs(root, 0, 0, mmap);

	int TopValueCol = INT_MIN;

	for (auto it = mmap.begin(); it != mmap.end(); it++) {
		int Currentcol = it->first.first;
		int level = it->first.second;
		int val = it->second;

		if (TopValueCol != Currentcol) {
			ans.push_back(val);
			TopValueCol = Currentcol;
		}
	}

	return ans;

}


vector<int>BottomViewColumnLevelWiseSortedUsingMultimap(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	multimap<pair<int, int>, int>mmap;
	dfs(root, 0, 0, mmap);

	// map<col, val>mp; This will store har col ka last node :
	map<int, int>mp;


	for (auto it = mmap.begin(); it != mmap.end(); it++) {
		int col = it->first.first;
		int val = it->second;

		mp[col] = val;//Last value of the same col will be updated.
	}

	for (auto x : mp) {
		ans.push_back(x.second);
	}

	return ans;

}

void dfs2(TreeNode<int>*root, int col, int level, map<pair<int, int>, vector<int>>&mp) {

	if (root == NULL) {
		return;
	}

	mp[ {col, level}].push_back(root->val);
	dfs2(root->left, col - 1, level + 1, mp);
	dfs2(root->right, col + 1, level + 1, mp);
}

vector<int>VerticalViewColumnLevelWiseSortedUsingMap(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	map<pair<int, int>, vector<int>>mp;
	dfs2(root, 0, 0, mp);



	for (auto x : mp) {
		for (auto y : x.second) {
			ans.push_back(y);
		}
	}

	return ans;

}



vector<int>TopViewColumnLevelWiseSortedUsingMap(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	map<pair<int, int>, vector<int>>mp;
	dfs2(root, 0, 0, mp);

	int TopValueCol = INT_MIN;

	for (auto it : mp) {
		int col = it.first.first;
		if (col != TopValueCol) {
			ans.push_back(it.second[0]);
			TopValueCol = col;
		}

	}

	return ans;
}

vector<int>BottomViewColumnLevelWiseSortedUsingMap(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	map<pair<int, int>, vector<int>>mp;
	dfs2(root, 0, 0, mp);

	// map<col, val>mp; This will store har col ka last node :
	map<int, int>mp2;

	for (auto x : mp) {
		int col = x.first.first;
		mp2[col] = x.second.back();
	}

	for (auto x : mp2) {
		ans.push_back(x.second);
	}

	return ans;
}

vector<int>TopViewColumnLevelWiseIterative(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	queue <pair<TreeNode<int>*, int>>q;
	map<int, int>mp;

	q.push({root, 0});

	while (!q.empty()) {

		auto it = q.front();
		q.pop();

		auto node = it.first;
		int col = it.second;

		if (mp.count(col) == 0) {
			mp[col] = node->val;
		}

		if (node->left != NULL) {
			q.push({node->left, col - 1});
		}
		if (node->right != NULL) {
			q.push({node->right, col + 1});
		}
	}

	for (auto x : mp) {
		ans.push_back(x.second);
	}


	return ans;
}

vector<int>BottomViewColumnLevelWiseIterative(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	queue <pair<TreeNode<int>*, int>>q;
	map<int, int>mp;

	q.push({root, 0});

	while (!q.empty()) {

		auto it = q.front();
		q.pop();

		auto node = it.first;
		int col = it.second;

		mp[col] = node->val;


		if (node->left != NULL) {
			q.push({node->left, col - 1});
		}
		if (node->right != NULL) {
			q.push({node->right, col + 1});
		}
	}

	for (auto x : mp) {
		ans.push_back(x.second);
	}


	return ans;
}

vector<int>VerticalViewColumnLevelWiseIterative(TreeNode<int>*root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	queue <pair<TreeNode<int>*, int>>q;
	map<int, vector<int>>mp;

	q.push({root, 0});

	while (!q.empty()) {

		auto it = q.front();
		q.pop();

		auto node = it.first;
		int col = it.second;

		mp[col].push_back(node->val);


		if (node->left != NULL) {
			q.push({node->left, col - 1});
		}
		if (node->right != NULL) {
			q.push({node->right, col + 1});
		}
	}

	for (auto x : mp) {
		for (auto y : x.second) {
			ans.push_back(y);
		}
	}


	return ans;
}


int main() {

	TreeNode<int>*root = BuildTree();
	BFS(root);

	vector<int>ans = TopViewColumnLevelWiseSortedUsingMultimap(root);
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;

	vector<int>ans2 = TopViewColumnLevelWiseSortedUsingMap(root);
	for (auto x : ans2) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;

	vector<int>ans3 = TopViewColumnLevelWiseIterative(root);
	for (auto x : ans3) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;

	vector<int>ans4 = BottomViewColumnLevelWiseSortedUsingMultimap(root);
	for (auto x : ans4) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;

	vector<int>ans5 = BottomViewColumnLevelWiseSortedUsingMap(root);
	for (auto x : ans5) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;

	vector<int>ans6 = BottomViewColumnLevelWiseIterative(root);
	for (auto x : ans6) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;


	vector<int>ans7 = VerticalViewColumnLevelWiseSortedUsingMultimap(root);
	for (auto x : ans7) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;

	vector<int>ans8 = VerticalViewColumnLevelWiseSortedUsingMap(root);
	for (auto x : ans8) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;
	vector<int>ans9 = VerticalViewColumnLevelWiseIterative(root);
	for (auto x : ans9) {
		cout << x << " ";
	}
	cout << endl << "----------------------" << endl;



}