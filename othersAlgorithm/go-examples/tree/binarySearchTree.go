package tree

import "fmt"

type Node struct {
	data  int
	left  *Node
	right *Node
}

func NewRoot(data int) *Node {
	return &Node{data: data}
}

func (t *Node) Insert(data int) *Node {
	if t == nil {
		t = NewRoot(data)
		return t
	}
	if data < t.data {
		t.left = t.left.Insert(data)
	} else {
		t.right = t.right.Insert(data)
	}
	return t
}

func (bt *Node) Pretravel(recursive bool) {
	if recursive {
		//递归来写, 前序遍历
		var inner func(node *Node)
		inner = func(node *Node) {
			if node == nil {
				return
			}
			fmt.Print(node.data, " ")
			if node.left != nil {
				inner(node.left)
			}
			if node.right != nil {
				inner(node.right)
			}
		}
		inner(bt)
	} else {
		// 用栈来做
		nodes := make([]*Node, 0)
		p := bt
		for p != nil || len(nodes) > 0 {
			for p != nil {
				fmt.Print(p.data, " \n")
				nodes = append(nodes, p)
				p = p.left
			}
			if len(nodes) > 0 {
				node := nodes[len(nodes)-1]
				nodes = nodes[:len(nodes)-1]
				p = node.right
			}
		}
	}
}

func (bt *Node) OrderTravel(recursive bool) {
	if recursive {
		var inner func(node *Node)
		inner = func(node *Node) {
			if node == nil {
				return
			}
			if node.left != nil {
				inner(node.left)
			}
			fmt.Print(node.data, " ")
			if node.right != nil {
				inner(node.right)
			}
		}
		inner(bt)
	} else {
		nodes := make([]*Node, 0)
		p := bt
		for p != nil || len(nodes) > 0 {
			for p != nil {
				nodes = append(nodes, p)
				p = p.left
			}
			if len(nodes) > 0 {
				node := nodes[len(nodes)-1]
				fmt.Println(node.data, " ")
				nodes = nodes[:len(nodes)-1]
				p = node.right
			}
		}
	}
}

func (bt *Node) PostTavel() {
	if bt == nil {
		return
	}
	if bt.left != nil {
		bt.left.PostTavel()
	}
	if bt.right != nil {
		bt.right.PostTavel()
	}
	fmt.Print(bt.data, " ")
}

func (bt *Node) FloorTravel() {
	queue := make([]*Node, 1)
	queue[0] = bt
	for len(queue) > 0 {
		tmp := make([]*Node, 0)
		for _, item := range queue {
			fmt.Print(item.data, " ")
			if item.left != nil {
				tmp = append(tmp, item.left)
			}
			if item.right != nil {
				tmp = append(tmp, item.right)
			}
		}
		queue = tmp
	}
}

// 有父亲节点
func (bt *Node) FindParent(node *Node, falg bool) {
	//中序遍历的前驱
	if falg {
		p := node.parent
		for p != nil && p.right != node {
			node = p
			p = node.parent
		}
		return p
	} else {
		p := node.parent
		for p != nil && p.left != node {
			node = p
			p = node.parent
		}
		return p
	}
}

// 终须
func (bt *Node) FindParentNoP(value int, flag bool) (node, firstParent, parent *Node) {
	root := bt
	if flag {
		for root != nil {
			if root.data == value {
				return node, p, firstParent
			}
			parent = root
			if p.data > value {
				root = root.left
			} else {
				firstParent = root
				root = root.right
			}
		}
	} else {
		for root != nil {
			if root.data == value {
				return
			}
			parent = root
			if root.data < value {
				root = root.right
			} else {
				firstParent = root
				root = root.left
			}
		}
	}
}

func getNode(node *Node, flag bool) {
	p := node
	if flag {
		for p.right != nil {
			p = p.right
		}
		return p
	} else {
		for p.left != nil {
			p = p.left
		}
		return p
	}
}

func (bt *Node) Predecessor(value int) *Node {
	node, firstParent, parent := bt.FindParentNoP(value, true)
	if node == nil {
		return nil
	}
	if node.left != nil {
		return getNode(node, true)
	} else if parent == nil || firstParent == nil {
		return nil
	} else if node == parent.right {
		return parent
	}
	return firstParent
}

func (bt *Node) Successos(value int) *Node {
	node, firstParent, parent := bt.FindParentNoP(value, false)
	if node == nil {
		return nil
	}
	if node.right != nil {
		return getNode(node, false)
	} else if parent == nil || firstParent == nil {
		return nil
	} else if node == parent.left {
		return parent
	}
	return firstParent
}

// 前序的遍历找前驱
func (bt *Node) PreP(node *Node) *Node {
	if node.parent != nil {
		return node.parent
	}
	if node == node.parent.right {
		if node.parent.left == nil {
			return node.parent
		} else {
			return getNode(node.parent.left, true)
		}
	}
}

func (bt *Node) SP(node *Node) *Node {
	if node.left != nil {
		return node.left
	} else if node.right != nil {
		return node.right
	} else {
		for (node.parent.right == nil || node.parent.right == node) && node != nil {
			node = node.parent
		}
		return node
	}
}

func (bt *Node) CommonFather(node1, node2 *Node) *Node {
	//寻找两个节点的公公祖先, 每个节点都做判断
	if hasNode(bt.left, node1) && hasNode(bt.left, node2) {
		return bt.left.CommonFather(node1, node2)
	}
	if hasNode(bt.right, node1) && hasNode(bt.right, node2) {
		return bt.right.CommonFather(node1, node2)
	}
	return bt
}

func hasNode(node1, node2 *Mode) bool {
	if node1 == nil {
		return false
	}
	if node1 == node2 {
		return true
	}
	return hasNode(node1.left, node2) || hasNode(node1.right, node2)
}

func (bt *Node) CommonFather2(node1, node2 *Node) *Node {
	if bt == nil {
		return nil
	}
	if bt.data == node1.data || bt.data == node2.data {
		return bt
	}
	l := bt.left.CommonFather2(node1, node2)
	r := bt.right.CommonFather2(node1, node2)
	if l && r {
		return bt
	}
	if l == nil {
		return r
	}
	return l
}
