#include<bits/stdc++.h>
using namespace std;

struct folder_node
{
	string name;//name of file or folder
	struct folder_node* next;//points to next folder or next file
	struct folder_node* file;//points to first file of current folder
};

struct folder_node* current;

folder_node* newfolder(string name)//new node for folder
{
	struct folder_node* temp=(struct folder_node*)malloc(sizeof(struct folder_node));
	temp->name=name;
	temp->next=NULL;
	temp->file=NULL;
	return temp;
}

folder_node* newfile(string name)//new node for file
{
	struct folder_node* temp=(struct folder_node*)malloc(sizeof(struct folder_node));
	temp->name=name;
	temp->next=NULL;
	temp->file=NULL;
	return temp;
}

void NEW(string x)//new folder in current folder and then changing the current folder 
{
	struct folder_node* q=newfolder(x);
	current->next=q;
	cout<<"Made "<<x<<" in "<<current->name<<endl;
	current=q;
	
}

void CREATE(string x)//creating new file in current file ahead of the previous ones
{
	struct folder_node* temp_file=newfile(x);
	if(current->file==NULL)
	{
		current->file=temp_file;
		cout<<"Created "<<x<<" in "<<current->name<<endl;
	}
	else
	{
		struct folder_node* p=current->file;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp_file;
		cout<<"Created "<<x<<" in "<<current->name<<endl;
	}
}

void DELETE()//delete the first file inserted in current folder 
{
	if(current->file==NULL){cout<<"Cannot delete file from "<<current->name<<endl;return ;}
	struct folder_node* temp=current->file;
	current->file=NULL;
	current->file=temp->next; 
	temp->next=NULL;
	cout<<"Deleted "<<temp->name<<" from "<<current->name<<endl;
	free(temp);
}

void delete_all_files()//delete all the files of the current folder
{
	if(current->file==NULL)
	{
		return ;
	}
	else
	{
		struct folder_node* p=current->file,*q;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
			free(q);
		}
		free(p);
		current->file=NULL;
		cout<<"deleted all files in "<<current->name<<endl;
	}
}

void BACK(struct folder_node* root)//go to previous folder deleting all the and the current folderS
{
	if(current==root)
	{
		cout<<"cannot go back from root"<<endl;
		return ;
	}
	else
	{
		delete_all_files();
		struct folder_node* p=root;
		while(p->next!=current)
		{
			p=p->next;
		}
		struct folder_node* temp=current;
		current=p;
		p->next=NULL;
		cout<<"Back from "<<temp->name<<endl;
		free(temp);
	}
}



int main()
{
	struct folder_node* root=newfolder("root");
	current=root;
	string function="",text;
	cout<<"start"<<endl;
	while(function!="-1")
	{
		cin>>function;
		if(function=="CREATE")//create file text inside latest folder 
		{
			cin>>text;
			CREATE(text);
		}
		else if(function=="NEW")//create text folder after latest folder
		{
			cin>>text;
			NEW(text);
		}
		else if(function=="DELETE")//oldest file inside lastest folder will be deleted
		{
			DELETE();
		}
		else if(function=="BACK")//return to parent folder of latest folder deleting everything inside it 
		{
			BACK(root);
		}
		else if(function=="-1")//end the process
		{
			return 0;
		}
	}
}