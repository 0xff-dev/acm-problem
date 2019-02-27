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
