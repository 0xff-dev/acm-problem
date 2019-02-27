package sort

func Bubble(datas []int) {
	length := len(datas)
	for i := 0; i < length-1; i++ {
		for j := 0; j < length-1-i; j++ {
			if datas[j] > datas[j+1] {
				datas[j], datas[j+1] = datas[j+1], datas[j]
			}
		}
	}
}

func SelectSort(datas []int) {
	length := len(datas)
	for i := 0; i < length-1; i++ {
		minIndex := i
		for j := i + 1; j < length; j++ {
			if datas[j] < datas[minIndex] {
				minIndex = j
			}
		}
		datas[minIndex], datas[i] = datas[i], datas[minIndex]
	}
}

func InsertSort(datas []int) {
	length := len(datas)
	for j := 1; j < length; j++ {
		for i := 0; i < j; i++ {
			if datas[i] >= datas[j] {
				aim := datas[j]
				for k := j - 1; k >= i; k-- {
					datas[k+1] = datas[k]
				}
				datas[i] = aim
				break
			}
		}
	}
}
