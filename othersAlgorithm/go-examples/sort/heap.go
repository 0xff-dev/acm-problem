package sort

func HeapSort(datas []int) {
	buildHeap(datas)
	length := len(datas) - 1
	for length >= 1 {
		datas[0], datas[length] = datas[length], datas[0]
		length--
		maintainHeap(datas, 0, length)
	}
}

func buildHeap(datas []int) {
	length := len(datas) - 1
	for i := len(datas) / 2; i >= 0; i-- {
		maintainHeap(datas, i, length)
	}
}

func maintainHeap(datas []int, index int, heapSize int) {
	aimIndex := index
	left, right := index*2+1, (index+1)*2
	if left <= heapSize && datas[left] > datas[aimIndex] {
		aimIndex = left
	}
	if right <= heapSize && datas[right] > datas[aimIndex] {
		aimIndex = right
	}
	if aimIndex != index {
		// 调整
		datas[aimIndex], datas[index] = datas[index], datas[aimIndex]
		maintainHeap(datas, aimIndex, heapSize)
	}
}
