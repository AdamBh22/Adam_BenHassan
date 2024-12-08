#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define make_pair mp 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vl vector<long long int>
#define pi pair<int,int>
#define pl pair<long long int ,long long int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define endl '\n'
const double eps=1e-12;
int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
const int mod=1e9+7;
class Task_Category{
private:
	set<string> categories;
	static Task_Category* categoryInstance;
	Task_Category(){};
public:
	Task_Category(const Task_Category &obj) = delete;
	static Task_Category* getInstancer(){
        if(categoryInstance == nullptr){
            categoryInstance = new Task_Category();
        }
        return categoryInstance ;
    }
    void add_Category(string category){
    	categories.insert(category);
    }
	set<string> getCategory(){
		return categories;
	}
	virtual ~Task_Category(){}
};

class Software_Category{
private:
	string description;
	int due_date;
public:
	Software_Category(string description ,int due_date){
		description = description ;
		due_date = due_date;
		categoryInstance.insert("Software_Category");
	};

	string getDescription(){
		return description ;
	}

	int getDue_Date(){
		return due_date;
	}

	void setDescription(string newDescription){
		description = newDescription ;
	}

	void serDue_Date(int newDate){
		due_date = newDate;
	}
	~Software_Category(){}
};

class Priority{
private:
	int priority ;
public:
	Priority(string ch){
		if(ch == "Low") priority = 0;
		else if(ch == "Middle") priority = 1;
		else priority = 2;
	}
	int getPriority(){
		return priority;
	}
	bool operator < (Priority* other){
		return this->priority >= other->priority;
	} 
	virtual ~Priority(){};
};

class Low_Priority : public Priority{
public:
	Low_Priority():Priority("Low"){};
	~Low_Priority(){};
};
class High_Priority : public Priority{
public:
	High_Priority():Priority("High"){};
	~High_Priority(){};
};
class Middle_Priority : public Priority{
public:
	Middle_Priority():Priority("Middle"){};
	~Middle_Priority(){};
};

class UnitTest_Development : public Software_Category , public Low_Priority{
private:
	string title;
public:
	UnitTest_Development(string title ,string description ,int due_date):title(title),Software_Category(description,due_date),Low_Priority(){};
	string getTitle(){
		return title ;
	}
	~UnitTest_Development(){};
};
class Backend_Development : public Software_Category , public High_Priority{
private:
	string title;
public:
	Backend_Development(string title ,string description ,int due_date):title(title),Software_Category(description,due_date),High_Priority(){};
	string getTitle(){
		return title;
	}
	~Backend_Development(){};
};

class Frontend_Development : public Software_Category , public Middle_Priority{
private:
	string title;
public:
	string getTitle(){
		return title;
	}
	~Frontend_Development(){};
};

class TaskPriority{
private:
	priority_queue<Priority*> tasks;
public:
	Task_Priority(){};
	void addTask(Priority* task){
		tasks.push(task);
	}
	Priority* getNextTask(){
		if(tasks.empty()){
			cout<<"Waring there is no tasks"<<endl;
		}
		else return tasks.front();
	}
	priority_queue<Priority*> getAllTasks(){
		return tasks;
	}
	void delete_task(){
		if(tasks.empty()){
			cout<<"Waring there is no tasks"<<endl;
			return;
		}
		tasks.pop();
	}
	~Task_Priority(){};
}
class Task_Operations{
private:
	Task_Category task_Category;
	TaskPriority taskPriority;
public:
	void add_FrontEnd_Task(string title ,string description ,int due_date){
		Frontend_Development* task =new Frontend_Development(title,description,due_date);
		taskPriority.addTask(task);
	}
	void add_Backend_Task(string title ,string description ,int due_date){
		Backend_Development* task =new Backend_Development(title,description,due_date);
		taskPriority.addTask(task);
	}
	void delete_task{
		taskPriority.delete_task();
	}
	priority_queue<Priority> getAllTasks(){
		return this->taskPriority.getAllTasks();
	}
};
Task_Category* Task_Category::categoryInstance = nullptr;
int main() {
    fast;
 //   Task_Category* task_Category = Task_Category::getInstancer();
}
