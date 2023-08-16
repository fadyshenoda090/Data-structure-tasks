#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node()
    {
        data = 0;
        right = left = NULL;
    }
    node(int _data)
    {
        data = _data;
        right = left = NULL;
    }
};

class tree
{
    node *root;
public:
    tree()
    {
        root = NULL;
    }

    void add(int data)
    {
        node *newnode = new node(data);
        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            node *pcurrent = root;
            node *pparent = pcurrent;
            while (pcurrent != NULL)
            {
                pparent = pcurrent;
                if (newnode->data > pcurrent->data)
                {
                    pcurrent = pcurrent->right;
                }
                else
                {
                    pcurrent = pcurrent->left;
                }
            }
            if (newnode->data < pparent->data)
            {
                pparent->left = newnode;
            }
            else
            {
                pparent->right = newnode;
            }
        }
    }

    node *searchnode(int psearach)
    {
        node *pcurrent = root;
        while (pcurrent != NULL)
        {
            if (psearach == pcurrent->data)
            {
                return pcurrent;
            }
            else if (psearach > pcurrent->data)
            {
                pcurrent = pcurrent->right;
            }
            else
            {
                pcurrent = pcurrent->left;
            }
        }
        return NULL;
    }

    node* parent(node* child)
    {
        node*pcurrent=root;
        while(pcurrent!=NULL)
        {
            if(pcurrent->right==child || pcurrent->left==child)
            {
                return pcurrent;
            }
            else if(child->data >pcurrent->data)
            {
                pcurrent=pcurrent->right;
            }
            else
            {
                pcurrent=pcurrent->left;
            }
        }
        return NULL;
    }
    void deletenode(node* pdelete)
    {
        //if the node is root
        if(pdelete==root)
        {
            //root with no children
            if(pdelete->right==NULL && pdelete->left==NULL)
            {
                root=NULL;
            }//root with one right child
            else if(root->left==NULL)
            {
                root=root->right;
            }//root with one left child
            else if(root->right==NULL)
            {
                root=root->left;
            }
            //root with two children
            else
            {
                node* pcurrent =root->right;
                while(pcurrent->left!=NULL)
                {
                    pcurrent=pcurrent->left;
                }
                node* pparent=parent(pcurrent);
                pcurrent->left=root->left;
                pcurrent->right=root->right;
                root=pcurrent;
                pparent->left=NULL;
            }
        }
        else//the node is not the root
        {
            node* pparent=parent(pdelete);
            //with no children
            if(pdelete->left==NULL && pdelete->right==NULL)
            {
                if(pparent->left==pdelete)
                {
                    pparent->left=NULL;
                }
                else
                {
                    pparent->right=NULL;
                }
            }//with one right child
            else if(pdelete->left==NULL)
            {
                if(pparent->left==pdelete)
                {
                    pparent->left=pdelete->right;
                }
                else
                {
                    pparent->right=pdelete->right;
                }
            }//with one left child
            else if(pdelete->right==NULL)
            {
                if(pparent->left==pdelete)
                {
                    pparent->left=pdelete->left;
                }
                else
                {
                    pparent->right=pdelete->left;
                }
            }
            else//with two children
            {
                node* pcurrent=pdelete->right;
                while(pcurrent->left!=NULL)
                {
                    pcurrent=pcurrent->left;
                }
                pcurrent->left=pdelete->left;
                if(pparent->right==pdelete)
                {
                    pparent->left = pdelete->right;
                }
                else
                {
                    pparent->right = pdelete->right;
                }
            }
        }
        delete pdelete;
    }

//lab RDL(right data left)
    void RDLdisplay()
    {
        RDLdisplay(root);
    }
private:
    void RDLdisplay(node* pdisplay)
    {
        if(pdisplay==NULL)
        {
            return;
        }
        RDLdisplay(pdisplay->right);
        cout<<pdisplay->data<<endl;
        RDLdisplay(pdisplay->left);
    }
};

int main()
{
    tree t;
    node* parent;

    t.add(1);
    t.add(20);
    t.add(50);
    t.add(9);
    t.add(65);
    t.add(70);
    t.add(10);
    t.RDLdisplay();
    node* element=t.searchnode(10);
    if(element!=NULL)
    {
        parent=t.parent(element);
        if(parent==NULL)
        {
            cout<<"no parent was found\n";
        }
        else
        {
            cout<<"the parent of the "<<element->data<<" is "<<parent->data<<endl;
        }
        t.deletenode(element);
        t.RDLdisplay();
    }
    else
    {
        cout<<"no element equal to "<<element<<" was found \n";
    }

    return 0;
}
