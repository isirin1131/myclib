#include"MyList.h"
#include<assert.h>

List* List_create() {
	return calloc(1, sizeof(List));
}

void List_destory(List* list) {
	LIST_FOREACH(list, first, next, cur) {
		if(cur->prev) free(cur->prev);
	}

	free(list->last);
	free(list);
}

void List_clear(List* list) {
	LIST_FOREACH(list, first, next, cur) {
		free(cur->value);
	}
}

void List_clear_destory(List* list) {
	List_clear(list);
	List_destory(list);
}

void List_push(List* list, void* value) {
	ListNode* node = calloc(1, sizeof(ListNode));

	node->value = value;

	if(list->last == NULL) {
		list->first = list->last = node;
	} else {
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}

	list->count++;
	
error:
	return;
}

void* List_pop(List *list) {
	ListNode* node = list->last;
	return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List* list, void* value) {
	ListNode* node = calloc(1, sizeof(ListNode));
	node->value = value;

	if(list->first == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->first->prev = node;
		node->next = list->first;
		list->first = node;
	}

	list->count++;
error:
	return;
}

void* List_shift(List* list) {
	ListNode* node = list->first;
	return node != NULL ? List_remove(list, node) : NULL;
}

void* List_remove(List* list, ListNode* node) {
	void* res = NULL;
	assert(list->count>0 && node!=NULL);

	if(node == list->first && node == list->last) {
		list->first = list->last = NULL;
	} else if(node == list->first) {
		list->first = node->next;
		list->first->prev = NULL;
	} else if(node == list->last) {
		list->last = node->prev;
		list->last->next = NULL;
	} else {
		ListNode* before = node->prev;
		ListNode* after = node->next;
		before->next = after;
		after->prev = before;
	}

	list->count--;
	res = node->value;
	free(node);

error:
	return res;
}

