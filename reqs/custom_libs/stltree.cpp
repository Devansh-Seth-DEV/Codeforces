#include <iostream>
#include <vector>
#include <initializer_list>
#include <memory>
#include <algorithm>

using namespace std;

template <typename T>
class Tree {
    private:
        // Node structure for the tree
        struct Node {
            T data;
            Node* left;
            Node* right;

            Node(T val) : data(val), left(nullptr), right(nullptr) {}
        };

    public:
        // Default constructor
        Tree(): root(nullptr) {}

        // Constructor with initial value
        Tree(T value): root(new Node(value)) {}

        // Constructor with initial values from a vector
        Tree(const vector<T>& values): root(nullptr) {
            for (const auto& value : values) {
                insert(value);
            }
        }

        // Constructor with initial values from an array
        Tree(const T* values, size_t size): root(nullptr) {
            for (size_t i = 0; i < size; ++i) {
                insert(values[i]);
            }
        }

        // Copy constructor with initializer list
        Tree(initializer_list<T> values): root(nullptr) {
            for (const auto& value : values) {
                insert(value);
            }
        }

        // Destructor to clear the tree
        ~Tree() {
            clear();
        }

        // Copy constructor
        Tree(const Tree<T>& other): root(nullptr) {
            if (other.root) {
                root = new Node(other.root->data);
                copySubtree(root, other.root);
            }
        }

        // Move constructor
        Tree(Tree<T>&& other) noexcept : root(other.root) {
            other.root = nullptr; // Transfer ownership
        }

        // Copy assignment operator
        Tree<T>& operator=(const Tree<T>& other) {
            if (this != &other) {
                clear(); // Clear current tree
                if (other.root) {
                    root = new Node(other.root->data);
                    copySubtree(root, other.root);
                } else {
                    root = nullptr;
                }
            }
            return *this;
        }

        // Move assignment operator
        Tree<T>& operator=(Tree<T>&& other) noexcept {
            if (this != &other) {
                clear(); // Clear current tree
                root = other.root; // Transfer ownership
                other.root = nullptr; // Nullify the other tree's root
            }
            return *this;
        }


        // Equality operator
        bool operator==(const Tree<T>& other) const {
            // Check if both trees are empty
            if (root == nullptr && other.root == nullptr) return true;
            // If one is empty and the other is not, they are not equal
            if (root == nullptr || other.root == nullptr) return false;
            // Compare the root data and recursively check left and right subtrees
            return (root->data == other.root->data) &&
                   (root->left == other.root->left) &&
                   (root->right == other.root->right);
        }


        // Inequality operator
        bool operator!=(const Tree<T>& other) const {
            return !(*this == other); // Use the equality operator to determine inequality
        }



        // Check if the tree contains a value
        bool contains(T value) const {
            return containsRec(root, value);
        }


        // Check if the tree is empty
        bool isEmpty() const {
            return root == nullptr;
        }

        // Get the root of the tree
        Node* getRoot() const {
            return root;
        }
        // Get the number of nodes in the tree
        int countNodes() const {
            return countNodesRec(root);
        }

        // Get the height of the tree
        int height() const {
            return heightRec(root);
        }

        // Clear the tree and deallocate memory
        void clear() {
            clearRec(root);
            root = nullptr;
        }


        // Insert multiple values into the tree
        void insert(const vector<T>& values) {
            for (const auto& value : values) {
                insert(value);
            }
        }

        // Insert an array of values into the tree
        void insert(const T* values, size_t size) {
            for (size_t i = 0; i < size; ++i) {
                insert(values[i]);
            }
        }

        // Insert a single value into the tree
        void insert(const T& value) {
            root = insertRec(root, value);
        }

        // In-order traversal of the tree
        void inorder() {
            inorderRec(root);
        }

        // Print the tree in-order
        void printInOrder() {
            if (isEmpty()) {
                cout << "Tree is empty." << endl;
                return;
            }
            cout << "In-order traversal: ";
            inorderRec(root);
            cout << endl;
        }

