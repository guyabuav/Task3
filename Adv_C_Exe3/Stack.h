#pragma once

/***************** Stack ADT Declaration *****************/

/// <summary>
/// 
/// </summary>
typedef struct charNode 
{
	char data;
	struct charNode* next;
}charNode;

/// <summary>
/// 
/// </summary>
typedef struct Stack 
{
	charNode* head;
}Stack;

/// <summary>
/// Initializes a stack structure.
/// 
///	A stack cannot be used with any
///	ADT function before init. the owner of the stack MUST
///	init the stack before use.
/// 
///	Uninitialized use of a stack (push, pop, isEmpty, destroy)
///	results in undefined behaviour.
/// 
/// Initializing an already initialized Stack results in undefined behaviour.
/// </summary>
/// 
/// <assumption> s != nullptr </assumption>
/// 
/// <param name="s"> a non null pointer to a struct Stack</param>
void initStack(Stack* s);

/// <summary>
/// Deallocates all resources used by the stack.
/// 
/// Destroying a stack more than once results in undefined behaviour.
/// 
/// Destroying a stack that has not been initialized results in undefined behaviour.
/// </summary>
/// 
/// <assumption> s != nullptr </assumption>
/// <assumption> stack has been initialized </assumption>
/// 
/// <param name="s"> a non null pointer to a struct Stack</param>
void destroyStack(Stack* s);

/// <summary>
/// Pushes a char element to the head of the stack.
/// </summary>
/// 
/// <assumption> s != nullptr </assumption>
/// <assumption> stack has been initialized </assumption>
/// 
/// <param name="s"> a non null pointer to a struct Stack</param>
/// <param name="data"> the character to push into the stack</param>
void push(Stack* s, char data);

/// <summary>
/// 
/// </summary>
/// <param name="s"> a non null pointer to a struct Stack</param>
/// <returns></returns>
char pop(Stack* s);

/// <summary>
/// 
/// </summary>
/// <param name="s"> a non null pointer to a struct Stack</param>
/// <returns></returns>
int isEmptyStack(const Stack* s);

/*************** Functions using Stacks - Declaration **************************/

/// <summary>
/// 
/// </summary>
/// <param name="sentence"></param>
void flipBetweenHashes(const char* sentence);

/// <summary>
/// 
/// </summary>
/// <param name="s"> a non null pointer to a struct Stack</param>
/// <returns></returns>
int isPalindrome(Stack* s);

/// <summary>
/// 
/// </summary>
/// <param name="s"> a non null pointer to a struct Stack</param>
/// <param name="n"></param>
void rotateStack(Stack* s, int n);