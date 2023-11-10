/*
 *	stack.h
 *	Interface for a standard generic stack.
 */

template <typename T>
class Stack{
	private:
		struct StackNode{
			T* data;
			StackNode* next;
			StackNode* prev;
		}

		StackNode* bottom;
		StackNode* top;
	
	public:
		Stack();
		void push(T* data){
			StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
			newNode->data = data;

			if(bottom == NULL){
				bottom = newNode;
				top = newNode;
			}else{
				top->next = newNode;
				newNode->prev = top;
				top = top->next;
			}
		}

		T* pop(){
			StackNode* removed = top;
			if(top == bottom){
				top = NULL;
				bottom = NULL;
			}else{
				top = top->prev;
				top->next = NULL;
				removed->prev = NULL;
			}

			T* data = removed->data;
			if(removed != NULL) free(removed);
			return data;
		};

		void clear(){
			while(top != bottom && bottom != NULL){
				pop();
			}
		};
}
