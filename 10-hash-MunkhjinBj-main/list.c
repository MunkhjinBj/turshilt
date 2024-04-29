#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, Student x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */

  Elm* a = (Elm*)malloc(sizeof(Elm));

  a->x = x;
  a->next = NULL;
  if(p->head == NULL || p == NULL){
    p->head = a;
    p->tail = a;
  }
  else {
    p->tail->next = a;
    p->tail = a;
  }

  p->len++;

}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, Student x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  Elm* a = (Elm*) malloc (sizeof(Elm));
  a->x = x;

  a->next = p->head;
  p->head = a;

  if(p->tail == NULL){
    p->tail = a;
  }
  p->len++;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, Student x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */

  if(pos < 0){
    return;
  }

  if(pos == 0){
    l_push_front(p,x);
    return;
  }

  if(pos > p->len || pos == p->len){
    l_push_back(p,x);
    return;
  }

  Elm* current = p->head;

  for(int i = 0; i < pos - 1; i++){
    current = current->next;
  }

  Elm* a = (Elm*)malloc(sizeof(Elm));
  if(a == NULL){
    return;
  }

  a->x = x;

  a->next = current->next;
  current->next = a;

  p->len++;
}


/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */

  Elm* temp = p->head;

  p->head = p->head->next;
  free(temp);

  p->len--;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */

  Elm* prev = NULL;
  Elm* current = p->head;
  while(current->next != NULL){
    prev = current;
    current = current -> next;
  }
  p->tail = prev;

  free(current);

  p->tail->next = NULL;
  p->len--;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */

  if(pos < 0){
    return;
  }

  if(p->len == pos || p -> len > pos){
    l_pop_back(p);
    return;
  }

  if(p == 0){
    l_pop_front(p);
    return;
  }

  Elm* prev = NULL;
  Elm* current = p->head;

  for(int i =0; i < pos; i++){
    prev = current;
    current = current -> next;
  }
  prev->next = current->next;
  free(current);

  p->len--;

}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p)
{
        /* Энд хэвлэх үйлдлийг хийнэ үү */
        Elm* current = p->head;

        while(current != NULL){
          printf("%c\n", current->x);
          current = current ->next;
        }
}

/*
  p-ийн зааж буй List-с id-тай оюутныг хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, const char id[])
{
        /*
          Энд хайх үйлдлийг хийнэ үү.
         */

        Elm* current = p->head;

        while(current != NULL){
          if(strcmp(current->x.id, id) == 0){
            return current;
          }
          current = current->next;
        }
        return NULL;
}
