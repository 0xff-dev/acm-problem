package list

import (
	"fmt"
	"testing"
)

func TestList(t *testing.T) {
	ll := &LinkList{}
	datas := []int{3, 10, 4, 6, 9}
	ll.initList(datas)
	ll.Display()
	fmt.Println(ll.MiddleNode())
	ll.Reverse()
	ll.Display()
	ll.Reverse()
	ll.Display()
	ll.Sort()
	fmt.Print("Sort")
	ll.Display()
	ll.HasCycle()
	fmt.Println("插入数据0")
	ll.Insert(0)
	ll.Display()
	ll.Sort()
	ll.Display()
	fmt.Println(ll.MiddleNode())
}
