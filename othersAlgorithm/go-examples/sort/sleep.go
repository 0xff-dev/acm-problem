package sort

import "fmt"
import "time"
import "sync"

var wg sync.WaitGroup

func SleepSort(datas []int) {
	wg.Add(len(datas))
	for _, v := range datas {
		go func(v int) {
			defer wg.Done()
			time.Sleep(time.Duration(v) * time.Second)
			fmt.Println(v)
		}(v)
	}
	wg.Wait()
}