        // Print the tree in visual format with branches marked by slashes
        void printTreeVisual() const {
            if (!root) {
            std::cout << "<empty tree>\n";
            return;
            }

            int h = height();
            int maxNodes = 1 << h;
            int maxWidth = 3 * (1 << (h - 1));

            // Use a single vector for current and next level to avoid repeated allocations
            std::vector<const Node*> curr, next;
            curr.push_back(root);

            for (int level = 0; level < h; ++level) {
            int nodes = curr.size();
            int spaceBetween = maxWidth / nodes;

            // Print node values
            for (int i = 0; i < nodes; ++i) {
                if (i == 0)
                std::cout << std::string(spaceBetween / 2, ' ');
                if (curr[i])
                std::cout << curr[i]->data;
                else
                std::cout << " ";
                std::cout << std::string(spaceBetween - 1, ' ');
            }
            std::cout << "\n";

            // Prepare next level and print slashes
            if (level < h - 1) {
                for (int i = 0; i < nodes; ++i) {
                if (i == 0)
                    std::cout << std::string(spaceBetween / 2, ' ');
                if (curr[i]) {
                    // Print left slash
                    if (curr[i]->left)
                    std::cout << "/";
                    else
                    std::cout << " ";
                    std::cout << std::string(spaceBetween / 2 - 1, ' ');
                    // Print right slash
                    if (curr[i]->right)
                    std::cout << "\\";
                    else
                    std::cout << " ";
                    std::cout << std::string(spaceBetween / 2 - 1, ' ');
                    next.push_back(curr[i]->left);
                    next.push_back(curr[i]->right);
                } else {
                    std::cout << std::string(spaceBetween, ' ');
                    next.push_back(nullptr);
                    next.push_back(nullptr);
                }
                }
                std::cout << "\n";
                curr.swap(next);
                next.clear();
            }
            }
        }
        

    private:
        // Helper function to copy the subtree
        void copySubtree(Node*& thisNode, Node* otherNode) {
            if (otherNode == nullptr) return;
            thisNode = new Node(otherNode->data);
            copySubtree(thisNode->left, otherNode->left);
            copySubtree(thisNode->right, otherNode->right);
        }


        // Helper function to check if a value exists in the tree recursively
        bool containsRec(Node* node, T value) const {
            if (node == nullptr) return false; // Base case: node is null
            if (node->data == value) return true; // Found the value
            // Recursively check left and right subtrees
            return containsRec(node->left, value) || containsRec(node->right, value);
        }

        // Helper function to count nodes recursively
        int countNodesRec(Node* node) const {
            if (node == nullptr) return 0;
            return 1 + countNodesRec(node->left) + countNodesRec(node->right);
        }

        // Helper function to calculate the height of the tree
        int heightRec(Node* node) const {
            if (node == nullptr) return 0;
            int leftHeight = heightRec(node->left);
            int rightHeight = heightRec(node->right);
            return max(leftHeight, rightHeight) + 1;
        }


        // Helper functions for recursive operations
        void clearRec(Node*& node) {
            if (node == nullptr) return;
            clearRec(node->left);
            clearRec(node->right);
            delete node;
            node = nullptr;
        }

        // Insert a value into the tree recursively
        Node* insertRec(Node* node, T value) {
            if (node == nullptr) return new Node(value);
            
            if(!node->left) {
                node->left = insertRec(node->left, value);
            } else if(!node->right) {
                node->right = insertRec(node->right, value);
            } else {
                // If both children are present, insert into the left subtree
                node->left = insertRec(node->left, value);
            }

            return node;
        }

        // In-order traversal of the tree
        void inorderRec(Node* node) {
            if(!node) return;
            
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }

        Node* root;
};

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Create a tree with initial values
    Tree<int> tree({1, 2, 3, 4, 5});
    tree.printInOrder(); // Output: 4 2 5 1 3

    // Insert a new value
    tree.insert(6);
    tree.printInOrder(); // Output: 6 4 2 5 1 3

    // Check if the tree contains a value
    cout << "Contains 3: " << (tree.contains(3) ? "Yes" : "No") << endl; // Output: Yes
    cout << "Contains 7: " << (tree.contains(7) ? "Yes" : "No") << endl; // Output: No

    // Get the number of nodes in the tree
    cout << "Number of nodes: " << tree.countNodes() << endl; // Output: 6
    
    // Get the height of the tree
    cout << "Height of the tree: " << tree.height() << endl; // Output: 4

    // Clear the tree
    tree.clear();
    tree.printInOrder(); // Output: Tree is empty.

    return 0;
}