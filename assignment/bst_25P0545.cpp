
    #include <iostream>
    #include <iomanip>
    using namespace std;

    struct node{
        int info;
        int size;
        node *left, *right;
    };

    void generateKeys(int R, int keys[], int n)
    {
        int s = R + 1;
        int count = 0;

        while(count < n)
        {
            s = (s * 7) % 10007;
            int k = 10 + s % 90;
            bool used = false;

            for(int j = 0; j < count; j++)
                if(keys[j] == k) used = true;

            if(!used) keys[count++] = k;
        }
    }

    class bin_search_tree{
    public:

        node *root;

        bin_search_tree(){
            root = NULL;
        }

        // Insert
        bool b_search_tree(node *temp, int number){

            if(temp == NULL){
                if(root == NULL){
                    root = new node;
                    root->info = number;
                    root->size = 1;
                    root->left = NULL;
                    root->right = NULL;
                }
                return true;
            }

            if(number == temp->info)
                return false;

            if(number < temp->info){

                if(temp->left == NULL){
                    temp->left = new node;
                    temp->left->info = number;
                    temp->left->size = 1;
                    temp->left->left = NULL;
                    temp->left->right = NULL;
                    temp->size++;
                    return true;
                }

                bool added = b_search_tree(temp->left, number);

                if(added)
                    temp->size++;

                return added;
            }

            else{

                if(temp->right == NULL){
                    temp->right = new node;
                    temp->right->info = number;
                    temp->right->size = 1;
                    temp->right->left = NULL;
                    temp->right->right = NULL;
                    temp->size++;
                    return true;
                }

                bool added = b_search_tree(temp->right, number);

                if(added)
                    temp->size++;

                return added;
            }
        }

        // Inorder
        void in_order(node *temp){

            if(temp == NULL) return;

            in_order(temp->left);
            cout << temp->info << " ";
            in_order(temp->right);
        }

        // Preorder
        void pre_order(node *temp){

            if(temp == NULL) return;

            cout << temp->info << ":" << temp->size << " ";

            pre_order(temp->left);
            pre_order(temp->right);
        }

        // Search
        void search(int key){

            node *p = root;

            while(p != NULL){

                cout << p->info << " ";

                if(p->info == key){
                    cout << "FOUND";
                    return;
                }

                if(key < p->info)
                    p = p->left;
                else
                    p = p->right;
            }

            cout << "NOT FOUND";
        }

        // Select
        int select(int i){

            node *p = root;

            while(p != NULL){

                int L = 0;

                if(p->left != NULL)
                    L = p->left->size;

                if(i == L + 1)
                    return p->info;

                if(i <= L)
                    p = p->left;

                else{
                    i = i - L - 1;
                    p = p->right;
                }
            }

            return -1;
        }

        // Rank
        int rank(int x){

            node *p = root;
            int count = 0;

            while(p != NULL){

                if(x <= p->info)
                    p = p->left;

                else{

                    if(p->left != NULL)
                        count += p->left->size;

                    count++;

                    p = p->right;
                }
            }

            return count;
        }

        // Search whether key exists
        bool contains(int x){

            node *p = root;

            while(p != NULL){

                if(p->info == x)
                    return true;

                if(x < p->info)
                    p = p->left;
                else
                    p = p->right;
            }

            return false;
        }

        // Range
        int countRange(int lo, int hi){

            int ans = rank(hi) - rank(lo);

            if(contains(hi))
                ans++;

            return ans;
        }

        // Orders
        unsigned long long orders(node *temp){

            if(temp == NULL)
                return 1;

            int L = 0, R = 0;

            if(temp->left != NULL)
                L = temp->left->size;

            if(temp->right != NULL)
                R = temp->right->size;

            unsigned long long c = 1;

            for(int i = 1; i <= L; i++){
                c = c * (L + R - i + 1) / i;
            }

            return c * orders(temp->left) * orders(temp->right);
        }

        // Check BST
        bool checkBST(node *temp, long long mn, long long mx, int &s){

            if(temp == NULL){
                s = 0;
                return true;
            }

            int L, R;

            bool leftOK = checkBST(temp->left, mn, temp->info, L);
            bool rightOK = checkBST(temp->right, temp->info, mx, R);

            s = L + R + 1;

            if(!leftOK || !rightOK)
                return false;

            if(temp->info <= mn || temp->info >= mx)
                return false;

            if(temp->size != s)
                return false;

            return true;
        }

        bool isBST(){

            int s;

            return checkBST(root, -2147483649LL, 2147483648LL, s);
        }

        // Find node without BST searching
        node* findNode(node *temp, int x){

            if(temp == NULL)
                return NULL;

            if(temp->info == x)
                return temp;

            node *p = findNode(temp->left, x);

            if(p != NULL)
                return p;

            return findNode(temp->right, x);
        }

        // Check slide rule
        bool slideRule(node *temp){

            if(temp == NULL)
                return true;

            if(temp->left != NULL){
                if(temp->info <= temp->left->info)
                    return false;
            }

            if(temp->right != NULL){
                if(temp->info >= temp->right->info)
                    return false;
            }

            return slideRule(temp->left) && slideRule(temp->right);
        }

        // Collect keys
        void collect(node *temp, int keys[], int &n){

            if(temp == NULL)
                return;

            collect(temp->left, keys, n);

            keys[n] = temp->info;
            n++;

            collect(temp->right, keys, n);
        }

        // Bad swaps
        void badSwaps(int &count, int &a, int &b){

            count = 0;
            a = -1;
            b = -1;

            int keys[100];
            int n = 0;

            collect(root, keys, n);

            for(int i = 0; i < n; i++){

                for(int j = i + 1; j < n; j++){

                    node *p = findNode(root, keys[i]);
                    node *q = findNode(root, keys[j]);

                    int t = p->info;
                    p->info = q->info;
                    q->info = t;

                    if(slideRule(root)){

                        count++;

                        if(a == -1){
                            a = keys[i];
                            b = keys[j];
                        }
                    }

                    t = p->info;
                    p->info = q->info;
                    q->info = t;
                }
            }
        }

        // Swap keys
        void swapKeys(int a, int b){

            node *p = findNode(root, a);
            node *q = findNode(root, b);

            if(p == NULL || q == NULL)
                return;

            int t = p->info;
            p->info = q->info;
            q->info = t;
        }

        // Remove minimum or maximum
        node* removeExtreme(node *temp, bool maximum, int &value){

            if(maximum){

                if(temp->right == NULL){

                    value = temp->info;

                    node *p = temp->left;

                    delete temp;

                    return p;
                }

                temp->right = removeExtreme(temp->right, maximum, value);

                temp->size--;

                return temp;
            }

            else{

                if(temp->left == NULL){

                    value = temp->info;

                    node *p = temp->right;

                    delete temp;

                    return p;
                }

                temp->left = removeExtreme(temp->left, maximum, value);

                temp->size--;

                return temp;
            }
        }

        // Delete helper
        node* deleteRec(node *temp, int key, bool useSuccessor,
                        int &caseNo, int &replacedBy, bool &deleted){

            if(temp == NULL)
                return NULL;

            if(key < temp->info){

                temp->left = deleteRec(temp->left, key, useSuccessor,
                                    caseNo, replacedBy, deleted);

                if(deleted)
                    temp->size--;

                return temp;
            }

            if(key > temp->info){

                temp->right = deleteRec(temp->right, key, useSuccessor,
                                        caseNo, replacedBy, deleted);

                if(deleted)
                    temp->size--;

                return temp;
            }

            // Case 1: Leaf
            deleted = true;

            if(temp->left == NULL && temp->right == NULL){

                caseNo = 1;

                delete temp;

                return NULL;
            }

            // Case 2: One child
            if(temp->left == NULL || temp->right == NULL){

                caseNo = 2;

                node *p;

                if(temp->left != NULL)
                    p = temp->left;
                else
                    p = temp->right;

                delete temp;

                return p;
            }

            // Case 3: Two children
            caseNo = 3;

            if(useSuccessor){

                temp->right = removeExtreme(temp->right, false, replacedBy);
            }

            else{

                temp->left = removeExtreme(temp->left, true, replacedBy);
            }

            temp->info = replacedBy;

            temp->size--;

            return temp;
        }

        // Delete key
        void deleteKey(int key, bool useSuccessor, int &caseNo, int &replacedBy){

            caseNo = 0;
            replacedBy = -1;

            bool deleted = false;

            root = deleteRec(root, key, useSuccessor,
                            caseNo, replacedBy, deleted);
        }
    };


    // Insert all
    void insertAll(bin_search_tree &t, int a[], int n){

        for(int i = 0; i < n; i++){
            t.b_search_tree(t.root, a[i]);
        }
    }


    int main(){

        // TEST0

        int t0[16] = {
            7, 6, 10, 1, 8, 15, 5, 9,
            13, 16, 3, 11, 14, 2, 4, 12
        };

        bin_search_tree test;

        insertAll(test, t0, 16);

        cout << "TEST0 PREORDER: ";
        test.pre_order(test.root);
        cout << endl;

        cout << "TEST0 ORDERS: " << test.orders(test.root) << endl;

        int c, rep;

        test.deleteKey(4, true, c, rep);

        cout << "TEST0 DELETE 4 CASE " << c << endl;

        cout << "TEST0 PREORDER: ";
        test.pre_order(test.root);
        cout << endl;

        test.deleteKey(5, true, c, rep);

        cout << "TEST0 DELETE 5 CASE " << c << endl;

        cout << "TEST0 PREORDER: ";
        test.pre_order(test.root);
        cout << endl;

        test.deleteKey(10, true, c, rep);

        cout << "TEST0 DELETE 10 CASE " << c
            << " REPLACED BY " << rep << endl;

        cout << "TEST0 PREORDER: ";
        test.pre_order(test.root);
        cout << endl;


        // OWN RUN

        int R = 545;

        int keys[13];

        generateKeys(R, keys, 13);

        bool useSuccessor = false;

        cout << "ROLL " << setw(4) << setfill('0') << R;
        cout << setfill(' ') << " RULE predecessor" << endl;

        cout << "KEYS: ";

        for(int i = 0; i < 13; i++)
            cout << keys[i] << " ";

        cout << endl;

        bin_search_tree t;

        insertAll(t, keys, 13);

        cout << "PREORDER: ";
        t.pre_order(t.root);
        cout << endl;

        cout << "ORDERS: " << t.orders(t.root) << endl;

        cout << "ISBST: " << (t.isBST() ? "YES" : "NO") << endl;


        // Duplicate insert

        bool added = t.b_search_tree(t.root, keys[0]);

        cout << "INSERT " << keys[0] << ": ";

        if(added)
            cout << "OK" << endl;
        else
            cout << "DUPLICATE" << endl;

        cout << "PREORDER: ";
        t.pre_order(t.root);
        cout << endl;


        // Bad swaps

        int count, a, b;

        t.badSwaps(count, a, b);

        cout << "BAD SWAPS: " << count
            << " FIRST " << a << " " << b << endl;


        // First swap

        t.swapKeys(a, b);

        cout << "SWAP " << a << " " << b << endl;

        cout << "ISBST: " << (t.isBST() ? "YES" : "NO") << endl;

        cout << "SEARCH " << a << ": ";
        t.search(a);
        cout << endl;

        cout << "SEARCH " << b << ": ";
        t.search(b);
        cout << endl;


        // Swap back

        t.swapKeys(a, b);

        cout << "SWAP " << a << " " << b << endl;

        cout << "ISBST: " << (t.isBST() ? "YES" : "NO") << endl;


        // Select, Rank, Range

        int i = (R % 13) + 1;
        int j = (R % 10) + 1;

        int S2 = keys[2] + 1;

        while(t.contains(S2))
            S2++;

        int lo, hi;

        if(keys[1] < keys[4]){
            lo = keys[1];
            hi = keys[4];
        }
        else{
            lo = keys[4];
            hi = keys[1];
        }

        cout << "SELECT " << i << ": " << t.select(i) << endl;

        cout << "RANK " << S2 << ": " << t.rank(S2) << endl;

        cout << "RANGE " << lo << " " << hi << ": "
            << t.countRange(lo, hi) << endl;


        // Deletions

        int D1 = 91;
        int D2 = 25;
        int D3 = 33;

        t.deleteKey(D1, useSuccessor, c, rep);

        cout << "DELETE " << D1 << " CASE " << c << endl;

        cout << "PREORDER: ";
        t.pre_order(t.root);
        cout << endl;


        t.deleteKey(D2, useSuccessor, c, rep);

        cout << "DELETE " << D2 << " CASE " << c << endl;

        cout << "PREORDER: ";
        t.pre_order(t.root);
        cout << endl;


        t.deleteKey(D3, useSuccessor, c, rep);

        cout << "DELETE " << D3 << " CASE " << c
            << " REPLACED BY " << rep << endl;

        cout << "PREORDER: ";
        t.pre_order(t.root);
        cout << endl;


        // Final output

        cout << "ORDERS: " << t.orders(t.root) << endl;

        cout << "SELECT " << j << ": " << t.select(j) << endl;

        cout << "RANK " << D1 << ": " << t.rank(D1) << endl;

        cout << "ISBST: " << (t.isBST() ? "YES" : "NO") << endl;

        return 0;
    }
