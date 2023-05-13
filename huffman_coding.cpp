#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Huffman tree node
struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator() (Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Traverse the Huffman tree and store the codes in a map
void encode(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        codes[root->data] = code;
    }
    encode(root->left, code + "0", codes);
    encode(root->right, code + "1", codes);
}

// Build the Huffman tree and return the root node
Node* buildHuffmanTree(string input) {
    unordered_map<char, int> freqMap;
    for (char c : input) {
        freqMap[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto entry : freqMap) {
        pq.push(new Node(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top();
}

// Encode a string using Huffman coding
string encodeString(string input) {
    Node* root = buildHuffmanTree(input);
    unordered_map<char, string> codes;
    encode(root, "", codes);
    string output = "";
    for (char c : input) {
        output += codes[c];
    }
    return output;
}

// Decode a string using Huffman coding
string decodeString(string input, Node* root) {
    string output = "";
    Node* curr = root;
    for (char c : input) {
        if (c == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        if (curr->left == nullptr && curr->right == nullptr) {
            output += curr->data;
            curr = root;
        }
    }
    return output;
}

int main() {
    string input = "Huffman coding is a lossless data compression algorithm";
    string encoded = encodeString(input);
    cout << "Encoded string: " << encoded << endl;

    Node* root = buildHuffmanTree(input);
    string decoded = decodeString(encoded, root);
    cout << "Decoded string: " << decoded << endl;

    return 0;
}
