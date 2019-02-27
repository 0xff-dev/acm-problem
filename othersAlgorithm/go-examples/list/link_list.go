package list

import "fmt"

type Node struct {
	data int
	Next *Node
}

type LinkList struct {
	head *Node
}

func (ll *LinkList) initList(nums []int) {
	fmt.Print("是否反序构造?(y/n)")
	var opt byte
	fmt.Scanf("%c", &opt)
	if opt == 'Y' || opt == 'y' {
		for _, v := range nums {
			tmp := &Node{v, nil}
			tmp.Next = ll.head
			ll.head = tmp
		}
	} else {
		p := ll.head
		for _, v := range nums {
			tmp := &Node{v, nil}
			if p == nil {
				p = tmp
				ll.head = p
			} else {
				tmp.Next = p.Next
				p.Next = tmp
				p = p.Next
			}
		}
	}
}

func (ll *LinkList) Insert(data int) bool {
	if ll.head == nil {
		ll.head = &Node{data, nil}
		return true
	}
	node := &Node{data, nil}
	p := ll.head
	for p.Next != nil {
		p = p.Next
	}
	node.Next = p.Next
	p.Next = node
	return true
}

func (ll *LinkList) Display() {
	p := ll.head
	for p != nil {
		fmt.Print(p.data, " ")
		p = p.Next
	}
	fmt.Println()
}

func (ll *LinkList) Reverse() {
	p, q := ll.head, ll.head.Next
	p.Next = nil
	for q != nil {
		tmp := q.Next
		q.Next = p
		p = q
		q = tmp
	}
	ll.head = p
}

func (ll *LinkList) Sort() {
	// 链表的排序
	sort(ll.head, nil)
}

func sort(head, end *Node) {
	if head == end || head.Next == end {
		return
	}
	aim := head
	p, q := head, head.Next
	for q != nil {
		if q.data < aim.data {
			p = p.Next
			p.data, q.data = q.data, p.data
		}
		q = q.Next
	}
	aim.data, p.data = p.data, aim.data
	sort(head, p)
	sort(p.Next, end)
}

func (ll *LinkList) HasCycle() bool {
	// 判断是否存在环
	p, q := ll.head, ll.head.Next
	for q != nil && q.Next != nil && p != q {
		p = p.Next
		q = q.Next.Next
	}
	if q != p {
		fmt.Println("不存在环: ")
		return false
	} else {
		fmt.Println("存在环, 寻找环")
		p = ll.head
		for p != q {
			p = p.Next
			q = q.Next
		}
		fmt.Print("入口点: ", p)
		return true
	}
}

func (ll *LinkList) MiddleNode() string {
	//如果是一个节点, 就输出一个, 否则输出两个
	p, q := ll.head, ll.head.Next
	// 一个走一步, 一个走两部
	for q != nil && q.Next != nil {
		p = p.Next
		q = q.Next.Next
	}
	if q == nil {
		return fmt.Sprintf("Only One %d\n", p.data)
	} else {
		return fmt.Sprintf("Double %d-%d\n", p.data, p.Next.data)
	}
}
