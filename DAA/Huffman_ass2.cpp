#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node{
    char ch ;
    int freq;
    Node* right;
    Node*left;
    Node(char c, int f){
        ch=c;
        freq=f;
        left=right=nullptr;

    }
};
struct Compare{
    bool operator()(Node* a,Node*b){
        return a-> freq > b-> freq;
    }
};
void generateCodes(Node* root, string code){
    if(!root)return;
    if(!root-> left && !root-> right){
        cout<< root -> ch <<":"<<code <<"\n";
    
    }
    generateCodes(root->left, code+"0");
    generateCodes(root-> right , code+"1");
}
int main(){
    int n;
    cout<<"enter the number of characters:";
    cin>>n;
    vector<char> chars(n);
    vector<int> freq(n);
    for(int i=0;i<n;i++){
        cout<<" enter the character:\n";
        cin>>chars[i];
        cout<<"enter the frequency of the character:\n";
        cin>>freq[1];
    }
    priority_queue<Node*, vector<Node*>, Compare>pq;
    for(int i=0;i<n ;i++){
        pq.push(new Node(chars[i],freq[i]));
    }
    while(pq.size()>1){
        Node* left = pq.top();pq.pop();
        Node* right=pq.top();pq.pop();
        Node* parent = new Node('-', left-> freq+ right-> freq);
        parent->left = left;
        parent->right=right;
        pq.push(parent);
    }
    Node* root =pq.top();
    cout<<"Huffman codes:\n";
    generateCodes(root,"");
    return 0;
}