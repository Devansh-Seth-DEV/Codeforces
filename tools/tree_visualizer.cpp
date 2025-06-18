/*

.................................1--
.................................|--
...............+--------------------------------+--
...............|--..............................|--
...............2--..............................3--
...............|--..............................|--
.....+-----------------+--...............+-----------------+--
.....|--...............|--...............|--...............|--
.....4--...............nil...............nil...............7--
.....|--...............|--...............|--...............|--
+---------+--.....+---------+--.....+---------+--.....+---------+--
|--.......|--.....|--.......|--.....|--.......|--.....|--.......|--
8--.......9--.....nil.......nil.....nil.......nil.....14-.......15-



...............1--
...............|--
.....+-----------------+--
.....|--...............|--
.....2--...............3--
.....|--...............|--
+---------+--.....+---------+--
|--.......|--.....|--.......|--
4--.......5--.....6--.......7--


......1--
......|--
+---------+--
|--.......|--
2--.......3--

*/

#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height_binary_tree(Node const *const root) {
    if (!root) return 0;
    return 1 + max(height_binary_tree(root->left), height_binary_tree(root->right));
}

void insert_binary_tree(Node*& root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    if (val < root->data) {
        insert_binary_tree(root->left, val);
    } else {
        insert_binary_tree(root->right, val);
    }
}

void delete_binary_tree(Node*& root) {
    if (!root) return;
    delete_binary_tree(root->left);
    delete_binary_tree(root->right);
    delete root;
    root = nullptr;
}

template <typename T>
string format_string(const T& str, int width = 1, const char fill = ' ', bool left_align = true, const string& fgcolor = "37", bool bold = false) {
    stringstream ss;
    if (bold) {
        ss << "\033[1m"; // Set bold text
    } else {
        ss << "\033[0m"; // Reset text formatting
    }
    ss << "\033[" << fgcolor << "m"; // Set foreground color
    if (left_align) {
        ss << left << setfill(fill) << setw(width) << str;
    } else {
        ss << right << setfill(fill) << setw(width) << str;
    }
    ss << "\033[0m"; // Reset text formatting
    return ss.str();
}

