/* 
	Solution to leetcode problem #94 using JavaScript. 
	https://leetcode.com/problems/binary-tree-inorder-traversal/ 
*/

const inorderTraversal = function(root) {
    let st = [];
    let visited = [];
    
    while(root || st.length != 0) {
        while(root != null){
            st.push(root);
            root = root.left;        
        }
        
        root = st.pop();
        visited.push(root.val);
        
        root = root.right;
    }
    
    return visited;
};

const main = function() {
    const tree =  {
        "val": 1,
        "right": {
            "val": 2,
            "right": null,
            "left": {
                "val": 3,
                "right": null,
                "left": null
            }
        },
        "left": null
    }
    
    console.log(inorderTraversal(tree));
}

main();