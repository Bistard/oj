#include <stdlib.h>
#include <stdbool.h>


/* 
    *** UNFINISHED AND NOT PROPERLY IMPLEMENTED ***
 */

bool CAS(int *addr, int oldval, int newval)
{
  if ( *addr != oldval ) {
      return false;
  }
  *addr = newval;
  return true;
}

typedef struct {
    int val;
    node *next;
}  node;

typedef struct {
    node *head;
    node *tail;
} queue;

queue *init_queue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    // dummy node ()
    node *dummy_node = (node *) malloc(sizeof(node));
    dummy_node->next = NULL;
    q->head = dummy_node;
    q->tail = dummy_node;
    return q;
}

node *new_node(int val) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->val = val;
    return newnode;
}

void en_queue_ver_1(queue *q, int data)
{
    node *newnode = new_node(data);
    node *p = NULL;
    do {
        p = q->tail;
    } while (CAS(p->next, NULL, newnode) != true);

    q->tail = newnode; // CAS(q->tail, p, newnode);
}

void en_queue_ver_2(queue *q, int data)
{
    node *newnode = new_node(data);
    node *p = q->tail;
    do {
        while (p->next != NULL)
            p = p->next;
    } while (CAS(p->next, NULL, newnode) != true);

    q->tail = newnode; // CAS(q->tail, p, newnode);
}

void en_queue_ver_3(queue *q, int data)
{
    node *newnode = new_node(data);
    while (true) {
        node *tail = q->tail;
        node *tail_next = tail->next;

        // 如果尾指针已经被移动了，则重新开始
        if (tail != tail_next) continue;

        // 如果尾指针的 next 不为NULL，则 fetch 全局尾指针到next
        if (tail_next != NULL) {
            q->tail = tail_next;
            continue;
        }

        //如果加入结点成功，则退出
        if (CAS(q->tail, tail, newnode) == true) break;
    }

    q->tail = newnode; // CAS(q->tail, p, newnode);
}

int de_queue(queue *q)
{
    node *head = NULL;
    do {
        head = q->head;
        if (head->next == NULL) {
            perror("queue is empty");
            exit(EXIT_FAILURE);
        }
    } while (CAS(q->head, head, head->next) != true);
    return q->head->val;
}



