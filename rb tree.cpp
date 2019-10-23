// Red Black Tree - Insertion, Deletion, Searching

#include<iostream>
using namespace std;

// template class for queue and its node

template<class T>
class queue;
template<class T>
class qnode
{
    	T i;
    	qnode<T> *next; 
        friend class queue<T>;     
    public:
        qnode(T s=0, qnode<T> *n=NULL)
        {
            i=s;
            next=n;
        }
};
template<class T>
class queue
{
        qnode<T> *front, *rear;
    public:
        queue()
        {
            front=NULL;
            rear=NULL;
        }
        void enqueue(T x);            
        T dequeue(); 
		bool isEmpty()
        {
        	if(front==NULL)
        		return true;
        	else 
				return false;
		}
		int get_size()
		{
			qnode<T> *temp=front;
			int s=0;
			while(temp!=NULL)
			{
				temp=temp->next;
				s++;
			}
			return s;
		}
};
template<class T>
void queue<T>::enqueue(T x)
{
    qnode<T> *n=new qnode<T>(x);
    if(n==NULL)
    {
    	cout<<"\n Overflow Condition: Out of memory!";
	}
    if(front==NULL)
	{
		front=n;
		rear=n;
	}
    else
    {
        qnode<T> *temp=rear;
        temp->next=n;
        rear=rear->next;
    }
}
template<class T>
T queue<T>::dequeue()
{
	if(front==NULL)
	{
		return NULL;
	}
	else
	{
		qnode<T> *t=front;
		front=front->next;
		T temp=t->i;
		delete t;
		return temp;
	}
}


// RB Tree and its classes

