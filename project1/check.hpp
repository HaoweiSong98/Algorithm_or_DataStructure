
template<typename Object>
class LLQueue
{
private:
	struct node{
		Object data;
		node *next = nullptr;
	};
	node *front, *rear;
	// fill in private member data here

public:
	LLQueue();

//	These are copy constructors and  assignment operators. 
	// These should be "deep copies" -- copy the contents, not just a pointer to the front. 
	LLQueue(const LLQueue & st);
	LLQueue & operator=(const LLQueue & st);
	~LLQueue()
	{
		// You do need to implement the destructor though.
		node newfront = this->front;
		while(newfront != nullptr){
			newfront = newfront->next;
			delete front;
			front = newfront;
		}
	}

	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	// We have two front() for the same reason the Stack in lecture week 2 had two top() functions.
	// If you do not know why there are two, your FIRST step needs to be to review your notes from that lecture.

	Object & front();
	const Object & front() const;

	void enqueue(const Object & elem);

// does not return anything.  Just removes. 
	void dequeue();
};

// TODO:  Fill in the functions here. 
template<typename Object>
LLQueue<Object>::LLQueue(){
	node *newnode = new node;
	this->front = newnode;
	this->rear = newnode;
}

template<typename Object>
LLQueue<Object>::LLQueue(const LLQueue<Object> & st){
	if(st.front != nullptr){
		Object get_data = st.front->data;
		node *changenode = new node;
		changenode->data = get_data;
		changenode->next = NULL;
		this->front = changenode;
		this->rear = changenode;
		while(st.front->next){
			st.front = st.front->next;
			this->rear->next = new node;
			this->rear->data = st.front->data;
			
		}
	}
	

}
template<typename Object>
LLQueue<Object> & LLQueue<Object>::operator=(const LLQueue<Object> & st){

}

#endif 
