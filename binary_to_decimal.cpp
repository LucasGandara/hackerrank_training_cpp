#include <iostream>

class LinkedBinaryNode
{
public:
    LinkedBinaryNode();
    LinkedBinaryNode(int data);
    LinkedBinaryNode(int data, LinkedBinaryNode *nextNode);

    int data;
    LinkedBinaryNode *next;
};

LinkedBinaryNode::LinkedBinaryNode(int data, LinkedBinaryNode *nextNode)
{
    LinkedBinaryNode::data = data;
    LinkedBinaryNode::next = nextNode;
}

LinkedBinaryNode::LinkedBinaryNode(int data)
{
    LinkedBinaryNode::data = data;
}

int main(int argc, char const *argv[])
{
    LinkedBinaryNode myBinaryTest{1};
    LinkedBinaryNode myBinary{
        1, LinkedBinaryNode{
               1, LinkedBinaryNode{0}}};

    if (myBinaryTest.data)
    {
        /* code */
    }

    char result = 0;
    std::cout << int(result) << "\n";
}
