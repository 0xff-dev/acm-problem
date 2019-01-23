package main

import "fmt"
import "strings"

func lengthOfLongestSubstring(s string) int {
    lenth := len(s)
    max := 1
    if lenth == 0 {
        return 0
    }
    for i := 0; i<lenth-1; i++ {
        store := map[byte]bool{}
        tmpL := 1
        store[s[i]] = true
        for j := i+1; j<lenth; j++{
            if !store[s[j]] {
                tmpL ++
                store[s[j]] = true
                if tmpL > max{
                    max = tmpL
                }
            } else {
                if tmpL > max {
                    max = tmpL
                }
                break
            }
        }
    }
    return max
}

func pro(s string) int {
    length := len(s)
    max := 1
    start, end := 0, 1
    for i := 1; i < length; i ++ {
        if strings.IndexByte(s[start:end], s[i]) == -1{
            end = i + 1
        } else {
            if end - start > max {
                max = end - start
            }
            start = strings.IndexByte(s[start:end], s[i]) + 1 + start
            end = i + 1
        }
    }
    if end - start > max {
        max = end - start
    }
    return max
}
func main() {
    testStrs := []string{
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "au",
    }
    for _, v := range testStrs {
        fmt.Println(lengthOfLongestSubstring(v))
        fmt.Println("Pro: ", pro(v))
    }
}
