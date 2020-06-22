#include <string>
#include <iostream>
#include <functional>

//https://blog.csdn.net/as480133937/article/details/83473208?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase

class HashMap
{
    private:
        struct Node
        {
            std::string key;
            std::string value;
            Node* next = nullptr;
        };

        static constexpr unsigned int initialBucketCount = 10;
        int curBucketCount;
        //typedef std::function<unsigned int(const std::string&)> HashFunction;
        //HashFunction hasher;

    private:
        unsigned int hasher(const std::string& key)
        {
            return key.length();
        }

    public: 
        Node* table;
        

    public:
        HashMap()
        {
        std::cout << "hashmap init!" << std::endl;
        curBucketCount = initialBucketCount;
        table = new Node[curBucketCount]();
        //hasher = hash_func_0;
        }

        ~HashMap()
        {
            delete [] table;
            std::cout << "hashmap is finished!" << std::endl;
        }
        
        void add(const std::string& key,const std::string& value) 
        {
            if (contains(key))
            {
                return;
            }

            int index = hasher(key);
            std::cout << "in add,index: " << index << std::endl;
            Node* entry = new Node();
            entry->key = key;
            entry->value = value;
            entry->next = nullptr;

            if (table[index].key == ""){
                table[index] = *entry;
                std::cout << "in add, first add!" << " , add node add: " << entry << std::endl;
            }else{
                entry->next = &table[index];
                table[index] = *entry;
                std::cout << "in add, not first add!" << " , add node add: " << entry << std::endl;
            }
            
            std::string k = table[index].key;
            std::string val = table[index].value;
            std::cout << val << std::endl;
            //std::cout << "in add 2: " << entry << std::endl;
            std::cout << "in add, value: " << val << std::endl;
        }

        std::string value(const std::string& key) 
        {
            int index = hasher(key);
            Node entry = table[index];
            //std::string k = entry->key;
            //std::string val = entry.value;
            std::cout << "in get: " << entry.value << std::endl;
            return entry.value;
        }

        bool contains(const std::string& key) 
        {
            bool result = false;
            int index = hasher(key);
            Node entry = table[index];
            if (entry.key == key)
            {
                result = true;
                return result;
            }
            while (entry.next != 0){
                    entry = *(entry.next);
                    if (entry.key == key)
                    {
                        result = true;
                        return result;
                    }
                }
            return result;
        }

        //for test, watch table data
        void printTable()
        {
            for(int i=0; i<curBucketCount; i++)
            {
                Node node = table[i];
                std::cout << "---in table, index: " << i << "  , key: " << node.key << " next: " << node.next << std::endl;
                Node* p = node.next;
                if (p != 0){
                    p = p->next;
                    std::cout << "------in table, index: " << i << "  , key: " << p->key << " next: " << p->next << std::endl;
                }/**/
            }
        }

};

int main()
{
    HashMap hm;
    std::string key = "tonye";
    std::string value = "Tonystus";
    hm.add(key, value);
    std::string val = hm.value(key);
    //printf("in main, value:%s\n", val.c_str());
    std::cout << "in main, value:" << val << std::endl;
    bool isContains = hm.contains("tony");
    std::cout << "in main, isContains:" << isContains << std::endl;
    hm.add("hzy", "bluedothe");
    hm.add("rices", "ricesname");
    hm.printTable();
    return 0;
}