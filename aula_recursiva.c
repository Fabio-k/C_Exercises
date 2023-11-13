#include <stdio.h>
int count(int num){
    if (num == -1){
        return 0;
    }
    count(num - 1);
    printf("%i\n",num);
}
int main(){
    int num = 0;
    scanf("%i",&num);
    count(num);
}