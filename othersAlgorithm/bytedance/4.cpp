#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int test, people;
    int *score = new int[100001];
    int *jp = new int[100001];
    while(cin >> test) {
        int *res = new int[test];
        int p = 0;
        while (p < test) {
            cin >> people;
            int minNum = 1000001, minIndex=0;
            for(int i=0; i<people; i++){
                cin >> score[i];
                if(score[i] < minNum) {
                    minNum = score[i];
                    minIndex = i;
                }
                jp[i] = 1;
            }
            int right = (minIndex+1) % people;
            int sum = jp[minIndex];
            while(right != minIndex) {
                int _left = (right-1+people) % people;
                int _right = (right+1) % people;
                if(score[right] > score[_left]) {
                    jp[right] = jp[_left]+1;
                }
                if(score[right] > score[_right]) {
                    jp[right] = min(jp[right], jp[_right]+1);
                }
                sum += jp[right];
                right = (right + 1) % people;
            }
            res[p++] = sum;
        }
        for(int i=0; i<test-1; i++){
            cout << res[i] << endl;
        }
        cout << res[test-1];
        delete []res;
    }
    delete []jp;
    delete []score;
    return 0;
}