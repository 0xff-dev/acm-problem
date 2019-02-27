package sort

import (
	"fmt"
	"testing"
	"time"
)

func TestQuickSort(t *testing.T) {
	datas := []int{300, 45, 89, 33, 9, 26}
	QiuckSort(datas, 0, 5)
	fmt.Println("Quick: ", datas)
	heapDatas := []int{100, 30, 780, 323, 478, 90}
	HeapSort(heapDatas)
	fmt.Println("Heap: ", heapDatas)
	mergeTest := []int{23, 349, 10, 2389, 472, 9}
	MererSort(mergeTest, 0, 5)
	fmt.Println("Merge: ", mergeTest)
	bubbleTest := []int{7, 3, 8, 4, 9, 3644, 2389, 2}
	Bubble(bubbleTest)
	fmt.Println("Bubble: ", bubbleTest)
	selectTest := []int{7, 3, 8, 4, 9}
	insertTest := []int{7, 3, 8, 4, 9, 2345, 32, 242}
	SelectSort(selectTest)
	InsertSort(insertTest)
	fmt.Println("Select: ", selectTest)
	fmt.Println("Insert: ", insertTest)
	time.Sleep(1 * time.Second)
	sleepTest := []int{6, 2, 5, 3}
	SleepSort(sleepTest)
}
