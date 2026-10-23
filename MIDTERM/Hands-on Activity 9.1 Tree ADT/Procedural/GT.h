#ifndef GT_H
#define GT_H


#include <iostream>
#include <string>

template <typename T>
class GeneralTree {
    private:
        T key;
        GeneralTree<T>* firstChild;
        GeneralTree<T>* nextSibling;

        // Helper functions for internal traversal tracking during findData
        bool preOrderSearch(T value);
        bool inOrderSearch(T value);
        bool postOrderSearch(T value);
        GeneralTree<T>* findNode(GeneralTree<T>* root, T targetKey);

    public:
        GeneralTree(T value);
        GeneralTree<T>* addChild(T value);

        bool insert(T parentKey, T childValue);

        void preOrder();
        void inOrder();
        void postOrder();

        void findData(std::string choice, T key);
};

template <typename T>
GeneralTree<T>::GeneralTree(T value) {
    key = value;
    firstChild = nullptr;
    nextSibling = nullptr;
}

template <typename T>
GeneralTree<T>* GeneralTree<T>::addChild(T value) {
    GeneralTree<T>* newChild = new GeneralTree<T>(value);
    if (firstChild == nullptr) {
        firstChild = newChild;
    } else {
        GeneralTree<T>* temp = firstChild;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = newChild;
    }
    return newChild;
}

//---------------------------- Traversal Functions ----------------------------

template <typename T>
void GeneralTree<T>::preOrder() {
    std::cout << key << " ";
    if (firstChild != nullptr) firstChild->preOrder();
    if (nextSibling != nullptr) nextSibling->preOrder();
}

template <typename T>
void GeneralTree<T>::inOrder() {
    //Traverse the first child (if it exists)
    if (firstChild != nullptr) {
        firstChild->inOrder();
    }

    //Visit the current root node
    std::cout << key << " ";

    //Traversd all remaining siblings sequentially
    if (firstChild != nullptr) {
        GeneralTree<T>* sibling = firstChild->nextSibling;
        while (sibling != nullptr) {
            sibling->inOrder();
            sibling = sibling->nextSibling;
        }
    }
}

template <typename T>
void GeneralTree<T>::postOrder() {
    //Visssit the leftmost child's subtree completely
    if (firstChild != nullptr) {
        firstChild->postOrder();
    }

    //Visit the current node
    std::cout << key << " ";

    //Visit the remaining siblings' subtrees completely
    if (nextSibling != nullptr) {
        nextSibling->postOrder();
    }
}

//---------------------------- Helper Function ----------------------------

template <typename T>
bool GeneralTree<T>::preOrderSearch(T value) {
    if (key == value) return true;
    if (firstChild != nullptr && firstChild->preOrderSearch(value)) return true;
    if (nextSibling != nullptr && nextSibling->preOrderSearch(value)) return true;
    return false;
}

template <typename T>
bool GeneralTree<T>::inOrderSearch(T value) {
    if (firstChild != nullptr && firstChild->inOrderSearch(value)) {
        return true;
    }
    if (key == value) {
        return true;
    }
    if (firstChild != nullptr) {
        GeneralTree<T>* sibling = firstChild->nextSibling;
        while (sibling != nullptr) {
            if (sibling->inOrderSearch(value)) return true;
            sibling = sibling->nextSibling;
        }
    }
    return false;
}

template <typename T>
bool GeneralTree<T>::postOrderSearch(T value) {
    if (firstChild != nullptr && firstChild->postOrderSearch(value)) {
        return true;
    }
    if (key == value) {
        return true;
    }
    if (nextSibling != nullptr && nextSibling->nextSibling != nullptr) {
        if (nextSibling->postOrderSearch(value)) {
            return true;
        }
    }
    return false;
}

//---------------------------- FindData Function ----------------------------

template <typename T>
void GeneralTree<T>::findData(std::string choice, T key) {
    bool found = false;
    
    if (choice == "PRE") {
        found = preOrderSearch(key);
    } else if (choice == "IN") {
        found = inOrderSearch(key);
    } else if (choice == "POST") {
        found = postOrderSearch(key);
    } else {
        std::cout << "Invalid choice selection!" << std::endl;
        return;
    }

    if (found) {
        std::cout << "{" << key << "} was found!" << std::endl;
    }
}

//---------------------------- Insert Function ----------------------------

// finding the node or the known subroot to insert the child below it
template <typename T>
GeneralTree<T>* GeneralTree<T>::findNode(GeneralTree<T>* root, T targetKey){
    if (root == nullptr) return nullptr;
    if(root->key == targetKey) return root;

    GeneralTree<T>* found = findNode(root->firstChild, targetKey);
    if (found != nullptr) return found;

    // checks the sibling branches 
    return findNode(root->nextSibling, targetKey);

}

template <typename T>
bool GeneralTree<T>::insert(T parentKey, T childValue) {
    GeneralTree<T>* parentNode = findNode(this, parentKey);

    if (parentNode != nullptr) {
        parentNode->addChild(childValue);
        return true;
    }
}

#endif 