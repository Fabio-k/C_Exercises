#include <stdio.h>
void quickFind();
void quickUnion();
void weightedQuickUnion();
void weightedQuickUnionWithPathCompression();
int main(){
	int option = 0;
	do{
		printf("digite uma das opções");
		scanf("%d",&option);
		switch (option)
		{
		case 0:
			quickFind();
			break;
		case 1:
			quickUnion();
			break;
		case 2:
			weightedQuickUnion();
			break;
		case 3:
			weightedQuickUnionWithPathCompression();
			break;
		case 5:
			break;
		default:
			break;
		}
	}while(option != 5);
	weightedQuickUnion();
}
void quickFind(){
	int id[10], p, q, i, t;
	for(i = 0; i < 10; i++)id[i] = i;
	while(scanf("%d %d\n",&p, &q) == 2){
		if(id[p] == id[q]) continue;
		for(t = id[p], i = 0; i < 10;i++){
			if(id[i] == t)id[i] = id[q];
			
		}
		printf("%i -- %i\n",p, q);
		for(i = 0; i < 10; i++) printf("%i--",id[i]);
		printf("\n");
	}
}
void quickUnion(){
	int id[10], p, q, i, j;
	for(i = 0; i < 10; i++)id[i] = i;
	while(scanf("%d %d\n",&p, &q) == 2){
		for(i = p; i != id[i];i = id[i]);
		for(j = q; j != id[j]; j = id[j]);
		if(i == j) continue;
		id[i] = j;
		printf("%i -- %i\n",p, q);
		for(i = 0; i < 10; i++) printf("%i--",id[i]);
		printf("\n");
	}
}
void weightedQuickUnion(){
	int id[10], p, q, i, j, sz[10];
	char data[50];
	for(i = 0; i < 10; i++)id[i] = i;
	while(scanf("%d %d",&p, &q) == 2){
		for(i = p; i != id[i];i = id[i]);
		for(j = q; j != id[j]; j = id[j]);
		if(i == j) continue;
		if (sz[i] < sz[j]){
			id[i] = j;
			sz[j] += sz[i];
		}
		else{
			id[j] = i;
			sz[i] += sz[j];
		}
		
		printf("%i -- %i\n",p, q);
		for(i = 0; i < 10; i++) printf("%i",id[i]);
		printf("\n");
	}

}
void weightedQuickUnionWithPathCompression(){
	int id[10], p, q, i, j, sz[10];
	for(i = 0; i < 10; i++)id[i] = i;
	while(scanf("%d %d",&p, &q) == 2){
		for(i = p; i != id[i];i = id[i]) id[i] = id[id[i]];
		for(j = q; j != id[j]; j = id[j]) id[j] = id[id[j]];
		if(i == j) continue;
		if (sz[i] < sz[j]){
			id[i] = j;
			sz[j] += sz[i];
		}
		else{
			id[j] = i;
			sz[i] += sz[j];
		}
		
		printf("%i -- %i\n",p, q);
		for(i = 0; i < 10; i++) printf("%i",id[i]);
		printf("\n");
	}

}