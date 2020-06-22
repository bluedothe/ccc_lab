#include <string>
#include <iostream>
#include <functional>

class HashMap2
{
    private:
        struct Node
        {
            std::string key;
            std::string value;
            Node* next; 
            //Node(std::string& key, std::string& value):key(key),value(value){}  //error
        };

        static constexpr unsigned int initialBucketCount = 10;
        int curBucketCount;
        int nodeCount;
        //typedef std::function<unsigned int(const std::string&)> HashFunction;
        //HashFunction hasher;

    private:
        unsigned int hasher(const std::string& key)
        {
            return key.length();
        }

        void HashMapCopy(Node** target, Node** source, unsigned int cap);
        void reHash();

    public: 
        Node** table;
        

    public:
        HashMap2()
        {
        std::cout << "hashmap init!" << std::endl;
        curBucketCount = initialBucketCount;
        table = new Node*[curBucketCount]();
        nodeCount = 0;
        //hasher = hash_func_0;
        }

        virtual ~HashMap2()
        {
            delete [] table;
            std::cout << "hashmap is finished!" << std::endl;
        }
        
        void add(const std::string& key,const std::string& value) 
        {
            if (contains(key)) return;
            int index = hasher(key);
            Node* entry = table[index];
            Node* prev = nullptr;

            //find end node pointer
            while (entry != nullptr)
            {
                prev = entry;
                entry = entry->next;
            }

            if (entry == nullptr)
            {
                entry = new Node{key, value};
                if (prev == nullptr)
                {
                    table[index] = entry;
                }else{
                    prev->next = entry;
                }
                nodeCount++;
            }
        }

        std::string value(const std::string& key) 
        {
            std::string result;
            int index = hasher(key);
            Node* entry = table[index];
            while (entry != nullptr)
            {
                if(entry->key == key)
                {
                    result = entry->value;
                    break;
                }else{
                    entry = entry->next;
                }
            }
            
            return result;
        }

        bool contains(const std::string& key) 
        {
            bool result = false;
            int index = hasher(key);
            Node* entry = table[index];
            while (entry != nullptr)
            {
                if(entry->key == key)
                {
                    result = true;
                    break;
                }else{
                    entry = entry->next;
                }
            }
            
            return result;
        }

        void remove(const std::string& key)
        {
            int index = hasher(key);
            Node* entry = table[index];
            Node* prev = entry;
            while (entry != nullptr)
            {
                if(entry->key == key)
                {
                    if(prev != entry)
                    {
                        prev->next = entry->next;
                    }else{
                        table[index] = nullptr;
                    }
                    delete entry;
                    nodeCount--;
                    std::cout << "remove key: " << key << std::endl;
                    break;
                }else{
                    prev = entry;
                    entry = entry->next;
                }
            }
        }

        unsigned int size() const
        {
            return nodeCount;
        }

        unsigned int bucketCount() const
        {
            return curBucketCount;
        }

        double loadFactor() const
        {
            return nodeCount/curBucketCount;
        }

        unsigned int maxBucketSize() const
        {
            unsigned int result = 0;
            for(int i=0; i<curBucketCount; i++)
            {
                unsigned int count = 0;
                Node* entry = table[i];
                while (entry != nullptr)
                {
                    count++;
                    entry = entry->next;
                }
                result = result < count ? count:result;
            }
            
            
            return result;
        }

        void clear()
        {
            
        }

        void PrintAll()
        {
            printTable();
        }

        //for test, watch table data
        void printTable()
        {
            for(int i=0; i<curBucketCount; i++)
            {
                Node* node = table[i];
                if (node == nullptr) continue;
                std::cout << "---in table, index: " << i << "  , key: " << node->key << " next: " << node->next << std::endl;
                Node* p = node->next;
                while (p != nullptr){
                    std::cout << "------in table, index: " << i << "  , key: " << p->key << " next: " << p->next << std::endl;
                    p = p->next;
                }/**/
            }
        }

};

int main()
{
    HashMap2 hm;
    std::string key = "tonye";
    std::string value = "Tonystus";
    hm.add(key, value);
    hm.add("hzy", "bluedothe");
    hm.add("rices", "ricesname");
    hm.add("Marya", "ricesname");
    std::cout << "in main: " << &hm.table << std::endl;
    std::cout << "in main, isContains:" << hm.contains("tony") << std::endl;
    std::cout << "in main, isContains:" << hm.contains("rices") << std::endl;
    std::cout << "in main, isContains:" << hm.contains("hzy") << std::endl;
    std::cout << "in main, isContains:" << hm.contains("tonye") << std::endl;
    std::cout << "in main, value:" << hm.value("hzy") << std::endl;
    std::cout << "in main, value:" << hm.value("hzyong") << std::endl;
    std::cout << "in main, maxBucketSize:" << hm.maxBucketSize() << std::endl;
    hm.printTable();
    hm.remove("rices");
    hm.remove("hzy");
    hm.printTable();
    return 0;
}