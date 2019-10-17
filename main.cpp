#include <iostream>
#include <stdint.h>
using namespace std;

struct BST_node{
    BST_node *parent,*left,*right;
    int key;
};

BST_node* search_root(BST_node* &node)
{
    BST_node*tmp=node;
    while((tmp->parent)!=nullptr)
    {
        tmp=tmp->parent;
    }
    return tmp;
}
bool search_key(BST_node* node, int key)
{
    BST_node* root=new BST_node;
    root=search_root(node);
    while(true)
    {
        if(key==root->key)
        {
            return true;

        }
        else if(key>root->key)
        {
            if(root->right!=nullptr)
                root=root->right;
            else
                return false;
        }
        else
        {
            if(root->left!=nullptr)
                root=root->left;
            else
                return false;
        }
    }
}
BST_node* search_key_node(BST_node* node, int key)
{
    BST_node* root=new BST_node;
    root=search_root(node);
    while(true)
    {
        if(key==root->key)
        {
            break;

        }
        else if(key>root->key)
        {
            if(root->right!=nullptr)
                root=root->right;
            else return nullptr;
            if(key==root->key)
                break;
        }
        else
        {
            if(root->left!=nullptr)
                root=root->left;
            else return nullptr;
            if(key==root->key)
                break;
        }
    }
    return root;
}
void pre_order(BST_node* initial)
{
    if(initial)
    {
        cout<<initial->key<<"\t";
        pre_order(initial->left);
        pre_order(initial->right);
    }

}
BST_node* minimum(BST_node* node)
{
    BST_node* tmp=new BST_node;
    tmp=node;
    while(tmp->left!=nullptr)
    {
        tmp=tmp->left;
    }
    return tmp;
}

BST_node* maksimum(BST_node* node)
{
    BST_node* tmp=new BST_node;
    tmp=node;
    while(tmp->right!=nullptr)
    {
        tmp=tmp->right;
    }
    return tmp;
}
BST_node* previous(BST_node* initial)
{
    BST_node* tmp=new BST_node;
    tmp=initial;
    BST_node* y=new BST_node;
    if(tmp->left!=nullptr)
    {
        return maksimum(tmp->left);
    }
    else
    {
        do
        {
            y=tmp;
            tmp=tmp->parent;
        } while ((tmp)&&(tmp->right!=y));
        return tmp;
    }
}
BST_node* next(BST_node* initial)
{
    BST_node* tmp=new BST_node;
    tmp=initial;
    BST_node* y=new BST_node;
    if(tmp->left!=nullptr)
    {
        return minimum(tmp->right);
    }
    else
    {
        do
        {
            y=tmp;
            tmp=tmp->parent;
        } while ((tmp)&&(tmp->left!=y));
        return tmp;
    }
}
void delete_node(BST_node* &initial,int key)
{
    BST_node* tmp=search_key_node(initial, key);
    if(tmp==nullptr)
    {
        cout<<"nie ma takiego elementu\n";
    }
    else
    {
        if((tmp->left==nullptr)&&(tmp->right==nullptr))
        {
            if(tmp->key>tmp->parent->key)
            {
                tmp->parent->right=nullptr;
            }
            else
            {
                tmp->parent->left=nullptr;
            }
        }
        if((tmp->left!=nullptr)&&(tmp->right!=nullptr))
        {
            BST_node* nastepnik=next(tmp);
            if(nastepnik->right!=nullptr)
            {
                nastepnik->parent->left=nastepnik->right;
                nastepnik->right->parent=nastepnik->parent;
            }
            if(key<tmp->parent->key)
            {
                tmp->parent->left=nastepnik;
            }
            else
            {
                tmp->parent->right=nastepnik;
            }
            nastepnik->parent=tmp->parent;
            nastepnik->left=tmp->left;
            nastepnik->right=tmp->right;
        }
        else
        {
            if(tmp->left!=nullptr)
            {
                if(tmp->parent->left==tmp)
                {
                    tmp->parent->left=tmp->left;
                    tmp->left->parent=tmp->parent;
                }
                else
                {
                    tmp->parent->right=tmp->left;
                    tmp->left->parent=tmp->parent;
                }
            }
            else
                if(tmp->parent->left==tmp)
                {
                    tmp->parent->left=tmp->right;
                    tmp->right->parent=tmp->parent;
                }
                else
                {
                    tmp->parent->right=tmp->right;
                    tmp->right->parent=tmp->parent;
                }
        }
    }
}


void add_node(BST_node* &initial, int key)
{
    if(search_key(initial,key))
    {
        std::cout<<"Already in BST tree\n";
    }
    else
    {
        BST_node* new_node=new BST_node;
        new_node->left=nullptr;
        new_node->right=nullptr;
        new_node->parent=nullptr;
        new_node->key=key;

        BST_node*tmp=new BST_node;

        if(initial==nullptr)
        {
            initial=new_node;
        }
        else
        {
            tmp=search_root(initial);
            while(true)
            {
                if(key>tmp->key)
                {
                    if(tmp->right!=nullptr)
                        tmp=tmp->right;
                    else
                    {
                        tmp->right=new_node;
                        new_node->parent=tmp;
                        break;
                    }
                }
                else
                {
                    if(tmp->left!=nullptr)
                        tmp=tmp->left;
                    else
                    {
                        tmp->left=new_node;
                        new_node->parent=tmp;
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    BST_node* damian=new BST_node;
    BST_node* iwas=new BST_node;
    BST_node* robert=new BST_node;
    damian->key=5;
    damian->parent=nullptr;
    damian->left=iwas;
    damian->right=robert;
    robert->parent=damian;
    iwas->parent=damian;
    robert->key=6;
    iwas->key=3;
    iwas->left=nullptr;
    robert->left=nullptr;
    iwas->right=nullptr;
    robert->right=nullptr;

    cout<<"&damian=\t"<<&damian<<endl;
    cout<<"damian=\t"<<damian<<endl;
    cout<<"&damian_parent=\t"<<&(damian->parent)<<endl;
    cout<<"damian_parent=\t"<<(damian->parent)<<endl;
//    add_node(damian,5);
//    add_node(damian,4);
//    add_node(damian,10);
//    add_node(damian,12);
    //pre_order(damian);
    //cout<<"znaleziony korzeń to:  \t"<<search_root(robert)<<endl;
    //cout<<search_key(damian,10)<<endl;
    add_node(damian,10);
    add_node(damian,8);
    pre_order(damian);
    delete_node(damian,8);
    pre_order(damian);
    return 0;
}
