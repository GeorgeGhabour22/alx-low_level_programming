#INCLUDE "LISTS.H"
/**
* FREE_LISTP2 - FREES A LINKED LIST
* @HEAD: HEAD OF A LIST.
*
* RETURN: NO RETURN.
*/
VOID FREE_LISTP2(LISTP_T **HEAD)
{
LISTP_T *TEMP;
LISTP_T *CURR;
IF (HEAD != NULL)
{
CURR = *HEAD;
WHILE ((TEMP = CURR) != NULL)
{
CURR = CURR->NEXT;
FREE(TEMP);
}
*HEAD = NULL;
}
}
/**
* FREE_LISTINT_SAFE - FREES A LINKED LIST.
* @H: HEAD OF A LIST.
*
* RETURN: SIZE OF THE LIST THAT WAS FREED.
*/
SIZE_T FREE_LISTINT_SAFE(LISTINT_T **H)
{
SIZE_T NNODES = 0;
LISTP_T *HPTR, *NEW, *ADD;
LISTINT_T *CURR;
HPTR = NULL;
WHILE (*H != NULL)
{
NEW = MALLOC(SIZEOF(LISTP_T));
IF (NEW == NULL)
EXIT(98);
NEW->P = (VOID *)*H;
NEW->NEXT = HPTR;
HPTR = NEW;
ADD = HPTR;
WHILE (ADD->NEXT != NULL)
{
ADD = ADD->NEXT;
IF (*H == ADD->P)
{
*H = NULL;
FREE_LISTP2(&HPTR);RETURN (NNODES);
}
}
CURR = *H;
*H = (*H)->NEXT;
FREE(CURR);
NNODES++;
}
*H = NULL;
FREE_LISTP2(&HPTR);
RETURN (NNODES);
}

