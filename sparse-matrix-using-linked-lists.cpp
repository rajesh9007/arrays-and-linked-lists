// Done by Rajesh Reddy

#include <iostream>
using namespace std;

struct NodeSparse
{
    int rowIndex;
    int colIndex;
    int elementValue;
    NodeSparse *nextSparseNode;
};

class UniqueSparseMatrix
{
private:
    NodeSparse *sparseHead;

public:
    UniqueSparseMatrix()
    {
        sparseHead = nullptr;
    }

    void insertElement(int row, int col, int val)
    {
        if (val != 0)
        {
            NodeSparse *newSparseNode = new NodeSparse;
            newSparseNode->rowIndex = row;
            newSparseNode->colIndex = col;
            newSparseNode->elementValue = val;
            newSparseNode->nextSparseNode = nullptr;

            if (sparseHead == nullptr)
            {
                sparseHead = newSparseNode;
            }
            else
            {
                NodeSparse *temp = sparseHead;
                while (temp->nextSparseNode != nullptr)
                {
                    temp = temp->nextSparseNode;
                }
                temp->nextSparseNode = newSparseNode;
            }
        }
    }

    void displaySparseMatrix()
    {
        if (sparseHead == nullptr)
        {
            cout << "Sparse Matrix is empty" << endl;
        }
        else
        {
            NodeSparse *temp = sparseHead;
            while (temp != nullptr)
            {
                cout << "Row: " << temp->rowIndex << ", Column: " << temp->colIndex << ", Value: " << temp->elementValue << endl;
                temp = temp->nextSparseNode;
            }
        }
    }
};

int main()
{
    using namespace std;

    UniqueSparseMatrix uniqueSparseMatrix;

    int numRows, numCols;
    cout << "Enter the number of rows in the matrix: ";
    cin >> numRows;

    cout << "Enter the number of columns in the matrix: ";
    cin >> numCols;

    cout << "Enter the elements of the matrix:" << endl;

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            int elementValue;
            cout << "Element at position (" << i << ", " << j << "): ";
            cin >> elementValue;

            uniqueSparseMatrix.insertElement(i, j, elementValue);
        }
    }

    cout << "\nSparse Matrix:" << endl;
    uniqueSparseMatrix.displaySparseMatrix();

    return 0;
}
