// --------------------------------------1-------------------------------

#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct HuffmanNode
{
    char data;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct CompareNodes
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->frequency > b->frequency;
    }
};

void buildHuffmanTree(priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNodes> &minHeap)
{
    while (minHeap.size() > 1)
    {
        HuffmanNode *left = minHeap.top();
        minHeap.pop();

        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        HuffmanNode *mergedNode = new HuffmanNode('$', left->frequency + right->frequency);
        mergedNode->left = left;
        mergedNode->right = right;

        minHeap.push(mergedNode);
    }
}

void generateHuffmanCodes(HuffmanNode *root, string code, map<char, string> &huffmanCodes)
{
    if (!root)
        return;

    if (root->data != '$')
    {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main()
{
    string inputString;
    cout << "Enter a string to encode: ";
    cin >> inputString;

    map<char, int> frequencyMap;
    for (char c : inputString)
    {
        frequencyMap[c]++;
    }

    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNodes> minHeap;

    for (const auto &pair : frequencyMap)
    {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    buildHuffmanTree(minHeap);

    HuffmanNode *root = minHeap.top();

    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:\n";
    for (const auto &pair : huffmanCodes)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}

// --------------------------------------2-------------------------------
// #include <bits/stdc++.h>

// using namespace std;

// struct MinHeapNode
// {
//     char data;
//     int freq;
//     MinHeapNode *left, *right;
//     MinHeapNode(char data, int freq)
//     {
//         left = right = nullptr;
//         this->data = data;
//         this->freq = freq;
//     }
// };

// void printCodes(struct MinHeapNode *root, string str)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     if (root->data != '$')
//     {
//         cout << root->data << ": " << str << endl;
//     }
//     printCodes(root->left, str + "0");
//     printCodes(root->right, str + "1");
// }

// struct compare
// {
//     bool operator()(MinHeapNode *a, MinHeapNode *b)
//     {
//         return (a->freq > b->freq);
//     }
// };

// void HuffmanCode(char data[], int freq[], int size)
// {
//     struct MinHeapNode *left, *right, *temp;

//     priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

//     for (int i = 0; i < size; i++)
//     {
//         minHeap.push(new MinHeapNode(data[i], freq[i]));
//     }

//     while (minHeap.size() != 1)
//     {
//         left = minHeap.top();
//         minHeap.pop();
//         right = minHeap.top();
//         minHeap.pop();
//         temp = new MinHeapNode('$', left->freq + right->freq);
//         temp->left = left;
//         temp->right = right;
//         minHeap.push(temp);
//     }
//     printCodes(minHeap.top(), "");
// }

// int main()
// {
//     char data[] = {'A', 'B', 'C', 'D'};
//     int freq[] = {23, 12, 34, 10};
//     HuffmanCode(data, freq, 4);
//     return 0;
// }

/*
Huffman Coding :
Time complexity: O(nlogn) where n is the number of unique characters.
If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calls minHeapify(). So, overall complexity is O(nlogn).
*/