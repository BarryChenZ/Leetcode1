/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> L = new ArrayList<>();
        if(root == null) return L;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int n = q.size();
            List<Integer> temp = new ArrayList<>(n);
            for(int i = 0; i < n; i++){
                TreeNode node = q.poll();
                temp.add(node.val);
                
                if(node.left != null){
                    q.add(node.left);
                }
                if(node.right != null){
                    q.add(node.right);
                }
            }
            L.add(temp);
        }
        return L;
    }
    public void input (TreeNode root, List<List<Integer>> L, int k){
        if(root == null) return;
        
        List<Integer> tempArr = new ArrayList<>();
        
        if(L.size() <= k){
            L.add(new ArrayList<Integer>());
            tempArr = L.get(k);
            tempArr.add(root.val);
            
        }
        else{
            tempArr = L.get(k);
            tempArr.add(root.val);
        }
        input(root.left, L, k + 1);
        input(root.right, L, k + 1);
        return;
    }
}
