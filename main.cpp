#include <iostream>
#include <vector>

#define MAX_INPUT 10

using namespace std;

struct transition
{
    vector<int> input;
    vector<int> output;
};

void print_reachable_marking(int *places, int size_places, transition *trans, int size_trans, int index)
{
    // int save_places[size_places];
    // for (int i = 0; i < size_places; i++)
    // {
    //     save_places[i] = places[i];
    // }
    // for (int i = 0; i < size_trans; i++)
    // {
    bool able = true;
    for (int j = 0; j < trans[index].input.size(); j++)
    {
        if (places[trans[index].input[j]] == 0)
            able = false;
    }
    if (able)
    {
        for (int j = 0; j < trans[index].input.size(); j++)
        {
            places[trans[index].input[j]] -= 1;
        }
        for (int j = 0; j < trans[index].output.size(); j++)
        {
            places[trans[index].output[j]] += 1;
        }
    }
    cout << "Reachable marking from firing transition[" << index << "]: [ ";
    for (int j = 0; j < size_places; j++)
    {
        if (j == 0)
            cout << places[j];
        else
        {
            cout << ", " << places[j];
        }
    }
    cout << " ]" << endl;
    // for (int j = 0; j < size_places; j++)
    //     save_places[j] = places[j];
    //}
}

int main()
{
    int num_of_places = 0;
    cout << "number of places: ";
    cin >> num_of_places;
    int num_of_trans = 0;
    cout << "number of transitions: ";
    cin >> num_of_trans;
    cout << "Press -1 if want to stop" << endl;
    transition trans[num_of_trans];
    for (int i = 0; i < num_of_trans; i++)
    {
        int index_input;
        cout << "input of transition[ " << i << " ]: ";
        while (true)
        {
            cin >> index_input;
            if (index_input == -1)
                break;
            trans[i].input.push_back(index_input);
        }
        int output_index;
        cout << "outputs of transition[ " << i << " ]: ";
        while (true)
        {
            cin >> output_index;
            if (output_index == -1)
                break;
            trans[i].output.push_back(output_index);
        }
    }
    int places[num_of_places];
    for (int i = 0; i < num_of_places; i++)
    {
        cout << "number of tokens in place[ " << i << " ]: ";
        int num_of_tokens = 0;
        cin >> num_of_tokens;
        places[i] = num_of_tokens;
    }
    // cout << "the initial state: ";
    // int initial_state = 0;
    // cin >> initial_state;
    cout << "Initial markings: [ ";
    for (int i = 0; i < num_of_places; i++)
    {
        if (i == 0)
        {
            cout << places[i];
        }
        else
            cout << ", " << places[i];
    }
    cout << " ]" << endl;
    cout << "Which transition you want to fire ?" << endl;
    cout << "Press -1 to escape the firing" << endl;
    while (true)
    {
        int index;
        cin >> index;
        if (index < 0)
            break;
        if (index >= num_of_trans)
        {
            cout << "Out of range of index of transitions" << endl;
            break;
        }
        print_reachable_marking(places, num_of_places, trans, num_of_trans, index);
    }
    cout << "The end." << endl;
    return 0;
}