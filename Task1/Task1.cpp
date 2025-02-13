// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <C:/Users/Beneduct/Tasks/Task_one/Task1/nlohmann/json.hpp>
#include <typeinfo>

using json = nlohmann::json;
using namespace std;

bool check_json(string path) {

    ifstream file(path);

    try { 
        json js = json::parse(file); 
    }
    catch (...) {
        return false;
    }
    return true;
}

bool check_field(json js) {
    array<string, 7> field{ "audio", "maxStreamDurationSec", "streamLimits",
                      "maxAudioStreams", "maxStreams", "maxVideoStreams",
                      "video" };

    char count = 0;

    for (json::iterator iter = js.begin(); iter != js.end(); iter++) {      //проход по ключам

        if (find(field.begin(), field.end(), iter.key()) != field.end()) {  //проверка соответствия ключей
            count++;
        }
        else
            return false;

        if (iter.key() == "streamLimits") {
            for (json::iterator j = iter.value().begin(); j != iter.value().end(); j++) {   //проход по ключам

                if (find(field.begin(), field.end(), j.key()) != field.end()) {             //проверка соответствия ключей
                    count++;
                }
                else
                    return false;
            }
        }
    }

    return count == 7;
}

bool check_value(json js) {
    /*
        ["audio"], ["maxStreamDurationSec"], ["streamLimits"],
            ["maxAudioStreams"], ["maxStreams"], ["maxVideoStreams"],
            ["video"]
    //*/
    try {
        if (!js["audio"])                                    //1
            if (js["streamLimits"]["maxAudioStreams"] != 0)
                return false;

        if (!js["video"])                                    //2
            if (js["streamLimits"]["maxVideoStreams"] != 0)
                return false;

        int a = js["streamLimits"]["maxAudioStreams"],      //3
            b = js["streamLimits"]["maxVideoStreams"],
            c = js["streamLimits"]["maxStreams"];
        if (a + b > c)
            return false;
    }
    catch (...) {
        return false;
    }

    return true;
}

int main() 
{
    string path;
    cout << "Enter the path to the file being checked\n";
    cin >> path; 
    /*Test path C:\Users\Beneduct\Tasks\Task_one\test_doc.cfg 
                Settings\settings.cfg
                //*/
    
    if (path.empty())
    {
        cout << "path is empty";
        return 0;
    }

    if (!check_json(path)) {                    //проверка требований формата json
        cout << " File is not correct";
        return 0;
    }
    else
        cout << " File is correct" << endl;

    ifstream file(path);
    json js = json::parse(file);

    if (check_field(js))
        cout << "Field similar" << endl; //поля идентичны
    else
        cout << "Field not the same" << endl; //поля не соответсвуют 
    ///*
    if (check_value(js))
        cout << "Value is correct" << endl;
    else
        cout << "Value is not correct" << endl;//*/

    return 0;
}
