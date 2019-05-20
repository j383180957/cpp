/*************************************************************************
* File Name: statistics.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Thu 16 May 2019 07:42:35 PM CST
 ************************************************************************/
#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<map>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::map;
class Dictionary
{
public:
    //string getFilename(const string& pathname);
    void read(const string& filename);
    void store(const string& filename);
    //int elfHash(char* key);
private:
    map<string, int> _wordCount;
};

void Dictionary::read(const string& filename)//读取文件内容并统计词频
{
    ifstream ifs(filename);
    if(!ifs)
    {
        cout << "openfile" << filename << "error" <<endl;
        return;
    }

    string word;
    while(ifs >> word)
    {
        ++_wordCount[word];
    }
    ifs.close();
}

void Dictionary::store(const string& filename)//词频信息写入新文件中
{
    ofstream ofs(filename);
    if(!ofs)
    {
        cout << "openfile" << filename << "error" <<endl;
    }

    for(const auto & word : _wordCount)
    {
        ofs << word.first << "     " << word.second << endl;
    }
    
    ofs.close();
}

int main(void)
{
    Dictionary dicForHoly;
    //string pathname;
    string filename;
    
   // cout << "请输入绝对路径" << endl;
   // cin >> pathname;
   // filename = dicForHoly.getFilename(pathname);
   
    cout << "请输入文件名" << endl;
    cin >> filename;
    dicForHoly.read(filename);
    dicForHoly.store("word_count.txt");
    
    return 0;
}

