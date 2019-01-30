/*
	启动两个线程, 一个输出1,3,5,7...99, 另一个输出2,4,6,8...100
	在stdout中输出1,2,3,4.....100, 感觉我的代码改成select 可以同样实现非阻塞的
	程序代码截图见image 文件夹
*/
package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup

func ThreadsToPrint(name string, channel chan bool, start int, own bool) {
	defer wg.Done()
	i := start
	for {
		res, err := <-channel
		if !err {
			fmt.Println("Done Close")
			return
		}
		if res == own {
			fmt.Printf("%s -> %d\n", name, i)
			i += 2
			if i > 101 {
				close(channel)
				return
			}
			channel <- !res
		} else {
			channel <- res
		}
	}
}

func main() {
	wg.Add(2)
	channel := make(chan bool)
	go ThreadsToPrint("t1", channel, 1, true)
	go ThreadsToPrint("t2", channel, 2, false)
	channel <- true
	wg.Wait()
}
