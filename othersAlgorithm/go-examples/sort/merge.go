package sort

func MererSort(datas []int, left, right int) {
	if left < right {
		mid := (left + right) / 2
		MererSort(datas, left, mid)
		MererSort(datas, mid+1, right)
		merge(datas, left, right)
	}
}

func merge(datas []int, left, right int) {
	if left < right {
		auxArray := make([]int, right-left+1)
		mid := (left + right) / 2
		i, j := left, mid+1
		index := 0
		for i <= mid && j <= right {
			if datas[i] < datas[j] {
				auxArray[index] = datas[i]
				i++
			} else {
				auxArray[index] = datas[j]
				j++
			}
			index++
		}
		for i <= mid {
			auxArray[index] = datas[i]
			index++
			i++
		}
		for j <= right {
			auxArray[index] = datas[j]
			index++
			j++
		}
		for k := 0; k < index; k++ {
			datas[k+left] = auxArray[k]
		}
	}
}
