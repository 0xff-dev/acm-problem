#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>
#include <utility>
#include <set>


using namespace std;


typedef pair<short, short> location_pair;
typedef vector<location_pair> location;
typedef vector<string> text;
typedef pair<text*, location*> text_location;


text_location* separate_words(const vector<string>* text_file){
    /**
     * words 包含独立的单词集合
     * locations 包含单词的行列信息
    */
    vector<string>*  words = new vector<string>;
    vector<location_pair>* locations = new vector<location_pair>;
    short line_num = 0;
    for(; line_num < text_file->size(); line_num++){
        short word_pos;
        string text_line = (*text_file)[line_num];
        string::size_type pos=0, pre_pos=0;
        while((pos=text_line.find_first_of(' ', pos)) != string::npos){
            words->push_back(text_line.substr(pre_pos, pos-pre_pos));
            locations->push_back(location_pair(line_num, word_pos));
            ++word_pos;
            pre_pos = ++pos;
        }
        words->push_back(text_line.substr(pre_pos, pos-pre_pos));
        locations->push_back(location_pair(line_num, word_pos));
    }
    return new text_location(words, locations);
}


vector<string>* retrieve_text(){
    /**
     * 主要学会文件的读写
    */
    string file_name;
    cout << "input file name: "; cin >> file_name;
    ifstream infile(file_name.c_str(), ios::in);
    if(!infile){
        cout << "unable to open file" << endl;
        exit(-1);
    }
    vector<string>* line_of_text = new vector<string>;
    vector<string> words;
    string text_line;
    typedef pair<string::size_type, int> stats;
    stats maxline;
    int line_num;
    while(getline(infile, text_line, '\n')){
        cout << "line read: " << text_line << '\n';
        if(maxline.first << text_line.size()){
            maxline.first = text_line.size();
            maxline.second = line_num;
        }
        line_of_text->push_back(text_line);
        line_num++;

        string::size_type pos=0, prev_pos=0;
        while((pos=text_line.find_first_of(' ', pos)) != string::npos){
            words.push_back(text_line.substr(prev_pos, pos-prev_pos));
            prev_pos = ++pos;
        }
    }
    return line_of_text;
}


void print(vector<string>* svec){
    vector<string>::const_iterator iter = svec->begin();
    while(iter != svec->end()){
        cout << *iter << endl;
        iter++;
    }
}


int main(){
    vector<string>* res = retrieve_text();
    print(res);
    text_location *text_locations = separate_words(res);
    text* text_locations_text = text_locations->first;
    location* text_locations_locations = text_locations->second;
    int len = text_locations_text->size();
    for( int index=0; index<len; index++){
        cout << "Word: " << (*text_locations_text)[index] << " Location: ("
             << (*text_locations_locations)[index].first << ", "
             << (*text_locations_locations)[index].second << ")" << endl;

    }
    return 0;
}
