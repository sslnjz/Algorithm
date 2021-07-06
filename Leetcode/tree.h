#ifndef ALGORITHM_TREE_H
#define ALGORITHM_TREE_H

#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#if 0
#ifndef T_ITERATIVELY
#define T_ITERATIVELY
#endif
#endif 

#if 1
#ifndef T_RECURSIVELY
#define T_RECURSIVELY
#endif
#endif 

namespace algorithm::tree
{
	template<class T>
	struct TreeNode
	{
	public:
		TreeNode() {}
		TreeNode(const T& d) : data(d) { }

	public:
		T data;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

   template<class T>
   class Tree
   {
   public:

#ifdef T_ITERATIVELY
      /// <summary>
      /// 
      /// </summary>
      /// <param name="root"></param>
      /// <returns></returns>
      static std::vector<T> preorder_traversal(TreeNode<T>* root)
      {
			if (root == nullptr) return {};

			std::vector<T> res;
			std::stack<TreeNode<T>*> s;
			s.push(root);
			while (s.size())
			{
				root = s.top();
				s.pop();
				res.emplace_back(root->data);

				if (root->right) s.push(root->right);
				if (root->left) s.push(root->left);
			}
			
			return res;
		}

      /// <summary>
      /// 
      /// </summary>
      /// <param name="root"></param>
      /// <returns></returns>
      static std::vector<T> inorder_traversal(TreeNode<T>* root)
      {
			if (root == nullptr) return {};

			std::vector<T> res;
			std::stack<TreeNode<T>*> s;

			while (root || s.size())
			{
				while (root)
				{
					s.push(root);
					root = root->left;
				}

				root = s.top();
				s.pop();
				res.emplace_back(root->data);

				root = root->right;
			}

			return res;
      }

      /// <summary>
      /// 
      /// </summary>
      /// <param name="root"></param>
      /// <returns></returns>
      static std::vector<T> postorder_traversal(TreeNode<T>* root)
      {
			if (root == nullptr) return {};

			std::vector<T> res;
			std::stack<TreeNode<T>*> s;
			TreeNode<T>* cur = nullptr;
			while (root || s.size())
			{
				while (root)
				{
					s.push(root);
					root = root->left;
				}

				root = s.top();
				if (root->right && root->right != cur)
				{
					root = root->right;
					s.push(root);
					root = root->left;
				}
				else
				{
					s.pop();
					res.emplace_back(root->data);

					cur = root;
					root = nullptr;
				}

			}

			return res;
      }

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <returns></returns>
		static std::vector<std::vector<T>> levelorder(TreeNode<T>* root)
		{
			if (nullptr == root) return {};

			std::vector<std::vector<T>> res;

			
			std::queue<TreeNode<T>*> q({root});

			while (q.size())
			{
				size_t n = q.size();
				std::vector<T> vec;
				for (int i = 0; i < n; ++i)
				{
					TreeNode<T>* node = q.front();
					vec.emplace_back(node->data);
					q.pop();

					if (node->left) q.push(node->left);
					if (node->right) q.push(node->right);
				}

				res.emplace_back(std::move(vec));
			}

			return res;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <returns></returns>
		static int max_depth(TreeNode<T>* root)
		{
			if (nullptr == root) return 0;

			int max = 0;
			std::queue<TreeNode<T>*> q({root});

			while (q.size())
			{
				++max;
				size_t n = q.size();
				for (; n > 0; --n)
				{
					TreeNode<T>* node = q.front();
					q.pop();

					if (node->left) q.push(node->left);
					if (node->right) q.push(node->right);
				}
			}

			return max;
		}

#endif
#ifdef T_RECURSIVELY
		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <returns></returns>
		static std::vector<T> preorder_traversal(TreeNode<T>* root)
		{
			if (root == nullptr) return {};

			std::vector<T> vec;
			preorder_traversal(root, vec);

			return vec;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <returns></returns>
		static std::vector<T> inorder_traversal(TreeNode<T>* root)
		{
			if (root == nullptr) return {};

			std::vector<T> vec;
			inorder_traversal(root, vec);

			return vec;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <returns></returns>
		static std::vector<T> postorder_traversal(TreeNode<T>* root)
		{
			if (root == nullptr) return {};

			std::vector<T> vec;
			postorder_traversal(root, vec);

			return vec;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <returns></returns>
		static std::vector<std::vector<T>> levelorder(TreeNode<T>* root)
		{
			if (root == nullptr) return {};

			std::vector<std::vector<T>> vec;
			levelorder(root, vec, 0);

			return vec;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <returns></returns>
		static int max_depth_topdown(TreeNode<T>* root)
		{
			if (nullptr == root) return 0;

			int max = 0;
			maxDepth_Topdown(root, max, 1);

			return max;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <returns></returns>
		static int max_depth_bottomup(TreeNode<T>* root)
		{
			if (nullptr == root) return 0;
			return 1 + std::max(max_depth_bottomup(root->left), max_depth_bottomup(root->right)) ;
		}

	private:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <param name="vec"></param>
		/// <param name="level"></param>
		static void levelorder(TreeNode<T>* root, std::vector<std::vector<T>>& vec, int&& level)
		{
			if (vec.size() == level)
				vec.emplace_back(std::vector<T>());

			vec[level].emplace_back(root->data);

			if (root->left) levelorder(root->left, vec, level + 1);
			if (root->right) levelorder(root->right, vec, level + 1);
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <param name="max"></param>
		/// <param name="depth"></param>
		static void max_depth_topdown(TreeNode<T>* root, int& max, int&& depth)
		{
			if (!root) return;

			if (!root->left && !root->right)
				max = std::max(max, depth);

			max_depth_topdown(root->left, max, depth + 1);
			max_depth_topdown(root->right, max, depth + 1);
		}

		/// <summary>
		/// post order of tree traversal
		/// </summary>
		/// <param name="root"></param>
		/// <param name="vec"></param>
		static void postorder_traversal(TreeNode<T>* root, std::vector<T>& vec)
		{
			if (root)
			{
				postorder_traversal(root->left, vec);
				postorder_traversal(root->right, vec);
				vec.emplace_back(root->data);
			}
		}

		/// <summary>
		/// postorder of tree traversal
		/// </summary>
		/// <param name="root">root node</param>
		/// <param name="vec">a set of tree node value with specified order</param>
		static void inorder_traversal(TreeNode<T>* root, std::vector<T>& vec)
		{
			if (root)
			{
				inorder_traversal(root->left, vec);
				vec.emplace_back(root->data);
				inorder_traversal(root->right, vec);
			}
		}

		/// <summary>
		/// Preorder of tree traversal
		/// </summary>
		/// <param name="root">root node</param>
		/// <param name="vec">a set of tree node value with specified order</param>
		static void preorder_traversal(TreeNode<T>* root, std::vector<T>& vec)
		{
			if (root)
			{
				vec.emplace_back(root->data);
				preorder_traversal(root->left, vec);
				preorder_traversal(root->right, vec);
			}
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="root"></param>
		/// <param name="sum"></param>
		/// <returns></returns>
		bool has_path_sum(TreeNode<T>* root, int sum)
		{
			if (!root) return false;

			if (root->left || root->right)
				return has_path_sum(root->left, sum - root->val) || has_path_sum(root->right, sum - root->val);
			else
				return sum == root->val;
		}
#endif


   };
}

#endif //ALGORITHM_TREE_H