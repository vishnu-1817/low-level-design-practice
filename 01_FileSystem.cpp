#include<bits/stdc++.h>
using namespace std;

// Forward declaration
class FileSystemItem;

class FileSystemItem {
protected:
    string name;
    FileSystemItem* parent;

public:
    // Base Constructor to handle initialization correctly
    FileSystemItem(string name) 
    	: name(name), parent(nullptr){}
    FileSystemItem(string name, FileSystemItem* parent) 
        : name(name), parent(parent) {}

    virtual string getName() const { return name; } // Added const for safety (the fn can't change the member varib)
    virtual FileSystemItem* getParent() const { return parent; }
    
    virtual void ls() = 0;
    virtual void showPath() = 0;
    virtual void showSize() = 0;

    // 2. FIX: Added virtual method for adding children so we can call it from Base pointers
    virtual void addFileSystemItem(FileSystemItem* item) {
        cout << "Error: Cannot add items to a File.\n";
    }

    // 3. FIX: Pure virtual destructor MUST have a body
    virtual ~FileSystemItem() {} 
};

// Provide body for pure virtual destructor outside (or use {} above)
// FileSystemItem::~FileSystemItem() {} 

class Folder : public FileSystemItem {
private:
    vector<FileSystemItem*> children;

public:
    // 4. FIX: Call Base Constructor
    Folder(string name, FileSystemItem* parent = nullptr) 
        : FileSystemItem(name, parent) {
        
        // 5. FIX: Auto-link logic. If I have a parent, I add myself to it.
        if (parent != nullptr) {
            parent->addFileSystemItem(this);
        }
    }

    ~Folder() override {
        cout << "Deleting Folder : " << getName() << "\n";
        // 6. FIX: Composite Pattern Ownership
        // When Folder dies, it deletes its children.
        for (FileSystemItem* child : children) {
            delete child;
        }
        children.clear();
    }

    void ls() override {
        cout << "Listing " << getName() << ":\n";
        for (FileSystemItem* child : children) {
            // 7. FIX: Added parentheses to function call
            cout << "  - " << child->getName() << "\n";
        }
    }

    void showPath() override {
        FileSystemItem* currentItem = this;
        while (currentItem != nullptr) {
            // 8. FIX: Print currentItem's name, not 'this' name
            cout << currentItem->getName();
            if(currentItem->getParent() != nullptr) cout << " <- ";
            currentItem = currentItem->getParent();
        }
        cout << "\n";
    }

    void showSize() override {
        cout << "Size calculation of Folder is due\n";
    }

    // Override the Base method to actually store the item
    void addFileSystemItem(FileSystemItem* item) override {
        children.push_back(item);
    }
};

class File : public FileSystemItem {
private:
    string content;

public:
    // 4. FIX: Call Base Constructor
    File(string name, FileSystemItem* parent = nullptr) 
        : FileSystemItem(name, parent) {
        
        // 5. FIX: Auto-link logic
        if (parent != nullptr) {
            parent->addFileSystemItem(this);
        }
    }

    ~File() override {
        // 7. FIX: Added parentheses
        cout << "Deleting File : " << getName() << "\n";
    }

    void ls() override {
        cout << getName() << "\n";
    }

    void showPath() override {
        FileSystemItem* currentItem = this;
        while (currentItem != nullptr) {
            // 8. FIX: Logic corrected
            cout << currentItem->getName();
            if(currentItem->getParent() != nullptr) cout << " <- ";
            currentItem = currentItem->getParent();
        }
        cout << "\n";
    }

    void showSize() override {
        cout << content.size() << "\n";
    }
};

int main() {
    cout << "Hii Bubu\n" << "VS FileSystem\n\n";

    // Create Root
    // Note: We use Folder* explicitly for root if we wanted to call specific folder methods,
    // but since we added addFileSystemItem to Base, FileSystemItem* works too.
    FileSystemItem* root = new Folder("root");

    // Create children (Auto-added to root because of FIX #5)
    FileSystemItem* rootFile1 = new File("rootFile1", root);
    FileSystemItem* rootFile2 = new File("rootFile2", root);
    FileSystemItem* home = new Folder("home", root);
    FileSystemItem* documents = new Folder("documents", root);
    
    // Create a nested file
    FileSystemItem* nestedFile = new File("resume.pdf", home);

    cout << "--- root->ls() ---\n";
    root->ls();
    
    cout << "\n--- home->ls() ---\n";
    home->ls();

    cout << "\n--- Path of nested file ---\n";
    nestedFile->showPath();

    cout << "\n--- Deletion ---\n";
    // 9. FIX: Only delete root. The Folder destructor will recursively delete children.
    delete root; 

    return 0;
}