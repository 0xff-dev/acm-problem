package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findTarget(root *TreeNode, k int) bool {
	//  尼玛, 我开始想的就是中序遍历+二分查找, 结果不知道还可以自定义结构
	resMap := map[int]bool{}
	var search func(*TreeNode, int, map[int]bool) bool
	search = func(root *TreeNode, k int, resMap map[int]bool) bool {
		if root == nil {
			return false
		}
		if _, ok := resMap[k-root.Val]; ok {
			return true
		}
		resMap[root.Val] = true
		return search(root.Left, k, resMap) || search(root.Right, k, resMap)
	}
	return search(root, k, resMap)
}

func findTargetII(root *TreeNode, k int) bool {
	var travel func(*TreeNode, func(*TreeNode) bool)
	var search func(*TreeNode, int) bool
	travel = func(root *TreeNode, f func(n *TreeNode) bool) {
		if root == nil {
			return
		}
		travel(root.Left, f)
		if f(root) {
			return
		}
		travel(root.Right, f)
	}
	search = func(root *TreeNode, aim int) bool {
		if root == nil {
			return false
		}
		if root.Val == aim {
			return true
		}
		if root.Val < aim {
			return search(root.Right, aim)
		}
		return search(root.Left, aim)
	}
	res := false
	travel(root, func(node *TreeNode) bool {
		if !res {
			tmp := k - node.Val
			res = tmp != node.Val && search(root, tmp)
		}
		return res
	})
	return res
}
