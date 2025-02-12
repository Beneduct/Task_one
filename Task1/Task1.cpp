// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <C:/Users/Beneduct/Tasks/Task_one/Task1/nlohmann/json.hpp>

using namespace std;

bool check_json(string path) {

    return true;
}



int main()
{
    string path;
    cout << "Enter the path to the file being checked\n";
    cin >> path; //Test path C:\Users\Beneduct\Tasks\Task_one

    if (path.empty())
    {
        cout << "path is empty";
        return 0;
    }

    for (int i = 0; i < path.length(); i++) {
        int index = path.find(92);
        if (index + 1 == 0)
            break;

        path.replace(index, 1, "/");
    }

    bool answer = check_json(path);

    if (answer)
        cout << answer << " File is correct";
    else
        cout << answer << " File is't correct";

    return 0;
}
