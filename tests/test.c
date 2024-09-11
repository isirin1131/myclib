#include<MyList.h>
#include<stdio.h>

int main() {
	ListNode test;
	int a = 999;
	test.value = &a;
	printf("%d", *((int*)test.value));
	return 0;
}
