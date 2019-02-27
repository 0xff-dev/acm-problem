package sort

func QiuckSort(datas []int, left, right int) {
	if left < right {
		i, j := left, right
		aim := datas[left]
		for i < j {
			for i < j && datas[j] > aim {
				// 但方向加入=, 会是的一个数字内空缺, 无法正常排序
				j--
			}
			for i < j && datas[i] < aim {
				i++
			}
			if i < j {
				datas[i], datas[j] = datas[j], datas[i]
			}
		}
		QiuckSort(datas, left, i-1)
		QiuckSort(datas, i+1, right)
	}
}
