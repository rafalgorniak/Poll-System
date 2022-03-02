#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "PollSystem.h"
#include "Display.h"
#include "DataStorage.h"
#include "SingleChoicePoll.h"
#include "MultiChoicePoll.h"
#include "RelativePercentage.h"
#include "AbsolutePercentage.h"
using namespace std;

int main() {
    unsigned short choice;
    string path, input;
    unsigned int number;
    vector<unsigned int> numbers;
    bool working = true, workingOnPoll;

    PollSystem pollSystem = PollSystem();
    auto display = make_shared<Display>();
    auto data = make_shared<DataStorage>();

    cout<<"-------------------------------------------------------- Welcome in the Poll System Application,"
          " here you can establish and conduct any survey --------------------------------------------------------\n";
    while(working)
    {
        cout<<"What would you like to do?\n";
        cout<<"1. Display poll from a file\n";
        cout<<"2. Create new poll\n";
        cout<<"3. Exit\n";
        try {
            cin >> input;
            choice = static_cast<unsigned short>(stoi(input));
        }
        catch (exception&){
            cout << "Invalid input\n";
            choice = 0;
        }
        switch (choice) {
            case 1:
            {
                cout << "File name(default: /home/student/oop21_ww_01/project/library/src/dane.txt): ";
                //cin >> path;
                path = "/home/student/oop21_ww_01/project/library/src/dane.txt";
                try {
                    pollSystem.displayFromFile(display, data, path);
                }
                catch(exception&) {
                    cout << "Error within the file occurred\n";
                }
                break;
            }

            case 2:
            {
                cout<<"1. Single-Voice-Poll\n";
                cout<<"2. Multi-Voice-Poll\n";
                try {
                    cin >> input;
                    choice = static_cast<unsigned short>(stoi(input));
                }
                catch (exception&){
                    cout << "Invalid input\n";
                    choice = 0;
                }
                switch (choice) {
                    case 1:
                    {
                        cout<<"Poll name:";
                        getchar();
                        getline(cin, input);
                        SingleChoicePoll poll = SingleChoicePoll(input, make_shared<RelativePercentage>());
                        workingOnPoll = true;
                        while(workingOnPoll)
                        {
                            cout<<"------------------Single-Choice-Poll service------------------\n";
                            cout<<"What do you want to do?\n";
                            cout<<"1. Add Option\n";
                            cout<<"2. Add Vote\n";
                            cout<<"3. Display\n";
                            cout<<"4. Save to File\n";
                            cout<<"5. Exit\n";
                            try {
                                cin >> input;
                                choice = static_cast<unsigned short>(stoi(input));
                            }
                            catch (exception&){
                                cout << "Invalid input\n";
                                choice = 0;
                            }
                            switch (choice) {
                                case 1:
                                {
                                    string name;
                                    cout<<"Option name:";
                                    getchar();
                                    getline(cin, input);
                                    poll.addOption(make_shared<Option>(input));
                                    break;
                                }
                                case 2:
                                {
                                    cout << "Poll options: \n";
                                    for(unsigned int i = 0; i < poll.getOptionsNumber(); i++){
                                        cout << i + 1 << ". " << poll.getOptionNames()[i] << "\n";
                                    }
                                    cout << "Option number: ";
                                    try {
                                        cin >> input;
                                        number = static_cast<unsigned int>(stoi(input));
                                    }
                                    catch (exception&){
                                        cout << "Invalid input, vote is counted as incorrect\n";
                                        number = 0;
                                    }
                                    pollSystem.makeSingleVote(poll, number);
                                    break;
                                }
                                case 3:
                                {
                                    try{
                                        pollSystem.displayPoll(poll, display);
                                    }
                                    catch (exception&){
                                        cout << "Error within the poll occurred\n";
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    try{
                                        cout << "File name(default: /home/student/oop21_ww_01/project/library/src/dane.txt): ";
                                        //cin >> path;
                                        path = "/home/student/oop21_ww_01/project/library/src/dane.txt";
                                        pollSystem.savePoll(poll, data, path);
                                    }
                                    catch (exception&) {
                                        cout << "Error while saving occurred\n";
                                    }
                                    break;
                                }
                                case 5:
                                {
                                    workingOnPoll = false;
                                    break;
                                }
                                default:
                                {
                                    cout<<"Wrong number picked\n";
                                    break;
                                }
                            }
                        }
                        break;
                    }

                    case 2:
                    {
                        cout << "Poll name:";
                        cin >> input;
                        MultiChoicePoll poll = MultiChoicePoll(input, make_shared<RelativePercentage>());
                        workingOnPoll = true;
                        while(workingOnPoll)
                        {
                            cout << "------------------Multi-Choice-Poll service------------------\n";
                            cout<<"What do you want to do?\n";
                            cout<<"1. Add Option\n";
                            cout<<"2. Add Vote\n";
                            cout<<"3. Display\n";
                            cout<<"4. Save to File\n";
                            cout<<"5. Exit\n";
                            try {
                                cin >> input;
                                choice = static_cast<unsigned short>(stoi(input));
                            }
                            catch (exception&){
                                cout << "Invalid input\n";
                                choice = 0;
                            }
                            switch (choice) {
                                case 1:
                                {
                                    cout<<"Option name:";
                                    getchar();
                                    getline(cin, input);
                                    poll.addOption(make_shared<Option>(input));
                                    break;
                                }
                                case 2:
                                {
                                    cout << "Poll options: \n";
                                    for(unsigned int i = 0; i < poll.getOptionsNumber(); i++){
                                        cout << i + 1 << ". " << poll.getOptionNames()[i] << "\n";
                                    }
                                    cout << "Option number (in order to stop type '0'): ";
                                    try {
                                        cin >> input;
                                        number = static_cast<unsigned int>(stoi(input));
                                    }
                                    catch (exception&){
                                        cout << "Invalid input, vote is counted as incorrect\n";
                                        number = 0;
                                    }
                                    while(number != 0){
                                        numbers.push_back(number);
                                        cin >> number;
                                    }
                                    pollSystem.makeMultiVote(poll, numbers);
                                    break;
                                }
                                case 3:
                                {
                                    try{
                                        pollSystem.displayPoll(poll, display);
                                    }
                                    catch (exception&){
                                        cout << "Error within the poll occurred\n";
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    try{
                                        cout << "File name(default: /home/student/oop21_ww_01/project/library/src/dane.txt): ";
                                        //cin >> path;
                                        path = "/home/student/oop21_ww_01/project/library/src/dane.txt";
                                        pollSystem.savePoll(poll, data, path);
                                    }
                                    catch (exception&){
                                        cout << "Error while saving occurred\n";
                                    }
                                    break;
                                }
                                case 5:
                                {
                                    workingOnPoll = false;
                                    break;
                                }
                                default:
                                {
                                    cout<<"Wrong number picked\n";
                                    break;
                                }
                            }
                        }
                        break;
                    }

                    default:
                        cout<<"Wrong number picked\n";
                        break;
                }
                break;
            }
            case 3:
            {
                working = false;
                break;
            }
            default:
                cout<<"Wrong number picked\n";
                break;
        }
    }
    return 0;
}