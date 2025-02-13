// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <C:/Users/Beneduct/Tasks/Task_one/Task1/nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

bool check_json(string path) {

    ifstream file(path);

    try { 
        json js = json::parse(file); 
    }
    catch ( ... ) { 
        cout << " File is't correct";
        return false;
    }
    cout << " File is correct";
    return true;
}



int main()
{
    string path;
    cout << "Enter the path to the file being checked\n";
    cin >> path; //Test path C:\Users\Beneduct\Tasks\Task_one\test_doc.cfg

    if (path.empty())
    {
        cout << "path is empty";
        return 0;
    }


    /*
    for (int i = 0; i < path.length(); i++) {
        int index = path.find(92);
        if (index + 1 == 0)
            break;

        path.replace(index, 1, "/");
    }//*/

    if (!check_json(path)) 
        return 0;

    ifstream file(path);
    json js = json::parse(file);

    return 0;
}
