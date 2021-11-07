#include <iostream>
#include <vector>
// #define FREE 0
// #define DOCU 2
// #define BUSY 1

// #define DONE 2
// #define WAIT 0
// #define INSIDE 1
// #define COUNT 3

// #define WAITING 0
// #define TREATING 1
// #define GIVE_DOCUMENT 2
// #define DONE_TREATING 3
// #define FREEING 4

// #define MAX_INPUT 10

using namespace std;

struct transition
{
    vector<int> input;
    vector<int> output;
};
// int specialists[3] = {0, 0, 0};
// int patients[4] = {0, 0, 0, 0};
// int patient_and_specialists[5] = {0, 0, 0, 0, 0};

// void Update_Transitions(transition *arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         bool able = true;
//         for (int j = 0; j < arr[i].input.size(); j++)
//         {
//             if (patient_and_specialists[arr[i].input[j]] <= 0)
//                 able = false;
//         }
//         if (able)
//         {
//             for (int j = 0; j < arr[i].input.size(); j++)
//             {
//                 patient_and_specialists[arr[i].input[j]] -= 1;
//             }
//             for (int j = 0; j < arr[i].output.size(); j++)
//             {
//                 patient_and_specialists[arr[i].output[j]] += 1;
//             }
//         }
//         if (i == 0)
//         {
//             cout << "Start: [ ";
//             for (int j = 0; j < 3; j++)
//             {
//                 if (j == 0)
//                 {
//                     cout << specialists[j];
//                 }
//                 else
//                 {
//                     cout << ", " << specialists[j];
//                 }
//             }
//             cout << " ]" << endl;
//         }
//         else if (i == 1)
//         {
//             cout << "Change: [ ";
//             for (int j = 0; j < 3; j++)
//             {
//                 if (j == 0)
//                 {
//                     cout << specialists[j];
//                 }
//                 else
//                 {
//                     cout << ", " << specialists[j];
//                 }
//             }
//             cout << " ]" << endl;
//         }
//         else
//         {
//             cout << "End: [ ";
//             for (int j = 0; j < 3; j++)
//             {
//                 if (j == 0)
//                 {
//                     cout << specialists[j];
//                 }
//                 else
//                 {
//                     cout << ", " << specialists[j];
//                 }
//             }
//             cout << " ]" << endl;
//         }
//     }
// }

int main()
{
    // transition spec_and_patient[4];
    // for (int i = 0; i < 4; i++)
    // {
    //     if (i == 0)
    //     {
    //         spec_and_patient[i].input.push_back(WAITING);
    //         spec_and_patient[i].input.push_back(FREEING);

    //         spec_and_patient[i].output.push_back(BUSY);
    //     }
    //     else if (i == 1)
    //     {
    //         spec_and_patient[i].input.push_back(TREATING);
    //         spec_and_patient[i].output.push_back(GIVE_DOCUMENT);
    //     }
    //     else
    //     {
    //         spec_and_patient[i].input.push_back(GIVE_DOCUMENT);
    //         spec_and_patient[i].output.push_back(FREEING);
    //         spec_and_patient[i].output.push_back(DONE_TREATING);
    //     }
    // }
    // cout << "Input for the number of tokens for M0: ";
    // int num = 0;
    // cin >> num;
    // patient_and_specialists[WAITING] = num;
    int num_of_places = 0;
    cout << "number of places: ";
    cin >> num_of_places;
    int num_of_trans = 0;
    cout << "number of transitions: ";
    cin >> num_of_trans;

    transition num_trans[num_of_trans];
    for (int i = 0; i < num_of_trans; i++)
    {
        int index_input;
        cout << "input of transition: " << i << ": ";
        while (true)
        {
            cin >> index_input;
            if (index_input == -1)
                break;
            num_trans[i].input.push_back(index_input);
        }
        int output_index;
        cout << endl;
        cout << "outputs of transition: " << i << ": ";
        while (true)
        {
            cin >> output_index;
            if (output_index == -1)
                break;
            num_trans[i].output.push_back(output_index);
        }
    }
    cout << endl;
    int places[num_of_places];
    for (int i = 0; i < num_of_places; i++)
    {
        cout << "number of tokens in place: " << i << ": ";
        int num_of_tokens = 0;
        cin >> num_of_tokens;
        places[i] = num_of_tokens;
    }
    cout << "the initial state: ";
    int initial_state = 0;
    cin >> initial_state;

    for (int i = 0; i < num_of_places; i++)
        cout << places[i] << " ";

    return 0;
}