class tnode
{
		char color;
		int key;
		tnode *p;
		tnode *left, *right;
		friend class rbtree;
	public:
		tnode(char c, int k)
		{
			color=c;
			key=k;
			p=left=right=NULL;
		}
		tnode(int k)
		{
			color='r';
			key=k;
			p=left=right=NULL;
		}
};
class rbtree
{
		tnode *root;
	public:
		tnode *nil;
		rbtree()
		{
			nil=new tnode('b',-999);
			root=nil;
		}
		void leftRotate(tnode *x)
		{
			tnode *y=x->right;
			x->right=y->left;
			if(y->left!=nil)
				y->left->p=x;
			y->p=x->p;
			if(x->p==nil)
				root=y;
			else if(x==x->p->left)
				x->p->left=y;
			else
				x->p->right=y;
			y->left=x;
			x->p=y;
		}
		void rightRotate(tnode *x)
		{
			tnode *y=x->left;
			x->left=y->right;
			if(y->right!=nil)
				y->right->p=x;
			y->p=x->p;
			if(x->p==nil)
				root=y;
			else if(x==x->p->right)
				x->p->right=y;
			else
				x->p->left=y;
			y->right=x;
			x->p=y;
		}
		void insert(int zkey)
		{
			tnode *z=new tnode(zkey);
			tnode *y=nil;
			tnode *x=root;
			while(x!=nil)
			{
				y=x;
				if(z->key<x->key)
					x=x->left;
				else
					x=x->right;
			}
			z->p=y;
			if(y==nil)
			{
				root=z;
			}
			else if(z->key<y->key)
				y->left=z;
			else
				y->right=z;
			z->left=nil;
			z->right=nil;
			z->color='r';
			insertfixup(z);
		}
		void insertfixup(tnode *z)
		{
			while(z->p->color=='r')
			{
				if(z->p==z->p->p->left)
				{
					tnode *y=z->p->p->right;
					if(y->color=='r')
					{
						z->p->color='b';
						y->color='b';
						z->p->p->color='r';
						z=z->p->p;
					}
					else
					{
						if(z==z->p->right)
						{
							z=z->p;
							leftRotate(z);
						}
						z->p->color='b';
						z->p->p->color='r';
						rightRotate(z->p->p);
					}
				}
				else
				{
					tnode *y=z->p->p->left;
					if(y->color=='r')
					{
						z->p->color='b';
						y->color='b';
						z->p->p->color='r';
						z=z->p->p;
					}
					else
					{
						if(z==z->p->left)
						{
							z=z->p;
							rightRotate(z);
						}
						z->p->color='b';
						z->p->p->color='r';
						leftRotate(z->p->p);
					}
				}
			}
			root->color='b';
		}
		void breadth_first()
		{
			queue<tnode*> q;
			int num=0;
			tnode *p=root;
			if(p!=0)
			{
				cout<<"\n Breadth-First Traversal: "<<endl;
				q.enqueue(p);
				while(!q.isEmpty())
				{
					p=q.dequeue();
					if(p->key!=-999)
					{
						cout<<"\n Node: "<<num;
						cout<<"    Key: "<<p->key;
						cout<<"    Color: "<<p->color;
						num++;
					}
					if(p->left!=0)
						q.enqueue(p->left);
					if(p->right!=0)
						q.enqueue(p->right);			
				}
				cout<<endl;	
			}
		}
		void transplant(tnode *u, tnode *v)
		{
			if(u->p==nil)
				root=v;
			else if(u==u->p->left)
			{
				u->p->left=v;
			}
			else
				u->p->right=v;
			v->p=u->p;
		}
		tnode* treemin(tnode *x)
		{
			while(x->left!=nil)
				x=x->left;
			return x;
		}
		void deletenode(int zkey)
		{
			tnode *z=search(zkey);	
			tnode *y=z;
			tnode *x;
			char y_original_color=y->color;
			if(z->left==nil)
			{
				x=z->right;
				transplant(z,z->right);
			}
			else if(z->right==nil)
			{
				x=z->left;
				transplant(z,z->left);
			}
			else
			{
				y=treemin(z->right);
				y_original_color=y->color;
				x=y->right;
				if(y->p==z)
				{
					x->p=y;
				}
				else
				{
					transplant(y,y->right);
					y->right=z->right;
					y->right->p=y;
				}
				transplant(z,y);
				y->left=z->left;
				y->left->p=y;
				y->color=z->color;
			}
			if(y_original_color=='b')
				deletefixup(x);
		}
		void deletefixup(tnode *x)
		{
			while(x!=root && x->color=='b')
			{
				if(x==x->p->left)
				{
					tnode *w=x->p->right;
					if(w->color=='r')
					{
						w->color='b';
						x->p->color='r';
						leftRotate(x->p);
						w=x->p->right;
					}
					if(w->left->color=='b' && w->right->color=='b')
					{
						w->color='r';
						x=x->p;
					}
					else
					{
						if(w->right->color=='b')
						{
							w->left->color='b';
							w->color='r';
							rightRotate(w);
							w=x->p->right;
						}
						w->color=x->p->color;
						x->p->color='b';
						w->right->color='b';
						leftRotate(x->p);
						x=root;
					}
				}
				else
				{
					tnode *w=x->p->left;
					if(w->color=='r')
					{
						w->color='b';
						x->p->color='r';
						rightRotate(x->p);
						w=x->p->left;
					}
					if(w->left->color=='b' && w->right->color=='b')
					{
						w->color='r';
						x=x->p;
					}
					else
					{
						if(w->left->color=='b')
						{
							w->right->color='b';
							w->color='r';
							leftRotate(w);
							w=x->p->left;
						}
						w->color=x->p->color;
						x->p->color='b';
						w->left->color='b';
						rightRotate(x->p);
						x=root;
					}
				}
			}
			x->color='b';
		}
		tnode* search(int xkey)
		{
			tnode *temp=root;
			while(temp!=nil)
			{
				if(temp->key==xkey)
				{
					return temp;
				}
				else if(xkey<temp->key)
					temp=temp->left;
				else
					temp=temp->right;
			}
			if(temp==nil)
				return nil;
		}		
};
int main()
{
	rbtree r;
	r.insert(41);
	r.insert(38);
	r.insert(31);
	r.insert(12);
	r.insert(19);
	r.insert(8);
	r.breadth_first();
	r.deletenode(8);
	r.deletenode(12);
	r.breadth_first();
	return 0;
}
