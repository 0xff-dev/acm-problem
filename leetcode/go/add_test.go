package main

import "testing"
import "fmt"

func TestAdd(t *testing.T) {
	l1 := &ListNode{
		Val:  1,
		Next: nil,
	}
	l2 := &ListNode{
		Val: 9,
		Next: &ListNode{
			Val:  9,
			Next: nil,
		},
	}
	l3 := addTwoNumbers(l1, l2)
	for l3 != nil {
		fmt.Println(l3.Val)
		l3 = l3.Next
	}
}
