#include <iostream>
using namespace std;
const int branchNum = 26; //�������� 
int i;
struct Trie_node
{
    bool isStr; //��¼�˴��Ƿ񹹳�һ������
    Trie_node *next[branchNum];//ָ�����������ָ��,�±�0-25����26�ַ�
    Trie_node():isStr(false)
    {
        memset(next,NULL,sizeof(next));
    }
};
class Trie
{
public:
    Trie();
    void insert(const char* word);
    bool search(char* word); 
    void deleteTrie(Trie_node *root);
	private:
    Trie_node* root;
};
Trie::Trie()
{
    root = new Trie_node();
}
void Trie::insert(const char* word)
{
    Trie_node *location = root;
    while(*word)
    {
        if(location->next[*word-'a'] == NULL)//����������
		  {
            Trie_node *tmp = new Trie_node();
            location->next[*word-'a'] = tmp;
        }    
        location = location->next[*word-'a']; //ÿ����һ�����൱����һ���´�������ָ��Ҫ�����ƶ�
        word++;
    }
    location->isStr = true; //����β��,���һ����
}

	bool Trie::search(char *word)
{
    Trie_node *location = root;
    while(*word && location)
    {
        location = location->next[*word-'a'];
        word++;
    }
    return(location!=NULL && location->isStr);
}

void Trie::deleteTrie(Trie_node *root)
{
    for(i = 0; i < branchNum; i++)
    {
        if(root->next[i] != NULL)
        {
            deleteTrie(root->next[i]);
        }
    }
    delete root;
}

void main() //�򵥲���
{
    Trie t;
    t.insert("a");         
    t.insert("abandon");
    char * c = "abandoned";
    t.insert(c);
    t.insert("abashed");
    if(t.search("abashed"))
        printf("true\n");
}