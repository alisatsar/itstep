#include <memory>
#include <fstream>
#include <iostream>
#include <string>
#include <streambuf>
 
int  main() {
    std::cout << "Enter file name: ";
    std::string filename;
    std::cin >> filename;
 
    int operation = 0;
    do {
        std::unique_ptr<std::fstream> file =
            std::make_unique<std::fstream>(filename, std::ios::in);
 
        std::cout << "\nChoose operation (0-exit 1-print 2-search): ";
        std::cin >> operation;
        switch (operation) {
        case 1: {
            while (!file->eof()) {
                std::unique_ptr<char[], std::default_delete<char[]>> buf(new char[100]);
                std::memset(buf.get(), 0, 100);
                file->read(buf.get(), 100);
                std::cout << buf.get();
            }
            break;
        }
        case 2: {
            std::string word;
            std::cout << "Enter word: ";
            std::cin >> word;
            if (!word.empty())
            {
                auto begin = std::istreambuf_iterator<char>(*file);
                auto end = std::istreambuf_iterator<char>();
                auto itr = begin;
                bool found = false;
                while (itr != end)
                {
                    itr = std::find(itr, std::istreambuf_iterator<char>(), word[0]);
                    auto stritr = word.begin();
                    for (; stritr != word.end(); ++stritr,++itr) {
                        if (itr == end || *stritr != *itr)
                        {
                            break;
                        }
                    }
                    if (stritr == word.end()) {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    std::cout << "Woohoo!\n";
                }
                else
                {
                    std::cout << "Not found!\n";
                }
            }
            break;
        }
        }
 
 
 
    } while (operation != 0);
 
    return 0;
}
