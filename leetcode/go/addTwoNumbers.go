package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	root := &ListNode{-1, nil}
	p := root
	cf := 0
	for l1 != nil && l2 != nil {
		tmp := l1.Val + l2.Val + cf
		cf = tmp / 10
		if tmp >= 10 {
			tmp %= 10
		}
		p.Next = &ListNode{tmp, nil}
		fmt.Println("V: ", tmp, " ", cf)
		p = p.Next
		l1 = l1.Next
		l2 = l2.Next
	}
	if l1 != nil {
		for l1 != nil {
			tmp := l1.Val + cf
			cf = tmp / 10
			if tmp >= 10 {
				tmp %= 10
			}
			p.Next = &ListNode{tmp, nil}
			p = p.Next
			l1 = l1.Next
		}
	}
	if l2 != nil {
		for l2 != nil {
			tmp := l2.Val + cf
			cf = tmp / 10
			if tmp >= 10 {
				tmp %= 10
			}
			p.Next = &ListNode{tmp, nil}
			p = p.Next
			l2 = l2.Next
		}
	}
	if cf != 0 {
		p.Next = &ListNode{cf, nil}
	}
	return root.Next
}
