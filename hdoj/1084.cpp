#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


struct student{
    int solve_problem;
    string cost_time;

    friend bool operator == (student s1, student s2){
        return s1.solve_problem==s2.solve_problem && s1.cost_time==s2.cost_time;
    }

    friend bool operator < (student s1, student s2){
        if (s1.solve_problem>s2.solve_problem)
            return true;
        else if (s1.solve_problem == s2.solve_problem){
            return s1.cost_time<s2.cost_time;
        }
        return false;
    }
};

bool find_value(vector<student>& vec, student s){
    if (vec.size() == 1)
        return true;
    for( int i=0; i<vec.size(); i++){
        if (vec[i] == s){
            if( i<vec.size()/2 )
                return true;
            else
                return false;
        }
    }
}

int main(){
    int n;
    vector<student> v, v1, v2, v3, v4, v5;
    while(cin >> n && n>=0){
        v.clear();
        v1.clear();
        v2.clear();
        v3.clear();
        v4.clear();
        v5.clear();
        while(n--){
            student s;
            cin >> s.solve_problem >> s.cost_time;
            v.push_back(s);
            if (s.solve_problem == 5)
                v5.push_back(s);
            else if (s.solve_problem == 4)
                v4.push_back(s);
            else if (s.solve_problem == 3)
                v3.push_back(s);
            else if (s.solve_problem == 2)
                v2.push_back(s);
            else if (s.solve_problem == 1)
                v1.push_back(s);
        }

        sort(v4.begin(), v4.end());
        sort(v3.begin(), v3.end());
        sort(v2.begin(), v2.end());
        sort(v1.begin(), v1.end());
        
        for( auto iter=v.begin(); iter!=v.end(); iter++ ){
            if( (*iter).solve_problem == 5 ){
                cout << 100 << endl;
            }
            else if( (*iter).solve_problem==4 ){
                if ( find_value(v4, (*iter)))
                    cout << 95 << endl;
                else
                    cout << 90 << endl;
            }
            else if ( (*iter).solve_problem==3 ){
                if ( find_value(v3, (*iter)))
                    cout << 85 << endl;
                else
                    cout << 80 << endl;
            }
            else if ((*iter).solve_problem == 2){
                if ( find_value(v2, (*iter)))
                    cout << 75 << endl;
                else
                    cout << 70 << endl;
            }
            else if ((*iter).solve_problem == 1){
                if ( find_value(v1, (*iter)))
                    cout << 65 << endl;
                else
                    cout << 60 << endl;
            }
            else 
                cout << 50 << endl;
        }
        cout << endl;
    }
    return 0;
}
