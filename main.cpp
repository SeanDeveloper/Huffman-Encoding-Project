#include <vector>
#include <iostream>
#include <queue>
#include <string>

/*  TODO:
    add support for space character
    add support for numerical values
*/

using namespace std;

// tree node
struct node {
    char inputChar;
    unsigned freqChar;
    // left = l, right = r
    node* l, * r;

    node(char inputChar, unsigned freqChar)
    {
        l = r = NULL;
        this->inputChar = inputChar;
        this->freqChar = freqChar;
    }
};

// For comparison of two heap nodes 
struct cmpr {
    bool operator()(node* l, node* r)
    {
        // comparison between two values
        // checking if left node is greater than the node on the right
        return (l->freqChar > r->freqChar);
    }
};

// creating two global vectors that store both the characters
// and the frequency 
vector<int> values;
vector<char> stringval;

void charValFreq(string str, bool extraCredit = false)
{
    if (extraCredit) {
        str = str + "ntht"; // extra credit
    }
    int n = str.size();
    int freq[100];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
        if (isalpha(str[i])) {
            freq[str[i] - 'A']++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (freq[str[i] - 'A'] != 0) {
            stringval.push_back(str[i]);
            values.push_back(freq[str[i] - 'A']);
            freq[str[i] - 'A'] = 0;
        }
    }
}

void code(struct node* root, string datastr)
{
    if (!root) {
        return;

    }

    if (root->inputChar != '$')

        cout << root->inputChar << ": " << datastr << "\n";
    // left and right nodes assignments 1, 0 we can change these values if we have left to represent 0 instead
    code(root->l, datastr + "0");
    code(root->r, datastr + "1");
}

void encode(char data[], int freq[], int sizedata)
{
    struct node* l, * r, * top;
    priority_queue<node*, vector<node*>, cmpr> nodeheap;
    for (int j = 0; j < sizedata; ++j)
        nodeheap.push(new node(data[j], freq[j]));
    while (nodeheap.size() != 1) {
        //remove left and right element from the top
        l = nodeheap.top();
        nodeheap.pop();
        r = nodeheap.top();
        nodeheap.pop();


        top = new node('$', l->freqChar + r->freqChar);
        top->l = l;
        top->r = r;
        nodeheap.push(top);
    }
    code(nodeheap.top(), "");
}




int main()
{
    // intitalizing string, prompting user for input
    string tobeEncoded;
    cout << "Huffman Encoder:" << endl;
    getline(cin, tobeEncoded);
    // taking the input and calculating characters and frequency
    charValFreq(tobeEncoded);

    // converting our vectors into a usable array
    char* characters = stringval.data();
    int* freq_values = values.data();

    // table with both char and freq
    cout << "char\t | \tfreq" << endl;
    for (int i = 0; i < stringval.size(); i++) {
        cout << characters[i] << "\t|\t" << freq_values[i] << endl;
    }

    cout << endl << endl;

    /*
    function returns huffman encoding
    characters: char[]
    freq_values: int[]
    stringval: int
    */
    encode(characters, freq_values, stringval.size());
    
    system("pause");

    return 0;
}