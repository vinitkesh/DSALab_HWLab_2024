# Level Order Traversal (BFS or Breadth First Search) of Binary Tree

There are 2 methods of doing level order traversal:

## 1.  Naive approach: 
    - by finding height of a level order tree
    - Time Complexity: O(N2), where N is the number of nodes in the skewed tree.
    - Auxiliary Space: O(1) If the recursion stack is considered the space used is O(N).


# 2. Using Queue

 1. Use a queue of nodes
 2. Push the root into the Queue(if root is NULL, exit)
 3. while ( q.isempty () ) 
    1. for(int i=0;i<q.size();i++)
       1. node temp = q.front
       2. print ( temp->data )
 	  
       3. q.pop
   
       4. if(node->left !=NULL)
          1. q.push(node->left)
       5. if(node->right !=NULL)
          1. q.push(node->right)

```cpp

 vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==NULL)// null tree check
            return ans;

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            vector<int> level;

            int n = q.size();// IMP: gets the number of values for that level

            for(int i=0;i<n;i++){
                TreeNode* temp = q.front(); 
                q.pop();
                level.push_back(temp->val);// added to current level

                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            
            ans.push_back(level);
        }
        return ans;
    }       
```