// Visualizes a binary tree in a structured format using ASCII art
// The tree is printed level by level, with branches connecting parent nodes to child nodes
// The width of each node is controlled by the parameter 'w'
void visualize_binary_tree(Node* root) {
    if (!root) {
        cout << 'nil\n';
        return;
    }
    
    const int h = height_binary_tree(root); // height of binary tree
    int w = 3;
    // if ((w&1) == 0) w += 1; // ensure odd width for better visualization

    // w = max(3, w); // minimum width of a node is 3

    const int mrsp = w+2; // minimum root prefix spacing
    const int mcsp = (mrsp<<1) - w; // minimum child prefix spacing
    

    const int n = 1<<(h-1); // max possible nodes at last level of binary tree
    const int g = n>>1; // max possible group of pairs at last level of binary tree
    const int last_level_width = (g*mcsp) + ((g-1) * mrsp) + (n*w); // width of last level of binary tree

    int prsp = max(mrsp, last_level_width>>1); // prefix root spacing
    if ((prsp&1) == 0) prsp = max(mrsp, prsp-1); // ensure odd prefix root spacing
    int pcsp = max(mrsp, (prsp/(mrsp<<1)) * mrsp); // prefix child spacing
    int icsp = max(mcsp, (prsp>>1) * mrsp); // inter child spacing
    int icgsp = prsp; // inter childs group spacing

    int current_level = 1; // current level of the tree
    int nodes_count = 0; // count of nodes at current level
    bool did_print_branch = false; // flag to check if branch was printed

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current_node = q.front();
        q.pop();
        
        nodes_count += 1;

        if (did_print_branch ) {
            // prefix padding for root node to child connector
            cout << left << setw(prsp) << ' ';
            
            int const n = (1<<(current_level - 1))>>1;
            
            // connecting child branches to parent
            for (int i = 1; i<=n; i++) {
                if ((i&1)==0) {
                    cout << left << setw(icsp) << ' ';
                } else if ( i > 1 ) {
                    cout << left << setw(icgsp) << ' ';
                }
                
                cout << setfill(' ') << left << setw(w) << '|';
                // vertical branch from parent to child in yellow color
                // cout << format_string<string>("|", w, ' ', true, "33");
                // reset color to default
                cout << "\033[0m";
            }
            cout << '\n';

            // prefix padding for next level except for the last level
            if (current_level < h) cout << left << setw(pcsp) << ' ';

            // recalculating prefix root spacing and child spacing for next level
            if ( current_level > 1 && nodes_count == 1 ) {
                icgsp = prsp;
                icsp = max(mcsp, (prsp/mrsp) * mrsp);
            }

            // connecting child nodes branches in a pair
            for (int i = 1; i<=n; i++ ) {
                if ( i > 1) cout << left << setw(icgsp) << ' ';

                // horizontal branch from parent to child in yellow color
                cout << setfill('-') << left << setw(w) << '+';
                cout << setfill('-') << left << setw(icsp) << '-';
                cout << setfill(' ') << left << setw(w) << '+';

                // cout << format_string<string>("+", w, '-', true, "33");
                // cout << format_string<string>("", icsp, '-', false, "33");
                // cout << format_string<string>("+", w, ' ', true, "33");
                // reset color to default
                cout << "\033[0m";
            }
            cout << '\n';

            // prefix padding for child nodes connector except for the last level
            if ( current_level < h ) cout << left << setw(pcsp) << ' ';

            // connecting child nodes group branch with child nodes
            for (int i = 1;  i<=n; i++ ) {
                if ( i > 1) cout << left << setw(icgsp) << ' ';

                // vertical branch from parent to child in yellow color
                // cout << format_string<string>("|", w, ' ', true, "33");
                // cout << format_string<string>("", icsp, ' ', false, "33");
                // cout << format_string<string>("|", w, ' ', true, "33");
                // // reset color to default
                // cout << "\033[0m";

                cout << left << setw(w) << '|';
                cout << left << setw(icsp) << ' ';
                cout << left << setw(w) << '|';
            }
            cout << '\n';
            
            // prefix padding for child nodes except for the last level
            if ( current_level < h ) cout << left << setw(pcsp) << ' ';

            did_print_branch = false;
        }

        // print prefix root spacing for the first node of the tree
        if ( current_level == 1 ) cout << left << setw(prsp) << ' ';

        // print current node data
        if ( !current_node ) {
            // print a placeholder for null nodes
            cout << format_string<string>("x", w, ' ', true, "31");
            // reset color to default
            cout << "\033[0m";

            q.push(nullptr);
            q.push(nullptr);
        } else {
            cout << format_string<int>(current_node->data, w, ' ', true, "32", true);
            // reset color to default
            cout << "\033[0m";

            q.push(current_node->left);
            q.push(current_node->right);
        }

        int const max_possible_nodes = 1<<(current_level - 1);
        if ( nodes_count == max(1, max_possible_nodes) ) {
            cout << '\n';
            nodes_count = 0;

            did_print_branch = true;
            
            if ( current_level > 1 ) {
                prsp = pcsp;
                pcsp = max(mrsp, (prsp/(mrsp<<1)) * mrsp);
            }
            current_level += 1;
            if ( current_level > h ) break;
        } else {
            if ( (nodes_count&1)==0 ) cout << left << setw(icgsp) << ' ';
            else cout << left << setw(icsp) << ' ';
        }
    }
}


int main() {
    Node* root = nullptr;

    int n; // Number of nodes to insert

    cout << "Enter the number of nodes to insert into the binary tree: ";
    cin >> n; // Read the number of nodes to insert

    if (n <= 0) {
        cout << "No nodes to insert.\n";
        return 0;
    }

    cout << "Inserting nodes into the binary tree:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val; // Read each node value
        insert_binary_tree(root, val);
    }

    cout << "Visualizing the binary tree after insertion:\n";
    visualize_binary_tree(root);

    delete_binary_tree(root);
    
    return 0;
}