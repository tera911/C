#include <stdio.h>

void showList(struct List ListAdd);
/* データだけを表示 */
void AddList(struct *List);
void DeleteList(struct *List);

struct List{
    struct *List Address;
    char[10] Date;
};

static struct *List ListAdd;

int main(void){
    
}