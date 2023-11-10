/*
 *	queue.hpp
 *	A standard generic Queue data structure.
 */

template <typename T>
class Queue{
	private:
		struct QueueNode{
			T* data;
			QueueNode* next;
		};

		typedef struct QueueNode QueueNode;
		QueueNode* start {NULL};
		QueueNode* end {NULL};

	public:
		void add(T* data){
			QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));
			newNode->data = data;
			newNode->next = NULL;

			if(start == NULL){
				start = newNode;
				end = newNode;
			}else{
				end->next = newNode;
				end = end->next;
			}
		}

		T* remove(){
			QueueNode* removed = start;
			T* data = removed->data;
			
			if(start == end){
				start = NULL;
				end = NULL;
			}else{
				start = start->next;
				removed->next = NULL;
			}

			free(removed);
			return data;
		}

		T* get(int index){
			QueueNode* iter = start;
			while(iter != NULL){
			if(index-- == 0) return iter->data;
				iter = iter->next;
			}
			return NULL;
		}

		int contains(T* element){
			int count = 0;
			QueueNode* iter = start;
			while(iter != NULL){
				if(iter->data = element) count++;
				iter = iter->next;
			}
			return count;
		}

		int size(){
			int size = 0;
			QueueNode* iter = start;
			while(iter != NULL){
				iter = iter->next;
				size++;
			}
			return size;
		}

		void clear(){
			while(start != NULL){
				remove();
			}
		}
};
