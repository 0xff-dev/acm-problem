package tree

import (
	"fmt"
	"testing"
)

func TestTree(t *testing.T) {
	b := NewRoot(5)
	datas := []int{3, 7, 4, 2, 6}
	for _, v := range datas {
		b.Insert(v)
	}
	fmt.Println(b)
	b.Pretravel(true)
	b.Pretravel(false)
	b.OrderTravel(true)
	b.OrderTravel(false)
	b.PostTavel()
	b.FloorTravel()
}
